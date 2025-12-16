#ifndef RENDERLOGO_H
#define RENDERLOGO_H

#include <QWidget>
#include <QPixmap>

class RenderLogo : public QWidget {
    Q_OBJECT

    public:
        explicit RenderLogo(const QString &path, int radius, QWidget *parent = nullptr);

    protected:
        void paintEvent(QPaintEvent *event) override;

    private:
        QPixmap m_originalPix;
        int m_radius;
};

#endif // RENDERLOGO_H
