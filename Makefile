MAIN_TARGET=quicksort

CC = gcc
CFLAGS = -Os -ffast-math -g -Wall -W --ansi --pedantic

all: $(MAIN_TARGET)

clean:
	$(RM) -f *.o *~ $(MAIN_TARGET)

.PHONY: all clean
