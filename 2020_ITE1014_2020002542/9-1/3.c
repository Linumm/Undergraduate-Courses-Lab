#include <stdio.h>

int main(void)
{
	int len=0;
	char c[50];
	scanf("%s", c);
	while(c[len]!='\0')
	{
		len++;
	}
	printf("%d\n", len);

	return 0;
}

