#include "visualtree.h"
#include "qpainter.h"

VisualTree::VisualTree(QWidget *parent)
    : QWidget{parent}
{
    this->setStyleSheet("background-color: black;");
    colorList.append(QColor(255, 0, 0, 80));
    colorList.append(QColor(0, 255, 0, 80));
    colorList.append(QColor(0, 0, 255, 80));
    scale = 1000;
}

int VisualTree::getLayer(int point)
{
    return log2(point) + 1;
}

void VisualTree::paintText(QPoint point, int current, QPainter& painter)
{
    textRect = {point.x() - radius, point.y() - radius, radius * 2, radius * 2};
    painter.drawText(textRect, Qt::AlignCenter, "(" + QString::number(current) + ") " + QString::number(nums[current]) + "");
    textRect.setWidth(5 * (1.0 * widgetWidth) / scale);
    textRect.setX(0);
    painter.drawText(textRect, Qt::AlignCenter, "第" + QString::number(getLayer(current)) + "层");
}

void VisualTree::paintCircle(QPoint point, QPainter &painter, QPen &pen, bool t, bool spec, bool isMain)
{

    if((contrast || swap || judge || inDown) && t){
        pen.setColor(QColor(222, 222, 222));
        if(spec || (!isMain && !contrast && !swap && !judge))
            pen.setColor(QColor(33, 33, 33));
    }
    painter.setPen(pen);
    painter.drawEllipse(point, radius, radius);
    if((contrast || swap || judge || (inDown && isMain)) && t)
        painter.drawEllipse(point, radius + 5, radius + 5);
    pen.setColor(QColor(0, 0, 0));
    painter.setPen(pen);
}

void VisualTree::paintArrow(QPoint point, QPainter &painter, QPen &pen, bool t, bool p)
{
    double sqrt2 = sqrt(2) / 2;
    QPoint nxtPnt;

    if(judge){
        if(p)
            pen.setColor(QColor(190, 190, 190));
        else
            pen.setColor(QColor(0, 0, 0));
        painter.setPen(pen);
    }
    if(swap and gotV){
        if(p)
            pen.setColor(QColor(0, 0, 0));
        else
            pen.setColor(QColor(190, 190, 190));
        painter.setPen(pen);
    }

    if(t){
        point.setY(point.y() + radius);
        nxtPnt.setX(point.x());
        nxtPnt.setY(point.y() + widgetWidth / 1000 * 50);
        painter.drawLine(point, nxtPnt);
        nxtPnt.setX(point.x() - widgetWidth / 1000 * 30 * sqrt2);
        nxtPnt.setY(point.y() + widgetWidth / 1000 * 30 * sqrt2);
        painter.drawLine(point, nxtPnt);
        nxtPnt.setX(nxtPnt.x() + widgetWidth / 1000 * 60 * sqrt2);
        painter.drawLine(point, nxtPnt);
    }
    pen.setColor(QColor(0, 0, 0));
    painter.setPen(pen);
}

