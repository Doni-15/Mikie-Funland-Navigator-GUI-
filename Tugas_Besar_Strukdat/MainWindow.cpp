#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QGraphicsDropShadowEffect>

#include "components/header_component.h"
#include "components/footer_component.h"
#include "components/main_content.h"

using namespace Qt;

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    logoRender();
    shadowRender();

    m_footer = new FooterComponent(ui->footer, this);
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
