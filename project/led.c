#include <msp430.h>
#include "led.h"
#include "switches.h"
unsigned char red_on = 0, green_on = 0;
unsigned char led_changed = 0;

static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};


void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  led_changed = 1;
  switch_state_changed = 1;
  led_update();
}

void led_update()
{
  if (led_changed) {
    char ledFlags = redVal[red_on] | greenVal[green_on];
    
    P1OUT &= (0xff^LEDS) | ledFlags; // clear bit for off leds
    P1OUT |= ledFlags;		     // set bit for on leds
    led_changed = 0;
  }
  char ledFlags = 0;
  //if(switch_state_changed){
    //  char ledFlags = 0;
  switch(switch_state_changed){
    // char ledFlags = 0;
  case 0:
    ledFlags |= switch_state_down ? LED_GREEN : 0;
    ledFlags |= switch_state_down ? 0 : LED_RED;
    //P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
    // P1OUT |= ledFlags;         // set bits for on leds
  
    switch_state_changed = 0;
    break;
  case 1:
   ledFlags |= switch_state_down1 ? LED_RED : LED_GREEN;
    ledFlags |= switch_state_down1 ? 0 : LED_RED;
    // P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
    // P1OUT |= ledFlags;         // set bits for on leds
  
    switch_state_changed = 0;
    break;
  case 2:
     ledFlags |= switch_state_down2 ? LED_RED : 0;
    ledFlags |= switch_state_down2 ? 0 : LED_GREEN ;
    // P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
    // P1OUT |= ledFlags;         // set bits for on leds
  
    switch_state_changed = 0;
    break;
  case 3:
    ledFlags |= switch_state_down3 ? LED_GREEN : LED_RED;
    ledFlags |= switch_state_down3 ? 0 : 0;
    // P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
    // P1OUT |= ledFlags;         // set bits for on leds
    
    switch_state_changed = 0;
  
    break;
  }
  P1OUT &= (0xff - LEDS) | ledFlags;
  P1OUT |= ledFlags;
  switch_state_changed = 0;
  
}
  /*
  if (switch_state_changed) {
    char ledFlags = 0; // by default, no LEDs on 
    if(switch_state_down){
    ledFlags |= switch_state_down ? LED_GREEN : 0;
    ledFlags |= switch_state_down ? 0 : LED_RED;
    switch_state_changed = 0;
      
    }
    else if(switch_state_down1){
    ledFlags |= switch_state_down1 ? LED_GREEN : LED_RED;
    ledFlags |= switch_state_down1 ? 0: 0;
    switch_state_changed = 0;
    }
    else if(switch_state_down2){
    ledFlags |= switch_state_down2 ? 0 : LED_RED;
    ledFlags |= switch_state_down2 ? LED_GREEN : 0;
    switch_state_changed = 0;
    }
    else if(switch_state_down3){
    ledFlags |= switch_state_down3 ? 0 : 0;
    ledFlags |= switch_state_down3 ? LED_GREEN : LED_RED;
    switch_state_changed = 0;
    }
    P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
    P1OUT |= ledFlags;         // set bits for on leds
  }
    switch_state_changed = 0;
} 
  */
