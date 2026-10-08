#include<lpc21xx.h>
//#include "delay.c"
#include "delay.h"
#include "LCD_COMMANDS.h"
#include "LCD_DEFINES.h"
#include "typedef.h"
#include "MACRO_DEFINES.h"

void WRITE_LCD_CMD(u8 CMD){
//perform write operation...rw=0
        SCLRBIT(IOCLR0,LCD_RW);
//select cmd register rs=0...
        SCLRBIT(IOCLR0,LCD_RS);
//write cmd on the pins...
        WRITEBYTE(IOPIN0,LCD_DATA,CMD);
//apply low to high pulse.....
        SSETBIT(IOSET0,LCD_EN);
        delay_ms(1);
        SCLRBIT(IOCLR0,LCD_EN);
//delay for internal process....
        delay_ms(2);
}

void INIT_LCD(void){
        WRITEBYTE(IODIR0,LCD_DATA,0XFF);
//cfg port 0.16,0.17,0.18...
        SETBIT(IODIR0,LCD_RS);
        SETBIT(IODIR0,LCD_RW);
        SETBIT(IODIR0,LCD_EN);
        delay_ms(15);
        WRITE_LCD_CMD(MODE_8BIT_LINE1);
        delay_ms(5);
        WRITE_LCD_CMD(MODE_8BIT_LINE1);
        delay_us(100);
        WRITE_LCD_CMD(MODE_8BIT_LINE1);

        WRITE_LCD_CMD(MODE_8BIT_LINE2);
        WRITE_LCD_CMD(DISP_ON_CUR_OFF);
        WRITE_LCD_CMD(CLEAR_LCD);
        WRITE_LCD_CMD(SHIFT_CUR_RIGHT);
        }

void WRITE_LCD_DATA(u8 ascii){

        SCLRBIT(IOCLR0,LCD_RW);
        //select data register rs=1...
        SSETBIT(IOSET0,LCD_RS);
        //write data on data pins;
        WRITEBYTE(IOPIN0,LCD_DATA,ascii);
        //APPLY H TO L PULSE....
        SETBIT(IOSET0,LCD_EN);
        delay_us(1);
        SCLRBIT(IOCLR0,LCD_EN);
        delay_ms(2);
}
void strLCD(u8* str){
        while(*str){
                WRITE_LCD_DATA(*str++);
                }
}
void U32LCD(u32 n){
        u8 a[10];
        s32 i=0;
        if(n==0){
        WRITE_LCD_DATA('0');
        }
        else{
                while(n){
                        a[i++]=n%10+48;
                        n/=10;
                        }
                        for(--i;i>=0;i--){
                                WRITE_LCD_DATA(a[i]);
                                }
						}
}
void S32LCD(s32 n)
{
        if(n<0){
                   WRITE_LCD_DATA('-');
                   n=-n;
                   }
                   U32LCD(n);
}

void F32LCD(f32 fn,u8 nDP){
        u32 inum,i;
        if(fn<0){
                WRITE_LCD_DATA('-');
                fn=-fn;
                }
                inum=fn;
                U32LCD(inum);
                WRITE_LCD_DATA('.');
                for(i=0;i<nDP;i++){
                fn=(fn-inum)*10;
                inum=fn;
                WRITE_LCD_DATA(inum+'0');
                }
}

void buildCGRAM(u8* p,u8 nb){

        s32 i;
        //select cgram..
        WRITE_LCD_CMD(GOTO_CGRAM);
        for(i=0;i<nb;i++){

                WRITE_LCD_DATA(p[i]);

        }
        //select ddram......
        WRITE_LCD_CMD(GOTO_LINE1_POS0);
}






