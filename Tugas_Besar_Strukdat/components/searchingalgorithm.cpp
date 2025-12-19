#include "searchingalgorithm.h"
#include <QLayout>

SearchingAlgorithm::SearchingAlgorithm() {}

QStringList SearchingAlgorithm::cariDanRenderRute(const QString& kategori, QWidget* parentWidget, QLabel* labelJumlah) {
    if (!parentWidget)
        return QStringList();

    QStringList hasilPencarian;

    int aktif = 0;

    QMap<QString, Lokasi>::iterator it;
    for (it = data_peta_lengkap.begin(); it != data_peta_lengkap.end(); ++it) {
        QString namaLokasi = it.key();
        QString tipeLokasi = it.value().tipe;

        bool match = false;

        if (kategori.isEmpty() || kategori == "Semua Kategori") {
            match = true;
        }

        else if (tipeLokasi == kategori) {
            match = true;
        }

        if (match) {
            hasilPencarian.append(namaLokasi);
            aktif++;
        }
    }

    renderHasilKeUI(hasilPencarian, parentWidget);
    labelJumlah->setText("Tersedia " + QString::number(aktif) + " dari " + QString::number(data_peta_lengkap.size()) + " lokasi");

    return hasilPencarian;
}

QStringList SearchingAlgorithm::cariRute(const QString &keyword, const QStringList &dataSumber, QWidget *parentWidget, QLabel *labelJumlah){
    if (!parentWidget)
        return QStringList();

    if(keyword.isEmpty()){
        renderHasilKeUI(dataSumber, parentWidget);
        if (labelJumlah)
            labelJumlah->setText("Tersedia " + QString::number(dataSumber.size()) +" dari " + QString::number(dataSumber.size()) + " lokasi");
        return dataSumber;
    }

    QStringList hasilBaru;
    int aktif = 0;

    for (const QString &namaLokasi : dataSumber) {
        if (keyword.isEmpty() || namaLokasi.contains(keyword, Qt::CaseInsensitive)) {
            hasilBaru.append(namaLokasi);
            aktif++;
        }
    }

    renderHasilKeUI(hasilBaru, parentWidget);

    if (labelJumlah) {
        labelJumlah->setText("Tersedia " + QString::number(aktif) + " dari " + QString::number(dataSumber.size()) + " lokasi");
    }

    return hasilBaru;
}

void SearchingAlgorithm::renderHasilKeUI(const QStringList& hasil, QWidget* parentWidget) {
    if (!parentWidget) return;

    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(parentWidget->layout());
    if (!layout) {
        layout = new QVBoxLayout(parentWidget);
        parentWidget->setLayout(layout);
    }

    QLayoutItem* item;
    while ((item = layout->takeAt(0)) != nullptr) {
        if (QWidget* widget = item->widget()) {
            widget->hide();
            widget->deleteLater();
        } else {
            delete item;
        }
    }

    layout->setSpacing(10);
    layout->setContentsMargins(10, 10, 10, 10);
    layout->setAlignment(Qt::AlignTop);

    if (hasil.isEmpty()) return;

    for (const QString& nama : hasil) {
        if (!data_peta_lengkap.contains(nama)) continue;
        Lokasi data = data_peta_lengkap.value(nama);

        QFrame* card = new QFrame();
        card->setMinimumHeight(70);
        card->setMaximumHeight(70);
        card->setStyleSheet(
            "QFrame { background-color: white; border-radius: 12px; border: 1px solid #dfe6e9; }"
            "QFrame:hover { border: 1px solid #3498db; background-color: #f7fbff; }"
            );

        QHBoxLayout* cardLayout = new QHBoxLayout(card);
        cardLayout->setContentsMargins(15, 0, 15, 0);
        cardLayout->setSpacing(15);

        QLabel* iconCircle = new QLabel();
        iconCircle->setFixedSize(40, 40);
        iconCircle->setStyleSheet("background-color: #e3f2fd; border-radius: 20px; border: none;");

        QLabel* iconImg = new QLabel(iconCircle);
        iconImg->setPixmap(QPixmap(":/logo/lokasi.png").scaled(20, 20, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        iconImg->setAlignment(Qt::AlignCenter);

        QVBoxLayout* vIconLayout = new QVBoxLayout(iconCircle);
        vIconLayout->setContentsMargins(0,0,0,0);
        vIconLayout->addWidget(iconImg);

        QWidget* textContainer = new QWidget();
        textContainer->setStyleSheet("border: none; background: transparent;");
        QVBoxLayout* textLayout = new QVBoxLayout(textContainer);
        textLayout->setContentsMargins(0, 0, 0, 0);
        textLayout->setSpacing(2);

        QLabel* labelNama = new QLabel(nama);
        labelNama->setStyleSheet("font-weight: bold; font-size: 14px; color: #2d3436; border: none;");

        QLabel* labelDetail = new QLabel(QString::number(data.rating, 'f', 1) + " ⭐ | " + data.tipe);
        labelDetail->setStyleSheet("font-size: 11px; color: #636e72; border: none;");

        textLayout->addWidget(labelNama);
        textLayout->addWidget(labelDetail);

        cardLayout->addWidget(iconCircle);
        cardLayout->addWidget(textContainer);
        cardLayout->addStretch();

        layout->addWidget(card);
    }

    layout->addStretch(1);
}
