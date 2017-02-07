#ifndef Deck_h
#define Deck_h

#include "Card.h"
#define NUMCARDS 52
class Deck
{


public:
	Deck();
	void resetDeck();
	Card getNextCard();

private:
	Card _Cards[NUMCARDS];

	int _usedIndex[NUMCARDS];

};

#endif

