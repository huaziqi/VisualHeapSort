#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "common.h"
#include "visualTree.h"
#include "codewidget.h"
#include "heapsort.h"

class MainWidget : public QWidget
{
    Q_OBJECT

private:
    QVBoxLayout *mainLayout, *codeLayout, *visualCode, *visualData, *fButtonLayout;
    QHBoxLayout *animationLayout, *controllerLayout;

    QScrollArea *visualTreeArea;
    VisualTree *visualTree; //可视化树

    QWidget *controllerWidget; //控制窗口
    QWidget *dataWidget; //输出数据窗口
    CodeWIdget *codeWidget;//代码窗口
    HeapSort *heapSort;

    QLabel *dataNum, *timeConsumed, *compareTimes, *swapTimes, *layersNum;
    QPushButton *startSortButton, *stepByStepButton, *stopAnimeButton, *resetButton, *inputDataButton;
    QPushButton *generateDataButton;

    QMessageBox msgBox;
    int rec, maxn;
    QTimer* timer;
    QSlider *timeSlider;

    bool dataProvided = false;
public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
protected:
    virtual void resizeEvent(QResizeEvent *event) override;
private:
    void initCodeLayout();
    void initController();
    void initTimer();
    int generateRandom();

private slots:
    void generateData();
    void inputData();
signals:
    void resetTree();
    void sendNums(const int &size, const QVector<int> &nums, int maxn);

};
#endif // MAINWIDGET_H
