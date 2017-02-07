#include "Hand.h"

Hand::Hand()
{

	return;
}

void Hand::setCard(int position, Card card)
{
	_cards[position] = card;


	return;
}

Card Hand::getCard(int position)
{
	
	return _cards[position];
}

Card Hand::highCard()
{
	Card card = _cards[0];

	for (int i = 1; i < 5; i++)
	{
		if (_cards[i].getRank() > card.getRank())
		{
			card = _cards[i];
		}

	}

	return card;

}

bool Hand::hasPair(void)
{
	//the hand should be bubble sorted before using this function!
	
	bool hasPair = false;
	

	//then check if any two cards in the _cards array have the same rank



	for (int k = 0; k < (sizeof(_cards)/sizeof(Card))-1; k++)
	{
		if (_cards[k].getRank() == _cards[k+1].getRank())
		{
			hasPair = true;
			cout << "you have a pair; Cards: " << k + 1 << " and " << k + 2 << endl;
		}
	}
	


	return hasPair;
}

void Hand::bubbleSort(void)
{
	int i = 0, j = 0, flag = 1;
	Card temp;
	for (i = 0; i < (sizeof(_cards)/sizeof(Card)) && flag; i++)
	{
		flag = 0;
		for (j = 0; j < (sizeof(_cards)/sizeof(Card))-1; j++)
		{
			if (_cards[j + 1].getRank() > _cards[j].getRank())
			{
				temp = _cards[j];
				_cards[j] = _cards[j + 1];
				_cards[j + 1] = temp;
				flag = 1;
			}
		}
	}

}

void Hand::displayHand(void) const
{

	/*int x = sizeof(_cards)/sizeof(Card);

	cout << x << endl;*/

	for (int i = 0; i < sizeof(_cards)/sizeof(Card); i++)
	{
		cout << i+1 <<": " <<_cards[i].getCommonName() << endl;
	}

}

bool Hand::has2Pair(void)
{
	//the hand should be bubble sorted before using this function!

	bool has2Pair = false;
	int pairs = 0;


	//then check if any two cards in the _cards array have the same rank



	for (int k = 0; k < (sizeof(_cards) / sizeof(Card)) - 1; k++)
	{
		if (_cards[k].getRank() == _cards[k + 1].getRank())
		{
			
			pairs++;
			
		}
	}

	if (pairs == 2)
	{
		has2Pair = true;
	}



	return has2Pair;
}

bool Hand::has3OfAKind()
{
	bool threeOfKind = false;
	
	for (int k = 0; k < (sizeof(_cards) / sizeof(Card)) - 2; k++)
	{
		if (_cards[k].getRank() == _cards[k + 1].getRank() && _cards[k].getRank() == _cards[k + 2].getRank())
		{

			threeOfKind = true;
		}
	}

	return threeOfKind;
}

bool Hand::has4OfAKind()
{
	bool fourOfKind = false;

	for (int k = 0; k < (sizeof(_cards) / sizeof(Card)) - 3; k++)
	{
		if (_cards[k].getRank() == _cards[k + 1].getRank() && _cards[k].getRank() == _cards[k + 2].getRank() && _cards[k].getRank() == _cards[k + 3].getRank())
		{

			fourOfKind = true;
		}
	}

	return fourOfKind;

}

bool Hand::hasStraight()
{
	int k = 0;
	bool straight = false;
	int rank1 = _cards[k].getRank();
	int rank2 = _cards[k + 1].getRank();
	int rank3 = _cards[k + 2].getRank();
	int rank4 = _cards[k + 3].getRank();
	int rank5 = _cards[k + 4].getRank();

	//all five cards in order

	if (rank1 == rank2 - 1 && rank1 == rank3 - 2 && rank1 == rank4 - 3 && rank1 == rank5 - 4)
	{
		straight = true;
	}

	return straight;

}

bool Hand::hasFullHouse()
{
	bool fullHouse = false;

	if (hasPair() && has3OfAKind())
	{
		fullHouse = true;
	}

	return fullHouse;

}

bool Hand::hasFlush()
{
	bool flush = false;
	if (_cards[0].getSuit() == _cards[1].getSuit() && _cards[0].getSuit() == _cards[2].getSuit() && _cards[0].getSuit() == _cards[3].getSuit() && _cards[0].getSuit() == _cards[4].getSuit())
	{
		flush = true;
	}

	return flush;
}
