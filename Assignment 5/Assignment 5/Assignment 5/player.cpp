#include "player.h"

using namespace std;

Player::Player()
{
	_boats = new GameBoard();
	_shots = new GameBoard();

	/*
	The Carrier has 5 cells, Battleship has 4 cells, Cruiser has 3 cells, Submarine has 3 cells, and the Destroyer has 2 cells.
	*/

	_carrier	= new Ship{ 5, 'C', "Carrier" };
	_battleship = new Ship{ 4, 'B', "Battleship" };
	_cruiser	= new Ship{ 3, 'R', "Cruiser" }; //R for cursier for some reason
	_sub		= new Ship{ 3, 'S', "Submarine" };
	_destroyer	= new Ship{ 2, 'D', "Destroyer" };
}

void Player::displayBoats()
{
	_boats->displayGameBoard();
}

void Player::displayShots()
{
	_shots->displayGameBoard();
}

void Player::placeShips()
{
	
	_carrier->placeShip(_boats);
	
	system("pause");
	system("cls");
	
	
	_battleship->placeShip(_boats);
	
	system("pause");
	system("cls");
	
	
	_cruiser->placeShip(_boats);
	
	system("pause");
	system("cls");
	
	
	_sub->placeShip(_boats);
	
	system("pause");
	system("cls");
	
	
	_destroyer->placeShip(_boats);
	
	system("pause");
	system("cls");
}
