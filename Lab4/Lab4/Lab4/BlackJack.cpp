#include "BlackJack.h"
#include <vector>




void playGame(void)
{
	Deck deck{};
	Card current;
	string someString = "", responce = "";

	int playerScore = 0, dealerScore = 0;
	bool winner = false, playerTurn = true, dealerTurn = true;

	printIntro();

	current = deck.getNextCard();
	playerScore += current.getScore();
	someString = ("Player is dealt a(n) " + current.getCommonName());
	cout << someString << endl;



	current = deck.getNextCard();
	dealerScore += current.getScore();
	someString = ("Dealer is dealt a(n) " + current.getCommonName());
	cout << someString << endl;


	current = deck.getNextCard();
	playerScore += current.getScore();
	someString = ("Player is dealt a(n) " + current.getCommonName());
	cout << someString << endl;

	current = deck.getNextCard();
	dealerScore += current.getScore();
	someString = ("Dealer is dealt a(n) " + current.getCommonName());
	cout << someString << endl;

	cout << "Player Score: " << playerScore << endl;
	cout << "Dealer Score: " << dealerScore << endl;

	if (playerScore == 21)
	{
		winner = true;
		playerTurn = false;
		dealerTurn = false;
		cout << "WINNER WINNER CHICKEN DINNER \nYou hit a BlackJack" << endl;
	}
	if (dealerScore == 21)
	{
		winner = true;
		playerTurn = false;
		dealerTurn = false;
		cout << "well that suks the dealer hit a BlackJack \nbetter luck next time" << endl;
	}

	while (playerTurn)
	{
		do
		{
			cout << "Player score: " << playerScore << endl;
			
			cout << "Would you like to hit <H> or stand <S>?" << endl;
			cin >> responce;
			if (responce == "H" || responce == "h")
			{
				current = deck.getNextCard();
				playerScore += current.getScore();
				someString = ("Player is dealt a(n) " + current.getCommonName());
				cout << someString << endl;

			}
			else
			{
				playerTurn = false;
			}

			if (playerScore > 21)
			{
				winner = true;
				playerTurn = false;
				dealerTurn = false;
				cout << "BUST...Dealer wins!" << endl;
				return;
			}
			if (playerScore == 21)
			{
				winner = true;
				playerTurn = false;
				dealerTurn = false;
				cout << "Player wins!!" << endl;
				return;

			}


		} while (responce == "H" || responce == "h");
	}
	//dealer turn
	while (dealerTurn)
	{
		cout << "Dealer score is: " << dealerScore << endl;

		if (dealerScore > 17)
		{
			dealerTurn = false;
			continue;
		}
		if (dealerScore <= 17)
		{
			current = deck.getNextCard();
			
			someString = ("Dealer is dealt a(n) " + current.getCommonName());
			dealerScore = current.getScore() + dealerScore;
			cout << someString << endl;
		}
		if (dealerScore > 21)
		{
			winner = true;
			dealerTurn = false;
			cout << "BUST...Player wins!" << endl;
			return;

		}
		if (dealerScore == 21)
		{
			winner = true;
			dealerTurn = false;
		}
		

	}

	if (dealerScore > playerScore)
	{
		winner = true;
		cout << "The house wins ;(" << endl;

	}
	if (playerScore >= dealerScore)
	{
		winner = true;
		cout << "Player wins! \nCongrats! :P" << endl;
	}






}


void printIntro(void)
{
	
	cout << "Hello!\nLets play some BlackJack" << endl;

	return;
}