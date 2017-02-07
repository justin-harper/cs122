#include "Deck.h"

Deck::Deck()
{
	int rank, suit, num = 0;

	for (rank = 1; rank <= NUMCARDS / 4; rank++)
	{
		for (suit = Club; suit <= Spade; suit++)
		{
			_Cards[num] = Card((Suit_t)suit, (Rank_t)rank);
			num++;
		}
		
	}

	resetDeck(); // just to ensure that all the values of _usedIndex are 0

}

Card Deck::getNextCard()
{
	int x = rand() % 52;
	Card card;
	if (_usedIndex[x] != 1)
	{

		card = _Cards[x];
		_usedIndex[x] = 1;
	}
	else
	{
		card = getNextCard();
	}
	return card;

}

void Deck::resetDeck(void)
{

	for (int i = 0; i < NUMCARDS; i++)
	{
		_usedIndex[i] = 0;
	}
}