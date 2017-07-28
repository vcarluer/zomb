#include <ncurses.h>
#include "game.h"
#include "player.h"

void Game::play() {
	nodelay(stdscr, TRUE);
	char input;

	Player p;
	p.x = 5;
	p.y = 5;
	int headerH = 1;
	while (true) {
		input = getch();
		if (input == 'u') {
			break;
		}

		switch(input) {
			case 'd':
				p.x++;
				break;
			case 'q':
				p.x--;
				break;
			case 'z':
				p.y--;
				break;
			case 's':
				p.y++;
				break;
		}

		if (p.x < 0) { p.x = 0; }
		if (p.x > COLS - 1) { p.x = COLS - 1; }
		if (p.y < headerH) { p.y = headerH; }
		if (p.y > LINES - 1) { p.y = LINES - 1; }

		erase();

		mvprintw(0, 0, "ZOMB!!! (press u to quit. zqsd to move)");
		mvprintw(p.y, p.x, "O");
	}
}
