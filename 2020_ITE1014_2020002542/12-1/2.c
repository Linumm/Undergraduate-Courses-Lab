#include <stdio.h>

int main()
{
	int arr[3][2];
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<2; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	for(int p=0; p<3; p++)
	{
		for(int q=0; q<2; q++)
		{
			printf("%d ", arr[p][q]);
		}
		printf("\n");
	}

	return 0;
}
