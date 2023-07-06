#include <stdio.h>

int main(void)
{
	double arr[5];
	double sum=0;
	scanf("%lf %lf %lf %lf %lf", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4]);
	double* parr=&*(arr+0);
	for(int i=0; i<5; i++)
	{
		*(parr+i)=*(parr+i)*2;
		printf("%f\n", *(parr+i));
		sum=sum+(*(parr+i));
	}
	printf("sum: %f\n", sum);

	return 0;
}
