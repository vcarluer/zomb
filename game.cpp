#include <cstddef>
#include <ncurses.h>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "game.h"
#include "player.h"
#include "zombie.h"

void Game::play() {
	nodelay(stdscr, TRUE);
	char input;

	itemCount = 0;
	Player p;
	this->addItem(&p, 0, 5);
	srand ( time(NULL) );
	int zx, zy;
	for (int zc = 0; zc < 70; zc++) {
		zx = rand() % COLS;
		zy = (rand() % (LINES - 3)) + 3;
		Zombie *z = new Zombie();
		this->addItem(z, zx, zy);
	}

	clock_t start, current = clock();
	double delta = 0;
	int forI = 0;
	while (true) {
		start = clock();
		input = getch();
		if (input == 'u') {
			break;
		}

		if (input == 'k') {
			p.shoot();
		}

		p.move(input, map);

		for(forI = 0; forI < itemCount;forI++) {
			GameItem *item = items[forI];
			if (!item->isIgnore()) {
				item->delta(delta, map, p);
			}
		}

		erase();

		mvprintw(0, 0, "ZOMB!!! (press u to quit. zqsd to move)");
		mvprintw(1, 0, "HP: %d", p.getHp());
		GameItem *ti = items[itemCount - 1];
		//mvprintw(2, 0, "items: %d", itemCount);
		for(forI = 0; forI < itemCount;forI++) {
			GameItem *item = items[forI];
/*			if (forI < 2) {
				mvprintw(forI + 3, 0, "name: %s", item->getName());
				mvprintw(forI + 3, 15, "x: %d", item->getX());
				mvprintw(forI + 3, 25, "y: %d", item->getY());
				mvprintw(forI + 3, 35, "direction: %c", item->getDirection());
			}
*/
			if (!item->isIgnore()) {
				item->print();
			}
		}

		refresh();
		current = clock();
		delta = diffclock(current, start);
	}
}

double Game::diffclock(clock_t clock1,clock_t clock2)
{
    double diffticks=clock1-clock2;
	double diffms=(diffticks)/(CLOCKS_PER_SEC/1000);
	return diffms;
}

void Game::addItem(GameItem *gameItem, int x, int y) {
	items[itemCount] = gameItem;
	gameItem->moveTo(x, y, map);
	gameItem->setGame(this, itemCount);
	itemCount++;
}

void Game::removeItem(int idx) {
	/*GameItem *toDelete = items[idx];
	if (toDelete != NULL) {
		items[idx] = NULL;
		map[toDelete->getX()][toDelete->getY()] = NULL;
		delete toDelete;
	}
	*/
}
