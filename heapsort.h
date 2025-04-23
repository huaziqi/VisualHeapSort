#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "common.h"

class HeapSort : public QWidget
{
    Q_OBJECT
public:
    explicit HeapSort(QWidget *parent = nullptr);

private:
    int vectorSize;
    QVector<int> sortNums;
    void heapSortA();
    void down(int u, int v);

public slots:
    void acceptData(const int& size, const QVector<int>& nums);
signals:
    void codesId(int codesId);

signals:
};

#endif // HEAPSORT_H
