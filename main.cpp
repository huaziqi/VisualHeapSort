#include "mainwidget.h"

#include <QApplication>
#include <QFile>

void loadStyle(){
    QFile qss(":/qss/style.qss");
    if(qss.open(QFile::ReadOnly)){
        qApp->setStyleSheet(qss.readAll());
        qss.close();
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    loadStyle();
    MainWidget w;
    w.show();
    return a.exec();
}
