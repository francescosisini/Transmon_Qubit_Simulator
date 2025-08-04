CC = gcc
CFLAGS = -Wall -lm -I./src/include

SRC = \
	main.c \
	src/analisi_dc.c \
	src/circuito.c \
	src/nodo.c \
	src/resistor.c \
	src/generator.c \
	src/transmon.c \
	src/resonator.c

all: simulatore

simulatore:
	$(CC) $(CFLAGS) -o simulatore $(SRC)

clean:
	rm -f simulatore
