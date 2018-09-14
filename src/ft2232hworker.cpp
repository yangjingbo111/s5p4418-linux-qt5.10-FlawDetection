#include "ft2232hworker.h"

UCHAR       DEFAULT_CONTROL_DATA[512]={
    0X01,
    0X00,
    0X00,
    0X00,
    0X00,
    0X01,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X40,
    0X42,
    0X0F,
    0X00,
    0X07,
    0X01,
    0X0A,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X49,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X09,
    0X00,
    0X00,
    0X00,
    0X00,
    0X10,
    0X00,
    0X00,
    0X02,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0XA0,
    0X00,
    0X00,
    0X00,
    0X00,
    0X32,
    0X00,
    0X00,
    0X00,
    0X02,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0XA0,
    0X00,
    0X00,
    0X00,
    0X00,
    0X32,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,
    0X00,

};

// gain table
int m_pVal[] = {
        400 ,
        54  ,
        103 ,
        157 ,
        211 ,
        265 ,
        325 ,
        372 ,
        432 ,
        485 ,
        535 ,
        589 ,
        648 ,
        702 ,
        751 ,
        804 ,
        854 ,
        907 ,
        961 ,
        1021,
        1069,
        1121,
        1173,
        1226,
        1274,
        1328,
        1382,
        1436,
        1490,
        1544,
        1600,
        1661,
        1713,
        1766,
        1823,
        1876,
        1937,
        1992,
        2043,
        2101,
        2157,
        2213,
        2269,
        2327,
        2381,
        2435,
        2495,
        2550,
        2604,
        2656,
        2709,
        2762,
        2813,
        2874,
        2929,
        2981,
        3033,
        3085,
        3142,
        3192,
        3250,
        3299,
        3353,
        3402,
        3456,
        3515,
        3564,
        3618,
        3672,
        3726,
        3780,
        3834,
        3888,
        3942,
        3996,
        4050};


#include <QThread>
#include <QDebug>
Ft2232HWorker::Ft2232HWorker(FT_HANDLE ftHandle, QObject *parent)
    :QObject (parent)
{
    m_ftHandle = ftHandle;
    loadDefaultWrBuf();     // load default fpga control data
//    qDebug()<<"unsigned int: "<< sizeof (unsigned int)<<"unsigned short: "<<sizeof (unsigned short)<< "ft2232hctl: "<<sizeof (Ft2232hCtl);
}

Ft2232HWorker::~Ft2232HWorker()
{
    qDebug()<<__func__;
    (void)FT_Close(m_ftHandle);
}

void Ft2232HWorker::loadDefaultWrBuf()
{
    memcpy(&m_wrData, DEFAULT_CONTROL_DATA, 512);
}


void Ft2232HWorker::writeFifo()
{
    FT_STATUS       ftStatus = FT_OK;
    DWORD       bytesWritten = 0;
    ftStatus = FT_Write(m_ftHandle, &m_wrData, 512, &bytesWritten);
    if (ftStatus != FT_OK)
    {
            printf("FT_Write failed (error %d).\n", (int)ftStatus);
            goto exit;
    }
    return;

exit:   //something is wrong, need to report
    (void)FT_Close(m_ftHandle);

}

void Ft2232HWorker::writeTCGGain()
{
    FT_STATUS       ftStatus = FT_OK;
    DWORD       bytesWritten = 0;
    USHORT tcgBuf[512]; // fow now, just simply use the local variable
    for(int i=0;i<512;i++){
        tcgBuf[i] = 54 + i*4;
    }
    ftStatus = FT_Write(m_ftHandle, tcgBuf, 1024, &bytesWritten);
    if (ftStatus != FT_OK)
    {
            printf("FT_Write failed (error %d).\n", (int)ftStatus);
            goto exit;
    }
    return;

exit:   //something is wrong, need to report
    (void)FT_Close(m_ftHandle);

}

#include <QDebug>
void Ft2232HWorker::testFun(int num)
{
//    m_wrData.ALARM_CTRL_REG = (UCHAR)num;
//    m_needWrite = true;
//    writeFifo();

    QString program = "/usr/bin/gpio_test";
    QStringList arg1,arg2;
    arg1 << "-s output -iGPIOB29 -v 1";
    arg1 << "-s output -iGPIOB29 -v 0";
    QProcess myProcess;
    myProcess.start(program, arg1, QIODevice::ReadWrite);
    myProcess.waitForFinished();
    myProcess.start(program, arg2, QIODevice::ReadWrite);
    myProcess.waitForFinished();
    qDebug()<<__func__<<QThread::currentThreadId();
}

