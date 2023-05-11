#ifndef WIN_H
#define WIN_H

#include <QtGui>
#include <QLabel>
#include <QPushButton>
#include "counter.h"


class Win : public QWidget
{
    Q_OBJECT
protected:
    QLabel * label1, * label2;
    Counter * edit1, * edit2;
    QPushButton * calcbutton;
    QPushButton * exitbutton;
public:
    Win(QWidget *parent = 0);
};

#endif // WIN_H
