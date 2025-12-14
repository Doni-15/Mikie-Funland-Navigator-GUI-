#include "headercomponent.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QPixmap>
#include <QPainter>
#include <QPainterPath>

using namespace Qt;

HeaderComponent::HeaderComponent(QWidget *parent) : QWidget(parent){
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    QLabel *imageLabel = new QLabel(this);
    imageLabel->setAlignment(AlignCenter);

    QPixmap pix(":/logo/logo/lokasi.png");

    int size = 50;
    QPixmap scaledPix = pix.scaled(size, size, KeepAspectRatio, SmoothTransformation);

    QPixmap roundedPix(scaledPix.size());
    roundedPix.fill(transparent);

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
