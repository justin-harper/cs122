#include "Vector.h"


//initialization function for int vectors
IntVector_t intVector_init(int initial_size)
{
	IntVector_t some_vector;
	
	//error checking
	if (initial_size <= 0)
	{
		initial_size = 0;
	}

	//set vector's initial size to requested size
	some_vector.size = initial_size;
	some_vector.items = (int *)calloc(initial_size, sizeof(int));
	return some_vector;
}

DoubleVector_t  DoubleVector_init(int initial_size)
{
	DoubleVector_t some_vector;

	//error checking
	if (initial_size <= 0)
	{
		initial_size = 0;
	}

	//set vector's initial size to requested size
	some_vector.size = initial_size;
	some_vector.items = (double *)calloc(initial_size, sizeof(double));
	return some_vector;
}

CharVector_t CharVector_init(int inital_size)
{
	CharVector_t some_vector;

	//error checking
	if (inital_size <= 0)
	{
		inital_size = 0;
	}

	//set vector's intial size to requested size
	some_vector.size = inital_size;
	some_vector.items = (char *)calloc(inital_size, sizeof(char));
	return some_vector;
}


//resize operation for int vectors
void intVector_resize(IntVector_t *some_vector, int new_size)
{
	//define variables
	int i = 0;
	int *new_array = (int *)calloc(new_size, sizeof(int));

	//take the smaller of the two vector sizes, used
	//for the loop below
	int smaller_size = (new_size < some_vector->size) 
		? new_size //if new_size is smaller
		: some_vector->size; //if some_vector's size is smaller

	//copy contents into new container
	for (i = 0; i < smaller_size; i++)
	{
		new_array[i] = some_vector->items[i];
	}

	//delete old container
	free(some_vector->items);

	//reassign values to new vector
	some_vector->items = new_array;
	some_vector->size = new_size;
	return;
}


//resize operation for double vectors
void DoubleVector_resize(DoubleVector_t *some_vector, int new_size)
{
	//define variables
	int i = 0;
	double *new_array = (double *)calloc(new_size, sizeof(double));
	//int smaller_size = 0;
	//take the smaller of the two vector sizes, used
	//for the loop below
	int smaller_size = (new_size < some_vector->size)
		? new_size //if new_size is smaller
		: some_vector->size; //if some_vector's size is smaller
	/*if (new_size < some_vector->size)
	{
		smaller_size = new_size;
	}
	else
	{
		smaller_size = some_vector->size;
	}*/


	//copy contents into new container
	for (i = 0; i < smaller_size; i++)
	{
		new_array[i] = some_vector->items[i];
	}

	//delete old container
	free(some_vector->items);

	//reassign values to new vector
	some_vector->items = new_array;
	some_vector->size = new_size;
	return;
}

//resize operation for double vectors
void CharVector_resize(CharVector_t *some_vector, int new_size)
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
		new_array[i] = some_vector->items[i];
	}

	//delete old container
	free(some_vector->items);

	//reassign values to new vector
	some_vector->items = new_array;
	some_vector->size = new_size;
	return;
}


//Inserts a value at the given location
void intVector_insert(IntVector_t *some_vector, int location, int value)
{
	//Is the current location within existing boundaries?
	if (some_vector->size < location + 1)
	{
		intVector_resize(some_vector, location + 1);
	}

	//assign the value to the vector
	some_vector->items[location] = value;
}

//Inserts a value at the given location
void DoubleVector_insert(DoubleVector_t *some_vector, int location, double value)
{
	//Is the current location within existing boundaries?
	if (some_vector->size < location + 1)
	{
		intVector_resize(some_vector, location + 1);
	}

	//assign the value to the vector
	some_vector->items[location] = value;
}

//Inserts a value at the given location
void CharVector_insert(CharVector_t *some_vector, int location, char value)
{
	//Is the current location within existing boundaries?
	if (some_vector->size < location + 1)
	{
		intVector_resize(some_vector, location + 1);
	}

	//assign the value to the vector
	some_vector->items[location] = value;
}

//Adds a value at the given location.  Will shift all other
//values to the right by 1
void intVector_add(IntVector_t *some_vector, int location, int value)
{
	int i = 0;

	//An "add" shifts all things to the right.  Start
	//at the right-most element and move each item 
	//"over" by 1.
	for (i = some_vector->size - 1; i > location - 1; i--)
	{
		intVector_insert(some_vector, i + 1, some_vector->items[i]);
	}

	//finally, we have a hole that we can insert our new
	//value into
	intVector_insert(some_vector, location, value);

}

//Adds a value at the given location.  Will shift all other
//values to the right by 1
void DoubleVector_add(DoubleVector_t *some_vector, int location, double value)
{
	int i = 0;

	//An "add" shifts all things to the right.  Start
	//at the right-most element and move each item 
	//"over" by 1.
	for (i = some_vector->size - 1; i > location - 1; i--)
	{
		intVector_insert(some_vector, i + 1, some_vector->items[i]);
	}

	//finally, we have a hole that we can insert our new
	//value into
	intVector_insert(some_vector, location, value);

}

//Adds a value at the given location.  Will shift all other
//values to the right by 1
void CharVector_add(CharVector_t *some_vector, int location, char value)
{
	int i = 0;

	//An "add" shifts all things to the right.  Start
	//at the right-most element and move each item 
	//"over" by 1.
	for (i = some_vector->size - 1; i > location - 1; i--)
	{
		intVector_insert(some_vector, i + 1, some_vector->items[i]);
	}

	//finally, we have a hole that we can insert our new
	//value into
	intVector_insert(some_vector, location, value);

}

//prints the int vector
void intVector_print(IntVector_t *some_vector)
{
	int i = 0;

	for (i = 0; i < some_vector->size; i++)
	{
		printf("intVector[%d]: %d\n", i, some_vector->items[i]);
	}

}

//prints the double vector
void DoubleVector_print(DoubleVector_t *some_vector)
{
	int i = 0;

	for (i = 0; i < some_vector->size; i++)
	{
		printf("doubleVector[%d]: %d\n", i, some_vector->items[i]);
	}

}

//prints the char vector
void CharVector_print(CharVector_t *some_vector)
{
	int i = 0;

	for (i = 0; i < some_vector->size; i++)
	{
		printf("charVector[%d]: %d\n", i, some_vector->items[i]);
	}

}