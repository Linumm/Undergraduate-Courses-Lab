#include <stdio.h>

int main(void)
{
	int arr [5];
	scanf("%d %d %d %d %d", &*(arr+0), &*(arr+1), &*(arr+2), &*(arr+3), &*(arr+4));
	int box0=*(arr+0), box1=*(arr+1), box2=*(arr+2), box3=*(arr+3);
	*(arr+0)=*(arr+4);
	*(arr+1)=box3;
	*(arr+2)=box2;
	*(arr+3)=box1;
	*(arr+4)=box0;

	for(int i=0; i<5; i++)
	{
		printf("%d ", *(arr+i));
	}
	printf("\n");

	return 0;
}
