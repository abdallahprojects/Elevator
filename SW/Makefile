#==== Main Options =============================================================

MCU = atmega32
F_CPU = 8000000
TARGET = main


#==== Compile Options ==========================================================

CFLAGS = -mmcu=$(MCU) -I.
CFLAGS += -DF_CPU=$(F_CPU)UL
CFLAGS += -Os
#CFLAGS += -mint8
#CFLAGS += -mshort-calls
CFLAGS += -funsigned-char
CFLAGS += -funsigned-bitfields
CFLAGS += -fpack-struct
CFLAGS += -fshort-enums
#CFLAGS += -fno-unit-at-a-time
CFLAGS += -Wall
CFLAGS += -Wstrict-prototypes
CFLAGS += -Wundef
#CFLAGS += -Wunreachable-code
#CFLAGS += -Wsign-compare
CFLAGS += -std=gnu99


#==== Programming Options (avrdude) ============================================

AVRDUDE_PROGRAMMER = usbasp

AVRDUDE_FLAGS = -p $(MCU) -c $(AVRDUDE_PROGRAMMER) 



#===============================================================================
#==== Targets ==================================================================

CC = avr-gcc
OBJCOPY = avr-objcopy
AVRDUDE = avrdude
REMOVE = rm -f

all:

	$(CC) -c $(CFLAGS) $(TARGET).c -o $(TARGET).o
	$(CC) $(CFLAGS) $(TARGET).o --output $(TARGET).elf
	$(OBJCOPY) -O ihex -j .text -j .data $(TARGET).elf $(TARGET).hex

program:
	$(AVRDUDE) $(AVRDUDE_FLAGS) -u -U flash:w:$(TARGET).hex

clean:
	$(REMOVE) "$(TARGET).hex"
	$(REMOVE) "$(TARGET).elf"
	$(REMOVE) "$(TARGET).o"