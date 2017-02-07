#include <stdio.h>
#include <stdlib.h>


typedef struct IntList_t
{
	int value;
	struct IntList_t *previous;
	struct IntList_t *next;
} IntList_t;


/*

IntList_t* intList_init(int starting_value)
Like our vector's init function, the LL version must dynamically create a new IntList_t and set its starting
value as well as setting the previous and next pointers to NULL.

IntList_t * intList_rewind(IntList_t *some_list)
This function returns a pointer to the "beginning" of the linked list. For our purposes, we will consider
the beginning of a linked list to be represented by the IntList_t whose previous pointer is equal to NULL.


void intList_add(IntList_t *some_list, int value)
This function will add a new IntList_t to the end of the current linked list. Note that for our purposes,
the last element in the list is represented by the individual IntList_t whose next pointer is equal to NULL.


void intList_remove(IntList_t *some_list)
This function removes the supplied IntList_t from the current chain of list items.

void intList_free(IntList_t *some_list)
Freeing up dynamic memory allocated for a linked list is a little more work than freeing up dynamic
memory for a vector. As such, this function should call free on every node in the linked list.

*/

IntList_t *intList_init(int starting_value);

IntList_t *intList_rewind(IntList_t *some_list);

void intList_add(IntList_t *some_list, int value);

void intList_remove(IntList_t *some_list);

void intList_freeLast(IntList_t *some_list);

void getValueToRemove(IntList_t *some_list);

void intList_Del(IntList_t *some_list);

void intList_freeAll(IntList_t *some_list);

void intList_freeFirst(IntList_t *some_list);

