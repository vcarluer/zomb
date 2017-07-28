#include "player.h"

Player::Player() {
	symbol = '@';
	hp = 100;
}

void Player::kill() {
	GameItem::kill();
	symbol = 'X';
}
