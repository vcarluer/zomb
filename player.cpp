#include "player.h"
#include "bullet.h"

Player::Player() {
	symbol = '@';
	hp = 100;
	name = "Player";
	speed = 0;
}

void Player::kill() {
	GameItem::kill();
	symbol = 'X';
}

void Player::shoot() {
	Bullet *bullet = new Bullet();
	bullet->setDirection(direction);
	int bX = x;
	int bY = y;
	switch (direction) {
		case 'd':
			bX++;
			break;
		case 'q':
			bX--;
			break;
		case 'z':
			bY--;
			break;
		case 's':
			bY++;
			break;
	}

	game->addItem(bullet, bX, bY);
}
