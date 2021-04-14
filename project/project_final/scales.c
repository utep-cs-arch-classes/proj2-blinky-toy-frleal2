#include "switches.h"
#include "buzzer.h"
#include "scales.h"


short scale = 0; //first scale by default
short timerAct = 0; // definition of timer act just for now

void choose_scale(){
  switch(scale){
    
  case 0: //play first scale
    ; //null statement so declaration can work
     static char cnt = 0;		/* # deciseconds/frequecy change */
     if (++cnt > 2) {		
       buzzer_advance_frequency();
       cnt = 0;
     }
    break;
  case 1: //play second scale
    ; //null statement
    static char cnt2 = 0;
    if(++cnt2 > 2){
      buzzer_advance_frequencyP(10);
      cnt2=0;
    }
    break;
  case 2: // play third scale
    ; //null statement
    static char cnt3 = 0;
    if(++cnt3 > 2){
      buzzer_advance_frequencyP(2);
      cnt3 = 0;
    }
    break;
  }


}
