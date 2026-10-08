#include "typedef.h"
void delay_us(u32 delay){
	for(delay*=12;delay>0;delay--);
}
void delay_ms(u32 delay){	
	for(delay*=12000;delay>0;delay--);
}

void delay_s(u32 delay){
	for(delay*=12000000;delay>0;delay--);
}


