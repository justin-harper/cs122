#ifndef gameboard_h
#define gameboard_h

#include <vector>
#include <string>

#define SIZE 10 //define the size of the gameboard (SIZE X SIZE)

using namespace std;
class GameBoard
{
public:
	GameBoard();
	int getSize() const;

	void displayGameBoard(void);

	void setElement(int x, int y, char designator);
	char getElement(int x, int y);


private:
	vector<vector<char>> _board;
	//vector<string> _test{ "~" }
	int _size;

protected:



};



#endif