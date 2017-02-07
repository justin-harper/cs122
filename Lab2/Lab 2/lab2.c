#include "lab2.h"



//Like our vector's init function, the LL version must dynamically create a new IntList_t and set its starting
//value as well as setting the previous and next pointers to NULL.

IntList_t *intList_init(int starting_value)
{

	IntList_t *ll = NULL;

	ll = (IntList_t *)malloc(sizeof(IntList_t));

	ll->next = NULL;
	ll->previous = NULL;
	ll->value = starting_value;

	return ll;



	/*IntList_t * LL = (IntList_t *)malloc(sizeof(IntList_t));

	

	LL->value = starting_value;

	LL->next = NULL;

	LL->previous = NULL;

	return LL;*/
}

//This function returns a pointer to the "beginning" of the linked list.For our purposes, we will consider
//the beginning of a linked list to be represented by the IntList_t whose previous pointer is equal to NULL.

IntList_t *intList_rewind(IntList_t *some_list)
{
	//IntList_t x;
	
	while (some_list->previous != NULL)
	{
		some_list = some_list->previous;
	}

	return some_list;

}


//This function will add a new IntList_t to the end of the current linked list.Note that for our purposes,
//the last element in the list is represented by the individual IntList_t whose next pointer is equal to NULL.

void intList_add(IntList_t *some_list, int value)
{
	while (some_list->next != NULL)
	{
		some_list = some_list->next;

	}

	some_list->next = intList_init(value);
	some_list->next->previous = some_list;
	//printf("%d\n", value);

	return;
}

//This function removes the supplied IntList_t from the current chain of list items.

void intList_remove(IntList_t *some_list)
{
	IntList_t *prev, *nex;

	prev = some_list->previous;
	nex = some_list->next;

	some_list->previous->next = some_list->next;
	some_list->next->previous = some_list->previous;

	/*prev->next = nex;
	nex->previous = prev;*/

	/*some_list->previous->next = some_list->next;
	some_list->next->previous = some_list->previous;*/

	free(some_list);

	return;
}

//Freeing up dynamic memory allocated for a linked list is a little more work than freeing up dynamic
//memory for a vector.As such, this function should call free on every node in the linked list.

void intList_freeLast(IntList_t *some_list)
{
	some_list = intList_rewind(some_list);
	while (some_list->next != NULL)
	{
		some_list->next = some_list->next->next;
		intList_remove(some_list);
		some_list = some_list->next;
	}
	//IntList_t temp;
	//if (some_list == NULL)
	//{
	//	printf("empty list");
	//}
	//else
	//{
	//	while (some_list->next != NULL)
	//	{
	//		some_list = some_list->next;
	//	}
	//	some_list->previous->next = NULL;
	//	free(some_list);

//	}
}

void intList_print(IntList_t *some_list)
{
	if (some_list == NULL)
	{
		printf("Empty List\n");

	}
	else
	{

		while (some_list->next != NULL)
		{
			printf("value: %d\n", some_list->value);
			some_list = some_list->next;
		}
		printf("value: %d\n", some_list->value);
	}
}

void getValueToRemove(IntList_t *some_list)
{
	

	int a = NULL;
	int removed = 0;
	
	printf("Please enter a value to remove from the list:\n");
	scanf(" %d", &a);
	printf("attempting to remove %d from the list\n", a);



	while (some_list->next != NULL)
	{

		if (some_list->value == a)
		{
			some_list = some_list->next;
			intList_remove(some_list->previous);
			removed = 1;
		}
		else
		{
			some_list = some_list->next;
		}
	}
	
	if (some_list->value == a)
	{
		//some_list = some_list->next;
		intList_remove(some_list);
		removed = 1;
	}
	
	if (removed = 1)
	{
		printf("%d was removed from the list!\n", a);
	}
	
	else
	{

		printf("sorry %d was not in the list\n", a);
	}
	return;
}

void intList_Del(IntList_t *some_list)
{
	free(some_list);
	
	return;
}

void intList_freeAll(IntList_t *some_list)
{
	while (some_list->next != NULL)
	{

		intList_freeLast(some_list);
		some_list = some_list->next;
	}

}


void intList_freeFirst(IntList_t *some_list)
{
	IntList_t * temp;
	if (some_list->previous == NULL)
	{
		if (some_list == NULL)
		{
			return;
		}
		else
		{
			temp = some_list;
			some_list = some_list->next;
			
			free(temp);
		}
	}
	else
	{
		//intList_FreeFirst(some_list->previous);
	}

}