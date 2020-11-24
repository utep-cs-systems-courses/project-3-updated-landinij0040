#include <libTimer.h>
#include <lcdutils.h>
#include <lcddraw.h>
#include <p2switches.h>
#include "project.h"

void main()
{
  configureClocks();
  lcd_init();
  p2sw_init(15);
  or_sr(0x8);			/* GIE (enable interrupts) */

  clearScreen(1111100000000000);
  drawString8x12(30,0, "DROP ME", 0xffff, 1111100000000000);
  while(1){
    int execute = (p2sw_read() & 1) ? 0 : 1;
    if(execute){
      drop(); // Calling the drop method
    }    
  }
  
}
