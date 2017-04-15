#include <QCoreApplication>
#include "QDebug"
#include "QTimer"
#include "pdi-ejemplo_06.h"

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
    timer->start(10000);  //300000ms = 5 minutos

    return a.exec();
}
