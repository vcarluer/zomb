#include <ncurses.h>
#include <cstring>
#include "title.h"

const char* text = "ZOMB!!";
const char* pressText = "Press a key";
void Title::show() {
	int baseLine = (LINES - 1) / 2;
	mvprintw(baseLine, getCenterX(text), text);
	baseLine++;
	mvprintw(baseLine, getCenterX(pressText), pressText);
	getch();
}

int Title::getCenterX(const char* text) {
	return COLS / 2 - strlen(text) / 2;
}
