CC = gcc
CFLAGS = -Os -ffast-math -g -Wall -W --ansi --pedantic

all: quicksort

clean:
	@$(RM) $(DESTPATH)

.PHONY: all clean
