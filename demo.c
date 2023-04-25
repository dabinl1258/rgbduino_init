/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <joerg@FreeBSD.ORG> wrote this file.  As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.        Joerg Wunsch
 * ----------------------------------------------------------------------------
 *
 * Simple AVR demonstration.  Controls a LED that can be directly
 * connected from OC1/OC1A to GND.  The brightness of the LED is
 * controlled with the PWM.  After each period of the PWM, the PWM
 * value is either incremented or decremented, that's all.
 *
 * $Id: demo.c 1637 2008-03-17 21:49:41Z joerg_wunsch $
 */

#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
void Delay(int tick);
int Init_Pin()
{
    DDRB = 0xff;
    DDRC = 0xff;
    DDRD = 0xff;
    
    PORTB = 0x00;
    PORTC = 0x00;
    PORTD = 0x00;    
    Delay(1000);

    PORTB |= 0x01;
    PORTC |= 0x01;
    PORTD |= 0x04;
}   
int
main (void)
{

     Init_Pin();   
    /* loop forever, the interrupts are doing the rest */
    for (;;)			/* Note [7] */
        sleep_mode();
       
    
    return (0);
}
void Delay(int tick)
{
    for(int i = 0; i < tick; i++)
    ;;
}
