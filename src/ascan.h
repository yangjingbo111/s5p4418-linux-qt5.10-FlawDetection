#ifndef ASCAN_H
#define ASCAN_H

#include <QQuickPaintedItem>
#include <QQuickItem>
#include <QPainter>
#include <QPoint>
#include <QTime>
class Ascan : public QQuickPaintedItem
{
    Q_OBJECT
public:
    explicit Ascan(QQuickItem *parent = nullptr);
    ~Ascan();
    void paint(QPainter *painter);
    Q_INVOKABLE void recvData(QByteArray data);
    Q_INVOKABLE void setrectificationType(int val);
public slots:

private:
    void geneFakeData();
    void combinePoints(QByteArray data);
private:
    int w;
    int h;
    QPoint m_points[512];
    QByteArray m_localData;
    QTime t;
    int m_rectificationType;
};

#endif // ASCAN_H
