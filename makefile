CC=g++
CFLAGS=-I.
DEP=-lncurses

zombmake: zomb.o title.o player.o game.o
	$(CC) $(DEP) -o zomb title.cpp game.cpp player.cpp zomb.cpp $(CFLAGS)
