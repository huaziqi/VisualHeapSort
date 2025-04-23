#include "mainwidget.h"


MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    heapSort = new HeapSort();
    mainLayout = new QVBoxLayout(this);
    animationLayout = new QHBoxLayout();
    mainLayout->addLayout(animationLayout);
    visualTreeArea = new QScrollArea();
    animationLayout->addWidget(visualTreeArea);

    codeLayout = new QVBoxLayout();
    animationLayout->addLayout(codeLayout);

    visualTree = new VisualTree();
    visualTree->resize(3000, 3000);
    visualTreeArea->setWidget(visualTree);

    QScrollBar *vScroll = visualTreeArea->verticalScrollBar();
    QScrollBar *hScroll = visualTreeArea->horizontalScrollBar();

    // 滚动到指定位置（x, y）
    hScroll->setValue(2000);  // 水平滚动到 x
    vScroll->setValue(2000);  // 垂直滚动到 y
    initCodeLayout();
    initController();

}

MainWidget::~MainWidget() {}

void MainWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
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
    stepByStepButton = new QPushButton("逐步执行");
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

    connect(generateDataButton, &QPushButton::clicked, this, &MainWidget::generateData);
}

int MainWidget::generateRandom()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100000);
    return dis(gen);
}

void MainWidget::generateData()
{
    QDialog* generateDataWindow = new QDialog();
    generateDataWindow->setFixedSize(300, 100);
    generateDataWindow->setModal(true);
    generateDataWindow->show();
    generateDataWindow->setStyleSheet("background-color: white;");

    QVBoxLayout* mainLayout = new QVBoxLayout();
    QHBoxLayout* inputLayout = new QHBoxLayout();

    QLabel *inputInfo = new QLabel("输入生成数据的规模：");

    QLineEdit* inputNums = new QLineEdit();
    QPushButton *confirmBtn = new QPushButton("确认");
    QLabel* finishLabel = new QLabel();
    QPushButton *openFile = new QPushButton("查看数据");
    openFile->setDisabled(true);
    finishLabel->setAlignment(Qt::AlignCenter);

    inputLayout->addWidget(inputInfo);
    inputLayout->addWidget(inputNums);
    inputLayout->addWidget(confirmBtn);

    generateDataWindow->setLayout(mainLayout);
    mainLayout->addLayout(inputLayout);
    mainLayout->addWidget(finishLabel);
    mainLayout->addWidget(openFile);

    mainLayout->setAlignment(Qt::AlignTop);

    connect(this, &MainWidget::sendNums, heapSort, &HeapSort::acceptData);

    connect(confirmBtn, &QPushButton::clicked, this, [=]{
        int length = inputNums->text().toInt();
        QVector<int> nums;
        nums.append(-1);
        QFile file("data.txt");
        if(file.open(QIODevice::WriteOnly)){
            QTextStream out(&file);
            for(int i = 1; i <= length; i ++){
                nums.append(generateRandom());
                out << nums[i] << " ";
            }
            emit sendNums(length, nums);
            finishLabel->setText("数据生成完成");
            dataProvided = true;
            openFile->setDisabled(false);
            file.close();
        }
        else{
            qDebug() << "文件打开失败";
        }
    });

    connect(openFile, &QPushButton::clicked, this, [=]{
        QUrl url = QUrl::fromLocalFile("data.txt");
        if(!QDesktopServices::openUrl(url)){
            qDebug() << "打开失败";
        }
    });
}


