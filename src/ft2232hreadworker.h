#ifndef FT2232HREADWORKER_H
#define FT2232HREADWORKER_H

#include <QObject>
#include "ftd2xx.h"

class Ft2232HReadWorker : public QObject
{
    Q_OBJECT
public:
    explicit Ft2232HReadWorker(FT_HANDLE ftHandle, QObject *parent = nullptr);
    ~Ft2232HReadWorker();

    void readLoop();
    void readFifo();

signals:
    void dataReady(QByteArray data);

public slots:
    void initWorker();

private:
    FT_HANDLE       m_ftHandle;
    int             portNumber = 0;
    bool m_isWorking;   // indicate ft2232h working status, in order to control the main loop
    bool m_needRead;    // true when need to read

    UCHAR m_rdBuf[1020];
};

#endif // FT2232HREADWORKER_H
