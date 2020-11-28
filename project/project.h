#ifndef project
#define project

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
void switch_to_change_state(signed char test);
#endif // project

