#include "ft2232hreadworker.h"

Ft2232HReadWorker::Ft2232HReadWorker(FT_HANDLE ftHandle, QObject *parent)
    :QObject (parent)
{
    m_ftHandle = ftHandle;
    m_isWorking = true;//probeFt2232H();   // probe ft2232h function
    m_needRead = true;      // read forever

}

Ft2232HReadWorker::~Ft2232HReadWorker()
{

}

void Ft2232HReadWorker::readLoop()
{
    while (m_isWorking) {
        if(m_needRead){
            readFifo();
        }
    }
}

void Ft2232HReadWorker::readFifo()
{

    FT_STATUS       ftStatus = FT_OK;
    DWORD       bytesReaded = 0;
    ftStatus = FT_Read(m_ftHandle, m_rdBuf, 1020, &bytesReaded);
    if (ftStatus != FT_OK)
    {
            printf("FT_Read failed (error %d).\n", (int)ftStatus);
//            goto exit;
            (void)FT_Close(m_ftHandle);
    }
//    printf("read: %d data.\n", bytesReaded);
//    for(int i=512;i<512+16/*bytesReaded*/;i++){
//            printf("%4x", m_rdBuf[i]);
//            if(i != 0 && i% 16 == 0)printf("\n");
//    }
    QByteArray array((const char *)m_rdBuf, (int)bytesReaded);
    emit dataReady(array);
//    return;


}

void Ft2232HReadWorker::initWorker()
{
    readLoop();
}
