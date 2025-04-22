#include "heapsort.h"

HeapSort::HeapSort(QWidget *parent)
    : QWidget{parent}
{}

void HeapSort::acceptData(const int &length, const QVector<int> &nums)
{
    this->vectorLength = length;
    this->sortNums = nums;

}
