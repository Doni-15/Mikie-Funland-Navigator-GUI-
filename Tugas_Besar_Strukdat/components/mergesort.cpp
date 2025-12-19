#include "mergesort.h"

MergeSort::MergeSort() {}

QStringList MergeSort::jalankanSorting(const QStringList &dataSumber, const QMap<QString, Lokasi> &dataMap) {
    QStringList hasil = dataSumber;

    if(!hasil.isEmpty()){
        devine(hasil, 0, hasil.size()-1, dataMap);
    }

    return hasil;
}

void MergeSort::devine(QStringList &arr, int left, int right, const QMap<QString,Lokasi> &dataMap){
    if(left >= right) return;

    int mid = left + (right - left)/2;

    devine(arr, left, mid, dataMap);
    devine(arr, mid+1, right, dataMap);
    conquere(arr, left, mid, right, dataMap);
}

void MergeSort::conquere(QStringList &arr, int left, int mid, int right, const QMap<QString,Lokasi> &dataMap){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    QStringList L = arr.mid(left, n1);
    QStringList R = arr.mid(mid+1, n2);

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2){
        if(compare(L[i], R[j], dataMap)){
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while(i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = R[j++];
}

bool MergeSort::compare(const QString &a, const QString &b, const QMap<QString,Lokasi> &dataMap){
    return dataMap.value(a).rating > dataMap.value(b).rating;
}
