#include <ncurses.h>
#include <ctime>
#include "game.h"
#include "player.h"

void Game::play() {
	nodelay(stdscr, TRUE);
	char input;

	Player p;
	int newX = 5;
	int newY = 5;
	int headerH = 1;
	clock_t start, current = clock();
	double delta = 0;
	while (true) {
		current = clock();
		delta = diffclock(current, start);
		start = clock();
		input = getch();
		if (input == 'u') {
			break;
		}

		switch(input) {
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

		if (newX < 0) { newX = 0; }
		if (newX > COLS - 1) { newX = COLS - 1; }
		if (newY < headerH) { newY = headerH; }
		if (newY > LINES - 1) { newY = LINES - 1; }
		p.move(newX, newY);

		erase();

		mvprintw(0, 0, "ZOMB!!! (press u to quit. zqsd to move)");
		mvaddch(p.getY(), p.getX(), '@');
		refresh();
	}
}

double Game::diffclock(clock_t clock1,clock_t clock2)
{
    double diffticks=clock1-clock2;
	double diffms=(diffticks)/(CLOCKS_PER_SEC/1000);
	return diffms;
}

