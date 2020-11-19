#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

void colorScreen(u_char col, u_char row, int color);

int main()
{
  configureClocks();
  lcd_init();
  clearScreen(COLOR_BLUE);
  u_char col = 20;
  u_char row = 20;
  colorScreen(col, row, COLOR_MAGENTA);
  //int i = 0;
  //whileLoop:
  //if(i == 100) goto end;
  //drawPixel(col, row, COLOR_MAGENTA);
  // col++;
  // i++;
  // goto whileLoop;
  // end: return 0;
  
  // while(i < 100){
    // drawPixel(col, row, COLOR_MAGENTA);
    // col++;
    //  i++;
    // }
  
  // for(int i = 0; i < 100; i++)
  //   drawPixel(col + i, row, COLOR_MAGENTA);
  
}
