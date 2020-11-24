#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include <p2switches.h>
#include "project.h"
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
  P1DIR |= LED_GREEN;		  // < Green led on when CPU on 		
  P1OUT |= LED_GREEN;  
  enableWDTInterrupts();          //< enable periodic interrupt 
  or_sr(0x8);	                  //< GIE (enable interrupts) 
  
  while (1) {			
    if (redrawScreen) {
      color_changes();            // makes drop me a dark blue 
      redrawScreen = 0;  
      if(rowChange == 140){       // Go back to starting position
	rowChange = 140;          // Row is now back to orginal position
	drawString8x12(30,rowChange, "DROP ME", color, 0xf800);
	//drawTriangle
	//button_change();// call the state machine button
	color = 0xffff;// put color back to white
	rowChange = 10; // put row change back to 10 
	return;
      }else{
	drawString8x12(30,rowChange, "DROP ME", color, 0xf800);
	rowChange += 10;          // Adding ten to make the word go down
      }
    }
    P1OUT &= ~LED_GREEN;	/* green off */
    or_sr(0x10);		/**< CPU OFF */
    P1OUT |= LED_GREEN;		/* green on */
  }

  
}
