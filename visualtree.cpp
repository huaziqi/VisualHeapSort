#include "visualtree.h"
#include "qpainter.h"

VisualTree::VisualTree(QWidget *parent)
    : QWidget{parent}
{
    this->setStyleSheet("background-color: black;");

}

void VisualTree::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    // 设置画笔
    painter.setPen(Qt::blue);

    // 设置画刷
    painter.setBrush(Qt::yellow);

    // 画一个矩形
    painter.drawRect(2000, 2000, 10, 10);

    // 画一条线
    painter.drawLine(10, 10, 110, 110);

    // 画文本
    painter.drawText(50, 150, "Hello, Qt!");
}
