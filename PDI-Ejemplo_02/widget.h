#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
// #include <wiringPi.h> // Solo para el RaspberryPi

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void update ();


private:
    Ui::Widget *ui;

};

#endif // WIDGET_H
