#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
//#include <p2switches.h>
#include "project.h"
#include "triangle.h"
#include "buzzer.h"
#include "switches.h"


#define LED_GREEN BIT6  // P1.6
int rowChange = 10;     // To make the word drop
int color = 0xffff;     // Declare color to be white at first
short redrawScreen = 1; // For the watch dog interrupt
char signed state = 3;         // For Changing the state

void wdt_c_handler()
{
  static int secCount = 0;
  secCount ++;
  if (secCount == 10) {	  
    secCount = 0;
    redrawScreen = 1;
  }
}

void pull()
{
  if(rowChange == 10){                                   // stops the drop call       
    drawString8x12(35,rowChange, "DROP ME", color, 0xf800);
    color = 0xffff;                                       // put color back to white
    rowChange = 10;                                       // put row change back to 10 
  }else{
    fillRectangle (9  , rowChange + 10, 13, 10, 0xf800);     // Left side
    fillRectangle (109, rowChange + 10, 13, 10, 0xf800);     // Right side
    up_triangle   (15 , rowChange  , 7);                  // Left Triangle
    up_triangle   (115, rowChange  , 7);                  // Right Triangle
    drawString8x12(35 , rowChange, "DROP ME", 0xf800, 0xf800);
    buzzer_set_period(500 + rowChange * 5);
    rowChange -= 10;                                        // Adding ten to make the word go down
  }
}

void drop()
{
  color_changes();                                        // makes DROP ME a darker blue 
  if(rowChange == 160){                                   // stops the drop call       
    drawString8x12(35,rowChange, "DROP ME", color, 0xf800);
    color = 0xffff;                                       // put color back to white
    rowChange = 160;                                       // put row change back to 10 
  }else{
    fillRectangle (9  , rowChange - 10, 13, 10, 0xf800);     // Left side
    fillRectangle (109, rowChange - 10, 13, 10, 0xf800);     // Right side
    down_triangle (15 , rowChange + 7 , 7);                  // Left Triangle
    down_triangle (115, rowChange + 7 , 7);                  // Right Triangle
    drawString8x12(35 , rowChange, "DROP ME", color, 0xf800);
    buzzer_set_period(500 + rowChange * 5);
    rowChange += 10;                                        // Adding ten to make the word go down
  }
}


void easter_egg(){
  clearScreen(COLOR_RED);
  buzzer_set_period(note_to_cycle('G'));
  
  clearScreen(COLOR_PURPLE);
  buzzer_set_period(note_to_cycle('F'));

  clearScreen(COLOR_GOLD);
  buzzer_set_period(note_to_cycle('E'));

  clearScreen(COLOR_DEEP);
  buzzer_set_period(note_to_cycle('D'));
  
  clearScreen(COLOR_ORANGE_RED);
  buzzer_set_period(note_to_cycle('C'));
  
  clearScreen(COLOR_KHAKI);
  buzzer_set_period(note_to_cycle('B'));

  clearScreen(COLOR_STEEL_BLUE);
  buzzer_set_period(note_to_cycle('A'));
  
  clearScreen(COLOR_BLUE);
  buzzer_set_period(0);
}


int main()
{
  P1DIR |= LED_GREEN;		                             // < Green led on when CPU on 		
  P1OUT |= LED_GREEN;
  configureClocks();
  lcd_init();
  buzzer_init();
  enableWDTInterrupts();                                     //< enable periodic interrupt 
  or_sr(0x8);	                                             //< GIE (enable interrupts) 
  switch_init();
  clearScreen(0xf800);
  
  while (1) {			
    if (redrawScreen) {    
      redrawScreen = 0;                                       // so when the interrupt needs to
      switch(state){
      case -2:       // Rainbow init
	easter_egg();
	state = 3;
	break;
      case 0:        // Init Drop Me
	drawString8x12(35,0,"DROP ME", 0xffff, 0xf800);
	break;
      case 1:        // down drop
	//clearScreen(0);
	drop();
	break;
      case 2:        // pull drop
	pull();
	break;
      default:
	clearScreen(0xf800);
      }
    }
    P1OUT &= ~LED_GREEN;	/* green off */
    or_sr(0x10);		/**< CPU OFF */
    P1OUT |= LED_GREEN;		/* green on */
  }
}
