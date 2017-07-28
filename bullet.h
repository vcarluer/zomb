#include "gameitem.h"

class Bullet:public GameItem{
	public:
		Bullet();
		virtual void contact(GameItem *);
		virtual void kill();
};
