#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "common.h"

enum Step{
    enterDown,
    downJudge_1,
    downSetV_1,
    downJudge_2,
    downSetV_2,
    downJudge_3,
    downSwap,
    downDown,
    loop_1,
    loop_2,
    loopDown_1, //10
    loopSet,
    loopSubSize,
    loopDown_2,
    enterHeap, //14
    over
};

class HeapSort : public QWidget
{
    Q_OBJECT
public:
    explicit HeapSort(QWidget *parent = nullptr);

private:
    int vectorSize = 4, loopI, nowLoop;
    int downU, downV;
    QVector<int> sortNums;
    void heapSortA();
    void down(int u, int v);
    Step step = enterHeap;
    int currentPoint;
    QFile* file;
    QTextStream out;
public slots:
    void acceptData(const int& size, const QVector<int>& nums);
    void stepedSort();
    void reset();
signals:
    void codesId(int codesId);
    void paintInfo(int currentPoint, QVector<int> nums, int size, bool contrast, bool swap, bool tow, bool gotV, bool vSide, bool judge, bool inDown, QString info);
signals:
};

#endif // HEAPSORT_H
