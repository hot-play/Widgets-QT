#ifndef COUNTER_H
#define COUNTER_H

#include <QLineEdit>

class Counter : public QLineEdit
{
    Q_OBJECT
public:
    Counter(const QString & contents, QWidget *parent=0):
    QLineEdit(contents, parent) {}
signals:
    void tick_signal();
public slots:
    void add_one();
};

#endif // COUNTER_H
