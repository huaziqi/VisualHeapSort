#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "common.h"

class HeapSort : public QWidget
{
    Q_OBJECT
public:
    explicit HeapSort(QWidget *parent = nullptr);

private:
    int vectorLength;
    QVector<int> sortNums;

private slots:
    void acceptData(const int& length, const QVector<int>& nums);

signals:
};

#endif // HEAPSORT_H
