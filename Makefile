OBJECTS = src/auxiliary.o src/quicksort.o src/lu.o src/main.o
TARGET = src/warmup

CC = gcc
CFLAGS = -Os -ffast-math -g -Wall -W --ansi --pedantic

all: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -f $(OBJECTS) *~ $(TARGET)

.PHONY: all clean
