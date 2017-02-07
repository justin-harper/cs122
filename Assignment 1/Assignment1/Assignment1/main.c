//Justin Harper
//SID: 
//CptS 122
//Assignment 1
//
//



#include "grocery.h"

int main(void)

{
	FILE * doc = fopen("grocery_list.txt", "r+");


	int lines = 0;
	if(doc == NULL)
	{
		printf("error");
	}
	
	
	lines = countLines(doc);
	fclose(doc);

	doc = fopen("grocery_list.txt", "r+");


	


	



	return 0;
}