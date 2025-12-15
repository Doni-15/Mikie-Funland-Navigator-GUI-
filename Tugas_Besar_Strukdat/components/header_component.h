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
        explicit HeaderComponent(QWidget *parent = nullptr);

    private:
        QLabel* createLogo(const QString &path, int size, int radius);
};

#endif // HEADER_COMPONENT_H
