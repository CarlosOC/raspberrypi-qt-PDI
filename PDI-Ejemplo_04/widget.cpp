#include "widget.h"
#include "ui_widget.h"
#include "QDebug"

long int area=0;
long int cnt=0;
int i;


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    int sizeX = 320;
    int sizeY = 240;

    //Saca una Foto con la Camara
    //system("sudo raspistill -hf -vf -w 320 -h 240 -o test5.bmp -e bmp");

    //Leer un archivo Imagen
    //QImage imagen = QImage("//home//pi//PruebaPDI-build-embedded-Qt_4_8_2_in_PATH__System__Release//test5","bmp");
    QImage imagen_Original = QImage("C:\\Users\\Carlos OC\\Documents\\Investigacion Pedroni\\Horizonte01","bmp");
    QImage imagen_Modificado = imagen_Original;

    //Mostrar Prop. de la imagen
    qDebug()<<imagen_Original;


    //Devuelve el color del Pix (x,y)formato index (8bits)
    int px=imagen_Original.pixelIndex(1,1);

    //Muestra el Valor del pixel (color)
    qDebug()<<px;

    qDebug ()<< " Empieza en: ";

    for(int x=0;x<imagen_Original.width(); x++)
        {
            for(int y=0;y<imagen_Original.height();y++)
            {
               area++;
             int px2=imagen_Original.pixelIndex(x,y);
             if (px2 > 0)
                    {
                    //px2 = color negro
                     px2=255;
                     //Cambiar el color a un pixel en la posicion (x,y) y el color (px2)
                     imagen_Modificado.setPixel(x,y,px2);
                     cnt++;
                    }
            }
        }


    qDebug ()<< " Termino!";

    qDebug ()<< " .... Ahora ....";
    qDebug ()<< " Pixeles Negros: ";
    qDebug ()<< cnt;
    qDebug ()<< "Area Total";
    qDebug ()<< area;
    qDebug ()<< "Pixeles Restantes";
    qDebug ()<< area - cnt;

    QGraphicsScene *graphic_Original = new QGraphicsScene (this);
    graphic_Original->addPixmap( QPixmap ::fromImage(imagen_Original));
    QGraphicsScene *graphic_Modificado = new QGraphicsScene (this);
    //graphic_Modificado->addPixmap( QPixmap ::fromImage(imagen_Modificado));
    graphic_Modificado->addPixmap( QPixmap ::fromImage(imagen_Modificado));

    ui->graphics_Original->setScene(graphic_Original);
    ui->graphics_Modificado->setScene(graphic_Modificado);

}

Widget::~Widget()
{

    delete ui;

}
