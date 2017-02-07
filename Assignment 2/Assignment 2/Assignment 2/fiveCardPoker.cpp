#include "fiveCardPoker.h"
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include <iostream>
#include <string>
#include <time.h>
#include <istream>



fiveCardPoker::fiveCardPoker(void)
{
	_gameDeck = Deck_h{};
	
	


}

void fiveCardPoker::playPoker(void)
{
	

	_gameDeck.resetDeck(); //shuffle


	Hand playerHand{};
	Hand DealerHand{};

	playerHand.setCard(0, _gameDeck.getNextCard());
	DealerHand.setCard(0, _gameDeck.getNextCard());

	playerHand.setCard(1, _gameDeck.getNextCard());
	DealerHand.setCard(1, _gameDeck.getNextCard());

	playerHand.setCard(2, _gameDeck.getNextCard());
	DealerHand.setCard(2, _gameDeck.getNextCard());

	playerHand.setCard(3, _gameDeck.getNextCard());
	DealerHand.setCard(3, _gameDeck.getNextCard());

	playerHand.setCard(4, _gameDeck.getNextCard());
	DealerHand.setCard(4, _gameDeck.getNextCard());


	playerHand.bubbleSort();
	DealerHand.bubbleSort();

	playerHand.displayHand();

	changeCards(&playerHand);
	playerHand.bubbleSort();
	system("cls");
	cout << "Here is your hand" << endl;
	playerHand.displayHand();

	cout << "Here is the dealers hand" << endl;
	DealerHand.displayHand();

	if (DealerHand.hasFlush() || DealerHand.hasFullHouse() || DealerHand.hasStraight() || DealerHand.hasFlush())
	{
		//dealer takes no cards
		cout << "Dealer takes no cards" << endl;

	}
	else if (DealerHand.has2Pair())
	{
		//dealer takes 1 card
		cout << "Dealer takes 1 card" << endl;

		//[0,1] [1,2] [2,3] [3,4]
		int indexPair1 = -1;
		int indexPair2 = -1;
		int index[5] = { 0, 0, 0, 0, 0 };
		int indexToReplace = -1;


		int rank1 = DealerHand.getCard(0).getRank();

		for (int i = 0; i < 4; i++)
		{
			if (DealerHand.getCard(i).getRank() == DealerHand.getCard(i + 1).getRank())
			{
				indexPair1 = i;
				index[i] = 1;
				index[i + 1] = 1;
				break;
			}
		}
		for (int i = indexPair1 + 2; i < 4; i++)
		{
			if (DealerHand.getCard(i).getRank() == DealerHand.getCard(i + 1).getRank())
			{
				indexPair2 = i;
				index[i] = 1;
				index[i + 1] = 1;
				break;
			}
		}
		for (int i = 0; i < sizeof(index) / (sizeof(int)); i++)
		{
			if (index[i] == 0)
			{
				indexToReplace = i;
			}
		}

		DealerHand.setCard(indexToReplace, _gameDeck.getNextCard());




	}
	else if (DealerHand.has3OfAKind())
	{
		//dealer takes 2 cards
		cout << "Dealer takes 2 cards" << endl;

		int indexToreplace1 = -1, indexToreplace2 = -1;
		if (DealerHand.getCard(0).getRank() == DealerHand.getCard(1).getRank() && DealerHand.getCard(0).getRank() == DealerHand.getCard(2).getRank())
		{
			indexToreplace1 = 3; indexToreplace2 = 4;
		}
		else if (DealerHand.getCard(1).getRank() == DealerHand.getCard(2).getRank() && DealerHand.getCard(1).getRank() == DealerHand.getCard(3).getRank())
		{
			indexToreplace1 = 0; indexToreplace2 = 4;
		}
		else if (DealerHand.getCard(2).getRank() == DealerHand.getCard(3).getRank() && DealerHand.getCard(2).getRank() == DealerHand.getCard(4).getRank())
		{
			indexToreplace1 = 0; indexToreplace2 = 1;
		}

		DealerHand.setCard(indexToreplace1, _gameDeck.getNextCard()); DealerHand.setCard(indexToreplace2, _gameDeck.getNextCard());

	}
	else if (DealerHand.hasPair())
	{
		//dealer takes 3 cards;
		cout << "Dealer takes 3 cards" << endl;
		int index[5] = { 0, 0, 0, 0, 0 };
		
		for (int i = 0; i < 4; i++)
		{
			if (DealerHand.getCard(i).getRank() == DealerHand.getCard(i + 1).getRank())
			{
				index[i] = 1;
				index[i + 1] = 1;
			}

		}
		for (int i = 0; i < 5; i++)
		{
			if (index[i] == 0)
			{
				DealerHand.setCard(i, _gameDeck.getNextCard());
			}
		}



	}
	else
	{
		//dealer takes 5 cards
		cout << "Dealer takes 5 cards" << endl;

		for (int i = 0; i < 5; i++)
		{
			DealerHand.setCard(i, _gameDeck.getNextCard());
		}
	}

	system("cls");

	cout << "Here is the dealers hand:" << endl;
	DealerHand.bubbleSort();
	DealerHand.displayHand();

	cout << endl << "Here is your hand:" << endl;

	playerHand.displayHand();

	//four of a kind
	if (playerHand.hasFlush() && DealerHand.hasFlush())
	{
		cout << "tie game" << endl;

	}
	else if (playerHand.hasFlush() && !DealerHand.hasFlush())
	{
		cout << "player wins :)" << endl;
	}
	else if (!playerHand.hasFlush() && DealerHand.hasFlush())
	{
		cout << "dealer wins :)" << endl;
	}

	//full house
	if (playerHand.hasFullHouse() && DealerHand.hasFullHouse())
	{
		cout << "tie game" << endl;

	}
	else if (playerHand.hasFullHouse() && !DealerHand.hasFullHouse())
	{
		cout << "player wins :)" << endl;
	}
	else if (!playerHand.hasFullHouse() && DealerHand.hasFullHouse())
	{
		cout << "dealer wins :)" << endl;
	}

	//Flush

	if (playerHand.hasFlush() && DealerHand.hasFlush())
	{
		cout << "tie game" << endl;

	}
	else if (playerHand.hasFlush() && !DealerHand.hasFlush())
	{
		cout << "player wins :)" << endl;
	}
	else if (!playerHand.hasFlush() && DealerHand.hasFlush())
	{
		cout << "dealer wins :)" << endl;
	}

	//stright
	if (playerHand.hasStraight() && DealerHand.hasStraight())
	{
		cout << "tie game" << endl;

	}
	else if (playerHand.hasStraight() && !DealerHand.hasStraight())
	{
		cout << "player wins :)" << endl;
	}
	else if (!playerHand.hasStraight() && DealerHand.hasStraight())
	{
		cout << "dealer wins :)" << endl;
	}
	
	//Three of a kind
	if (playerHand.has3OfAKind() && DealerHand.has3OfAKind())
	{
		cout << "tie game" << endl;

	}
	else if (playerHand.has3OfAKind() && !DealerHand.has3OfAKind())
	{
		cout << "player wins :)" << endl;
	}
	else if (!playerHand.has3OfAKind() && DealerHand.has3OfAKind())
	{
		cout << "dealer wins :)" << endl;
	}

	//Two pair
	if (playerHand.has2Pair() && DealerHand.has2Pair())
	{
		cout << "tie game" << endl;

	}
	else if (playerHand.has2Pair() && !DealerHand.has2Pair())
	{
		cout << "player wins :)" << endl;
	}
	else if (!playerHand.has2Pair() && DealerHand.has2Pair())
	{
		cout << "dealer wins :)" << endl;
	}

	//Pair
	if (playerHand.hasPair() && DealerHand.hasPair())
	{
		cout << "tie game" << endl;

	}
	else if (playerHand.hasPair() && !DealerHand.hasPair())
	{
		cout << "player wins :)" << endl;
	}
	else if (!playerHand.hasPair() && DealerHand.hasPair())
	{
		cout << "dealer wins :)" << endl;
	}

	




	
	
}

void fiveCardPoker::changeCards(Hand *playerHand)
{
	string x = "How many cards would you like to swap?";
	string y = "Which card would you like to swap?";
	int z = -1;
	int indextoSwap = -1;


	bool swap = false;

	cout << x << endl;
	cin >> z;
	system("cls");
	playerHand->displayHand();
	if (z > 0)
	{
		swap = true;
	}


	if (swap)
	{
		//z = number of cards to swap
		int local = 0;

		while (local < z)
		{
			cout << y << endl;
			cin >> indextoSwap;

			cout << "swapping " << playerHand->getCard(indextoSwap - 1).getCommonName() << endl;
			cout << endl;
			playerHand->setCard(indextoSwap - 1, _gameDeck.getNextCard());

			local++;
		}
		//swap = false;

	}

}

