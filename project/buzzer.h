#ifndef buzzer_included
#define buzzer_included
void buzzer_init();
void buzzer_set_period(short cycles);
int find_note_cycle(char note);
int cycle_finder(int freq);
#endif // included
