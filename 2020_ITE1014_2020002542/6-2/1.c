#include <stdio.h>

int main(void)
{
	int num;
	scanf("%d",&num);

	int cnum=1;

	while (cnum<10)
	{
		printf("%dx%d=%d \n", num, cnum, num*cnum);
		cnum++;
	}
	return 0;
}

