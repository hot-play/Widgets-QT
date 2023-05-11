#include "area.h"

Area::Area(QWidget *parent):QWidget(parent)
{
    setFixedSize(QSize(300, 200)); // Зададим размеры окна
    myline = new MyLine(80, 100, 50); // Создадим линию
    myrect = new MyRect(220, 100, 50); // Создадим квадрат
    alpha = 0; // Угол наклона изначально будет нулевой
}

void Area::showEvent(QShowEvent *)
{
    myTimer = startTimer(50); // Создать таймер
}

void Area::paintEvent(QPaintEvent *)
{
    // Создадим художника и отрисуем фигуры заново, но под углом alpha
    QPainter painter(this);
    painter.setPen(Qt::blue); // Цвет кисти
    myline->move(alpha, &painter);
    painter.setPen(Qt::green); // Цвет кисти
    myrect->move(alpha * (-0.5), &painter);
}

void Area::timerEvent(QTimerEvent * event)
{
    if (event->timerId() == myTimer) { // Пока таймер существует увеличиваем угол поворота
        alpha = alpha + 0.2;
        update(); // Обновить внешний вид
    } else {
     QWidget::timerEvent(event); // иначе передать для стандартной обработки
    }
}

void Area::hideEvent(QHideEvent *)
{
    killTimer(myTimer); // уничтожить таймер
}

Area::~Area()
{
    delete myline;
    delete myrect;
}

