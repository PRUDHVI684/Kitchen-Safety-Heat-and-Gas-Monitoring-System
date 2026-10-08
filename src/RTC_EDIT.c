#include "type.h"
#include "RTC1.h"
#include "LCD.h"
#include "kpm.h"
#include "delay.h"
#include "LCD_COMMANDS.h"

extern s32 hour;
extern s32 min;
extern s32 sec;

extern s32 date;
extern s32 month;
extern s32 year;
extern s32 day;   
u32 Option1;   


void EditRTC(void)
{   
        while(1){
     WRITE_LCD_CMD(GOTO_LINE1_POS0);   
         strLCD("1.TIME 2.DATE");   
         WRITE_LCD_CMD(GOTO_LINE2_POS0);   
         strLCD("                  ");   
         WRITE_LCD_CMD(GOTO_LINE2_POS0);   
         strLCD("3.DAY 4.EXIT");   
         Option1=ReadNum2();   
   
         if(Option1==1){   
                Edit_time();   
                update();   
                }   
        else if(Option1==2){   
                Edit_date();   
                update();   
                }   
        else if(Option1==3){   
                Edit_day();   
                update();   
                }   
        else if(Option1==4){   
                break;   
                }   
        else{   
                 WRITE_LCD_CMD(GOTO_LINE1_POS0);   
                 strLCD("INVALID OPTION");   
                 delay_ms(700);   
                 }   
        }   
   }   
void Edit_time(void){
    /* Get current RTC values */
    GetRTCTimeInfo(&hour, &min, &sec);
    GetRTCDateInfo(&date, &month, &year);
        GetRTCDayInfo(&day);

    /* -------- EDIT HOUR -------- */   

        WRITE_LCD_CMD(GOTO_LINE1_POS0);
    strLCD("                ");   
        WRITE_LCD_CMD(GOTO_LINE1_POS0);
    strLCD("ENTER HOUR");
        WRITE_LCD_CMD(GOTO_LINE2_POS0);   
        strLCD("                ");   
        WRITE_LCD_CMD(GOTO_LINE2_POS0);
    hour = ReadNum();

    while(hour > 23 )
    {      
                WRITE_LCD_CMD(GOTO_LINE1_POS0);
        strLCD("                ");   
                WRITE_LCD_CMD(GOTO_LINE1_POS0);
        strLCD("INVALID HOUR");
        delay_ms(500);
                WRITE_LCD_CMD(GOTO_LINE1_POS0);
        strLCD("                ");   
                WRITE_LCD_CMD(GOTO_LINE1_POS0);
        strLCD("ENTER HOUR");   
                WRITE_LCD_CMD(GOTO_LINE2_POS0);
        hour = ReadNum();
    }

    /* -------- EDIT MINUTE -------- */
        WRITE_LCD_CMD(GOTO_LINE1_POS0);
    strLCD("                ");   
        WRITE_LCD_CMD(GOTO_LINE1_POS0);
    strLCD("ENTER MIN");
        WRITE_LCD_CMD(GOTO_LINE2_POS0);   
        strLCD("            ");   
        WRITE_LCD_CMD(GOTO_LINE2_POS0);
    min = ReadNum();

    while(min > 59)
    {   
                WRITE_LCD_CMD(GOTO_LINE1_POS0);
        strLCD("                ");   
                WRITE_LCD_CMD(GOTO_LINE1_POS0);
        strLCD("INVALID MIN");
        delay_ms(1000);

        strLCD("                ");   
                WRITE_LCD_CMD(GOTO_LINE1_POS0);
        strLCD("ENTER MIN");   
                WRITE_LCD_CMD(GOTO_LINE2_POS0);   
                strLCD("            ");   
                WRITE_LCD_CMD(GOTO_LINE2_POS0);
        min = ReadNum();
    }

    /* -------- EDIT SECOND -------- */
        WRITE_LCD_CMD(GOTO_LINE1_POS0);
    strLCD("                ");   
        WRITE_LCD_CMD(GOTO_LINE1_POS0);
    strLCD("ENTER SEC");
        WRITE_LCD_CMD(GOTO_LINE2_POS0);   
        strLCD("           ");   
        WRITE_LCD_CMD(GOTO_LINE2_POS0);
    sec = ReadNum();

    while(sec > 59)
    {   WRITE_LCD_CMD(GOTO_LINE1_POS0);
        strLCD("                ");   
                WRITE_LCD_CMD(GOTO_LINE1_POS0);
        strLCD("INVALID SEC");
        delay_ms(1000);
                WRITE_LCD_CMD(GOTO_LINE1_POS0);
        strLCD("                ");   
                WRITE_LCD_CMD(GOTO_LINE1_POS0);
        strLCD("ENTER SEC");   
                WRITE_LCD_CMD(GOTO_LINE2_POS0);
        sec = ReadNum();
    }   
         SetRTCTimeInfo(hour, min, sec);   

}   

