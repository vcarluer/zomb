#include "gameitem.h"


GameItem::GameItem() {
	x = 0;
	y = 0;
	direction = 'd';
}

void GameItem::move(int newX, int newY) {
	x = newX;
	y = newY;
}

int GameItem::getX() {
	return x;
}

int GameItem::getY() {
	return y;
}

int GameItem::getDirection() {
	return direction;
}

void GameItem::contact(GameItem) {
}

void GameItem::hit(int damage) {
	hp -= damage;
}

void GameItem::delta(double) {

}
void GameItem::kill() {

}
