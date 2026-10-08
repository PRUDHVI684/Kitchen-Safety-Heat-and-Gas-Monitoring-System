#include "type.h"
void WRITE_LCD_CMD(u8 CMD);
void INIT_LCD(void);
void WRITE_LCD_DATA(u8 ascii);
void strLCD(u8* str);
void U32LCD(u32 n);
void S32LCD(s32 n);
void F32LCD(f32 fn,u8 nDP);
void buildCGRAM(u8* p,u8 nb);
void Edit_time(void);
void Edit_date(void);
void Edit_day(void);
void update(void);

