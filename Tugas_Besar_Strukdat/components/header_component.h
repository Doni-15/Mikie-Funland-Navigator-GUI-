#ifndef HEADER_COMPONENT_H
#define HEADER_COMPONENT_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPixmap>
#include <QPainter>
#include <QPainterPath>
#include <QDebug>

class QLabel;
class QString;

class HeaderComponent : public QWidget {
    Q_OBJECT

    public:
        explicit HeaderComponent(const QString &logoPath, QWidget *parent = nullptr);
};

#endif // HEADER_COMPONENT_H
