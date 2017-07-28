#ifndef GAME_H
#define GAME_H
#include <ctime>
// #include "gameitem.h"
class GameItem;

class Game {
	public:
		void play();
		void addItem(GameItem*, int, int);
		void removeItem(int);
	private:
		double diffclock(clock_t, clock_t);
		GameItem *map [999][999];
		GameItem *items [999];
		int itemCount;
};
#endif
