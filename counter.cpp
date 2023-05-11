#include "counter.h"

void Counter::add_one()
{
    // Обработка для 5 кликов
    QString str = text();
    int r = str.toInt();
    if (r != 0 && r % 5 ==0) {
        emit tick_signal();
    }
    r++;
    str.setNum(r);
    setText(str);
}
