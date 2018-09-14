#ifndef FT2232HWORKER_H
#define FT2232HWORKER_H

#include <QObject>
#include <QProcess>
#include "ftd2xx.h"
#include "micros.h"

class Ft2232HWorker : public QObject
{
    Q_OBJECT
public:
    explicit Ft2232HWorker(FT_HANDLE ftHandle, QObject *parent = nullptr);
    ~Ft2232HWorker();

    void loadDefaultWrBuf();
    void writeFifo();
    void writeTCGGain();

public slots:
    void testFun(int num);
    void wrGain(int gain);
    void wrRange(int val);
    void wrHighVol(int val);
    void wrEmitDamp(int val);
    void wrFilterBand(int val);

    void wrrectificationType(int val);
    void wrtransducerType(int val);
    void wrtcgGain(int val);
    void wrkeyBoardBacklight(int val);
    void wrvga(int val);
private:
    FT_HANDLE       m_ftHandle;
    int         portNumber = 0;
    bool m_needWrite;   // true when need to write

    Ft2232hCtl m_wrData;
};

#endif // FT2232HWRITEWORKER_H
