

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
	case Club: suitString = "Clubs";
		break;
	case Diamond: suitString = "Diamonds";
		break;
	case Heart: suitString = "Hearts";
		break;
	case Spade: suitString = "Spades";
		break;
	}

	return suitString;

}

string Card::getRankName() const
{
	Rank_t rank = getRank();
	string rankName = "Two";

	switch (rank)
	{
	default: break;
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

int Card::getScore() const
{
	Rank_t rank = getRank();
	int score = 0;

	switch (rank)
	{
	case Two: score = 2;
		break;
	case Three: score = 3;
		break;
	case Four: score = 4;
		break;
	case Five: score = 5;
		break;
	case Six: score = 6;
		break;
	case Seven: score = 7;
		break;
	case Eight: score = 8;
		break;
	case Nine: score = 9;
		break;
	case Ten: 
	case Jack:
	case Queen:
	case King: score = 10;
		break;
	case Ace: score = 11;
		break;

	}

	return score;

}

string Card::getCommonName() const
{
	string commonName = "";

	commonName += getRankName() +" of " + getSuitName();

	return commonName;


}

