#include <ncurses.h>
#include "gameitem.h"


GameItem::GameItem() {
	x = 0;
	y = 1;
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

void GameItem::delta(double deltaValue) {
	deltaSum += deltaValue;
	if (speed != 0 && deltaSum / 1000 >= speed) {
		int newX = x;
		int newY = y;

		switch(direction) {
			case 'd':
				newX++;
				break;
			case 'q':
				newX--;
				break;
			case 'z':
				newY--;
				break;
			case 's':
				newY++;
				break;
		}

		x = newX;
		y = newY;
		deltaSum = 0;
	}
}

void GameItem::kill() {

}

void GameItem::print() {
	mvaddch(y, x, symbol);
}
