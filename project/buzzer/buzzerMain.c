#include <msp430.h>
#include "./../timerLib/libTimer.h"
#include "buzzer.h"

int main() {
    configureClocks();
 
    buzzer_init();

    or_sr(0x18);          // CPU off, GIE on
}
