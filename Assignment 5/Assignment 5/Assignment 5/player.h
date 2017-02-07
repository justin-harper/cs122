#ifndef player_h
#define player_h

#include "gameboard.h"
#include "ship.h"

class Player
{
public:
	Player();
	void displayBoats();
	void displayShots();
	
	void placeShips();


private:


protected:
	GameBoard *_boats;
	GameBoard *_shots;

	Ship *_carrier;
	Ship *_battleship;
	Ship *_cruiser;
	Ship *_sub;
	Ship *_destroyer;

};



/*
The Carrier has 5 cells, Battleship has 4 cells, Cruiser has 3 cells, Submarine has 3 cells, and the Destroyer has 2 cells.

*/


#endif