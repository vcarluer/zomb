#include <ncurses.h>
#include <ctime>
#include "game.h"
#include "player.h"
#include "zombie.h"

void Game::play() {
	nodelay(stdscr, TRUE);
	char input;

	GameItem *map [999][999];
	GameItem items [2];
	Player p;
	p.moveTo(0,5, map);
	items[0] = p;
	Zombie z;
	z.moveTo(1,6, map);
	items[1] = z;

	clock_t start, current = clock();
	double delta = 0;
	while (true) {
		start = clock();
		input = getch();
		if (input == 'u') {
			break;
		}

		p.move(input, map);
		z.delta(delta, map);

		erase();

		mvprintw(0, 0, "ZOMB!!! (press u to quit. zqsd to move)");
		mvprintw(1, 0, "HP: %d", p.getHp());
		p.print();
		z.print();
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

