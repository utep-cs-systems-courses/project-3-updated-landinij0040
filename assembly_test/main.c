#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

int main()
{
  configureClocks();
  lcd_init();
  clearScreen(COLOR_BLUE);
}
