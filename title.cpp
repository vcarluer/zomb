#include <ncurses.h>
#include <cstring>
#include "title.h"

const char* text = "ZOMB!!";
void Title::show() {
	mvprintw((LINES - 1) / 2, COLS / 2 - strlen(text) / 2, text);
	getch();
}
