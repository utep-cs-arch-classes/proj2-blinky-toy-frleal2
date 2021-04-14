#include "switches.h"
#include "led.h"
#include "ledStates.h"
	.arch msp430g2553
	
	.global led_state; our variable of state, declare it global to be used externally
	.data
led_state:.word 0; vriable definition
	.global led_off	; our variable to check if led is off
led_off:.word 0	; variable definition
	
	.text
jt:
	.word on ; or value 0 of the led state variable
	.word off ; or value 1 of the led state variable

	.global led_toggle ; declare function as global

led_toggle:
	;;we do not need to do a comparison for our state variable, we will not
	;;have anything but 0 or 1, and we do not have a default state 
	;;so we will modify our variable and index right away into the state
	mov &led_state, r13 ; move it so we can modify it to get right jt address
	add r13, r13 ;  we double it
	mov jt(r13), r0 ; jump to the corresponding state

on:
	mov #1, &led_off ; set led off to a 1 (or turn off led)
	jmp end ; break
off:
	mov #0, &led_off ; set led off to a 0 (or turn on led)
	jmp end  ; break
end:
	;; end program somehow
	ret
