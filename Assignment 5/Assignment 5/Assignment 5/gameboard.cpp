#include "gameboard.h"
#include <iostream>

using namespace std;

GameBoard::GameBoard()
{
	vector<char> temp{ '~', '~', '~', '~', '~', '~', '~', '~', '~', '~' };
	for (int i = 0; i < SIZE; i++)
	{
		_board.push_back(temp);
		_size = SIZE;
	}
	
}


void GameBoard::displayGameBoard()
{
	string test = " ";
	for (int s = 0; s < _size; s++)
	{
		test += to_string(s) + " ";
		
		
	}

	cout << test << endl;

	for (int i = 0; i < _board.size(); i++)
	{
		cout << i;
		for (int j = 0; j < _board[i].size(); j++)
		{

			cout << _board[i][j] << " ";
		}

		cout << endl;
	}

}

int GameBoard::getSize() const
{
	return _size;
}

void GameBoard::setElement(int x, int y, char designator)
{
	if (_board[x][y] == '~')
	{

		_board[x][y] = designator;

	}
	else
	{
		throw out_of_range{"error alread a boat here"};
	}
}

char GameBoard::getElement(int x, int y)
{
	return _board[y][x];
}