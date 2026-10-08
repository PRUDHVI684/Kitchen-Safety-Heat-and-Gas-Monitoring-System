#include<lpc214x.h>
//#include<lpc21xx.h>
#include "RTC1.h"
#include "lcd_commands.h"
#include "LCD.h"
#include "type.h"    


#define FOSC 12000000
#define CCLK (5*FOSC)
#define PCLK (CCLK/4)
#define PREINT_VAL ((PCLK/32768)-1)
#define PREFRAC_VAL (PCLK-((PREINT_VAL+1)*32768))
#define EINT_PIN  0

#define RTC_ENABLE (1<<0)
#define RTC_RESET (1<<1)
#define RTC_CLKSRC (1<<4)

#define CPU_LPC2148

//S32 hour,min,sec,date,month,year,day;    
//s32 day;
u8 week[][4]={"SUN","MON","TUE","WED","THU","FRI","SAT"};

#define SUN 0
#define MON 1
#define TUE 2
#define WED 3
#define THU 4
#define FRI 5
#define SAT 6

void RTC_Init(void){

        //diasable and reset the rtc
        CCR=RTC_RESET;
        #ifndef CPU_LPC2148
        //set prescalar integer and fractional part
        PREINT=PREINT_VAL;
        PREFRAC=PREFRAC_VAL;

        //enable the rtc
        CCR=RTC_ENABLE;  //LPC2129
        #else
        //enable the rtc with external clock
        CCR=RTC_ENABLE | RTC_CLKSRC; //LPC2148
        #endif

}
void SetRTCTimeInfo(u32 hour,u32 min,u32 sec){

        HOUR=hour;
        MIN=min;
        SEC=sec;
}

void GetRTCTimeInfo(s32 *hour,s32 *min,s32 *sec){

        *hour=HOUR;
        *min= MIN;
        *sec= SEC;
}

void DisplayRTCTimeInfo(u32 hour,u32 min,u32 sec){

        WRITE_LCD_CMD(GOTO_LINE1_POS0);
        WRITE_LCD_DATA(hour/10+48);
        WRITE_LCD_DATA(hour%10+48);
        WRITE_LCD_DATA(':');
        WRITE_LCD_DATA(min/10+48);
        WRITE_LCD_DATA(min%10+48);
        WRITE_LCD_DATA(':');
        WRITE_LCD_DATA(sec/10+48);
        WRITE_LCD_DATA(sec%10+48);
}
void SetRTCDateInfo(u32 date,u32 month,u32 year){


        DOM=date;
        MONTH=month;
        YEAR=year;
}
void GetRTCDateInfo(s32 *date,s32 *month,s32 *year){

        *date=DOM;
        *month=MONTH;
        *year=YEAR;
}

void DisplayRTCDateInfo(u32 date, u32 month,u32 year){

        WRITE_LCD_CMD(GOTO_LINE2_POS0);
        WRITE_LCD_DATA(date/10+48);
        WRITE_LCD_DATA(date%10+48);
        WRITE_LCD_DATA('/');
        WRITE_LCD_DATA(month/10+48);
        WRITE_LCD_DATA(month%10+48);
        WRITE_LCD_DATA('/');
        U32LCD(year);

}

void SetRTCDayInfo(u32 dow){
        DOW=dow;
}
void GetRTCDayInfo(s32 *dow){

        *dow=DOW;
}
void DisplayRTCDayInfo(u32 day){

        WRITE_LCD_CMD(GOTO_LINE1_POS0 + 10);
        strLCD(week[day]);

	
	
}    

