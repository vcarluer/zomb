#include <cstddef>
#include <ncurses.h>
#include "gameitem.h"

GameItem::GameItem() {
	x = 0;
	y = 1;
	direction = 'd';
	name = "GameItem";
	ignoreMe = false;
}

void GameItem::moveTo(int newX, int newY, GameItem *map[999][999]) {
	int headerH = 2;

	if (newX < 0) { newX = 0; }
	if (newX > COLS - 1) { newX = COLS - 1; }
	if (newY < headerH) { newY = headerH; }
	if (newY > LINES - 1) { newY = LINES - 1; }

	bool authorizedMove = true;
	GameItem *contactItem = map[newX][newY];
	if (contactItem != NULL && contactItem != this) {
		// contactItem->contact(this);
		this->contact(contactItem);
		authorizedMove = !(contactItem->isBlocking());
	} 

	if (authorizedMove) {
		map[x][y] = NULL;
		x = newX;
		y = newY;
		map[x][y] = this;
	}
}

void GameItem::move(char dirMove, GameItem *map[999][999]) {
	if (dirMove == 'd' || dirMove == 'q' || dirMove == 'z' || dirMove == 's') {
		int newX = x;
		int newY = y;

		direction = dirMove;
		if (!dead) {
			switch(dirMove) {
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

			moveTo(newX, newY, map);
		}
	}
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

void GameItem::setDirection(char newDirection) {
	direction = newDirection;
}

void GameItem::contact(GameItem *contactItem) {
}

void GameItem::hit(int damage) {
	if (hp > 0) {
		hp -= damage;
		if (hp <= 0) {
			hp = 0;
			kill();
		}
	}
}

void GameItem::delta(double deltaValue, GameItem *map [999][999], GameItem player) {
	deltaSum += deltaValue;
	if (speed > 0 && deltaSum / 1000 >= speed) {
		nodelay(stdscr, TRUE);
		move(direction, map);
		deltaSum = 0;
	}
}

void GameItem::kill() {
	dead = true;
}

void GameItem::print() {
	mvaddch(y, x, symbol);
}

int GameItem::getHp() {
	return hp;
}

bool GameItem::isBlocking() {
	return !(trigger || dead || ignoreMe);
}

void GameItem::setGame(Game *newGame, int idx) {
	game = newGame;
	index = idx;
}

const char* GameItem::getName() {
	return name;
}

bool GameItem::isIgnore() {
	return ignoreMe;
}