void VisualTree::paintEvent(QPaintEvent *event)
{

    if(!gotInfo)
        return;
    widgetWidth = this->width();
    radius = widgetWidth / scale * 60;
    double sqrt2 = sqrt(2) / 2;
    int lineLength = 120;
    int fillWidth;
    int stdLine = widgetWidth / scale * lineLength * sqrt2;
    QPainter painter(this);
    QFont font;
    font.setPointSize(widgetWidth / scale * 10 + 10);
    painter.setFont(font);
    painter.drawText(50, 50, someInfo);

    if(size == 0){
        return;
    }
    QPen pen;
    pen.setWidth(3);
    painter.setPen(pen);

    QPoint prePainterPos(widgetWidth / 2, lineLength + 100);
    QPoint nowPainterPos(widgetWidth / 2, lineLength + 100 - radius);

    if(currentPoint / 2 >= 1){
        painter.fillRect(0, prePainterPos.y() - radius * 2, widgetWidth, 2 * radius + (radius + stdLine / 2) * sqrt2, colorList[getLayer(currentPoint / 2) % 3]);
        painter.drawEllipse(prePainterPos, radius, radius);
        paintText(prePainterPos, currentPoint / 2, painter);

        if(currentPoint % 2 == 0){
            prePainterPos.setX(prePainterPos.x() - radius * sqrt2);
            nowPainterPos.setX(prePainterPos.x() - stdLine * sqrt2);
        }
        else{
            prePainterPos.setX(prePainterPos.x() + radius * sqrt2);
            nowPainterPos.setX(prePainterPos.x() + stdLine * sqrt2);
        }
        prePainterPos.setY(prePainterPos.y() + radius * sqrt2);
        nowPainterPos.setY(prePainterPos.y() + stdLine * sqrt2);
        painter.drawLine(prePainterPos, nowPainterPos);
    }

    if(currentPoint / 2 < 1){
        nowPainterPos.setY(prePainterPos.y() + radius + stdLine);
    }
    else{
        nowPainterPos.setY(nowPainterPos.y() + radius * sqrt2);
        if(currentPoint % 2 == 0)
            nowPainterPos.setX(nowPainterPos.x() - sqrt2 * radius);
        else
            nowPainterPos.setX(nowPainterPos.x() + sqrt2 * radius);
    }
    fillWidth = widgetWidth;
    if(contrast || swap || judge)
        fillWidth = 1.0 * nums[currentPoint] / 1000 * widgetWidth;
    if(swap)
        painter.fillRect(0, nowPainterPos.y() - (radius + stdLine / 2) * sqrt2, fillWidth, (2 * radius + stdLine) * sqrt2, colorList[(getLayer(currentPoint) + 1) % 3]);
    else
        painter.fillRect(0, nowPainterPos.y() - (radius + stdLine / 2) * sqrt2, fillWidth, (2 * radius + stdLine) * sqrt2, colorList[getLayer(currentPoint) % 3]);
    paintCircle(nowPainterPos, painter, pen, true, inDown, true);
    paintArrow(nowPainterPos, painter, pen, (judge || swap), true);
    paintText(nowPainterPos, currentPoint, painter);

    if(currentPoint * 2 <= size){
        prePainterPos.setX(nowPainterPos.x() - 1.0 * radius * sqrt2);
        prePainterPos.setY(nowPainterPos.y() + 1.0 * radius * sqrt2);
        nowPainterPos.setX(prePainterPos.x() - stdLine * sqrt2);
        nowPainterPos.setY(prePainterPos.y() + stdLine * sqrt2);
        painter.drawLine(prePainterPos, nowPainterPos);
        nowPainterPos.setX(nowPainterPos.x() - sqrt2 * radius);
        nowPainterPos.setY(nowPainterPos.y() + sqrt2 * radius);
        fillWidth = widgetWidth;
        if((contrast || swap || judge)){
            fillWidth = 1.0 * nums[currentPoint * 2] / 1000 * widgetWidth;
            if (!tow){
                if(swap)
                    painter.fillRect(0, nowPainterPos.y() - (radius + stdLine / 2) * sqrt2, fillWidth, (2 * radius + stdLine) * sqrt2, colorList[(getLayer(currentPoint * 2) - 1) % 3]);
                else
                    painter.fillRect(0, nowPainterPos.y() - (radius + stdLine / 2) * sqrt2, fillWidth, (2 * radius + stdLine) * sqrt2, colorList[getLayer(currentPoint * 2) % 3]);

            }
        }
        else
            painter.fillRect(0, nowPainterPos.y() - (radius + stdLine / 2) * sqrt2, fillWidth, (2 * radius + stdLine) * sqrt2, colorList[getLayer(currentPoint * 2) % 3]);
        paintCircle(nowPainterPos, painter, pen, !tow, swap && gotV && !vSide, false);
        paintArrow(nowPainterPos, painter, pen, gotV && !vSide, false);
        paintText(nowPainterPos, currentPoint * 2, painter);
    }
    if(currentPoint * 2 + 1 <= size){
        prePainterPos.setX(prePainterPos.x() + 2.0 * radius * sqrt2);
        nowPainterPos.setX(prePainterPos.x() + stdLine * sqrt2);
        nowPainterPos.setY(prePainterPos.y() + stdLine * sqrt2);
        painter.drawLine(prePainterPos, nowPainterPos);
        nowPainterPos.setX(nowPainterPos.x() + sqrt2 * radius);
        nowPainterPos.setY(nowPainterPos.y() + sqrt2 * radius);
        fillWidth = widgetWidth;
        if ((contrast || swap || judge)){
            fillWidth = 1.0 * nums[currentPoint * 2 + 1] / 1000 * widgetWidth;
            if (tow){
                if(swap)
                    painter.fillRect(0, nowPainterPos.y() - (radius + stdLine / 2) * sqrt2, fillWidth, (2 * radius + stdLine) * sqrt2, colorList[(getLayer(currentPoint * 2) - 1)% 3]);
                else
                    painter.fillRect(0, nowPainterPos.y() - (radius + stdLine / 2) * sqrt2, fillWidth, (2 * radius + stdLine) * sqrt2, colorList[getLayer(currentPoint * 2) % 3]);
            }
        }
        paintCircle(nowPainterPos, painter, pen, tow, swap && gotV && vSide, false);
        paintArrow(nowPainterPos, painter, pen, gotV && vSide, false);
        textRect = {nowPainterPos.x() - radius, nowPainterPos.y() - radius, radius * 2, radius * 2};
        painter.drawText(textRect, Qt::AlignCenter,  "(" + QString::number(currentPoint * 2 + 1) + ") " + QString::number(nums[currentPoint * 2 + 1]) + "");
    }
}

void VisualTree::getInfo(int currentPoint, QVector<int> nums, int size, bool contrast, bool swap, bool tow,\
                         bool gotV, bool vSide, bool judge, bool inDown, QString info){
    gotInfo = true;
    this->currentPoint = currentPoint;
    this->nums = nums;
    this->size = size;
    this->swap = swap;
    this->tow = tow;
    this->gotV = gotV;
    this->vSide = vSide;
    this->contrast = contrast;
    this->judge = judge;
    this->inDown = inDown;
    someInfo = info;
    this->update();
}
