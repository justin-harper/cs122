#include "Vector.h"

int main(void)
{

	IntVector_t		vectorInt		= intVector_init(0);
	DoubleVector_t	vectorDouble	= DoubleVector_init(0);
	CharVector_t	vectorChar		= CharVector_init(0);

	intVector_insert(&vectorInt, 0, 4);
	DoubleVector_insert(&vectorDouble, 0, 3.3);
	CharVector_insert(&vectorChar, 0, 't');

	intVector_print(&vectorInt);
	
	DoubleVector_print(&vectorDouble);
	
	CharVector_print(&vectorChar);
	printf("\n");
	printf("\n");

	printf("size of IntVector: %d\n", vectorInt.size);
	printf("size of DoubleVector: %d\n", vectorDouble.size);
	printf("size of CharVector: %d\n", vectorChar.size);

	system("pause");

	intVector_resize(&vectorInt, 7);
	DoubleVector_resize(&vectorDouble, 10);
	CharVector_resize(&vectorChar, 10);
	printf("size of IntVector: %d\n", vectorInt.size);
	printf("size of DoubleVector: %d\n", vectorDouble.size);
	printf("size of CharVector: %d\n", vectorChar.size);



	return 0;
}