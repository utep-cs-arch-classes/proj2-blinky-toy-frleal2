#ifndef switches_included
#define switches_included

#define SW0 BIT0
#define SW1 BIT1		/* switch1 is p2.1 hopefully */
#define SWITCHES (SW1 | SW0)		/* only 2 switch on this board */

void switch_init();
void switch_interrupt_handler();

extern char switch_state_down, switch_state_changed; /* effectively boolean */

#endif // included
