#ifndef PLAYER_H
#define PLAYER_H
#include "gameitem.h"

class Player: public GameItem {
	public:
		Player();
		virtual void kill();
		void shoot();
};
#endif
