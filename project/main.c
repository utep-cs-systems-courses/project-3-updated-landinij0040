#include <msp430.h>
#include <libTimer.h>
#include <lcdutils.h>
#include <lcddraw.h>
#include <p2switches.h>
#include "project.h"
#include "buzzer.h"

int main()
{
  configureClocks();
  lcd_init();
  buzzer_init();                
  p2sw_init(15);                // Initialize all switches
  or_sr(0x8);			// GIE (enable interrupts)
  clearScreen(0xf800);
  button_change();
}
