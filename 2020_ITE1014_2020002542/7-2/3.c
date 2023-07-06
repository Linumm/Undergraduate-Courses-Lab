#include <stdio.h>

int main(void)
{
	while (1)
	{
		char string;
		scanf(" %c",&string);
		if(string>=97 && string<=122)
		{
			printf("%c\n",string-32);
			continue;
		}
		if(string>=65 && string<=90)
		{
			printf("%c\n",string+32);
			continue;
		}
		if(string>=48 && string<=57)
		{
			printf("%c\n",string);
			continue;
		}
		else
		{
			break;
		}
	}
	return 0;
}
