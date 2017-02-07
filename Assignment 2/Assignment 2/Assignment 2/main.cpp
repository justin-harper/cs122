/*
Justin Harper

WSU ID: 10696738

version 0.1

2/19/14

*/


#include "Card.h"
#include "Deck.h"
#include "fiveCardPoker.h"
#include <string>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <iomanip>


using namespace std;

int main(void)
{
	srand((unsigned)time(NULL));

	fiveCardPoker fiveCard{};

	fiveCard.playPoker();


	return 0;
}