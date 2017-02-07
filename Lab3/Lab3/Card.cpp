

#include "Card.h"

Card::Card()
{
	_suit = Club;
	_rank = Two;

}



Card::Card(Suit_t suit, Rank_t rank)
{
	_suit = suit;
	_rank = rank;

}

Suit_t Card::getSuit() const
{
	return _suit;

}

Rank_t Card::getRank() const
{

	return _rank;
}


string Card::getSuitName() const
{
	Suit_t suit = getSuit();
	string suitString = "";

	switch (suit)
	{
	case Club: suitString = "Club";
		break;
	case Diamond: suitString = "Diamond";
		break;
	case Heart: suitString = "Heart";
		break;
	case Spade: suitString = "Spade";
		break;
	}
	
	return suitString;

}

string Card::getRankName() const
{
	Rank_t rank = getRank();
	string rankName = "";

	switch (rank)
	{
	case Two: rankName = "Two";
		break;
	case Three: rankName = "Three";
		break;
	case Four: rankName = "Four";
		break;
	case Five: rankName = "Five";
		break;
	case Six: rankName = "Six";
		break;
	case Seven: rankName = "Seven";
		break;
	case Eight: rankName = "Eight";
		break;
	case Nine: rankName = "Nine";
		break;
	case Ten: rankName = "Ten";
		break;
	case Jack: rankName = "Jack";
		break;
	case Queen: rankName = "Queen";
		break;
	case King: rankName = "King";
		break;
	case Ace: rankName = "Ace";
		break;
	
	}

	return rankName;
}

