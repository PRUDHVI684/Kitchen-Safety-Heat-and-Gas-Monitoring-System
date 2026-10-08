#include "kpm.h"   
#include "LCD_COMMANDS.h"   
#include "RTC1.h"   
#include "delay.h"  
#include "LCD.h"
   
u32 password=1234;
u32 ENTER_password;   
u32 Option;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
u32 count=0;   
u32 *pass=&password;   
//u32 *New_password;   
   
u32 NEW_TEMP_THRES;   
u32 NEW_GAS_THRES;   
extern volatile u32 TEMP_THRES;   
extern volatile u32 GAS_THRES_VALUE;   
   
   
void edit_TEMP_THRES_Value(void){
                                 WRITE_LCD_CMD(GOTO_LINE1_POS0);
                                 strLCD("           ");   
                                 WRITE_LCD_CMD(GOTO_LINE1_POS0);
                                 strLCD("enter new_thres");
                                 WRITE_LCD_CMD(GOTO_LINE2_POS0);   
                                 strLCD("                ");   
                                 WRITE_LCD_CMD(GOTO_LINE2_POS0);
                                 NEW_TEMP_THRES=ReadNum();
                                 TEMP_THRES = NEW_TEMP_THRES;   
                                 WRITE_LCD_CMD(GOTO_LINE1_POS0);   
                                 strLCD("                ");   
                                 WRITE_LCD_CMD(GOTO_LINE1_POS0);   
                                 strLCD("THRES_UPDATED");   
                                 delay_ms(1000);   
                                 WRITE_LCD_CMD(GOTO_LINE1_POS0);   
                                  strLCD("                ");   
   
   
}   
/*void edit_GasThres_value(void){   
   
         WRITE_LCD_CMD(GOTO_LINE1_POS0);
         strLCD("           ");   
         WRITE_LCD_CMD(GOTO_LINE1_POS0);
         strLCD("enter new_Thres");
         WRITE_LCD_CMD(GOTO_LINE2_POS0);
         NEW_GAS_THRES=ReadNum();
         GAS_THRES_VALUE = NEW_GAS_THRES;   
} */   
   
void change_Thres_values(void){   
   
                         WRITE_LCD_CMD(GOTO_LINE1_POS0);   
                         strLCD("                 ");   
                         WRITE_LCD_CMD(GOTO_LINE1_POS0);
                         strLCD("enter pass");
                         WRITE_LCD_CMD(GOTO_LINE2_POS0);   
                         strLCD("              ");
                         ENTER_password=ReadNum1();   
   
                           
                         if(count<=2){
                                if(ENTER_password==password){   
                                        while(1){   
                                         WRITE_LCD_CMD(GOTO_LINE1_POS0);   
                                         strLCD("ACCESS GRANTED");   
                                         WRITE_LCD_CMD(GOTO_LINE2_POS0);   
                                         strLCD("             ");   
   
                                         delay_ms(1000);   
                                         WRITE_LCD_CMD(GOTO_LINE1_POS0);   
                                         strLCD("               ");   
                                         WRITE_LCD_CMD(GOTO_LINE1_POS0);   
                                         strLCD("1.TM_SET");   
                                         WRITE_LCD_CMD(GOTO_LINE1_POS0+9);   
                                         strLCD("2.PASS");   
                                         WRITE_LCD_CMD(GOTO_LINE2_POS0);   
                                         strLCD("                ");   
                                         WRITE_LCD_CMD(GOTO_LINE2_POS0);   
                                         strLCD("3.RTC_E");   
                                         WRITE_LCD_CMD(GOTO_LINE2_POS0+7);   
                                         strLCD("4.EXIT");   
                                         //WRITE_LCD_CMD(GOTO_LINE2_POS0);   
                                         Option=ReadNum2();   
                                         if(Option==1){   
   
                                                edit_TEMP_THRES_Value();   
                                                WRITE_LCD_CMD(GOTO_LINE2_POS0+15);   
                                                strLCD("     ");   
   
                                                }   
                                        else if(Option==2){   
                                                 Change_Password();   
                                                 WRITE_LCD_CMD(GOTO_LINE2_POS0+15);   
                                                strLCD("     ");   
                                                 }   
                                        else if(Option==3){   
                                                        EditRTC();   
                                                        WRITE_LCD_CMD(GOTO_LINE2_POS0+15);   
                                                strLCD("     ");   
                                                }   
                                        else if(Option==4){   
                                                        WRITE_LCD_CMD(0X80);   
                                                        strLCD("                 ");   
                                                        WRITE_LCD_CMD(0XC0);   
                                                        strLCD("                ");   
                                                        WRITE_LCD_CMD(0XC0);   
                                                        strLCD("EXITING");   
                                                        delay_ms(700);   
   
                                                        break;   
                                                }           
                                        else{   
                                                WRITE_LCD_CMD(GOTO_LINE1_POS0);   
                                                strLCD("                ");   
                                                WRITE_LCD_CMD(GOTO_LINE2_POS0);   
                                                strLCD("                ");   
                                                WRITE_LCD_CMD(GOTO_LINE1_POS0);   
                                                strLCD("INVALID OPTION");   
                                                delay_ms(1000);   
                                                WRITE_LCD_CMD(GOTO_LINE1_POS0);   
                                                strLCD("                ");                                                 
   
                                                }   
                                        }   
                                }   
                                                   
                                else{   
                                           
                                         WRITE_LCD_CMD(GOTO_LINE2_POS0);
                                         strLCD("                ");   
                                         WRITE_LCD_CMD(GOTO_LINE2_POS0);   

                                         strLCD("incorrect pass");   
                                         count++;   
                                         delay_ms(1000);   
                                         WRITE_LCD_CMD(GOTO_LINE2_POS0);   
   
                                         strLCD("                ");   
                                         WRITE_LCD_CMD(GOTO_LINE1_POS0);   
                                         strLCD("                  ");   
                                }   
                        }   
   
   
                        else{   
   
                                 WRITE_LCD_CMD(GOTO_LINE2_POS0);   
                                 strLCD("              ");   
                                 WRITE_LCD_CMD(GOTO_LINE2_POS0);   
                                 strLCD("DEVICE BLOCKED");   
                                 delay_s(10);   
                                 count=0;   
                        }   
}          

