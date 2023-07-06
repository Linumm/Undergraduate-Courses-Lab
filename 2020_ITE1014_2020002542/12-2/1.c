#include <stdio.h>

void printArray(char** arr, int len)
{
	printf("Array [0]:%s, [1]:%s\n", arr[0], arr[1]);
}

void swap(char** arr)
{
	const char* temp=arr[0];
	char* a0=&arr[0];
	char* a1=&arr[1];
	*a0=*a1;
	*a1=temp;
}
int main()
{
	char* arr[2]={"aaa", "bbb"};
	printArray(arr, 2);
	swap(arr);
	printArray(arr, 2);

	return 0;
}
