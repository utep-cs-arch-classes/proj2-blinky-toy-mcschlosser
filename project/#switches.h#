#ifndef switches_included
#define switches_included

#define SW1 BIT3                /* switch1 is p1.3 */
#define SW2 BIT2
#define SW3 BIT1
#define SW4 BIT0
#define SWITCHES (SW4 | SW3 | SW2 | SW1)            /* only 1 switch on this board */

void switch_init();
void switch_interrupt_handler();

extern char switch_state_down, switch_state_down1, switch_state_down2, switch_state_down3, switch_state_changed; /* effectively boolean */

#endif // included
