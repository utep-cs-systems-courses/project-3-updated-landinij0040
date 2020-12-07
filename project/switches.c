#include <msp430.h>
#include "switches.h"
#include "project.h"

static char
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);/* if switch down, sense up */
  return p2val;
}

void
switch_init()/* setup switch */
{
  P2REN |= SWITCHES;/* enables resistors for switches */
  P2IE |= SWITCHES;/* enable interrupts from switches */
  P2OUT |= SWITCHES;/* pull-ups for switches */
  P2DIR &= ~SWITCHES;/* set switches' bits for input */
  switch_update_interrupt_sense();
}

void button_change(){
  char p2val = switch_update_interrupt_sense();
  signed char test = 3;
  if(test == 3){
    test = (p2val & SW1) ? 3:0;// init the dropme
  }
  if(test == 3){
    test = (p2val & SW2) ? 3:1;// drop the dropme
  }
  if(test == 3){
    test = (p2val & SW3) ? 3:2;// pull the dropme
  }
  if(test == 3){
    test = (p2val & SW4) ? 3:-2;// the rainbow reset
  }
  switch_to_change_state(test);
  
}
