#include <stdio.h>

void getSumDiff(int a, int b, int* pSum, int* pDiff)
{
	*pSum=a+b;
	*pDiff=a-b;
}

int main(void)
{
	int pSum, pDiff, a, b;
	scanf("%d %d", &a, &b);
	getSumDiff(a, b, &pSum, &pDiff);
	printf("Sum: %d\n", pSum);
	printf("Diff: %d\n", pDiff);

	return 0;
}
