#ifndef MERGESORT_H
#define MERGESORT_H

#include <QStringList>
#include <QMap>
#include <QDebug>
#include "data_render.h"

class MergeSort {
    public:
        MergeSort();

        static QStringList jalankanSorting(
            const QStringList &dataSumber,
            const QMap<QString, Lokasi> &dataMap
        );

    private:
        static void devine(
            QStringList &arr,
            int left,
            int right,
            const QMap<QString, Lokasi> &dataMap
        );

        static void conquere(
            QStringList &arr,
            int left,
            int mid,
            int right,
            const QMap<QString, Lokasi> &dataMap
        );

        static bool compare(
            const QString &a,
            const QString &b,
            const QMap<QString, Lokasi> &dataMap
        );
};

#endif // MERGESORT_H
