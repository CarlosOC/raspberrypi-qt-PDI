#ifndef MAIN_H
#define MAIN_H
#include <QObject>
#include <wiringPi.h> // Solo para el RaspberryPi

class Interrup : public QObject
{
Q_OBJECT
public:
    explicit Interrup(QObject *parent = 0);

signals:
    void done();

public slots:
    void Interrupcion();

};
#endif // MAIN_H

