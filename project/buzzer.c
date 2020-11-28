#include <math.h>
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

int cycle_finder(int freq){
  return 2000000/freq;
}

int freq_finder(int note)
{
  int freqRet = 0; 
  switch(note){
  case'A': freqRet = 440 ;break;
  case'B': freqRet = 449; break;
  case'C': freqRet = 523; break;
  case'D': freqRet = 587; break;
  case'E': freqRet = 655; break;
  case'F': freqRet = 698; break;
  case'G': freqRet = 783; break;
  }
  return freqRet;
}


