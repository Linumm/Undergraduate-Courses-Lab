#include <stdio.h>

int main(void)
{
	int arr [5];
	int max=0, sum=0;
	scanf("%d %d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4]);
	int min=arr[0];
	for(int i=0; i<5; i++)
	{
		sum=sum+arr[i];
		if(arr[i]>=max)
		{
			max=arr[i];
		}
		else if(arr[i]<min)
		{
			min=arr[i];
		}
	}
	printf("min: %d\n", min);
	printf("max: %d\n", max);
	printf("sum: %d\n", sum);
	
	return 0;
}
