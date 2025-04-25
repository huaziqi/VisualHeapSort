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
    int size;
    int currentPoint = 1;
    void drawNum();
protected:
    void paintEvent(QPaintEvent *event);

signals:
};

#endif // VISUALTREE_H
