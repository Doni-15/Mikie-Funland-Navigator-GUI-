#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QPixmap>
#include <QPainter>
#include <QPainterPath>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    QVBoxLayout *layout = new QVBoxLayout(ui->logo);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    QLabel *imageLabel = new QLabel(ui->logo);
    imageLabel->setAlignment(Qt::AlignCenter);

    QPixmap pix(":/images/images/lokasi.png");

    int w = ui->logo->width();
    int h = ui->logo->height();

    QPixmap scaledPix = pix.scaled(w, h, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    QPixmap roundedPix(scaledPix.size());
    roundedPix.fill(Qt::transparent);

    QPainter painter(&roundedPix);
    painter.setRenderHint(QPainter::Antialiasing);

    QPainterPath path;
    int radius = 15;
    path.addRoundedRect(0, 0, scaledPix.width(), scaledPix.height(), radius, radius);

    painter.setClipPath(path);
    painter.drawPixmap(0, 0, scaledPix);

    imageLabel->setPixmap(roundedPix);
    layout->addWidget(imageLabel);
}

MainWindow::~MainWindow(){
    delete ui;
}
