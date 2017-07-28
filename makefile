CC=g++
CFLAGS=-I.
DEP=-lncurses

zombmake: zomb.o title.o
	$(CC) $(DEP) -o zomb title.cpp zomb.cpp $(CFLAGS)
