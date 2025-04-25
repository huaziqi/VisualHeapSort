#include "visualtree.h"
#include "qpainter.h"

VisualTree::VisualTree(QWidget *parent)
    : QWidget{parent}
{
    this->setStyleSheet("background-color: black;");
    colorList.append(QColor(255, 0, 0, 127));
    colorList.append(QColor(0, 255, 0, 127));
    colorList.append(QColor(0, 0, 255, 127));
    qDebug() << getLayer(4);
}

int VisualTree::getLayer(int point)
{
    return log2(point + 1) + 1;
}

void VisualTree::paintEvent(QPaintEvent *event)
{
    if(!gotInfo)
        return;
    if(size == 0){
        return;
    }
    double sqrt2 = sqrt(2) / 2;
    double width = this->width();
    int lineLength = 70;
    int layer = 3;
    int scale = 1000;
    int stdLine = width / scale * lineLength * sqrt2;
    QPainter painter(this);
    QColor rectColor;
    int radius = width / scale * 40;

    QFont font;
    font.setPointSize(width / scale * 20);
    painter.setFont(font);

    QPen pen;
    pen.setWidth(3);
    painter.setPen(pen);

    QPoint prePainterPos(width / 2, lineLength + 100);
    QPoint nowPainterPos(width / 2, lineLength + 100 - radius);
    QRect textRect;

    if(currentPoint / 2 >= 1){

        painter.fillRect(0, prePainterPos.y() - radius - stdLine / 2, width, 2 * radius + stdLine, colorList[0]);
        painter.drawEllipse(prePainterPos, radius, radius);
        textRect = {prePainterPos.x() - radius, prePainterPos.y() - radius, radius * 2, radius * 2};
        painter.drawText(textRect, Qt::AlignCenter, QString::number(nums[currentPoint / 2]));
        nowPainterPos.setX(prePainterPos.x());
        nowPainterPos.setY(prePainterPos.y() + radius + stdLine);
        prePainterPos.setY(prePainterPos.y() + radius);
        painter.drawLine(prePainterPos, nowPainterPos);
    }
    if(currentPoint / 2 < 1)
        nowPainterPos.setY(prePainterPos.y() + radius + stdLine);
    else
        nowPainterPos.setY(nowPainterPos.y() + radius);
    painter.fillRect(0, nowPainterPos.y() - radius - stdLine / 2, width, 2 * radius + stdLine - radius * sqrt2 * 0.8, colorList[1]);
    painter.drawEllipse(nowPainterPos, radius, radius);
    textRect = {nowPainterPos.x() - radius, nowPainterPos.y() - radius, radius * 2, radius * 2};
    painter.drawText(textRect, Qt::AlignCenter, QString::number(nums[currentPoint]));


    if(currentPoint * 2 <= size){
        prePainterPos.setX(nowPainterPos.x() - 1.0 * radius * sqrt2);
        prePainterPos.setY(nowPainterPos.y() + 1.0 * radius * sqrt2);
        nowPainterPos.setX(prePainterPos.x() - stdLine);
        nowPainterPos.setY(prePainterPos.y() + stdLine);
        painter.drawLine(prePainterPos, nowPainterPos);
        nowPainterPos.setX(nowPainterPos.x() - sqrt2 * radius);
        nowPainterPos.setY(nowPainterPos.y() + sqrt2 * radius);
        painter.fillRect(0, nowPainterPos.y() - radius - stdLine / 2, width, 2 * radius + stdLine, colorList[2]);
        painter.drawEllipse(nowPainterPos, radius, radius);
        textRect = {nowPainterPos.x() - radius, nowPainterPos.y() - radius, radius * 2, radius * 2};
        painter.drawText(textRect, Qt::AlignCenter, QString::number(nums[currentPoint * 2]));
    }

    if(currentPoint * 2 + 1 <= size){
        prePainterPos.setX(prePainterPos.x() + 2.0 * radius * sqrt2);
        nowPainterPos.setX(prePainterPos.x() + stdLine);
        nowPainterPos.setY(prePainterPos.y() + stdLine);
        painter.drawLine(prePainterPos, nowPainterPos);
        nowPainterPos.setX(nowPainterPos.x() + sqrt2 * radius);
        nowPainterPos.setY(nowPainterPos.y() + sqrt2 * radius);
        painter.fillRect(0, nowPainterPos.y() - radius - stdLine / 2, width, 2 * radius + stdLine, colorList[2]);
        painter.drawEllipse(nowPainterPos, radius, radius);
        textRect = {nowPainterPos.x() - radius, nowPainterPos.y() - radius, radius * 2, radius * 2};
        painter.drawText(textRect, Qt::AlignCenter, QString::number(nums[currentPoint * 2 + 1]));
    }

}

void VisualTree::getInfo(int currentPoint, QVector<int> nums, int size)
{
    gotInfo = true;
    this->currentPoint = currentPoint;
    this->nums = nums;
    this->size = size;
    this->update();
}
