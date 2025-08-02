# Makefile per Transmon_Qubit_Simulator

CC = gcc
CFLAGS = -Wall -O2 -Isrc/include
SRC = src
OBJ = $(SRC)/resonator.o $(SRC)/main.o
TARGET = bin/resonator_test

all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p bin
	$(CC) -o $@ $^

$(SRC)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(SRC)/*.o $(TARGET)
