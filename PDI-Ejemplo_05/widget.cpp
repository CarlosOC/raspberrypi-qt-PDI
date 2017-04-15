#include "widget.h"
#include "ui_widget.h"

#include <ctime>
#include <fstream>
#include <iostream>
#include <raspicam/raspicam.h>
#include "QDebug"
#define Width 1280
#define Height 960

long int area=0;
long int cnt=0;
int i;


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    raspicam::RaspiCam Camera; //Camera object

    //Configuracion de la Camara
    Camera.setExposure(raspicam::RASPICAM_EXPOSURE_AUTO);
    Camera.setAWB(raspicam::RASPICAM_AWB_AUTO);
    //Multiple de 240: 240,480,960
    Camera.setHeight(Height);
    //Multiple de 320: 320,640,1280
    Camera.setWidth(Width);
    //Brightness: 0 a  100
    Camera.setBrightness(50);
    //Sharpness: -100 a 100
    Camera.setSharpness(0);
    //Contrast: -100 a 100
    Camera.setContrast(0);
    //Saturation:
    Camera.setSaturation(0);
    //ShutterSpeed:
    Camera.setShutterSpeed(0);
    //ISO: 100 a 800
    Camera.setISO(400);
    Camera.setVideoStabilization(true);
    //Exposure Compensation: -10 a 10
    Camera.setExposureCompensation(0);
    //Exposure:
    //Camera.setExposure();
    //AWB_RB:0 a 1 (float)
    //Camera.setAWB_RB();
    //Format:
    Camera.setFormat(raspicam::RASPICAM_FORMAT_RGB);

    qDebug()<<"Configuracion de la Camara";
    qDebug()<<"Brightness:";
    qDebug()<< Camera.getBrightness();
    qDebug()<<"Sharpness:";
    qDebug()<< Camera.getSharpness();
    qDebug()<<"Contrast:";
    qDebug()<< Camera.getContrast();
    qDebug()<< "Saturation:";
    qDebug()<< Camera.getSaturation();
    qDebug()<< "ShutterSpeed:";
    qDebug()<< Camera.getShutterSpeed();
    qDebug()<<"ISO:";
    qDebug()<< Camera.getISO();
    qDebug()<<"Exposure:";
    qDebug()<< Camera.getExposure();
    qDebug()<<"AWB:";
    qDebug()<<Camera.getAWB();
    qDebug()<<"AWBG_Blue:";
    qDebug()<<Camera.getAWBG_blue();
    qDebug()<<"AWBG_Red";
    qDebug()<<Camera.getAWBG_red();
    qDebug()<<"Format:";
    qDebug()<< Camera.getFormat();
    qDebug()<<"Imagen Effec:";
    qDebug()<< Camera.getImageEffect();
    //Open camera
    qDebug()<<"Opening Camera...";

    if ( !Camera.open()) {

                            qDebug()<<"Error Opening Camera ...";
                            //return -1;
                         }

    //allocate memory
    unsigned char *data=new unsigned char [ Camera.getImageBufferSize ()];
    qDebug()<<"Allocate Memory OK";

    qDebug()<<"Capture";
    //Numero de Frames que Captura
    for(int i=0;i<100;i++)
        {
         Camera.grab();
        //get camera image
        Camera.retrieve (data);
        }
    qDebug()<<"Get Imagen OK";


    //save File

    std::ofstream outFile ( "raspicam_image_QT.ppm",std::ios::binary);
    outFile<<"P6\n"<<Camera.getWidth() <<" "<<Camera.getHeight() <<" 255\n";
    outFile.write ( ( char* ) data, Camera.getImageBufferSize () );

    qDebug()<<"Imagen saved at raspicam_image_QT.ppm";

    //free resrources
    delete data;
    Camera.release();


}

Widget::~Widget()
{

    delete ui;




}
