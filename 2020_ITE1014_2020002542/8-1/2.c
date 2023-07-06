#include <stdio.h>

int gMul=1;

int addTotal(int n)
{
	return n*(n+1)/2;
}
int mulTotal(int n)
{
	if(n==1)
	{
		gMul=1;
	}
	else
	{
		gMul=n*mulTotal(n-1);
	}
}

int main(void)
{
	int n;
	scanf("%d", &n);
	printf("addTotal(): %d\n", addTotal(n));
	mulTotal(n);
	printf("gMul: %d\n", gMul);

	return 0;
}
