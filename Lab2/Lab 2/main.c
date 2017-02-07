#include "lab2.h"

int main(void)
{
	IntList_t ll, *ll2;

	int i = 1;

	ll = *intList_init(0);

	ll2 = &ll;

	while (i < 10)
	{
		intList_add(&ll, i);
		//printf("%d\n", i);

		i++;

	}

	//system("pause");


	/*while (temp.next != NULL)
	{
	printf("%d\n", temp.value);
	temp = *temp.next;
	}*/



	intList_print(&ll);


	//printf("value at temp.previous: %d\n", temp.previous->value);


	getValueToRemove(&ll);

	intList_print(&ll);

	intList_freeLast(&ll);

	return 0;
}

