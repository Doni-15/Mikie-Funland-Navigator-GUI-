#ifndef FOOTER_COMPONENT_H
#define FOOTER_COMPONENT_H

#include <QObject>
#include <QFrame>
#include <QLabel>
#include <QVBoxLayout>

class FooterComponent : public QObject{
    Q_OBJECT

    public:
        explicit FooterComponent(QFrame *frame, QObject *parent = nullptr);

    private:
        QFrame *m_frame;
        QLabel *m_lblMain;
        QLabel *m_lblSub;

        void setupUI();
        void setupStyle();
};

#endif // FOOTER_COMPONENT_H
