#include "visualtree.h"
#include "qpainter.h"

VisualTree::VisualTree(QWidget *parent)
    : QWidget{parent}
{
    this->setStyleSheet("background-color: black;");
    currentPoint = 2;
    nums.append(-1);
    nums.append(1);
    nums.append(2222);
    nums.append(3);
    nums.append(4);
    nums.append(4);
    nums.append(4);
    nums.append(4);
    nums.append(4);
    size = 8;
}

void VisualTree::paintEvent(QPaintEvent *event)
{
    double sqrt2 = sqrt(2) / 2;
    int lineLength = 70;
    int layer = 3;
    int scale = 1000;
    QPainter painter(this);
    double width = this->width();
    int radius = width / scale * 40;

    QFont font;
    font.setPointSize(width / scale * 20);
    painter.setFont(font);

    QPen pen;
    pen.setWidth(3);
    painter.setPen(pen);


    QPoint prePainterPos(width / 2, lineLength);
    QPoint nowPainterPos(width / 2, lineLength - radius);
    QRect textRect;

    painter.drawEllipse(prePainterPos, radius, radius);

    if(currentPoint / 2 >= 1){
        textRect = {prePainterPos.x() - radius, prePainterPos.y() - radius, radius * 2, radius * 2};
        painter.drawText(textRect, Qt::AlignCenter, QString::number(nums[currentPoint / 2]));
        nowPainterPos.setX(prePainterPos.x());
        nowPainterPos.setY(prePainterPos.y() + radius + width / scale * lineLength);
        prePainterPos.setY(prePainterPos.y() + radius);
        painter.drawLine(prePainterPos, nowPainterPos);
    }
    nowPainterPos.setY(nowPainterPos.y() + radius);
    painter.drawEllipse(nowPainterPos, radius, radius);
    textRect = {nowPainterPos.x() - radius, nowPainterPos.y() - radius, radius * 2, radius * 2};
    painter.drawText(textRect, Qt::AlignCenter, QString::number(nums[currentPoint]));

    if(currentPoint * 2 <= size){
        prePainterPos.setX(nowPainterPos.x() - 1.0 * radius * sqrt2);
        prePainterPos.setY(nowPainterPos.y() + 1.0 * radius * sqrt2);
        nowPainterPos.setX(prePainterPos.x() - width / scale * lineLength * sqrt2);
        nowPainterPos.setY(prePainterPos.y() + width / scale * lineLength * sqrt2);
        painter.drawLine(prePainterPos, nowPainterPos);
        nowPainterPos.setX(nowPainterPos.x() - sqrt2 * radius);
        nowPainterPos.setY(nowPainterPos.y() + sqrt2 * radius);
        painter.drawEllipse(nowPainterPos, radius, radius);
        textRect = {nowPainterPos.x() - radius, nowPainterPos.y() - radius, radius * 2, radius * 2};
        painter.drawText(textRect, Qt::AlignCenter, QString::number(nums[currentPoint * 2]));
    }

    if(currentPoint * 2 + 1 <= size){
        prePainterPos.setX(prePainterPos.x() + 2.0 * radius * sqrt2);
        nowPainterPos.setX(prePainterPos.x() + width / scale * lineLength * sqrt2);
        nowPainterPos.setY(prePainterPos.y() + width / scale * lineLength * sqrt2);
        painter.drawLine(prePainterPos, nowPainterPos);
        nowPainterPos.setX(nowPainterPos.x() + sqrt2 * radius);
        nowPainterPos.setY(nowPainterPos.y() + sqrt2 * radius);
        painter.drawEllipse(nowPainterPos, radius, radius);
        textRect = {nowPainterPos.x() - radius, nowPainterPos.y() - radius, radius * 2, radius * 2};
        painter.drawText(textRect, Qt::AlignCenter, QString::number(nums[currentPoint * 2 + 1]));
    }



}
