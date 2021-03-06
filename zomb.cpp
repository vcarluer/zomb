#include <ncurses.h>
#include <ctime>
#include <cstring>
#include "title.h"
#include "game.h"

using namespace std;


double diffclock(clock_t clock1,clock_t clock2)
{
    double diffticks=clock1-clock2;
	double diffms=(diffticks)/(CLOCKS_PER_SEC/1000);
	return diffms;
}

int main() {
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);

	Title t;
	t.show();

	Game g;
	g.play();

/*	bool cont = true;
	const char *info = "huhu (press q)";
	mvprintw((LINES - 1) / 2, COLS/ 2 - strlen(info) / 2, info);
	int xPos = 0;
	clock_t start = clock();
	while (cont) {
		clock_t current = clock();
		int ch = getch();
		if (ch == 'q') {
			cont = false;
		} else {
			double diff = diffclock(current, start);
			if (diff >= 1000) {
				erase();
				mvprintw((LINES - 1) / 2, COLS/ 2 - strlen(info) / 2, info);
				start = clock();
				mvaddch(0, xPos, '.');
				xPos++;
				if (xPos > COLS - 1) {
					xPos = 0;
				}
			}
		}
		
		refresh();
	}
*/	
	endwin();
	return 0;
}
