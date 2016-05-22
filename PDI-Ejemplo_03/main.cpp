#include <QCoreApplication>
#include "QDebug"
#include "QTimer"
#include "Ejemplo3.h"
void update()
{

    qDebug() << "Timer...";
}


int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);

    Interrup interrup;
    QTimer *timer = new QTimer(NULL);
    QObject::connect(timer,SIGNAL(timeout()),&interrup,SLOT( Interrupcion() ));
    timer->start(100);
    return a.exec();
}
