#include <stdio.h>

int fibona(int n)
{
	if (n<=0)
	{
		return 0;
	}
	else if (n==1)
	{
		return 1;
	}
	else
	{
		return fibona(n-1)+fibona(n-2);
	}
}

int main (void)
{
	int n;
	scanf("%d", &n);
	printf("%d\n", fibona(n));
	
	return 0;
}
