
#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"


void state_advance()		/* sos */
{
  char changed = 0;

  static char state = 0;

  switch(state){
  case 0: red_on = 1; green_on ^= 1; state++;break;
  case 1: red_on = 1; green_on ^= 1; state++;break;
  case 2: red_on = 0; green_on ^= 0; state++;break;
  case 3: red_on = 1; green_on ^= 1; state++;break;
  case 4: red_on = 1; green_on ^= 1; state++;break;
  case 5: red_on = 0; green_on ^= 0; state++;break;
  case 6: red_on = 1; green_on ^= 1; state++;break;
  case 7: red_on = 1; green_on ^= 1; state++;break;
    
  case 8: red_on = 0; green_on ^= 0; state++;break;
  case 9: red_on = 1; green_on ^= 1; state++;break;
  case 10: red_on = 0; green_on ^= 0; state++;break;
  case 11: red_on = 1; green_on ^= 1; state++;break;
  case 12: red_on = 0; green_on ^= 0; state++;break;
  case 13: red_on = 1; green_on ^= 1; state = 0; break;
    
  default: state = 0; 
  }
  
  changed = 1;
  led_changed = changed;
  led_update();
}

void buzzer_state_advance(){
  if (switch_state_down){
      buzz_state_1_advance();
    } else {
    buzzer_set_period(0);
    }
}
void buzz_state_1_advance(){
  static char buzz_state = 0;
  switch(buzz_state){
  case 0: buzzer_set_period(3822); buzz_state++; break;
  case 1: buzzer_set_period(3214); buzz_state++; break;
  case 2: buzzer_set_period(2551); buzz_state=0; break;
  default: buzz_state = 0;
  } 
}
