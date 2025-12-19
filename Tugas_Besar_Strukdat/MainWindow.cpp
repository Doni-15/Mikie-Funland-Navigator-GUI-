#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QGraphicsDropShadowEffect>
#include <algorithm>

#include "components/header_component.h"
#include "components/footer_component.h"
#include "components/main_content.h"
#include "components/data_render.h"
#include "components/djikstraalgorithm.h"

using namespace Qt;

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    logoRender();
    shadowRender();
    getListItems();

    m_footer = new FooterComponent(ui->footer, this);

    connect(ui->hapus_list, &QPushButton::clicked, this, &MainWindow::on_hapus_list_clicked);
    connect(ui->dari_kota, &QComboBox::currentTextChanged, this, &MainWindow::updateRuteOtomatis);
    connect(ui->tujuan_kota, &QComboBox::currentTextChanged, this, &MainWindow::updateRuteOtomatis);
}

void MainWindow::updateRuteOtomatis() {
    QString asal = ui->dari_kota->currentText();
    QString tujuan = ui->tujuan_kota->currentText();

    if (asal == tujuan || asal.isEmpty() || tujuan.isEmpty()) {
        if (ui->isi_lokasi->layout()) {
            QLayoutItem* item;
            while ((item = ui->isi_lokasi->layout()->takeAt(0)) != nullptr) {
                if (item->widget()) delete item->widget();
                delete item;
            }
        }

        ui->cari_rute->setMinimumHeight(400);
        ui->jarak_total->setText("0 meter");
        ui->jumlah_lokasi->setText("0 lokasi");

        ui->cari_rute->updateGeometry();
        if(ui->cari_rute->parentWidget() && ui->cari_rute->parentWidget()->layout()) {
            ui->cari_rute->parentWidget()->layout()->activate();
        }

        return;
    }

    QList<QString> hasilRute = DjikstraAlgorithm::cariDanRenderRute(
        asal,
        tujuan,
        ui->isi_lokasi,
        ui->jarak_total,
        ui->jumlah_lokasi
    );

    // int tinggiMinimalAwal = 400;
    // int tinggiPerItem = 60;

    // int totalTinggiRute = hasilRute.size() * tinggiPerItem;

    // int tinggiFinal = std::max(tinggiMinimalAwal, totalTinggiRute);

    // ui->cari_rute->setMinimumHeight(tinggiFinal);
    // ui->cari_rute->updateGeometry();

    int tinggiMinimalAwal = 400;
    int tinggiPerItem = 60;
    int tinggiHeaderDanMargin = 100;

    int totalTinggiKonten = (hasilRute.size() * tinggiPerItem) + tinggiHeaderDanMargin;

    int tinggiFinal = std::max(tinggiMinimalAwal, totalTinggiKonten);

    ui->cari_rute->setMinimumHeight(tinggiFinal);

    if(ui->cari_rute->parentWidget()->layout()) {
        ui->cari_rute->parentWidget()->layout()->activate();
    }
}

void MainWindow::on_hapus_list_clicked() {
    DataRender::ClearListKategori(ui->dari_kota, ui->tujuan_kota);
    ui->kategori->setCurrentIndex(0);

    if (ui->isi_lokasi->layout()) {
        QLayoutItem* item;
        while ((item = ui->isi_lokasi->layout()->takeAt(0)) != nullptr) {
            if (item->widget()) delete item->widget();
            delete item;
        }
    }

    ui->cari_rute->setMinimumHeight(400);
    ui->cari_rute->updateGeometry();
}

void MainWindow::getListItems(){
    DataRender::RenderListLokasi(ui->dari_kota);
    DataRender::RenderListLokasi(ui->tujuan_kota);
    DataRender::RenderListKategori(ui->kategori);
}

void MainWindow::logoRender(){
    auto setupLogo = [](QWidget* container, QWidget* content) {
        QVBoxLayout *layout = new QVBoxLayout(container);
        layout->setContentsMargins(0,0,0,0);
        layout->setAlignment(Qt::AlignCenter);
        layout->addWidget(content);
    };

    setupLogo(ui->logo, new HeaderComponent(":/logo/lokasi.png", ui->logo));
    setupLogo(ui->logo_judul, new MainContent(":/logo/cari_rute.png", ui->logo_judul));
    setupLogo(ui->telusuri_logo, new MainContent(":/logo/tune.png", ui->telusuri_logo));
}

void MainWindow::shadowRender(){
    auto shadow = [this](QWidget* widget, int radius, int x, int y, QColor color) {
        QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
        shadow->setBlurRadius(radius);
        shadow->setOffset(x, y);
        shadow->setColor(color);
        widget->setGraphicsEffect(shadow);
    };

    shadow(ui->cari_rute, 20, 0, 0, QColor(0, 0, 0, 80));
    shadow(ui->telusuri_wahana, 20, 0, 0, QColor(0, 0, 0, 80));
}

MainWindow::~MainWindow(){
    delete ui;
}
