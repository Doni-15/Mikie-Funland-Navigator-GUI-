#ifndef DJIKSTRAALGORITHM_H
#define DJIKSTRAALGORITHM_H

#include <QStringList>
#include <QFrame>
#include <QVBoxLayout>
#include <QLabel>
#include <QMap>
#include "data_render.h"

class DjikstraAlgorithm {
public:
    DjikstraAlgorithm();

    static QStringList cariDanRenderRute(
        const QString& awal,
        const QString& tujuan,
        QWidget* parentWidget,
        QLabel* labelJarak,
        QLabel* labelJumlah
        );

private:
    static void renderRuteKeUI(const QStringList& rute, QWidget* parentWidget);
};

#endif // DJIKSTRAALGORITHM_H
