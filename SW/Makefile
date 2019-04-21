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

AVRDUDE_PROGRAMMER = stk500v1
AVRDUDE_PORT = /dev/ttyUSB0
AVRDUDE_BAUD = 19200

AVRDUDE_FLAGS = -p $(MCU) -P $(AVRDUDE_PORT) -b $(AVRDUDE_BAUD) -c $(AVRDUDE_PROGRAMMER)



#===============================================================================
#==== Targets ==================================================================

CC = avr-gcc
OBJCOPY = avr-objcopy
AVRDUDE = avrdude
REMOVE = rm -f

all: build

build:
	$(CC) -c $(CFLAGS) ..\..\$(TARGET).c -o $(TARGET).o
	$(CC) $(CFLAGS) $(TARGET).o --output $(TARGET).elf
	$(OBJCOPY) -O ihex -j .text -j .data $(TARGET).elf $(TARGET).hex

program:
	$(AVRDUDE) $(AVRDUDE_FLAGS) $(AVRDUDE_WRITE_FLASH) -U flash:w:$(TARGET).hex

clean:
	$(REMOVE) "$(TARGET).hex"
	$(REMOVE) "$(TARGET).elf"
	$(REMOVE) "$(TARGET).o"