void Ft2232HWorker::wrGain(int gain) // gain type needs to be float
{
    int MAX_GAIN = 1100;
    int JumpPnt1Index = 0;
    int m_iJumpPnt1 = m_pVal[JumpPnt1Index];//400;
    int m_iValNum = sizeof (m_pVal)/sizeof (int);//76;

    int iGain = (int)(gain * 10);
    int fixGain = 0;
    int iOffset = 0, iOdd;
    if (iGain < m_iJumpPnt1)
    {
        iOffset = iGain/10;
        iOdd = iGain%10;
        if (iOffset < m_iValNum)
        {
            iOdd *= ((m_pVal[iOffset+1]-m_pVal[iOffset])/10);
            iGain = m_pVal[iOffset] + iOdd;
            fixGain = 0;
        }
    }
    else if (iGain < MAX_GAIN)
    {
        iOffset = (iGain-m_iJumpPnt1)/10;
        iOdd = (iGain-m_iJumpPnt1)%10;
        if (iOffset < m_iValNum)
        {
            iOdd *= ((m_pVal[iOffset+1]-m_pVal[iOffset])/10);
            iGain = m_pVal[iOffset] + iOdd;
            fixGain = 1;
        }
    }
    else
    {
        iGain = m_pVal[m_iValNum-1];
        fixGain = 1;
    }
    m_wrData.SYS_GAIN_REG = ((unsigned short)iGain) | (m_wrData.SYS_GAIN_REG & 0x1000);
    writeFifo();
    qDebug()<<__func__<<gain<<iGain<<fixGain;
}

void Ft2232HWorker::wrRange(int val)
{
    int tmp = (float)val/2/5.96*100;
    m_wrData.SampLen_Reg = (unsigned int)tmp;
    writeFifo();
    qDebug()<<__func__<<val<<tmp;
}

void Ft2232HWorker::wrHighVol(int val)
{
    m_wrData.HV_Sel_Reg = (UCHAR)val;
    writeFifo();
    qDebug()<<__func__<<val;

}

void Ft2232HWorker::wrEmitDamp(int val)
{
    m_wrData.DAMP_SEL_REG = (UCHAR)val;
    writeFifo();
    qDebug()<<__func__<<val;
}

void Ft2232HWorker::wrFilterBand(int val)
{
    m_wrData.RX_MUX_REG = ((UCHAR)val << 2) | (m_wrData.RX_MUX_REG & 0x13);
    writeFifo();
    qDebug()<<__func__<<val;
}

void Ft2232HWorker::wrrectificationType(int val)
{
    // to be finished
    m_wrData.RX_MUX_REG = ((UCHAR)val ) | (m_wrData.RX_MUX_REG & 0x1c) ;
    writeFifo();
    qDebug()<<__func__<<val;
}

void Ft2232HWorker::wrtransducerType(int val)
{
    m_wrData.PROBE_TYPE_REG = (UCHAR)val;
    writeFifo();
}


void Ft2232HWorker::wrtcgGain(int val)
{
    // to be finished
//    m_wrData.RX_MUX_REG = ((UCHAR)val << 4) | (m_wrData.RX_MUX_REG & 0x0f) ;
//    writeFifo();
    // change gpio GPIOB[31:30] to 01
    //    gpio_test  -s output -iGPIOB30 -v 1
    QString program = "/usr/bin/gpio_test";
    QStringList arg1,arg2;
    arg1 << "-s output -iGPIOB30 -v 1";
    QProcess myProcess;
    myProcess.start(program, arg1, QIODevice::ReadWrite);

    // write 512 half word from 54 to 54+4 54+8 54+12 ...
    if(myProcess.waitForFinished(1000)){
        qDebug()<<__func__<<"gpio_test  -s output -iGPIOB30 -v 1";
        writeTCGGain();
    }

    // change gpio GPIOB[31:30] back to 00
    arg1 << "-s output -iGPIOB30 -v 0";
    myProcess.start(program, arg2, QIODevice::ReadWrite);
    if(myProcess.waitForFinished(1000)){
        qDebug()<<__func__<<"gpio_test  -s output -iGPIOB30 -v 0";
    }
    qDebug()<<__func__<<val;
}

void Ft2232HWorker::wrkeyBoardBacklight(int val)
{
    m_wrData.KEY_LED_REG = (UCHAR)val;
    writeFifo();
}

void Ft2232HWorker::wrvga(int val)
{
    m_wrData.VGA_PWR_EN = (UCHAR)val;
    writeFifo();
}




