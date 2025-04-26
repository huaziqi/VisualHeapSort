#include "heapsort.h"

HeapSort::HeapSort(QWidget *parent)
    : QWidget{parent}
{}

void HeapSort::acceptData(const int &size, const QVector<int> &nums){
    this->vectorSize = size;
    this->sortNums = nums;
    file = new QFile("ans.txt");
    out.setDevice(file);
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
    bool swap = false, contrast = false, tow = false, gotV = false, vSide = false, judge = false;
    QString info = "";
    switch(step){
    case enterHeap:
        emit codesId(10);
        currentPoint = 1;
        step = loop_1;
        info = "开始建堆";
        nowLoop = 0;
        loopI = vectorSize / 2 + 1;
        break;
    case loop_1:
        emit codesId(11);
        loopI -= 1;
        if(loopI == 0){
            info = "开始弹出堆顶";
            step = loop_2;
            file->open(QIODevice::WriteOnly);
            nowLoop = 1;
            break;
        }
        step = loopDown_1;
        break;
    case loopDown_1:
        emit codesId(12);
        currentPoint = loopI;
        downU = downV = loopI;
        info = "转到(" + QString::number(downU) + ")";
        step = enterDown;
        break;
    case loop_2:
        emit codesId(14);
        currentPoint = 1;
        if(vectorSize == 0){
            step = over;
            info = "结束排序，打开文件";
            file->close();
            QUrl url = QUrl::fromLocalFile("ans.txt");
            if(!QDesktopServices::openUrl(url)){
                qDebug() << "打开失败";
            }
            break;
        }
        step = loopSet;
        break;
    case loopSet:
        emit codesId(15);
        info = "输出堆顶到文件";
        out << sortNums[1] << " ";
        sortNums[1] = sortNums[vectorSize];
        step = loopSubSize;
        break;
    case loopSubSize:
        emit codesId(16);
        info = "减小堆的大小";
        vectorSize --;
        step = loopDown_2;
        break;
    case loopDown_2:
        emit codesId(17);
        info = "转到堆顶节点， 开始下沉";
        currentPoint = 1;
        downU = downV = 1;
        step = enterDown;
        break;
    case enterDown:
        emit codesId(0);
        info = "转到(" + QString::number(downU) + ")";
        currentPoint = downU;
        step = downJudge_1;
        break;
    case downJudge_1:
        emit codesId(1);
        info = "判断 (" + QString::number(2 * downU) + ") 是否小于(" + QString::number(downV) + ")";
        contrast = true;
        tow = false;
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
        gotV = true;
        vSide = false;
        info = "确实小于，存储 2 * downU ";
        downV = 2 * downU;
        step = downJudge_2;
        break;
    case downJudge_2:
        emit codesId(3);
        info = "判断 (" + QString::number(2 * downU + 1) + ") 是否小于 (" + QString::number(downV) + ") ";
        contrast = true;
        tow = true;
        gotV = downU == downV ? false :true;
        vSide = (gotV && downV == 2 * downU) ? false : true;
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
        gotV = true;
        vSide = true;
        info = "确实小于，存储 2 * downU + 1 ";
        downV = 2 * downU + 1;
        step = downJudge_3;
        break;
    case downJudge_3:
        emit codesId(5);
        judge = true;
        gotV = downU == downV ? false :true;
        vSide = (gotV && downV == 2 * downU) ? false : true;
        info = "判断(" + QString::number(downU) + ")和(" + QString::number(downV) + ")是否相等";
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
        swap = true;
        gotV = downU == downV ? false :true;
        vSide = (gotV && (downV == 2 * downU)) ? false : true;
        tow = (downV == 2 * downU) ?  false : true;
        info = "交换(" + QString::number(downU) + ")和(" + QString::number(downV) + ")";
        std::swap(sortNums[downU], sortNums[downV]);
        step = downDown;
        break;
    case downDown:
        emit codesId(7);
        info = "转到(" + QString::number(downV) + ")";
        currentPoint = downV;
        downU = downV;
        step = enterDown;
        break;
    case over:
        emit codesId(20);
    }
    emit paintInfo(currentPoint, sortNums, vectorSize, contrast, swap, tow, gotV , vSide, judge,info);
}


