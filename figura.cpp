#include "figura.h"

void Figura::move(float Alpha, QPainter *Painter)
{
    // Движение будет создавать по средствам перересовки линий фигур
    dx = halflen * cos(Alpha);
    dy = halflen * sin(Alpha);
    draw(Painter);
}

void MyLine::draw(QPainter * Painter)
{
    // За счет drawLine и координат будем рисовать линии
    Painter->drawLine(x+dx, y+dy, x-dx, y-dy);
}

void MyRect::draw(QPainter *Painter)
{
    // За счет drawLine и координат будем рисовать линии
    Painter->drawLine(x+dx, y+dy, x+dy, y-dx);
    Painter->drawLine(x+dy, y-dx, x-dx, y-dy);
    Painter->drawLine(x-dx, y-dy, x-dy, y+dx);
    Painter->drawLine(x-dy, y+dx, x+dx, y+dy);
}

