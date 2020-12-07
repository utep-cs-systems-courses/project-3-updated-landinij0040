#include <msp430.h>
#include <libTimer.h>
#include <lcdutils.h>
#include <lcddraw.h>
//#include <p2switches.h>
#include "project.h"
#include "buzzer.h"

void restart_state();




/**
 * Restarts the state 
 */  
void restart_state(){
  // Make the buzzer be quite
  buzzer_set_period(0);
  // Redraw the the screen to be blue
  clearScreen(0xf800);
  // redraw the Drop me
  drawString8x12(35,0,"DROP ME", 0xffff, 0xf800); 
}

/**
 * Displays rainbow color screen
 */

