/***************************************************************
* Programmer: Justin Harper                                    *
* Class: Cpt S 122, Spring 2014;			                   *
* Programming Assignment: pa7                                  *
* Description: Simpletron									   *
****************************************************************/
#include "SIMPLETRON.h"

int main(void)
{

	std::cout.precision(4);

	SIMPLETRON step;

	// function call instruction
	instruction();
	// function calls the loadMemory, its indicates where each individual functions is loaded in memory
	step.loadMemory();
	//function calls the execute function programme in function c
	step.execute();
	system("pause");

	return 0;
}
