#ifndef HEADERCOMPONENT_H
#define HEADERCOMPONENT_H

#include <QWidget>

class HeaderComponent : public QWidget{
    Q_OBJECT
public:
    explicit HeaderComponent(QWidget *parent = nullptr);
};

#endif // HEADERCOMPONENT_H
