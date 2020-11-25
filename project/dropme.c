#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include <p2switches.h>
#include "project.h"
#include "triangle.h"
#include "buzzer.h"

#define LED_GREEN BIT6  // P1.6
int rowChange = 10;     // To make the word drop
int color = 0xffff;     // Declare color to be white at first
short redrawScreen = 1; // For the watch dog interrupt

void wdt_c_handler()
{
  static int secCount = 0;
  secCount ++;
  if (secCount == 10) {	  
    secCount = 0;
    redrawScreen = 1;
  }
}
  

void drop()
{
  P1DIR |= LED_GREEN;		                             // < Green led on when CPU on 		
  P1OUT |= LED_GREEN;  
  enableWDTInterrupts();                                     //< enable periodic interrupt 
  or_sr(0x8);	                                             //< GIE (enable interrupts) 

  while (1) {			
    if (redrawScreen) {
      color_changes();                                        // makes DROP ME a darker blue 
      redrawScreen = 0;                                       // so when the interrupt needs to
      
      if(rowChange == 160){                                   // stops the drop call       
	drawString8x12(35,rowChange, "DROP ME", color, 0xf800);
	color = 0xffff;                                       // put color back to white
	rowChange = 10;                                       // put row change back to 10 
	return;
      }else{
	fillRectangle(9  , rowChange - 10, 13, 10, 0xf800);     // Left side
	fillRectangle(109, rowChange - 10, 13, 10, 0xf800);     // Right side
	draw_triangle(15 , rowChange + 7 , 7);                  // Left Triangle
	draw_triangle(115, rowChange + 7 , 7);                  // Right Triangle
	drawString8x12(35, rowChange, "DROP ME", color, 0xf800);
	buzzer_set_period(500 + rowChange * 5);
	rowChange += 10;                                        // Adding ten to make the word go down
      }
    }
    P1OUT &= ~LED_GREEN;	/* green off */
    or_sr(0x10);		/**< CPU OFF */
    P1OUT |= LED_GREEN;		/* green on */
  }

  
}
