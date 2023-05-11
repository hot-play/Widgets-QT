#include "win.h"
#include <QHBoxLayout>

Win::Win(QWidget *parent):QWidget(parent)
{
    this->setWindowTitle("Счетчик"); // Проставим название окна
    label1 = new QLabel("Cчет по 1", this); // Создадим ярлык для поля счетчика 1 клика
    label2 = new QLabel("Cчет по 5", this); // Создадим ярлык для поля счетчика 5 кликов
    edit1 = new Counter("0", this); // Создадим поле счетчика 1 клика
    edit2 = new Counter("0", this); // Создадим поле счетчика 5 кликов
    calcbutton=new QPushButton("+1", this); // Создадим кнопку +1 для счетчика
    exitbutton=new QPushButton("Выход", this); // Создадим кнопку выхода
    // Добавим элементы интерфейса в соответствующие поле окна
    QHBoxLayout *layout1 = new QHBoxLayout();
    layout1->addWidget(label1);
    layout1->addWidget(label2);
    QHBoxLayout *layout2 = new QHBoxLayout();
    layout2->addWidget(edit1);
    layout2->addWidget(edit2);
    QHBoxLayout *layout3 = new QHBoxLayout();
    layout3->addWidget(calcbutton);
    layout3->addWidget(exitbutton);
    QVBoxLayout *layout4 = new QVBoxLayout(this);
    layout4->addLayout(layout1);
    layout4->addLayout(layout2);
    layout4->addLayout(layout3);
    // Связь сигнала нажатия кнопки и слота закрытия окна
    connect(calcbutton, SIGNAL(clicked(bool)), edit1, SLOT(add_one()));
    connect(edit1, SIGNAL(tick_signal()), edit2, SLOT(add_one()));
    connect(exitbutton, SIGNAL(clicked(bool)), this, SLOT(close()));
}
