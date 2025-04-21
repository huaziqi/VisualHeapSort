#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "common.h"
#include "visualTree.h"
#include "codewidget.h"

class MainWidget : public QWidget
{
    Q_OBJECT

private:
    QVBoxLayout *mainLayout, *codeLayout, *visualCode, *visualData;
    QHBoxLayout *animationLayout, *controllerLayout;

    QScrollArea *visualTreeArea;
    VisualTree *visualTree; //可视化树

    QWidget *controllerWidget; //控制窗口
    QWidget *dataWidget; //输出数据窗口
    CodeWIdget *codeWidget;//代码窗口

    QLabel *dataNum, *timeConsumed, *compareTimes, *swapTimes, *layersNum;
public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private:
    void initCodeLayout();
    void initController();
};
#endif // MAINWIDGET_H
