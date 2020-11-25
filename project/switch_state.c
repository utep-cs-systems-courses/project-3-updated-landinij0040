#include <msp430.h>
#include <libTimer.h>
#include <lcdutils.h>
#include <lcddraw.h>
#include <p2switches.h>
#include "project.h"
#include "buzzer.h"

void restart_state();
void button_change(){
  while(1){
    signed char test = 2;              // do nothing
    if(test == 2){
      test = (p2sw_read() & 1) ? 2:0;  // if the first button was pushed
    }
    if(test == 2){
      test = (p2sw_read() & 2) ? 2:1;  // if the second button was pushed
    }
    if(test == 2){
       test = (p2sw_read() & 4) ? 2:-2; // if the third button was pushed
    }
    switch(test){
    case -2: easter_egg(); break;                    // easter egg
    case 0: restart_state(); break;    // restart state
    case 1: drop(); break;             // drop state
    default: break;                    // do nothing
    }
  }
}
  
void restart_state(){
  // Make the buzzer be quite
  buzzer_set_period(0);
  // Redraw the the screen to be blue
  clearScreen(0xf800);
  // redraw the Drop me
  drawString8x12(35,0,"DROP ME", 0xffff, 0xf800);
  // redraw the triangles
  // redraw the left 
}

void easter_egg(){
  clearScreen(COLOR_RED);
  buzzer_set_period(find_note_cycle('G'));
  
  clearScreen(COLOR_PURPLE);
  buzzer_set_period(find_note_cycle('F'));

  clearScreen(COLOR_GOLD);
  buzzer_set_period(find_note_cycle('E'));

  clearScreen(COLOR_DEEP);
  buzzer_set_period(find_note_cycle('D'));
  
  clearScreen(COLOR_ORANGE_RED);
  buzzer_set_period(find_note_cycle('C'));
  
  clearScreen(COLOR_KHAKI);
  buzzer_set_period(find_note_cycle('B'));

  clearScreen(COLOR_STEEL_BLUE);
  buzzer_set_period(find_note_cycle('A'));
  clearScreen(COLOR_BLUE);
  buzzer_set_period(0);
}
