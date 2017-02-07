#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct charVector
{

	int size;
	char *item;


}charVector;

charVector charVectorInit (int startSize);

void charVector_print (charVector *some_vector);

void CharVector_add(charVector *some_vector, int location, char value);

void CharVector_insert(charVector *some_vector, int location, char value);

void charVector_resize(charVector *some_vector, int new_size);

int countLines (FILE * doc);