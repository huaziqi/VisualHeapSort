#include "codewidget.h"

CodeWIdget::CodeWIdget(QWidget *parent)
    : QWidget{parent}
{
    this->setStyleSheet("background-color: #0f0f0f; color: white; font-size: 15px;");
    codesContent << "void HeapSort::down(int u, int v){"
                 << "    if(2 * u <= vectorSize && sortNums[2 * u] < sortNums[v])"
                 << "        v = 2 * u;"
                 << "    if(2 * u + 1 <= vectorSize && sortNums[2 * u + 1] < sortNums[v])"
                 << "        v = 2 * u + 1;"
                 << "    if(u != v){"
                 << "        std::swap(sortNums[u], sortNums[v]);"
                 << "        down(v, v);"
                 << "    }"
                 << "}"
                 << "void HeapSort::heapSortA(){"
                 << "    for(int i = vectorSize / 2; i >= 1; i --){"
                 << "        down(i, i);"
                 << "    }"
                 << "    for(int i = 1; i <= n; i ++){"
                 << "        sortNums[1] = sortNums[vectorSize];"
                 << "        vectorSize --;"
                 << "        down(1, 1);"
                 << "    }"
                 << "}";
    codesLayout = new QVBoxLayout();
    codesLayout->setSpacing(0);
    for(int i = 0; i < codesContent.length(); i ++){
        QLabel *tempLabel = new QLabel(codesContent[i], this);
        codeLabels.append(tempLabel);
        codesLayout->addWidget(codeLabels[i]);
        tempLabel->setStyleSheet("font-size: 18px;");
    }
    this->setLayout(codesLayout);
}

void CodeWIdget::acceptId(int codesId)
{
    if(lastId != -1){
        codeLabels[lastId]->setStyleSheet("background-color: black; color: white; font-size: 18px;");
    }
    lastId = codesId;
    codeLabels[codesId]->setStyleSheet("background-color: white; color: blue; font-size: 22px;");
}
