#ifndef CODEWIDGET_H
#define CODEWIDGET_H

#include "common.h"

class CodeWIdget : public QWidget
{
    Q_OBJECT
public:
    explicit CodeWIdget(QWidget *parent = nullptr);

private:
    QVBoxLayout *codesLayout;
    QVector<QLabel*> codeLabels;
    QStringList codesContent;
signals:

public slots:
    void acceptId(int codesId);
};

#endif // CODEWIDGET_H
