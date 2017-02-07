#ifndef Hand_t
#define Hand_t

#include "Deck.h"
#include "Card.h"
#include <iostream>
#include <string>



class Hand
{

private:
	Card _cards[5];
	

public:
	Hand();
	void setCard(int position, Card card);
	Card getCard(int positon);
	Card highCard(void);
	bool hasPair();
	bool has2Pair();
	bool has3OfAKind();
	bool hasStraight();
	bool hasFlush();
	bool hasFullHouse();
	bool has4OfAKind();
	void bubbleSort();

	void displayHand() const;

};


#endif