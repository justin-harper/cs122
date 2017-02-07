#ifndef Card_h
#define Card_h



#include <iostream>


using namespace std;

enum Suit_t { Club, Diamond, Heart, Spade };
enum Rank_t { Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace };



class Card
{

public:

	

	Card();

	Card(Suit_t suit, Rank_t rank);

	Suit_t getSuit() const;

	Rank_t getRank() const;

	string getSuitName() const;

	string getRankName() const;
	

	private:
		

		Suit_t _suit;
		Rank_t _rank;

	


};



#endif // !Card_h
