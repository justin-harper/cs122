#ifndef Deck_h
#define Deck_h

#include "Card.h"
#define NUMCARDS 52
class Deck
{
	private:
		
		
		Card _Cards[NUMCARDS];

		int _usedIndex[NUMCARDS];

	public:
		Deck();
		void resetDeck();
		Card getNextCard();

};

#endif

