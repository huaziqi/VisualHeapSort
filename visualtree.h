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
    int size;
    int currentPoint = 1;
    bool gotInfo = false;
    void drawNum();
    int getLayer(int point);
protected:
    void paintEvent(QPaintEvent *event);
public slots:
    void getInfo(int currentPoint, QVector<int> nums, int size);

signals:
};

#endif // VISUALTREE_H