void Edit_date(void){
   /* -------- EDIT DATE -------- */
                WRITE_LCD_CMD(GOTO_LINE1_POS0);
    strLCD("                ");   
        WRITE_LCD_CMD(GOTO_LINE1_POS0);
    strLCD("ENTER DATE");
        WRITE_LCD_CMD(GOTO_LINE2_POS0);   
        strLCD("            ");   
        WRITE_LCD_CMD(GOTO_LINE2_POS0);
    date = ReadNum();

    while((date < 1 || date > 31))
    {   
                WRITE_LCD_CMD(GOTO_LINE1_POS0);
        strLCD("                ");   
                WRITE_LCD_CMD(GOTO_LINE1_POS0);
        strLCD("INVALID DATE");   
                WRITE_LCD_CMD(GOTO_LINE1_POS0);
        delay_ms(1000);

        strLCD("                 ");   
                WRITE_LCD_CMD(GOTO_LINE1_POS0);
        strLCD("ENTER DATE");   
                WRITE_LCD_CMD(GOTO_LINE2_POS0);   
                strLCD("            ");   
                WRITE_LCD_CMD(GOTO_LINE2_POS0);
        date = ReadNum();
    }

    /* -------- EDIT MONTH -------- */
        WRITE_LCD_CMD(GOTO_LINE1_POS0);
    strLCD("                ");   
        WRITE_LCD_CMD(GOTO_LINE1_POS0);
    strLCD("ENTER MONTH");
        WRITE_LCD_CMD(GOTO_LINE2_POS0);   
        strLCD("            ");   
        WRITE_LCD_CMD(GOTO_LINE2_POS0);
    month = ReadNum();

    while(month < 1 || month > 12)
    {   
                WRITE_LCD_CMD(GOTO_LINE1_POS0);
        strLCD("                ");   
                WRITE_LCD_CMD(GOTO_LINE1_POS0);
        strLCD("INVALID MONTH");
        delay_ms(1000);

        strLCD("                ");   
                WRITE_LCD_CMD(GOTO_LINE1_POS0);
        strLCD("ENTER MONTH");   
                WRITE_LCD_CMD(GOTO_LINE2_POS0);   
                strLCD("            ");   
                WRITE_LCD_CMD(GOTO_LINE2_POS0);
        month = ReadNum();
    }

    /* -------- EDIT YEAR -------- */
        WRITE_LCD_CMD(GOTO_LINE1_POS0);
    strLCD("                ");   
        WRITE_LCD_CMD(GOTO_LINE1_POS0);
    strLCD("ENTER YEAR");
        WRITE_LCD_CMD(GOTO_LINE2_POS0);   
        strLCD("              ");   
        WRITE_LCD_CMD(GOTO_LINE2_POS0);
    year = ReadNum();

    while(year < 2000 || year > 2099)
    {   
                WRITE_LCD_CMD(GOTO_LINE1_POS0);
        strLCD("                ");   
                WRITE_LCD_CMD(GOTO_LINE1_POS0);
        strLCD("INVALID YEAR");
        delay_ms(1000);
                WRITE_LCD_CMD(GOTO_LINE1_POS0);
        strLCD("                 ");   
                WRITE_LCD_CMD(GOTO_LINE1_POS0);
        strLCD("ENTER YEAR");   
                WRITE_LCD_CMD(GOTO_LINE2_POS0);   
                strLCD("               ");   
                WRITE_LCD_CMD(GOTO_LINE2_POS0);
        year = ReadNum();
    }   
        SetRTCDateInfo(date, month, year);   
}   
   
void Edit_day(void){   
        //************EDIT DAY **************   
   
        WRITE_LCD_CMD(GOTO_LINE1_POS0);
    strLCD("                ");   
        WRITE_LCD_CMD(GOTO_LINE1_POS0);
    strLCD("ENTER DAY");
        WRITE_LCD_CMD(GOTO_LINE2_POS0);   
        strLCD("               ");   
        WRITE_LCD_CMD(GOTO_LINE2_POS0);
    day = ReadNum();

    while(day < 1 || day > 7)
    {   
                WRITE_LCD_CMD(GOTO_LINE1_POS0);
        strLCD("                ");   
                WRITE_LCD_CMD(GOTO_LINE1_POS0);
        strLCD("INVALID DATE");
        delay_ms(1000);

        strLCD("                ");   
                WRITE_LCD_CMD(GOTO_LINE1_POS0);
        strLCD("ENTER DATE");   
                WRITE_LCD_CMD(GOTO_LINE2_POS0);   
                strLCD("            ");   
                WRITE_LCD_CMD(GOTO_LINE2_POS0);
        date = ReadNum();   
                SetRTCDayInfo(day);   

    }   
}


    /* -------- SAVE TIME -------- */

    /* -------- SAVE DATE ------- - */



void update(void){
        WRITE_LCD_CMD(GOTO_LINE1_POS0);
    strLCD("                ");   
        WRITE_LCD_CMD(GOTO_LINE1_POS0);
    strLCD("RTC UPDATED");

    delay_ms(1000);   
        WRITE_LCD_CMD(GOTO_LINE1_POS0);   
        strLCD("                ");
}

