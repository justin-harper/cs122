#include "grocery.h"


charVector charVectorInit (int startSize)
{
	charVector x;
	
	if(startSize <= 0)
	{
		startSize = 1;
	}
	
	x.item = (char*)calloc(startSize, sizeof(char));
	x.size = startSize;
	
	
	return x;
	
}


void charVector_print(charVector *some_vector)
{
	int i = 0;

	for (i = 0; i < some_vector->size; i++)
	{
		printf("charVector[%d]: %d\n", i, some_vector->item[i]);
	}

}

//Adds a value at the given location.  Will shift all other
//values to the right by 1
void CharVector_add(charVector *some_vector, int location, char value)
{
	int i = 0;

	//An "add" shifts all things to the right.  Start
	//at the right-most element and move each item 
	//"over" by 1.
	for (i = some_vector->size - 1; i > location - 1; i--)
	{
		CharVector_insert(some_vector, i + 1, some_vector->item[i]);
	}

	//finally, we have a hole that we can insert our new
	//value into
	CharVector_insert(some_vector, location, value);

}

//Inserts a value at the given location
void CharVector_insert(charVector *some_vector, int location, char value)
{
	//Is the current location within existing boundaries?
	if (some_vector->size < location + 1)
	{
		charVector_resize(some_vector, location + 1);
	}

	//assign the value to the vector
	some_vector->item[location] = value;
}

//resize operation for double vectors
void charVector_resize(charVector *some_vector, int new_size)
{
	//define variables
	int i = 0;
	char *new_array = (char *)calloc(new_size, sizeof(char));

	//take the smaller of the two vector sizes, used
	//for the loop below
	int smaller_size = (new_size < some_vector->size)
		? new_size //if new_size is smaller
		: some_vector->size; //if some_vector's size is smaller

	//copy contents into new container
	for (i = 0; i < smaller_size; i++)
	{
		new_array[i] = some_vector->item[i];
	}

	//delete old container
	free(some_vector->item);

	//reassign values to new vector
	some_vector->item = new_array;
	some_vector->size = new_size;
	return;
}

int countLines (FILE * doc)
{
	int lines = 0;
	int a;

	while (!feof(doc))
	{
		a = fgetc(doc);
		if(a == '\n')
		{
		
		lines++;
		}
	}

	return lines;


}

int countChar (FILE * doc)
{
	char a = '\0';
	int chars = 0;

	do
	{
		a = fgetc(doc);
		if(a != '\n')
		{
			chars++;
		}
	}
	while(a!='\n');


	return chars;
}