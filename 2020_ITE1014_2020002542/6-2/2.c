#include <stdio.h>

int main(void)
{
	int num, i;
	scanf("%d", &num);

	for(i=1; i<num+1; i++)
	{
		int j;
		for(j=1; j<i+1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
