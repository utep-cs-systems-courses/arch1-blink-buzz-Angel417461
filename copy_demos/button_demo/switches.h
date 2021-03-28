#ifndef switches_included
#define switches_included

#define SW1 BIT0
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3

#define SWITCHES (SW1 | SW2 | SW3 | SW4)   

void switch_init();
void switch_interrupt_handler();
void switchSM();

extern char ssd1, ssd2, ssd3, ssd4, switch_state_down, switch_state_changed; /* effectively boolean */

#endif // included
