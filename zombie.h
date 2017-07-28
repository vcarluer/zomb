#include "gameitem.h"
#include "player.h"

class Zombie:public GameItem {
	public:
		Zombie();
		virtual void contact(GameItem *);
		virtual void delta(double, GameItem * [999][999], GameItem);
		virtual void kill();
};
