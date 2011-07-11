Target = quick
MainSources = quicksort.c

CC = gcc
CFLAGS = -Os -ffast-math -g -Wall -W --ansi --pedantic

DESTPATH = ./$(Target)$(SUF)

all:
	$(CC) $(CCFLAGS) $(MainSources) $(Objects) -o $(DESTPATH) $(LDFLAGS)

clean:
	@$(RM) $(DESTPATH)

.PHONY: all clean
