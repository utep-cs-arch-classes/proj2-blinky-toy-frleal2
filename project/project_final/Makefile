
# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: button.elf 

assembly: buttonA.elf

#additional rules for files
button.elf: ${COMMON_OBJECTS}wd_inthandlr.o led.o buzzer.o ledStates.o scales.o switches.o bbmain.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: button.elf
	mspdebug rf2500 "prog button.elf"

buttonA.elf: ${COMMON_OBJECTS} wd_inthandlr.o led.o buzzer.o st.o scales.o switches.o bbmain.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

loadA: buttonA.elf
	mspdebug rf2500 "prog buttonA.elf"

clean:
	rm -f *.o *.elf

bbmain.o: buzzer.h switches.h led.h 
led.o: switches.h led.h
switches.o: switches.h buzzer.h led.h scales.h
buzzer.o: buzzer.h
wd_inthandlr.o: switches.h scales.h
scales.o: scales.h buzzer.h switches.h
ledStates.o: switches.h ledStates.h led.h
st.o: ledStates.h switches.h led.h
