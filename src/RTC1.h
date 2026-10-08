#include "type.h"

void RTC_Init(void);
void SetRTCTimeInfo(u32 hour,u32 min,u32 sec);
void GetRTCTimeInfo(s32 *hour,s32 *min,s32 *sec);
void DisplayRTCTimeInfo(u32 hour,u32 min,u32 sec);
void SetRTCDateInfo(u32 date,u32 month,u32 year);
void GetRTCDateInfo(s32 *date,s32 *month,s32 *year);
void DisplayRTCDateInfo(u32 date, u32 month,u32 year);
void SetRTCDayInfo(u32 dow);
void GetRTCDayInfo(s32 *dow);
void DisplayRTCDayInfo(u32 dow);
void eint0_enable(void);
extern volatile u32 edit_mode;
void eint1_enable(void);
void EditRTC(void);   
void edit_TEMP_THRES_Value(void);   
void edit_GasThres_value(void);   
void change_Thres_values(void);   
void change_time_data(void);   
void Change_Password(void);   
u32 ReadNum1(void);   
u32 ReadNum2(void);   
//s32 hour,min,sec,date,month,year,day;

