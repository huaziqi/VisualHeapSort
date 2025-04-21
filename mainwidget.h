#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "common.h"
#include "visualTree.h"

class MainWidget : public QWidget
{
    Q_OBJECT

private:
    QVBoxLayout *mainLayout, *codeLayout;
    QHBoxLayout *animationLayout, *controllerLayout;
    QScrollArea *visualTreeArea;
    VisualTree *visualTree;
public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
};
#endif // MAINWIDGET_H
