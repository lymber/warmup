OBJECTS = quicksort.o lu.o main.o
TARGET = warmup

CC = gcc
CFLAGS = -Os -ffast-math -g -Wall -W --ansi --pedantic

all: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) -f *.o *~ $(TARGET)

.PHONY: all clean
