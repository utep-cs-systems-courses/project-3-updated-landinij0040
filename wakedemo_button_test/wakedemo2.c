#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

#define LED_GREEN BIT6             // P1.6


short redrawScreen = 1;
u_int fontFgColor = COLOR_ORANGE;

void wdt_c_handler()
{
  static int secCount = 0;

  secCount ++;
  if (secCount == 10) {		/* once/sec */
    secCount = 0;
    fontFgColor = (fontFgColor == COLOR_ORANGE) ? COLOR_BLACK : COLOR_ORANGE;
    redrawScreen = 1;
  }
}
  

void main()
{
  P1DIR |= LED_GREEN;		/**< Green led on when CPU on */		
  P1OUT |= LED_GREEN;
  configureClocks();
  lcd_init();
  
  enableWDTInterrupts();      /**< enable periodic interrupt */
  or_sr(0x8);	              /**< GIE (enable interrupts) */
  
  static int rowChange = 30;
  clearScreen(COLOR_BLUE);
  while (1) {			/* forever */
    if (redrawScreen) {
      redrawScreen = 0;
      drawString8x12(30,rowChange, "DROP ME", fontFgColor, COLOR_BLUE);
      rowChange += 2; // Adding two to make the word go down
      if(rowChange == 140){
	fillRectangle(30,30,61,122, COLOR_BLUE);
	rowChange = 30;
      }
    }
    P1OUT &= ~LED_GREEN;	/* green off */
    or_sr(0x10);		/**< CPU OFF */
    P1OUT |= LED_GREEN;		/* green on */
  }
}
