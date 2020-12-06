# makfile configuration
CPU             	= msp430g2553
CFLAGS          	= -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/ 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-gcc -mmcu=${CPU} -c

all:project.elf

project.elf: ${COMMON_OBJECTS} buzzer.o main.o wdt_handler.o colorChanger.o switch_state.o triangle.o state_switcher_A.o music_A.o p2_interrupt_handler.c
	$(CC) $(CFLAGS) ${LDFLAGS} -o $@ $^ -lLcd -lp2sw -lTimer

load: project.elf 
	msp430loader.sh $^
clean:
	rm -f *.o *.elf
