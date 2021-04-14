/*File with state machine representing led states, basically just toggles the led, it will be controled by switch number 3 (the one that turns)
off everything.
*/

#include "switches.h"
#include "ledStates.h"
#include "led.h"

short led_state = 0;

void led_toggle(){
  switch(led_state){
    case 0: //led is on
      led_off = 1;//set led to off
      break;
    case 1: //led is off
      led_off = 0;//set led to on
      break;
  }


}
