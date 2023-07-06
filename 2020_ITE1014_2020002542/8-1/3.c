#include <stdio.h>

int sigma(int n)
{
	if(n==1)
	{
		return 1;
	}
	else
	{
		return n+sigma(n-1);
	}
}

int main(void)
{
	int n;
	scanf("%d", &n);
	printf("%d\n", sigma(n));

	return 0;
}
