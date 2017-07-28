#ifndef GAMEITEM_H
#define GAMEITEM_H

class GameItem {
	public:
		GameItem();
		virtual void move(char, GameItem * [999][999]);
		virtual void moveTo(int, int, GameItem * [999][999]);
		int getX();
		int getY();
		int getDirection();
		int getHp();
		virtual void contact(GameItem*);
		virtual void hit(int);
		virtual void delta(double, GameItem * [999][999], GameItem);
		void print();
		bool isBlocking();
	protected:
		virtual void kill();
		int x;
		int y;
		char direction;
		int speed;
		int hp;
		int power;
		char symbol;
		double deltaSum;
		bool dead;
		bool trigger;
};
#endif
