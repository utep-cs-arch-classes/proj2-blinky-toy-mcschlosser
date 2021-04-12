#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"

char toggle_red()		/* always toggle! */
{
  static char state = 0;

  switch (state) {
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }
  return 1;			/* always changes an led */
}

char toggle_green()	/* only toggle green if red is on!  */
{
  char changed = 0;
  if (red_on) {
    green_on ^= 1;
    changed = 1;
  }
  return changed;
}


void state_advance()		/* alternate between toggling red & green */
{
  char changed = 0;  

  static enum {R=0, G=1} color = G;
  switch (color) {
  case R: changed = toggle_red(); color = G; break;
  case G: changed = toggle_green(); color = R; break;
  }

  led_changed = changed;
  led_update();
}
void state_advance1(){
  static char state = 0;
  char changed = 0;
  switch(state){
  case 0:
    red_on = 0;
    green_on = 1; //turns green on
    state++;
    break;
  }
  led_changed = 1;
  led_update();

}

void state_advance2(){
  static char state = 0;
  char changed = 0;
  switch(state){
  case 0:
    red_on = 1; //turns red light on
    green_on = 0;
    state++;
    break;
  }
  led_changed = 1;
  led_update();
}
void state_advance3(){
  static char state = 0;
  char changed = 0;
  switch(state){
  case 0: red_on = 0;
    green_on = 0;
    state++;
    break;
  }
  led_changed = 1;
  led_update();
}
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
    buzz_state_adv3();
    state_advance2();
  }
  else if(switch_state_down3){
    buzz_state_adv4();
    state_advance3();
  }
   else{
    buzzer_set_period(0);
  }
}
