#include "renderlogo.h"
#include <QPainter>
#include <QPainterPath>
#include <QDebug>

RenderLogo::RenderLogo(const QString &path, int radius, QWidget *parent): QWidget(parent), m_radius(radius) {
    m_originalPix.load(path);
    if (m_originalPix.isNull()) {
        qDebug() << "Gagal load gambar:" << path;
    }

    setMinimumSize(50, 50);
}

void RenderLogo::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    if (m_originalPix.isNull())
        return;

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);

    QPixmap scaledPix = m_originalPix.scaled(this->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);

    int x = (this->width() - scaledPix.width()) / 2;
    int y = (this->height() - scaledPix.height()) / 2;

    QPainterPath path;
    path.addRoundedRect(x, y, scaledPix.width(), scaledPix.height(), m_radius, m_radius);
    painter.setClipPath(path);
    painter.drawPixmap(x, y, scaledPix);
}
