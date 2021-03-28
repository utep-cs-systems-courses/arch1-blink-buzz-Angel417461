#include "led.h"
#include "switches.h"
#include "buzzer.h"

void switchSM(){
  if (ssd1) red_on ^= 1;
  else red_on = 0;
  if(ssd2) green_on ^= 1;
  else green_on = 0;
  if (ssd3 && !ssd1) buzzer_set_period(2000);
  else if (ssd3 && ssd1) buzzer_set_period(1000);
  else buzzer_set_period(0);

  led_changed = 1;
  led_update();
}

void state_machine_1(){
  static char state = 0;
  switch (state){
  case 0: red_on = 1; state++; break;
  }
}
