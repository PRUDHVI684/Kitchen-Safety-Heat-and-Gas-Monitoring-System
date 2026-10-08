#include <lpc21xx.h>
#include "type.h"
#include "delay.h"

#define CHNO 14

volatile u32 edit_mode = 0;


void eint0_isr(void)__irq
{
    edit_mode = 1;          // Request threshold editing

    EXTINT = 1<<0;          // Clear EINT0 flag
    VICVectAddr = 0;        // End of ISR
}


void eint0_enable(void)
{
    // P0.1 -> EINT0
    PINSEL0 &= ~(3<<2);
    PINSEL0|=0x0000000C;

    // EINT0 is IRQ, not FIQ
    VICIntSelect &= ~(1<<CHNO);

    // Enable EINT0 interrupt
    VICIntEnable |= 1<<CHNO;

    // ISR address
    VICVectAddr0 = (u32)eint0_isr;

    // Enable vector slot 0 + interrupt number
    VICVectCntl0 = (1<<5) | CHNO;

    // Edge sensitive
    EXTMODE |= 1<<0;

    // Falling edge
    EXTPOLAR &= ~(1<<0);

    // Clear any pending EINT0
    EXTINT = 1<<0;
}

