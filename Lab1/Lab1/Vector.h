#include <stdlib.h>
#include<stdio.h>

#ifndef VECTOR_H
#define VECTOR_H

typedef struct IntVector_t
{
	int size;
	int *items;
} IntVector_t;

typedef struct DoubleVector_t
{
	int size;
	double *items;

} DoubleVector_t;

typedef struct CharVector_t
{
	int size;
	char *items;

}CharVector_t;


//initialization function for int vectors
IntVector_t intVector_init(int initial_size);

//initialization function for double vectors
DoubleVector_t DoubleVector_init(int initial_size);

//intialization function for char vectors
CharVector_t CharVector_init(int inital_size);

//resize operation for int vectors
void intVector_resize(IntVector_t *some_vector, int new_size);

//resize operation for double vectors
void DoubleVector_resize(DoubleVector_t *some_vector, int new_size);

//resize operation for char vectors
void CharVector_resize(CharVector_t *some_vector, int new_size);

//Inserts a value at the given location
void intVector_insert(IntVector_t *some_vector,
	int location,
	int value
	);

//Inserts a value at the given location
void DoubleVector_insert(DoubleVector_t *some_vector,
	int location,
	double value
	);

//Inserts a value at the given location
void CharVector_insert(CharVector_t *some_vector,
	int location,
	char value
	);

//Adds a value at the given location.  Will shift all other
//values to the right by 1
void intVector_add(IntVector_t *some_vector, int location, int value);

//Adds a value at the given location.  Will shift all other
//values to the right by 1
void DoubleVector_add(DoubleVector_t *some_vector, int location, double value);


//Adds a value at the given location.  Will shift all other
//values to the right by 1
void CharVector_add(CharVector_t *some_vector, int location, char value);

//prints the int vector
void intVector_print(IntVector_t *some_vector);

//prints the double vector
void DoubleVector_print(DoubleVector_t *some_vector);

//prints the char vector
void CharVector_print(CharVector_t *some_vector);

#endif