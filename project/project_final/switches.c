#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"
#include "scales.h"
#include "ledStates.h"

char switch_state_down, switch_state_changed; /* effectively boolean */
extern void led_toggle(); //declaration of function from assembly
extern short led_state;

static char 
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

void 
switch_init()			/* setup switch */
{  
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE = SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
  led_update();
}

void
switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();

  if(!(p2val & SW1)){
    timerAct = 0; //turn off timer
    switch_state_down = (p2val & SW1) ? 0 : 1; /* 0 when SW1 is up */
    switch_state_changed = 1;
    buzzer_advance_frequency();
    led_off = 0; //leds must be on
    led_update();
  }
  if(!(p2val & SW0)){
    timerAct = 0; //turn off timer
    switch_state_down = (p2val & SW0) ? 1 : 0; /*1 when SW0 is up*/
    switch_state_changed = 1;
    buzzer_set_period(1000);
    led_off = 0;
    led_update();

  }
  if(!(p2val & SW2)){
    timerAct = 0; //turn off timer
    buzzer_init(); //we will try to turn off the buzzer by just restarting it
    switch_state_changed = 1;
    if(led_state == 0){//if the led was turned off (machine was in state 0) we set state to turn it on
      led_state = 1;
      led_toggle();
    }else{ //led state can only be 0 or 1 so if zero we assume it is one, here led is on so we turn off
      led_state = 0;
      led_toggle();
    }
    led_update(); //turn off led
  }
  if(!(p2val & SW3)){
    timerAct = 1;
    if(scale == 2)
      scale = 0;
    scale++; //abilitate timer
  
  }

  
}
