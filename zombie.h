#include "gameitem.h"

class Zombie:public GameItem {
	public:
		Zombie();
		virtual void contact(GameItem *);
};
