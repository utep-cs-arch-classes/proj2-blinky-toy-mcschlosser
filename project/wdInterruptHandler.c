#include <msp430.h>
#include "stateMachines.h"
#include "buzzer.h" 

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  static char buzzer_count = 0;
  if (++blink_count == 150) {
    state_advance();
    blink_count = 0;
  }
  if(++buzzer_count == 86){
    buzz_state_adv();
  
    buzzer_count = 0;
  }
}
