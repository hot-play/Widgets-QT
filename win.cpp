#include "win.h"
#include <QVBoxLayout>
#include <QMessageBox>

Win::Win(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Возведение в квадрат"); // Поставим название виджета
    frame = new QFrame(this); // Создадим фрейм и пропишем ему свойства
    frame->setFrameShadow(QFrame::Raised);
    frame->setFrameShape(QFrame::Panel);

    inputLabel = new QLabel("Введите число:", this); // Создадим ярлык поля ввода числа
    inputEdit = new QLineEdit("",this); // Создадим поле ввода числа

    StrValidator *v=new StrValidator(inputEdit); // Для поля создадим валидатор
    inputEdit->setValidator(v);

    outputLabel = new QLabel("Результат:", this); // Создадим ярлык результата
    outputEdit = new QLineEdit("",this); // Создадим поле результата
    nextButton = new QPushButton("Следующее", this); // Создадим кнопку "Следующее"
    exitButton = new QPushButton("Выход", this); // Создадим кнопку "Выход"

    // Добавим все созданные компоненты, в соответствующие поля виджета
    QVBoxLayout *vLayout1 = new QVBoxLayout(frame);
    vLayout1->addWidget(inputLabel);
    vLayout1->addWidget(inputEdit);
    vLayout1->addWidget(outputLabel);
    vLayout1->addWidget(outputEdit);
    vLayout1->addStretch();
    QVBoxLayout *vLayout2 = new QVBoxLayout();
    vLayout2->addWidget(nextButton);
    vLayout2->addWidget(exitButton);
    vLayout2->addStretch();
    QHBoxLayout *hLayout = new QHBoxLayout(this);
    hLayout->addWidget(frame);
    hLayout->addLayout(vLayout2);
    begin(); // Выставим значения по умолачнию
    // Подключим сигналы для кнопок
    connect(exitButton, SIGNAL(clicked(bool)), this,SLOT(close()));
    connect(nextButton, SIGNAL(clicked(bool)), this,SLOT(begin()));
    connect(inputEdit, SIGNAL(returnPressed()), this,SLOT(calc()));
}
void Win::begin()
{
    // Выставим значения по умолчанию
    inputEdit->clear();
    nextButton->setEnabled(false);
    nextButton->setDefault(false);
    inputEdit->setEnabled(true);
    outputLabel->setVisible(false);
    outputEdit->setVisible(false);
    outputEdit->setEnabled(false);
    inputEdit->setFocus();
}

void Win::calc()
{
    bool Ok=true;
    float r,a;
    QString str=inputEdit->text();
    // Приведем к числу с плавающей запятой
    a=str.toDouble(&Ok);
    if (Ok) {
    r=a*a; // Рассчитаем квадрат числа
    str.setNum(r); // Преобразуем искомое число в строку
    // Выведем результат
    outputEdit->setText(str);
    inputEdit->setEnabled(false);
    outputLabel->setVisible(true);
    outputEdit->setVisible(true);
    nextButton->setDefault(true);
    nextButton->setEnabled(true);
    nextButton->setFocus();
    } else if (!str.isEmpty()) { // Если результат некорректный, то выведем сообщение с ошибкой
    QMessageBox msgBox(QMessageBox::Information, "Возведение в квадрат.", "Введено неверное значение.", QMessageBox::Ok);
    msgBox.exec();
    }
}

