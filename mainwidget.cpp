#include "mainwidget.h"


MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    heapSort = new HeapSort();
    mainLayout = new QVBoxLayout(this);
    animationLayout = new QHBoxLayout();
    mainLayout->addLayout(animationLayout, 1);
    visualTreeArea = new QScrollArea();
    animationLayout->addWidget(visualTreeArea);

    codeLayout = new QVBoxLayout();
    animationLayout->addLayout(codeLayout);

    visualTree = new VisualTree();
    visualTreeArea->setWidget(visualTree);
    visualTree->resize(visualTreeArea->size());

    initCodeLayout();
    initController();
    initTimer();

    connect(heapSort, &HeapSort::paintInfo, visualTree, &VisualTree::getInfo);
    connect(stepByStepButton,  &QPushButton::clicked, heapSort, &HeapSort::stepedSort);
    connect(heapSort, &HeapSort::codesId, codeWidget, &CodeWIdget::acceptId);

    QFont font("", 14);
    this->setFont(font);

}

MainWidget::~MainWidget() {}

void MainWidget::resizeEvent(QResizeEvent *event)
{
    visualTree->resize(visualTreeArea->size());
    QWidget::resizeEvent(event);
}

void MainWidget::initCodeLayout()
{
    dataWidget = new QWidget();
    visualData = new QVBoxLayout();
    dataWidget->setLayout(visualData);
    codeLayout->addWidget(dataWidget);

    codeWidget = new CodeWIdget();

    codeLayout->addWidget(codeWidget);

    codeLayout->setAlignment(Qt::AlignTop | Qt::AlignCenter);

    dataNum = new QLabel("数据量: ");
    layersNum = new QLabel("堆高度: ");
    timeConsumed = new QLabel("消耗时间: ");
    compareTimes = new QLabel("比较次数: ");
    swapTimes = new QLabel("交换次数: ");

    visualData->addWidget(dataNum);

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

    QVBoxLayout *sliderLayout = new QVBoxLayout();
    timeSlider = new QSlider(Qt::Vertical);
    timeSlider->setMaximumHeight(100);
    QLabel* sliderLabel = new QLabel("动画速度");
    sliderLayout->addWidget(timeSlider, 0, Qt::AlignHCenter);
    sliderLayout->addWidget(sliderLabel, 0, Qt::AlignHCenter);

    inputDataButton = new QPushButton("导入数据");
    generateDataButton = new QPushButton("生成数据");
    startSortButton = new QPushButton("自动播放");
    stopAnimeButton = new QPushButton("停止动画");
    stepByStepButton = new QPushButton("逐步执行");
    resetButton = new QPushButton("重置");

    startSortButton->setDisabled(true);
    stepByStepButton->setDisabled(true);

    QSize hugeButtonSize = QSize(100, 95), smallButtonSize = QSize(100, 45);

    inputDataButton->resize(hugeButtonSize);
    generateDataButton->resize(hugeButtonSize);
    startSortButton->resize(hugeButtonSize);
    stopAnimeButton->resize(hugeButtonSize);
    stepByStepButton->resize(smallButtonSize);
    resetButton->resize(smallButtonSize);

    controllerLayout->setAlignment(Qt::AlignLeft);

    inputDataButton->setMinimumSize(hugeButtonSize);
    generateDataButton->setMinimumSize(hugeButtonSize);
    startSortButton->setMinimumSize(hugeButtonSize);
    stopAnimeButton->setMinimumSize(hugeButtonSize);
    stepByStepButton->setMinimumSize(smallButtonSize);
    resetButton->setMinimumSize(smallButtonSize);

    controllerLayout->addWidget(inputDataButton);
    controllerLayout->addWidget(generateDataButton);
    controllerLayout->addWidget(startSortButton);
    controllerLayout->addWidget(stopAnimeButton);
    fButtonLayout = new QVBoxLayout();
    controllerLayout->addLayout(fButtonLayout);
    fButtonLayout->addWidget(stepByStepButton);
    fButtonLayout->addWidget(resetButton);
    controllerLayout->addLayout(sliderLayout);

    connect(resetButton, &QPushButton::clicked, this, [=]{
        emit resetTree();
    });
    connect(this, &MainWidget::resetTree, heapSort, &HeapSort::reset);
    connect(generateDataButton, &QPushButton::clicked, this, &MainWidget::generateData);
    connect(inputDataButton, &QPushButton::clicked, this, &MainWidget::inputData);
}

void MainWidget::initTimer()
{
    timer = new QTimer();
    timer->setInterval(500);
    timer->stop();
    timeSlider->setRange(0, 100);
    timeSlider->setValue(50);
    timeSlider->setSingleStep(1);
    connect(timeSlider, &QSlider::valueChanged, this, [=]{
        timer->setInterval(1000 *  (1.0 * timeSlider->value() / 100) + 100);
    });
    connect(startSortButton, &QPushButton::clicked, this, [=]{
        timer->start();
    });
    connect(stepByStepButton, &QPushButton::clicked, this, [=]{
        timer->stop();
    });
    connect(stopAnimeButton, &QPushButton::clicked, this, [=]{
        timer->stop();
    });
    connect(timer, &QTimer::timeout, heapSort, &HeapSort::stepedSort);
}

int MainWidget::generateRandom(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000);
    return dis(gen);
}

void MainWidget::generateData()
{
    QDialog* generateDataWindow = new QDialog(this);
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
    if(!dataProvided)
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
            startSortButton->setDisabled(false);
            stepByStepButton->setDisabled(false);
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

void MainWidget::inputData()
{

}


