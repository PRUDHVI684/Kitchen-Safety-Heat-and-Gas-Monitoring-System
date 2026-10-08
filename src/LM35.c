
#include "typeDEF.h"
#include "myADC.h"
#include "adc_defines.h"
f32 LM35tC(void)
{
	u32 dval;
	f32 eAR;
	read_adc(CH0,&dval,&eAR);
	return (eAR*100);
}
f32 LM35tF(void)
{
	f32 tempC;
	tempC=LM35tC();
	return(tempC*(1.8)+32);
}
void LM35NT(f32* tempC,f32* tempF)
{
	u32 dval1,dval2;
	
	f32 eAR1,eAR2;
	//adc output voltage
	read_adc(CH0,&dval1,&eAR1);
	// offset volatage
	read_adc(CH1,&dval2,&eAR2);
	
	*tempC=(eAR1-eAR2)*100;
	
	*tempF=((*tempC)*1.8)+32;
}

