#include "djikstraalgorithm.h"
#include <queue>
#include <QLayout>
#include <QLabel>
#include <QDebug>
#include <limits>

const int INF = std::numeric_limits<int>::max();

DjikstraAlgorithm::DjikstraAlgorithm() {}

QStringList DjikstraAlgorithm::cariDanRenderRute(const QString& awal, const QString& tujuan, QWidget* parentWidget, QLabel* labelJarak, QLabel* labelJumlah) {
    if (!parentWidget || !labelJarak || !labelJumlah) return QStringList();

    if (awal.isEmpty() || tujuan.isEmpty() || !data_peta_lengkap.contains(awal)) {
        labelJarak->setText("-");
        labelJumlah->setText("0 lokasi");
        return QStringList();
    }

    QMap<QString, int> dist;
    QMap<QString, QString> ruteSebelumnya;
    std::priority_queue<std::pair<int, QString>, std::vector<std::pair<int, QString>>, std::greater<std::pair<int, QString>>> pq;

    for (auto it = data_peta_lengkap.begin(); it != data_peta_lengkap.end(); ++it) {
        dist[it.key()] = INF;
    }
    dist[awal] = 0;
    pq.push({0, awal});

    while (!pq.empty()) {
        int d = pq.top().first;
        QString u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;
        if (u == tujuan) break;

        for (const Koneksi& edge : data_peta_lengkap.value(u).daftarTetangga) {
            QString v = edge.namaTujuan;
            int w = edge.jarak;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                ruteSebelumnya[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist.value(tujuan, INF) == INF) {
        labelJarak->setText("Tak terjangkau");
        labelJumlah->setText("0 lokasi");
        renderRuteKeUI(QStringList(), parentWidget);
        return QStringList();
    }

    QStringList ruteFinal;
    QString saatIni = tujuan;
    while (!saatIni.isEmpty() && saatIni != awal) {
        ruteFinal.prepend(saatIni);
        saatIni = ruteSebelumnya.value(saatIni, "");
    }
    ruteFinal.prepend(awal);

    labelJarak->setText(QString::number(dist[tujuan]) + " meter");
    labelJumlah->setText(QString::number(ruteFinal.size()) + " lokasi");

    renderRuteKeUI(ruteFinal, parentWidget);

    return ruteFinal;
}

void DjikstraAlgorithm::renderRuteKeUI(const QStringList& rute, QWidget* parentWidget) {
    if (!parentWidget) return;

    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(parentWidget->layout());
    if (!layout) {
        layout = new QVBoxLayout(parentWidget);
        layout->setContentsMargins(0,0,0,0);
        layout->setSpacing(0);
        parentWidget->setLayout(layout);
    }

    QLayoutItem* item;
    while ((item = layout->takeAt(0)) != nullptr) {
        if (item->widget()) delete item->widget();
        delete item;
    }

    if (rute.isEmpty()) return;

    for (int i = 0; i < rute.size(); ++i) {
        QString nama = rute[i];
        if (!data_peta_lengkap.contains(nama)) continue;
        QString tipe = data_peta_lengkap.value(nama).tipe;

        QWidget* row = new QWidget();
        QHBoxLayout* rowLayout = new QHBoxLayout(row);
        rowLayout->setContentsMargins(10, 0, 10, 0);

        QLabel* dot = new QLabel();
        dot->setFixedSize(14, 14);
        QString color = (i == 0) ? "#2ecc71" : (i == rute.size() - 1 ? "#e74c3c" : "#3498db");
        dot->setStyleSheet(QString("background-color: %1; border-radius: 7px; border: 2px solid white;").arg(color));

        QLabel* labelNama = new QLabel(nama);
        labelNama->setStyleSheet("font-weight: bold; font-size: 13px; color: #2c3e50;");

        QLabel* labelTipe = new QLabel(tipe);
        labelTipe->setStyleSheet("background-color: #dfe6e9; color: rgb(22, 36, 85); padding: 2px 6px; border-radius: 4px; font-size: 10px;");

        rowLayout->addWidget(dot);
        rowLayout->addSpacing(10);
        rowLayout->addWidget(labelNama);
        rowLayout->addStretch();
        rowLayout->addWidget(labelTipe);

        layout->addWidget(row);

        if (i < rute.size() - 1) {
            QWidget* lineContainer = new QWidget();
            QHBoxLayout* lineLayout = new QHBoxLayout(lineContainer);
            lineLayout->setContentsMargins(16, 0, 0, 0);
            lineLayout->setSpacing(0);

            QFrame* line = new QFrame();
            line->setFixedWidth(2);
            line->setFixedHeight(20);
            line->setStyleSheet("background-color: #b2bec3;");
            lineLayout->addWidget(line);
            lineLayout->addStretch();
            layout->addWidget(lineContainer);
        }
    }
    layout->addStretch();
}
