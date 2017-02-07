#include "ship.h"

#include "toUpper.h"


using namespace std;

Ship::Ship(int hits, char des, string name)
{
	_hitPoints = hits;
	_damage = 0;
	_designator = des;
	_name = name;
}

int Ship::getDamage() const
{
	return _damage;
}

int Ship::getHits() const
{
	return _hitPoints;
}

void Ship::setHit(int hits)
{
	_hitPoints = hits;
}

void Ship::increaseDamage()
{
	_damage++;
}

void Ship::setDesignator(char des)
{
	_designator = des;
}

void Ship::placeShip(GameBoard *board)
{
	int x = 0;
	int y = 0;
	int size = board->getSize();

	string direction = "";

	bool success = false;

	while (!success)
	{
		board->displayGameBoard();
		cout << "Player please place the " << _name << " on the board\n Note"
			<< _name << " is " << _hitPoints << " units\n" << endl;

		cout << "please enter top / left Y coordiante: ";
		cin >> x;
		cin.clear();

		if (x < 0 || x >= size)
		{
			system("cls");
			cout << "invalid Y coordiante\nplease try again" << endl;
			system("pause");
			system("cls");
			continue;
		}

		cout << endl;


		cout << "please enter top / left X coordinate: ";
		cin >> y;
		cin.clear();

		if (y < 0 || y >= size)
		{
			system("cls");
			cout << "invalid X corrdiante\nplease try again" << endl;
			system("pause");
			system("cls");
			
			continue;
		}

		cout << endl;

		cout << "please enter direction(H for horizantal, V for vertical): ";
		cin >> direction;
		cin.clear();

		cout << endl;

		direction = toUpper(direction);

		
		
		if (direction == "V")
		{ //check vertical placement
			if (y < size + _hitPoints && x < size)
			{
				actualyPlace(board, x, y, direction);
				success = !success;
			}
			else
			{
				cout << "error vertical\n please try again" << endl;
				system("pause");
				system("cls");
			}
		}
		if (direction == "H")
		{
			if (x < size + _hitPoints && y < size)
			{
				actualyPlace(board, x, y, direction);
				success = !success;
			}
			else
			{
				cout << "error horizantal\n please try again" << endl;
				system("pause");
				system("cls");
			}
		}
		else
		{
			cout << "invalid direction\n please try again" << endl;
		}




	}
}

void Ship::actualyPlace(GameBoard *board, int x, int y, string dir)
{
	if (dir == "H")
	{ //Horizantal placement

		for (int i = 0; i < _hitPoints&& i < board->getSize(); i++)
		{
			try
			{
				board->setElement(x, y + i, _designator);
			}
			catch (...)
			{
				cout << "error..." << x << " " << y << "...aborting" << endl;
				system("pause");
				//abort();
			}
		}
		
	}

	else
	{ //Vertical placement

		for (int i = 0; i < _hitPoints&& i < board->getSize(); i++)
		{
			try
			{
				board->setElement(x + i, y, _designator);
			}
			catch (...)
			{
				cout << "error..."<< x << " " << y << "...aborting" << endl;
				system("pause");
				//abort();
			}
		}
	
	}

}

void Ship::placeShipRandom(GameBoard *board)
{
	
}

bool Ship::check(GameBoard *board, int x, int y, int shipSize, string direction)
{
	bool allClear = false;

	if (direction == "H")
	{
		// check horizantal
		int i = 0;
		bool clear = true;
		for (i = 0; i < shipSize && i < board->getSize(); i++)
		{
			if (clear && board->getElement(x+ i, y == '~'))
			{
				clear = true;
			}
			else
			{
				clear = false;
			}
		}

		if (i == shipSize)
		{
			allClear = clear;
		}


	}
	else
	{
		//check vertical

		int i = 0;
		bool clear = true;
		for (i = 0; i < shipSize && i < board->getSize(); i++)
		{
			if (clear && board->getElement(x, y + i == '~'))
			{
				clear = true;
			}
			else
			{
				clear = false;
			}
		}

		if (i == shipSize)
		{
			allClear = clear;
		}
	}

	return allClear;

}