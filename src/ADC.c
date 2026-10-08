#include<lpc21xx.h>
#include "typedef.h"
#include "delay.h"
#include "adc_defines.h"

void INIT_ADC(void){

        PINSEL1&=~(255<<((27-16)*2));
        PINSEL1|=0x00400000;
        PINSEL1|=0x01000000;
        ADCR|=((1<<21) |( 4<<8));

}


void read_adc(u32 chno,u32 *dval,f32 *eAR){

                ADCR=ADCR&~(255<<0);
                ADCR|=((1<<chno)|( 1<<START_CONV));
                delay_ms(3);
                while(((ADDR>>31)&1)==0);

                ADCR&=~(1<<START_CONV);

                *dval=((ADDR>>RESULT)&1023);
                *eAR=(3.3/1023)*(*dval);
}





