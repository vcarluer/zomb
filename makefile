CC=g++
CFLAGS=-I.
DEP=-lncurses

zombmake: zomb.o title.o gameitem.o player.o zombie.o bullet.o game.o
	$(CC) $(DEP) -o zomb title.cpp game.cpp gameitem.cpp player.cpp zombie.cpp bullet.cpp zomb.cpp $(CFLAGS)
