#include "data_render.h"

DataRender::DataRender() {}

void DataRender::RenderListLokasi(QComboBox *comboBox) {
    if (!comboBox)
        return;

    comboBox->clear();

    QStringList daftarNama = data_peta_lengkap.keys();
    daftarNama.sort();

    comboBox->addItems(daftarNama);
    comboBox->setMaxVisibleItems(6);
    comboBox->view()->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    comboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);
}

void DataRender::RenderListKategori(QComboBox *comboBox) {
    if (!comboBox)
        return;

    comboBox->clear();
    comboBox->addItem("Semua Kategori");

    QStringList kategoriUnik;
    for (const auto &lokasi : data_peta_lengkap) {
        if (!kategoriUnik.contains(lokasi.tipe)) {
            kategoriUnik.append(lokasi.tipe);
        }
    }
    kategoriUnik.sort();

    comboBox->addItems(kategoriUnik);
}

void DataRender::ClearListKategori(QComboBox* dari_lokasi, QComboBox* tujuan_lokasi){
    if (dari_lokasi)
        dari_lokasi->setCurrentIndex(0);
    if (tujuan_lokasi)
        tujuan_lokasi->setCurrentIndex(0);
}
