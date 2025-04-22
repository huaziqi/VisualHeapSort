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
    visualTree->resize(500, 300);
    visualTreeArea->setWidget(visualTree);

    initCodeLayout();
    initController();

}

MainWidget::~MainWidget() {}

void MainWidget::resizeEvent(QResizeEvent *event)
{

}

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

}

void MainWidget::initController()
{
    controllerWidget = new QWidget();
    mainLayout->addWidget(controllerWidget);
    controllerLayout = new QHBoxLayout();
    controllerWidget->setLayout(controllerLayout);
    controllerWidget->setMinimumHeight(80);
    controllerLayout->setSpacing(10);

    generateDataButton = new QPushButton("生成数据");
    startSortButton = new QPushButton("开始排序");
    stopAnimeButton = new QPushButton("停止动画");
    stepByStepButton = new QPushButton("逐步排序");
    resetButton = new QPushButton("重置");

    QSize hugeButtonSize = QSize(100, 65), smallButtonSize = QSize(100, 30);


    generateDataButton->resize(hugeButtonSize);
    startSortButton->resize(hugeButtonSize);
    stopAnimeButton->resize(hugeButtonSize);
    stepByStepButton->resize(smallButtonSize);
    resetButton->resize(smallButtonSize);

    controllerLayout->setAlignment(Qt::AlignLeft);

    generateDataButton->setMinimumSize(hugeButtonSize);
    startSortButton->setMinimumSize(hugeButtonSize);
    stopAnimeButton->setMinimumSize(hugeButtonSize);
    stepByStepButton->setMinimumSize(smallButtonSize);
    resetButton->setMinimumSize(smallButtonSize);

    controllerLayout->addWidget(generateDataButton);
    controllerLayout->addWidget(startSortButton);
    controllerLayout->addWidget(stopAnimeButton);
    fButtonLayout = new QVBoxLayout();
    controllerLayout->addLayout(fButtonLayout);


    fButtonLayout->addWidget(stepByStepButton);
    fButtonLayout->addWidget(resetButton);
}


