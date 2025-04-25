#include "visualtree.h"
#include "qpainter.h"

VisualTree::VisualTree(QWidget *parent)
    : QWidget{parent}
{
    this->setStyleSheet("background-color: black;");


}

void VisualTree::paintEvent(QPaintEvent *event)
{

}
