#include <msp430.h>
#include "project.h"
/* Switch on P1 (S2) */
void
__interrupt_vec(PORT2_VECTOR) Port_1(){
  if (P2IFG & SWITCHES) {      /* did a button cause this interrupt? */
    P2IFG &= ~SWITCHES;      /* clear pending sw interrupts */
  }
}
