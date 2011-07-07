# Makefile para o exercício-programa de MATIV

Target = quick
# Objects = funcoes.o
# ObjectSources = funcoes.c
MainSources = quicksort.c

# Općões genéricas do compilador
CXX = gcc
CXXFLAGS = -O0 -ffast-math -g -Wall -W --ansi --pedantic

# Alvo default é Linux
all: all_linux

ifeq ($(HOSTTYPE), x86_64)
LIBSELECT=64
endif

# Configuraćões específicas de cada alvo
all_linux: LDFLAGS=-lm
all_linux clean_linux: SYSTEM=Linux
all_win32: LDFLAGS=-lm
all_win32 clean_win32: SYSTEM=Win32-gcc
all_win32 clean_win32: SUF=.exe
# Nome do binário - Válido para alvos que definem SYSTEM
DESTPATH = ./$(Target)$(SUF)

all_linux all_win32:
#	$(warning Building objects...)
#Gerando os objects
#	$(CXX) -c $(CXXFLAGS) $(ObjectSources) -o $(Objects)
	$(warning Building quick...)
	$(CXX) $(CXXFLAGS) $(MainSources) $(Objects) -o $(DESTPATH) $(LDFLAGS)

clean: clean_linux clean_win32
	$(warning Cleaning...)

clean_linux clean_win32:
	@$(RM) $(DESTPATH)

.PHONY: all all_win32 clean clean_linux clean_win32
