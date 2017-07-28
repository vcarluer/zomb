#ifndef GAMEITEM_H
#define GAMEITEM_H
class GameItem {
	public:
		GameItem();
		virtual void move(int, int);
		int getX();
		int getY();
		int getDirection();
		virtual void contact(GameItem);
		virtual void hit(int);
		virtual void delta(double);
		void print();
	protected:
		virtual void kill();
		int x;
		int y;
		char direction;
		int speed;
		int hp;
		char symbol;
		double deltaSum;
};
#endif
