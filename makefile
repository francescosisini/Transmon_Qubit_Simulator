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

OBJ = $(SRC:.c=.o)

all: simulatore

simulatore: $(OBJ)
	$(CC) $(CFLAGS) -o simulatore $(SRC)

clean:
	rm -f simulatore *.o src/*.o
