#include "Deck.h"
#include "Card.h"
#include <time.h>
#include <ostream>
#include <string>



using namespace std;



int main(void)
{
	srand((unsigned int)time(NULL));

	Deck newDeck{};
	Card card;
	string x = "";


	//card = newDeck.getNextCard();

	//x = card.getRankName();

	//cout << x;
	
	
	for (int i = 0; i < 52; i++)
	{
		card = newDeck.getNextCard();
		x = card.getRankName() + " of " + card.getSuitName();
		cout << x << endl;
		//x = "";
	}

	//cout << "hello" << endl;
	return 0;
}