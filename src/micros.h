#ifndef MICROS_H
#define MICROS_H

//#include "WinTypes.h"
typedef struct Ft2232hCtl{
    unsigned char INIT_CTRL_REG;
    unsigned char res1;                 // 0x001
    unsigned char Encoder_Ctrl_Reg;
    unsigned char Scan_Unit_Reg;
    unsigned char ALARM_CTRL_REG;
    unsigned char VGA_PWR_EN;
    unsigned char res6;                 // 0x006
    unsigned char res7;                 // 0x007
    unsigned char KEY_LED_REG;
    unsigned char res9;
    unsigned char resA;
    unsigned char resB;
    unsigned char resC;
    unsigned char resD;
    unsigned char resE;
    unsigned char resF;

    unsigned int  RepeatFre;        // 4 bytes
    unsigned char HV_Sel_Reg;
    unsigned char TX_CTRL_REG;
    unsigned char TX_WIDTH_REG;
    unsigned char res17;
    unsigned short TX_DELAY_REG;    // 2 bytes
    unsigned char PROBE_TYPE_REG;
    unsigned char DAMP_SEL_REG;
    unsigned char res1C;
    unsigned char res1D;
    unsigned char res1E;
    unsigned char res1F;

    unsigned int  SampLen_Reg;      // 4 bytes
    unsigned int  SampDelay_Reg;    // 4 bytes
    unsigned char RX_MUX_REG;
    unsigned char res29;
    unsigned char res2A;
    unsigned char res2B;
    unsigned short SYS_GAIN_REG;    //2 bytes
    unsigned char ECHOREJ_AMP_REG;
    unsigned char res2F;

    unsigned char GATE1_CTRL_REG;
    unsigned char res31;
    unsigned char res32;
    unsigned char res33;
    unsigned char res34;
    unsigned char res35;
    unsigned char res36;
    unsigned char GATE1_HIGH_REG;
    unsigned int  GATE1_POS_REG;
    unsigned int GATE1_WID_REG;

    unsigned char GATE2_CTRL_REG;
    unsigned char res41;
    unsigned char res42;
    unsigned char res43;
    unsigned char res44;
    unsigned char res45;
    unsigned char res46;
    unsigned char GATE2_HIGH_REG;
    unsigned int GATE2_POS_REG;
    unsigned int GATE2_WID_REG;

    unsigned char res[432];

} Ft2232hCtl;
#endif // MICROS_H
