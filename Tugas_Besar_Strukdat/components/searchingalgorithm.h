#ifndef SEARCHINGALGORITHM_H
#define SEARCHINGALGORITHM_H

#include <QStringList>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QFrame>
#include <QDebug>
#include <QMap>

#include "data_render.h"

class SearchingAlgorithm{
    public:
        SearchingAlgorithm();

        static QStringList cariDanRenderRute(
            const QString& kategori,
            QWidget* parentWidget,
            QLabel* labelJumlah
        );

        static QStringList cariRute(
            const QString &keyword,
            const QStringList &dataSumber,
            QWidget *parentWidget,
            QLabel *labelJumlah
        );

    private:
        static void renderHasilKeUI(
            const QStringList& hasil,
            QWidget* parentWidget
        );
};

#endif // SEARCHINGALGORITHM_H
