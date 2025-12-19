#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

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

        void logoRender();
        void shadowRender();
        void getListItems();

    private slots:
        void on_hapus_list_clicked();
        void updateRuteOtomatis();
};
#endif // MAINWINDOW_H
