#ifndef MAINCONTENT_H
#define MAINCONTENT_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPixmap>
#include <QPainter>
#include <QPainterPath>
#include <QDebug>

class QLabel;
class QString;

class MainContent : public QWidget {
    Q_OBJECT

    public:
        explicit MainContent(const QString &logoPath, QWidget *parent = nullptr);

};

#endif // MAINCONTENT_H
