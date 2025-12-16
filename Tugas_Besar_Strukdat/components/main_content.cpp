#include "main_content.h"
#include "components/renderlogo.h"

MainContent::MainContent(const QString &logoPath, QWidget *parent) : QWidget(parent){
    int radius = 15;

    RenderLogo *logo = new RenderLogo(logoPath, radius, this);
    logo->setFixedSize(48, 48);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0,0,0,0);
    layout->setAlignment(Qt::AlignCenter);
    layout->addWidget(logo);
}
