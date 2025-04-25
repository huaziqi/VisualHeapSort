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
    double widgetWidth;

    void drawNum();
    int getLayer(int point);
    void paintText(QPoint point, int current, QPainter& painter);
protected:
    void paintEvent(QPaintEvent *event);
public slots:
    void getInfo(int currentPoint, QVector<int> nums, int size, bool contrast, bool swap, bool tow, QString info);

signals:
};

#endif // VISUALTREE_H
