#ifndef buzzer_included
#define buzzer_included
void buzzer_init      (            );
void buzzer_set_period(short cycles);

/**
 * finds the cycle depending on the letter note 
 */
int  note_to_cycle    (char note   );
int  cycle_finder     (int freq    );
int  freq_finder      (int note    );
#endif  //included
