#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[50];
	scanf("%s", str);
	for(int i=0; i<strlen(str); i++)
	{
		if(str[i]>=65 && str[i]<=90)
		{
			str[i]=str[i]+32;
		}
		else if(str[i]>=97 && str[i]<=122)
		{
			str[i]=str[i]-32;
		}
	}

	printf("%s\n", str);

	return 0;
}

