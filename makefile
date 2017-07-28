CC=g++
CFLAGS=-I.
DEP=-lncurses

zombmake: zomb.o title.o gameitem.o player.o game.o
	$(CC) $(DEP) -o zomb title.cpp game.cpp gameitem.cpp player.cpp zomb.cpp $(CFLAGS)
