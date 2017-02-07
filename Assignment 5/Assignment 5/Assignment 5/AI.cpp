#include "ai.h"

AI::AI()
{
	::Player();
	
	/*
	The Carrier has 5 cells, Battleship has 4 cells, Cruiser has 3 cells, Submarine has 3 cells, and the Destroyer has 2 cells.
	*/

	_carrier->placeShipRandom(_boats);
	_battleship->placeShipRandom(_boats);
	_cruiser->placeShipRandom(_boats);
	_sub->placeShipRandom(_boats);
	_destroyer->placeShipRandom(_boats);

	_boats->displayGameBoard();

	
}