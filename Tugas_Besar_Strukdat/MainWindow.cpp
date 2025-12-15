#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "components/header_component.h"
#include "components/footer_component.h"

using namespace Qt;

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    QVBoxLayout *containerLayout = new QVBoxLayout(ui->logo);
    containerLayout->setContentsMargins(0,0,0,0);
    containerLayout->setAlignment(AlignCenter);

    HeaderComponent *header = new HeaderComponent(ui->logo);
    containerLayout->addWidget(header);

    m_footer = new FooterComponent(ui->footer, this);
}

MainWindow::~MainWindow(){
    delete ui;
}
