#include "heapsort.h"

HeapSort::HeapSort(QWidget *parent)
    : QWidget{parent}
{}

void HeapSort::acceptData(const int &size, const QVector<int> &nums){
    this->vectorSize = size;
    this->sortNums = nums;
}


// << "void HeapSort::down(int u, int v){"
//     << "    if(2 * u <= vectorSize && sortNums[2 * u] < sortNums[v])"
//     << "        v = 2 * u;"
//     << "    if(2 * u + 1 <= vectorSize && sortNums[2 * u + 1] < sortNums[v])"
//     << "        v = 2 * u + 1;"
//     << "    if(u != v){"
//     << "        std::swap(sortNums[u], sortNums[v]);"
//     << "        down(v, v);"
//     << "    }"
//     << "}"
//     << "void HeapSort::heapSortA(){"
//     << "    for(int i = vectorSize / 2; i >= 1; i --){"
//     << "        down(i, i);"
//     << "    }"
//     << "    for(int i = 1; i <= vectorSize; i ++){"
//     << "        sortNums[1] = sortNums[vectorSize];"
//     << "        vectorSize --;"
//     << "        down(1, 1);"
//     << "    }"
//     << "}";
void HeapSort::stepedSort()
{
    switch(step){
    case enterHeap:
        emit codesId(10);
        currentPoint = 1;
        step = loop_1;
        nowLoop = 0;
        loopI = vectorSize / 2 + 1;
        break;
    case loop_1:
        emit codesId(11);
        currentPoint = 1;
        loopI -= 1;
        if(loopI == 0){
            step = loop_2;
            loopI = 0;
            nowLoop = 1;
            break;
        }
        step = loopDown_1;
        break;
    case loopDown_1:
        emit codesId(12);
        currentPoint = loopI;
        downU = downV = loopI;
        step = enterDown;
        break;

    case loop_2:
        emit codesId(14);
        loopI ++;
        if(loopI >= vectorSize + 1){
            break;
        }
        step = loopSet;
        break;
    case loopSet:
        emit codesId(15);
        sortNums[1] = sortNums[vectorSize];
        step = loopSubSize;
        break;
    case loopSubSize:
        emit codesId(16);
        vectorSize --;
        step = loopDown_2;
        break;
    case loopDown_2:
        emit codesId(17);
        downU = downV = 1;
        step = enterDown;
        break;
    case enterDown:
        emit codesId(0);
        step = downJudge_1;
        break;
    case downJudge_1:
        emit codesId(1);
        if(2 * downU <= vectorSize && sortNums[2 * downU] < sortNums[downV]){
            step = downSetV_1;
            break;
        }
        else{
            step = downJudge_2;
            break;
        }
    case downSetV_1:
        emit codesId(2);
        downV = 2 * downU;
        step = downJudge_2;
        break;
    case downJudge_2:
        emit codesId(3);
        if(2 * downU + 1 <= vectorSize && sortNums[2 * downU + 1] < sortNums[downV]){
            step = downSetV_2;
            break;
        }
        else{
            step = downJudge_3;
            break;
        }
    case downSetV_2:
        emit codesId(4);
        downV = 2 * downU + 1;
        step = downJudge_3;
        break;
    case downJudge_3:
        emit codesId(5);
        if(downU != downV){
            step = downSwap;
            break;
        }
        else{
            if(nowLoop == 0) step = loop_1;
            else step = loop_2;
            break;
        }
    case downSwap:
        emit codesId(6);
        std::swap(sortNums[downU], sortNums[downV]);
        step = downDown;
        break;
    case downDown:
        emit codesId(7);
        downU = downV;
        step = enterDown;
        break;
    }


}


