#include<lpc214x.h>
#include "type.h"
#include "myADC.h"
#include "lcd.h"
#include "lm35.h"
#include "delay.h"
#include "RTC1.h"   
#include "lcd_commands.h"
#include "kpm.h"


#define SUN 0
#define MON 1
#define TUE 2
#define WED 3
#define THU 4
#define FRI 5
#define SAT 6

//varible declerations
s32 hour,min,sec,date,month,year,day;

u32 TEMP_THRES=60;

f32 tempC;
f32 tempF;   
f32 GasP;   
f32 *haz;   


int main()
{
        IODIR0|=((1<<5)|(1<<6));

        INIT_ADC();
        INIT_LCD();
        RTC_Init();
        InitKPM();   
        eint0_enable();
        SetRTCTimeInfo(11,54,0);
				SetRTCDateInfo(12,9,2026);
				SetRTCDayInfo(SAT);
        while(1)
        {
                if(edit_mode == 1){
                         edit_mode = 0;   
                         change_Thres_values();   
                         } 


								//to get time
                GetRTCTimeInfo(&hour,&min,&sec);
                DisplayRTCTimeInfo(hour,min,sec);
												 
                // date
                GetRTCDateInfo(&date,&month,&year);
                DisplayRTCDateInfo(date,month,year);
												 
                //day of week;
                GetRTCDayInfo(&day);
                DisplayRTCDayInfo(day);

                delay_ms(2000);
                WRITE_LCD_CMD(0x80);
                strLCD("                ");
                WRITE_LCD_CMD(0xC0);
                strLCD("                ");
        
                LM35NT(&tempC,&GasP);
                haz=&tempC;   
               
   
                WRITE_LCD_CMD(0xC0);   
   
                if(((IOPIN0>>3)&1)==1){   
                        IOCLR0=((1<<5)|(1<<6));
                        strLCD("Gas:NORMAL");   
              
                        }   
                else{   
                        WRITE_LCD_CMD(0xC0);   
                        strLCD("            ");   
                        WRITE_LCD_CMD(0xC0);   
                        strLCD("Gas:DETECTED");   
                        IOSET0=((1<<5)|(1<<6));   
                        while(((IOPIN0>>7)&1)==1);   
                        }   

                if(*haz<=TEMP_THRES){   
                IOCLR0=((1<<5)|(1<<6));
                WRITE_LCD_CMD(0x80);
                strLCD("TempC:");
                F32LCD(tempC,1);
                WRITE_LCD_DATA(0xDF);
                WRITE_LCD_DATA('C');     

                }
                else{   

                        WRITE_LCD_CMD(GOTO_LINE1_POS0);
                        strLCD("               ");
                        WRITE_LCD_CMD(GOTO_LINE1_POS0);
                        strLCD("Temp:HAZARD");
                        delay_ms(500);
                        IOSET0=((1<<5)|(1<<6));
                        while(((IOPIN0>>7)&1)==1);

                }
                delay_ms(2000);
                WRITE_LCD_CMD(0x80);
                strLCD("                ");
                WRITE_LCD_CMD(0xC0);
                strLCD("                ");
        }
}   

