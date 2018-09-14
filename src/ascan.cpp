#include "ascan.h"
#include <QBrush>
#include <QColor>
#include <QPen>

Ascan::Ascan(QQuickItem *parent)
    :QQuickPaintedItem (parent)
{
    w = 512;
    h = 400;
    m_rectificationType = 2; // default to plus rectification
}

Ascan::~Ascan()
{

}

void Ascan::paint(QPainter *painter)
{
    // paint background
    painter->fillRect(QRectF(0,0,w,h), QBrush(QColor(Qt::black)));

    // paint grid
    QPen pen;
    pen.setWidth(1);
    pen.setColor(QColor(Qt::gray));
    painter->setPen(pen);
    int x=0,y=0;
    while(y < h){
        while (x < w) {
            painter->drawPoint(x, y);
            x += 10;
        }
        x = 0;
        y += 40;
    }
    x = 0; y = 0;
    while(y < h){
        while (x < w + 1) {
            painter->drawPoint(x, y);
            x += 50;
        }
        x = 0;
        y += 10;
    }
    //painter->save();

    // paint A scan
    painter->setPen(QPen(QColor(Qt::green)));
//    geneFakeData();
    painter->drawPolyline(m_points, w);

    // calculate and display fps
    static int frame_cnt=0;
    static int fps = 0;
    frame_cnt ++;
    static int time = 0;
    time += t.elapsed();
    if(time > 1000){
        fps = frame_cnt * 1000 / time;
        time = 0;
        frame_cnt = 0;
    }
    static int f_max=1, f_min=1000;
    if(fps > 0){     // filter invalid data
        if(fps > f_max) f_max = fps;
        if(fps < f_min) f_min = fps;
    }

    painter->drawText(20,20,QString("FPS: ")+QString::number(fps)+QString(" max: ")+QString::number(f_max)+QString(" min: ")+QString::number(f_min));
    t.restart();
    // end fps
}

void Ascan::recvData(QByteArray data)
{
//    qDebug()<<__func__<<data.mid(512, 16);
//    m_localData = data;
    combinePoints(data);
}

void Ascan::setrectificationType(int val)
{
    if(m_rectificationType != val){
        m_rectificationType = val;
    }
}

#include <math.h>
#define PI 3.141592
void Ascan::geneFakeData()
{
    int k = (rand()/RAND_MAX)*70+70;
    for(int i=1;i<=512;i++){

        m_points[i].setX(i);
        m_points[i].setY(k*sin(8*PI*((double)i/512))+180);
    }
}

void Ascan::combinePoints(QByteArray data)
{
    // ATTENTION: 400 is the window height[top left is the origin]
    if(m_rectificationType > 0) // 1 2 3
    {
        for(int i = 0; i< 512; i++){
            m_points[i].setX(i);
            if((unsigned char)data.at(i) > 200){  // shape the peak and
                m_points[i].setY(0);
            }
            else {
                unsigned int tmp = (unsigned char)data.at(i);
                tmp <<= 1;
                m_points[i].setY(399 - tmp);  // scale 2
            }
        }
    }
    else{ //radio rectification
        for(int i = 0; i< 512; i++){
            m_points[i].setX(i);
            if((unsigned char)data.at(i) <= 28){  // shape the peak and
                m_points[i].setY(399);
            }
            else if((unsigned char)data.at(i) > 228){  // shape the peak and
                m_points[i].setY(0);
            }
            else {
                unsigned int tmp = (unsigned char)data.at(i) - 28;
                tmp <<= 1;
                m_points[i].setY(399 - tmp);  // scale 2
            }
        }
    }
//    for(int i = 0; i< 512; i++){
//        m_points[i].setX(i);
//        m_points[i].setY(399 - (unsigned char)data.at(i));
//        // 400 is the window height[top left is the origin]
//    }
    update();
}
