#ifndef fiveCardPoker_h
#define fivewCardPoker_h

#include "Card.h"
#include "Deck.h"
#include "Hand.h"


class fiveCardPoker
{



public:
	fiveCardPoker();

	void playPoker();
	void changeCards(Hand *playerHand);

private:
	Deck _gameDeck;
	Hand _playerHand;
	Hand _dealerHand;



};





#endif
