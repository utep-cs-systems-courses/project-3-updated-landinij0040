# makfile configuration
CPU             	= msp430g2553
CFLAGS          	= -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/ 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-gcc -mmcu=${CPU} -c

all:wakedemo.elf

#additional rules for files
wakedemo.elf: ${COMMON_OBJECTS} wakedemo.o wdt_handler.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd

wakedemo2.elf: ${COMMON_OBJECTS} wakedemo2.o wdt_handler.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd

buttontest.elf: ${COMMON_OBJECTS} buttontest.o buzzer.o wakedemo2.o wdt_handler.o colorChanger.o
	$(CC) $(CFLAGS) ${LDFLAGS} -o $@ $^ -lLcd -lp2sw -lTimer


# For the original demo
load: wakedemo.elf
	msp430loader.sh $^
# For what I want to be a project
load2: wakedemo2.elf
	msp430loader.sh $^
# Making sure I can see stuff from different folders
load3: buttontest.elf 
	msp430loader.sh $^
clean:
	rm -f *.o *.elf
