#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Components/headercomponent.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    QVBoxLayout *containerLayout = new QVBoxLayout(ui->logo);
    containerLayout->setContentsMargins(0,0,0,0);
    containerLayout->setAlignment(Qt::AlignCenter);

    HeaderComponent *header = new HeaderComponent(this);

    containerLayout->addWidget(header);
}

MainWindow::~MainWindow(){
    delete ui;
}
