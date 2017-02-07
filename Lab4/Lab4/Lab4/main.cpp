#include "BlackJack.h"
#include "Card.h"
#include "Deck.h"
//#include <ostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <iomanip>



using namespace std;


int main(void)
{

	srand((unsigned int)time(NULL));
	playGame();

	/*Deck deck{};
	int i = 0;
	while ( i < 52)
	{
		cout << deck.getNextCard().getCommonName() << endl;
		i++;
	}
	*/


	return 0;
}





