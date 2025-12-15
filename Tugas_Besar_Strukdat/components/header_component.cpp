#include "header_component.h"

using namespace Qt;

HeaderComponent::HeaderComponent(QWidget *parent) : QWidget(parent){
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    QLabel *logoLabel = createLogo(":/logo/lokasi.png", 50, 15);
    layout->addWidget(logoLabel);
}

QLabel* HeaderComponent::createLogo(const QString &path, int size, int radius) {
    QLabel *imageLabel = new QLabel(this);
    imageLabel->setAlignment(AlignCenter);

    QPixmap pix(path);
    if (pix.isNull()) {
        qDebug() << "Gagal load gambar:" << path;
        return imageLabel;
    }

    QPixmap scaledPix = pix.scaled(size, size, KeepAspectRatio, SmoothTransformation);
    QPixmap roundedPix(scaledPix.size());

    roundedPix.fill(transparent);

    QPainter painter(&roundedPix);
    painter.setRenderHint(QPainter::Antialiasing);

    QPainterPath clipPath;
    clipPath.addRoundedRect(0, 0, scaledPix.width(), scaledPix.height(), radius, radius);

    painter.setClipPath(clipPath);
    painter.drawPixmap(0, 0, scaledPix);
    painter.end();

    imageLabel->setPixmap(roundedPix);
    return imageLabel;
}
