#include "Ejemplo3.h"
#include "QDebug"
#include <QtGui/QImage>

Interrup::Interrup(QObject *parent) :
    QObject(parent)
{
}

void Interrup::Interrupcion()
{
    qDebug() << "Timer...";
    long int area=0;
    long int cnt=0;
    int i;
    int sizeX = 320;
    int sizeY = 240;
    //Leer un archivo Imagenupdate()
    QImage imagen_Original = QImage("C:\\Users\\Carlos OC\\Documents\\Investigacion Pedroni\\Horizonte01","bmp");
    QImage imagen_Modificado = imagen_Original;

        for(int x=0;x<sizeX; x++)
            {
                for(int y=0;y<sizeY;y++)
                {
                   area++;
                 int px2=imagen_Original.pixelIndex(x,y);
                 if (px2 == 0)
                        {
                        //px2 = color negro
                         px2=255;
                         //Cambiar el color a un pixel en la posicion (x,y) y el color (px2)
                         imagen_Modificado.setPixel(x,y,px2);
                         cnt++;
                        }
                }
            }
        qDebug ()<< " Pixeles Negros: ";
        qDebug ()<< cnt;
        qDebug ()<< "Area Total";
        qDebug ()<< area;
        qDebug ()<< "Pixeles Restantes";
        qDebug ()<< area - cnt;
}
