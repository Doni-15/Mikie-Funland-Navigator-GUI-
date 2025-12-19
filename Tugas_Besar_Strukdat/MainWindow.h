#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QStringList>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class FooterComponent;

class MainWindow : public QMainWindow{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private:
        Ui::MainWindow *ui;
        FooterComponent *m_footer;
        QStringList data_cari;
        QString kategori_dipakai;

        void logoRender();
        void shadowRender();
        void getListItems();

    private slots:
        void on_hapus_list_clicked();
        void updateRuteOtomatis();
        void kategoriLokasi(const QString &kategori);
        void cariNamaLokasi(const QString &cari_lokasi);
};
#endif // MAINWINDOW_H
