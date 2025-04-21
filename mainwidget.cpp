#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    mainLayout = new QVBoxLayout(this);
    animationLayout = new QHBoxLayout();
    mainLayout->addLayout(animationLayout);
    visualTreeArea = new QScrollArea();
    animationLayout->addWidget(visualTreeArea);
    codeLayout = new QVBoxLayout();
    animationLayout->addLayout(codeLayout);
    controllerLayout = new QHBoxLayout();
    mainLayout->addLayout(controllerLayout);
    visualTree = new VisualTree();
    visualTree->resize(1000, 1000);
    visualTreeArea->setWidget(visualTree);

}

MainWidget::~MainWidget() {}
