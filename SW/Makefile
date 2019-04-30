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
#============== External Directories ===========================================
EXT =

#===============================================================================
#==== Targets ==================================================================
# Read main src file
SRC = $(TARGET).c

# Read All C files
CFILES    = $(filter %.c, $(SRC))
EXTC     := $(foreach dir, $(EXT), $(wildcard $(dir)/*.c))
SRCS = $(CFILES) $(EXTC)
# Convert them to Object files in OBJ
OBJ = $(CFILES:.c=.o) $(EXTC:.c=.o)

#================================================================================
CC = avr-gcc
OBJCOPY = avr-objcopy
AVRDUDE = avrdude
REMOVE = rm -f
SIZE = avr-size --format=avr --mcu=$(MCU)

#to do all, there is a prerequisites the hex file, if the hex file doesn't exist, make will
#look for a rule to build the hex file
all:$(TARGET).hex

	$(CC) -c $(CFLAGS) $(TARGET).c -o $(TARGET).o
	$(CC) $(CFLAGS) $(TARGET).o --output $(TARGET).elf
	

# Rule to build the hex file, requires the elf file to exist as a prerequisite, if the elf doesn't exit
# look for a rule to build it
$(TARGET).hex: $(TARGET).elf
	rm -f $(TARGET).hex
	$(OBJCOPY) -O ihex -j .text -j .data $(TARGET).elf $(TARGET).hex
	$(SIZE) $(TARGET).elf
# Rule to build the elf file, requires all the objects files to exist and up to date, otherwise look for
# a rule to build the object files
$(TARGET).elf: $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET).elf $(OBJ)
	
# Rule to build objects from c files
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@
	
program:
	$(AVRDUDE) $(AVRDUDE_FLAGS) -u -U flash:w:$(TARGET).hex

clean:
	$(REMOVE) $(TARGET).hex
	$(REMOVE) $(TARGET).elf
	$(REMOVE) $(OBJ)