u32 ReadNum1(void)
{
        u8 key;
        u32 sum=0;   
        u32 i=0;
        while(1)
        {
                key=KeyScan();   
                delay_ms(200);
                if(key>='0' && key<='9')
                {
                        sum=(sum*10)+(key-48);   
                        //WRITE_LCD_CMD(0Xc0);   
                        //sum=(sum*10)+(key-48);
            WRITE_LCD_CMD(0Xc0+i);
            //S32LCD(sum);
                        WRITE_LCD_DATA(key);   
                        delay_ms(500);
                        WRITE_LCD_CMD(0Xc0+i);

                        WRITE_LCD_DATA('*');
                //      WRITE_LCD_CMD(0Xc0);
                //      strLCD("          ");   
   
                        i++;
                }
                else
                        break;
        }
        return sum;
}   
   
u32 ReadNum2(void)
{
        u8 key;
        u32 sum=0;   

        while(1)
        {
                key=KeyScan();
                if(key>='0' && key<='9')
                {   
                        sum=(sum*10)+(key-48);   
                        WRITE_LCD_CMD(0Xc0+15);   
                        S32LCD(sum);   
                        delay_ms(500);   
                        WRITE_LCD_CMD(0Xc0+15);   
                        strLCD("          ");

                }
                else
                        break;
        }
        return sum;   
}   
   

void Change_Password(void){   
   
         WRITE_LCD_CMD(GOTO_LINE1_POS0);   
         strLCD("               ");   
         WRITE_LCD_CMD(GOTO_LINE1_POS0);   
         strLCD("ENTER NEW PASS");   
         WRITE_LCD_CMD(GOTO_LINE2_POS0);   
         strLCD("                  ");   
         WRITE_LCD_CMD(GOTO_LINE2_POS0);   
   
         *pass=ReadNum1();   
         //password=&New_password;   
   
         WRITE_LCD_CMD(GOTO_LINE1_POS0);   
         strLCD("                ");   
         WRITE_LCD_CMD(GOTO_LINE1_POS0);   
            
         strLCD("PASS UPDATED");   
         delay_ms(1000);   
         WRITE_LCD_CMD(GOTO_LINE1_POS0);   
         strLCD("              ");   
   
                   
   
}   
   
   
   


  