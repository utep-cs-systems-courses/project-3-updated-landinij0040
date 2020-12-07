#ifndef switches_included
#define switches_included

#define SW1 1/* switch1 is p2.0 */
#define SW2 2           /* switch2 is p2.1 */
#define SW3 4           /* switch3 is p2.2 */
#define SW4 8           /* switch4 is p2.3 */
#define SWITCHES (SW1 | SW2 | SW3 | SW4)     /* all the switches*/
void switch_init();
void button_change();
#endif // included
