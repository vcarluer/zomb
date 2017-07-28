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
	protected:
		virtual void kill();
		int x;
		int y;
		char direction;
		int speed;
		int hp;
};
