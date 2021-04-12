
#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "stateMachines.h"
#include "switches.h"
void buzzer_init()
{
    /* 
       Direct timer A output "TA0.1" to P2.6.  
        According to table 21 from data sheet:
          P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero
          P2SEL.6 must be 1
        Also: P2.6 direction must be output
    */
    timerAUpmode();		/* used to drive speaker */
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7; 
    P2SEL |= BIT6;
    P2DIR = BIT6;		/* enable output to speaker (P2.6) */
}

void buzzer_set_period(short cycles) /* buzzer clock = 2MHz.  (period of 1k results in 2kHz tone) */
{
  CCR0 = cycles; 
  CCR1 = cycles >> 1;		/* one half cycle */
}
void buzz_state_adv1(){
  static int b_state = 0;
  switch(b_state){
  case 0: buzzer_set_period(3000); break;
  case 1: buzzer_set_period(10); break;
  case 3: buzzer_set_period(5000); break;
  case 4: buzzer_set_period(890); break;
    //default: b_state = 0;
  }
  b_state++;
  if(b_state == 4){
    //  buzz_state_adv2();
    b_state = 0;
  }
  
}
   
void buzz_state_adv2(){
  static int b_state = 0;
  switch(b_state){
  case 0: buzzer_set_period(8000); break;
  case 1: buzzer_set_period(8000); break;
  case 3: buzzer_set_period(1000); break;
  case 4: buzzer_set_period(50); break;
    //default: b_state = 0;
  }
  b_state++;
  if(b_state == 4){
     b_state = 0;
    // buzz_state_adv1();
  }
}
void buzz_state_adv3(){
  static int b_state = 0;
  switch(b_state){
  case 0: buzzer_set_period(5); break;
  case 1: buzzer_set_period(10); break;
  case 2: buzzer_set_period(5); break;
  }
  b_state++;
  if(b_state == 2){
    b_state = 0;
  }
}
void buzz_state_adv4(){
  static int b_state = 0;
  switch(b_state){
  case 0: buzzer_set_period(500); break;
  case 1: buzzer_set_period(0); break;
  }
  b_state++;
  if(b_state == 1){
    b_state = 0;
  }
}
/*
void buzz_state_adv(){
  if(switch_state_down){
    buzz_state_adv1();
    state_advance();
  }
  else if(switch_state_down1){
    buzz_state_adv2();
    state_advance1();
  }
  else if(switch_state_down2){
    buzz_state_adv2();
    state_advance2();
  }
  else if(switch_state_down3){
    buzz_state_adv1();
    state_advance3();
  }
  // else{
  //  buzzer_set_period(0);
  //}
}
*/					   

    
    
  

