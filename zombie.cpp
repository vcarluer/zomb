#include "zombie.h"

Zombie::Zombie() {
	symbol = 'z';
	speed = 1;
	hp = 10;
	power = 10;
}

void Zombie::contact(GameItem *contactItem) {
	contactItem->hit(power);
}
