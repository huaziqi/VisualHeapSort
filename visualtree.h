#ifndef VISUALTREE_H
#define VISUALTREE_H

#include "common.h"

class VisualTree : public QWidget
{
    Q_OBJECT
public:
    explicit VisualTree(QWidget *parent = nullptr);
private:
    QVector<int> nums;
    QVector<QColor> colorList;
    QRect textRect;
    QString someInfo;
    int size, currentPoint = 1;
    int radius, scale;
    bool gotInfo = false;
    bool swap, contrast, tow, gotV, vSide, judge, inDown;
    double widgetWidth;

    void drawNum();
    int getLayer(int point);
    void paintText(QPoint point, int current, QPainter& painter);
    void paintCircle(QPoint point, QPainter& painter, QPen& pen, bool t, bool spec, bool isMain);
    void paintArrow(QPoint point, QPainter& painter, QPen& pen, bool t, bool p);
protected:
    void paintEvent(QPaintEvent *event);
public slots:
    void getInfo(int currentPoint, QVector<int> nums, int size, bool contrast, bool swap, bool tow, bool gotV, bool vSide, bool judge, bool inDown, QString info);

signals:
};

#endif // VISUALTREE_H
