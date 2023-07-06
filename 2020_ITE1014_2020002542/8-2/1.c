#include <stdio.h>

int printLine(int n)
{
	for (int i=1; i<n+1; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
}

int main (void)
{
	int n;
	scanf("%d", &n);

	for (int m=1; m<n+1; m++)
	{
		printLine(m);
	}
	for (int p=n; p>0; p--)
	{
		printLine(p);
	}

	return 0;
}
