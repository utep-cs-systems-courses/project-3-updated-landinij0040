#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

void buzzer_init()
{
  /* 
       Direct timer A output "TA0.1" to P2.6.  
        According to table 21 from data sheet:
          P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero
          P2SEL.6 must be 1
        Also: P2.6 direction must be output
  */
  timerAUpmode();/* used to drive speaker */
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;/* enable output to speaker (P2.6) */
}

void buzzer_set_period(short cycles) /* buzzer clock = 2MHz.  (period of 1k results in 2kHz tone) */
{
  CCR0 = cycles;
  CCR1 = cycles >> 1;/* one half cycle */
}

int find_note_cycle(char note){
  switch(note){
  case 'A': return cycle_finder(440); break;// if note is 65 return cycle for A
  case 'B': return cycle_finder(493.88); break;// if note is 66 return cycle for B
  case 'C': return cycle_finder(523.25); break;// if note is 67 return cycle for C
  case 'D': return cycle_finder(587.33); break;// if note is 68 return cycle for D
  case 'E': return cycle_finder(659.25); break;// if note is 69 return cycle for E
  case 'F': return cycle_finder(698.46); break;// if note is 70 return cycle for F
  case 'G': return cycle_finder(783.99); break;// if note is 71 return cycle for G 
                            //if note is less than 65 return 0
  default: return 0; break; //if note is bigger than 72 return 0 
 }
}

int cycle_finder(int freq){
  return 2000000/freq;
}
