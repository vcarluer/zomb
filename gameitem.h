#ifndef GAMEITEM_H
#define GAMEITEM_H
#include "game.h"

class GameItem {
	public:
		GameItem();
		virtual void move(char, GameItem * [999][999]);
		virtual void moveTo(int, int, GameItem * [999][999]);
		int getX();
		int getY();
		int getDirection();
		void setDirection(char);
		int getHp();
		bool isIgnore();
		virtual void contact(GameItem*);
		virtual void hit(int);
		virtual void delta(double, GameItem * [999][999], GameItem);
		void print();
		bool isBlocking();
		void setGame(Game*, int);
		const char* getName();
	protected:
		virtual void kill();
		int x;
		int y;
		char direction;
		double speed;
		int hp;
		int power;
		char symbol;
		double deltaSum;
		bool dead;
		bool trigger;
		Game *game;
		const char* name;
		int index;
		bool ignoreMe;
};
#endif
