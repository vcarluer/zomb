#include "bullet.h"

Bullet::Bullet() {
	speed = 0.2;
	symbol = '*';
	power = 5;
	name = "Bullet";
	trigger = true;
}

void Bullet::contact(GameItem *contactItem) {
	contactItem->hit(power);
	this->kill();
}

void Bullet::kill() {
	ignoreMe = true;
	GameItem::kill();
	game->removeItem(index);
}
