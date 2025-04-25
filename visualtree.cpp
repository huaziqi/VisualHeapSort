#include "visualtree.h"
#include "qpainter.h"

VisualTree::VisualTree(QWidget *parent)
    : QWidget{parent}
{
    this->setStyleSheet("background-color: black;");
    colorList.append(QColor(255, 0, 0, 127));
    colorList.append(QColor(0, 255, 0, 127));
    colorList.append(QColor(0, 0, 255, 127));
    scale = 1000;

}

int VisualTree::getLayer(int point)
{
    return log2(point) + 1;
}

void VisualTree::paintText(QPoint point, int current, QPainter& painter)
{
    textRect = {point.x() - radius, point.y() - radius, radius * 2, radius * 2};
    painter.drawText(textRect, Qt::AlignCenter, QString::number(nums[current]));
    textRect.setX(widgetWidth / scale * 100);
    painter.drawText(textRect, Qt::AlignCenter, "第" + QString::number(getLayer(current)) + "层");
}

void VisualTree::paintEvent(QPaintEvent *event)
{
    if(!gotInfo)
        return;
    if(size == 0){
        return;
    }
    widgetWidth = this->width();
    radius = widgetWidth / scale * 40;
    double sqrt2 = sqrt(2) / 2;
    int lineLength = 70;
    int stdLine = widgetWidth / scale * lineLength * sqrt2;

    QPainter painter(this);
    QFont font;
    font.setPointSize(widgetWidth / scale * 20);
    painter.setFont(font);

    QPen pen;
    pen.setWidth(3);
    painter.setPen(pen);

    QPoint prePainterPos(widgetWidth / 2, lineLength + 100);
    QPoint nowPainterPos(widgetWidth / 2, lineLength + 100 - radius);


    if(currentPoint / 2 >= 1){
        painter.fillRect(0, prePainterPos.y() - radius - stdLine / 2, widgetWidth, 2 * radius + stdLine, colorList[getLayer(currentPoint / 2) % 3]);
        painter.drawEllipse(prePainterPos, radius, radius);
        paintText(prePainterPos, currentPoint / 2, painter);
        nowPainterPos.setX(prePainterPos.x());
        nowPainterPos.setY(prePainterPos.y() + radius + stdLine);
        prePainterPos.setY(prePainterPos.y() + radius);
        painter.drawLine(prePainterPos, nowPainterPos);
    }

    if(currentPoint / 2 < 1)
        nowPainterPos.setY(prePainterPos.y() + radius + stdLine);
    else
        nowPainterPos.setY(nowPainterPos.y() + radius);

    painter.fillRect(0, nowPainterPos.y() - radius - stdLine / 2, widgetWidth, 2 * radius + stdLine - radius * (1 - sqrt2), colorList[getLayer(currentPoint) % 3]);
    painter.drawEllipse(nowPainterPos, radius, radius);
    paintText(nowPainterPos, currentPoint, painter);

    if(currentPoint * 2 <= size){
        prePainterPos.setX(nowPainterPos.x() - 1.0 * radius * sqrt2);
        prePainterPos.setY(nowPainterPos.y() + 1.0 * radius * sqrt2);
        nowPainterPos.setX(prePainterPos.x() - stdLine);
        nowPainterPos.setY(prePainterPos.y() + stdLine);
        painter.drawLine(prePainterPos, nowPainterPos);
        nowPainterPos.setX(nowPainterPos.x() - sqrt2 * radius);
        nowPainterPos.setY(nowPainterPos.y() + sqrt2 * radius);
        painter.fillRect(0, nowPainterPos.y() - radius - stdLine / 2 + radius * (1 - sqrt2), widgetWidth, 2 * radius + stdLine, colorList[getLayer(currentPoint * 2) % 3]);
        painter.drawEllipse(nowPainterPos, radius, radius);
        paintText(nowPainterPos, currentPoint * 2, painter);
    }
    if(currentPoint * 2 + 1 <= size){
        prePainterPos.setX(prePainterPos.x() + 2.0 * radius * sqrt2);
        nowPainterPos.setX(prePainterPos.x() + stdLine);
        nowPainterPos.setY(prePainterPos.y() + stdLine);
        painter.drawLine(prePainterPos, nowPainterPos);
        nowPainterPos.setX(nowPainterPos.x() + sqrt2 * radius);
        nowPainterPos.setY(nowPainterPos.y() + sqrt2 * radius);
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
