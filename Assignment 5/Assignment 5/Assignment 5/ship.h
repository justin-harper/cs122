#ifndef ship_h
#define ship_h

#include <vector>
#include <string>
#include <iostream>
#include "gameboard.h"




class Ship
{
public:
	//~ship();
	Ship();
	Ship(int hits, char des, string name);

	int getDamage() const;
	int getHits() const;

	void placeShip(GameBoard *board);

	void actualyPlace(GameBoard *board, int x, int y, string dir);

	void placeShipRandom(GameBoard *board);

	bool check(GameBoard *board, int x, int y, int shipSize, string direction);
	


protected:
	
	void setHit(int hits);
	void increaseDamage(void);
	void setDesignator(char des);

private:

	 int _hitPoints = 0;
	 int _damage = 0;
	 char _designator = '\0';
	 string _name = "";




};


#endif