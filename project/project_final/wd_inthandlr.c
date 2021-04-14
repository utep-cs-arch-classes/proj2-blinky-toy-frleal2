#include <msp430.h>
#include "switches.h"
#include "scales.h"

/* Switches on P2 (S2) */
void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & SWITCHES) {	      /* did a button cause this interrupt? */
    P2IFG &= ~SWITCHES;		      /* clear pending sw interrupts */
    switch_interrupt_handler();	/* single handler for all switches */
  }
}

/*Timer interrupt, along with buttons it will check pass of time*/
void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char count = 0;
  if (++count == 125) {
    if(timerAct==1){
      choose_scale();
    }
    count = 0;
  }
}

