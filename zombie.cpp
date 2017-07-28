#include <cmath>
#include "zombie.h"

Zombie::Zombie() {
	symbol = 'Z';
	speed = 1;
	hp = 10;
	power = 10;
	name = "Zombie";
}

void Zombie::contact(GameItem *contactItem) {
	contactItem->hit(power);
}

void Zombie::delta(double delta, GameItem *map [999][999], GameItem player) {
	int xDiff = player.getX() - x;
	int yDiff = player.getY() - y;
	if (std::abs(xDiff) > std::abs(yDiff)) {
		if (xDiff > 0) {
			direction = 'd';
		} else {
			direction = 'q';
		}
	} else {
		if (yDiff > 0) {
			direction = 's';
		} else {
			direction = 'z';
		}
	}

	GameItem::delta(delta, map, player);
}

void Zombie::kill() {
	GameItem::kill();
	symbol = 'x';
}
