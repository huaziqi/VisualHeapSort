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

    visualTree = new VisualTree();
    visualTree->resize(1000, 1000);
    visualTreeArea->setWidget(visualTree);

    initCodeLayout();
    initController();

}

MainWidget::~MainWidget() {}

void MainWidget::initCodeLayout()
{
    dataWidget = new QWidget();
    visualData = new QVBoxLayout();
    dataWidget->setLayout(visualData);
    codeLayout->addWidget(dataWidget);

    codeWidget = new CodeWIdget();
    visualCode = new QVBoxLayout();
    codeWidget->setLayout(visualCode);
    codeLayout->addWidget(codeWidget);

    codeLayout->setAlignment(Qt::AlignTop | Qt::AlignCenter);

    dataNum = new QLabel("数据量: ");
    layersNum = new QLabel("堆高度: ");
    timeConsumed = new QLabel("消耗时间: ");
    compareTimes = new QLabel("比较次数: ");
    swapTimes = new QLabel("交换次数: ");

    visualData->addWidget(dataNum);
    visualData->addWidget(layersNum);
    visualData->addWidget(timeConsumed);
    visualData->addWidget(compareTimes);
    visualData->addWidget(swapTimes);

    dataWidget->setMinimumWidth(100);
    dataWidget->setMaximumWidth(200);
    dataWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);


}

void MainWidget::initController()
{
    controllerWidget = new QWidget();
    mainLayout->addWidget(controllerWidget);
    controllerLayout = new QHBoxLayout();
    controllerWidget->setLayout(controllerLayout);
    controllerWidget->setMinimumHeight(80);
}


