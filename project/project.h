#ifndef project
#define project

// For the switches
// #define SW1 0x01
// #define SW2 0x02
// #define SW3 0x04
// #define SW4 0x08
// #define SWITCHES (SW1 | SW2 | SW3 | SW4)
void drop(); // executing the drop

extern int rowChange; // for changing the row of drop me

// For Changing the Colors Of Drop Me
extern int color;
void color_changes();

// For changing the state of the system based on the buttons pressed
void button_change();
void restart_state();
void easter_egg();

// For changing the state
extern signed char state;
void switch_to_change_state(signed char test);
#endif // project

