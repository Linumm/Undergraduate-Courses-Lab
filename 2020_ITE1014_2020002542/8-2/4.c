#include <stdio.h>

int comb(int n, int r)
{
	if(r==0 || r==n)
	{
		return 1;
	}
	else
	{
		return comb(n-1, r)+comb(n-1,r-1);
	}
}

int main(void)
{
	int n, r;
	scanf("%d %d", &n, &r);
	printf("%d\n",comb(n, r));

	return 0;

}
