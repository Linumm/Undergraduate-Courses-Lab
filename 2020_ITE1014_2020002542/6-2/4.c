#include <stdio.h>

int main(void)
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	int maxNum=a, minNum=a;

	if(a<c)
	{maxNum=c;
		if(c<b)
		{maxNum=b;}
		else if(b<a)
		{minNum=b;}
	}
	else if(a<b)
	{maxNum=b;
		if(b<c)
		{maxNum=c;}
		else if(c<a)
		{minNum=c;}
	}
	else if(a>b)
	{minNum=b;
		if(b>c)
		{minNum=c;}
	}
	
	printf("max: %d \n", maxNum);
	printf("min: %d \n", minNum);

	return 0;
}
