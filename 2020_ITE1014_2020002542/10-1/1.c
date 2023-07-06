#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[50], str2[50];
	scanf("%s %s", str1, str2);
	
	int i=0;
	if(strcmp(str1, str2)!=0)
	{
		i=1;
	}
	printf("str1: %s\n", str1);
	printf("str2: %s\n", str2);
	printf("length of str1: %ld\n", strlen(str1));
	printf("length of str2: %ld\n", strlen(str2));
	printf("str1+str2: %s\n", strcat(str1, str2));

	if(i==0)
	{
		printf("same\n");
	}
	else
	{
		printf("not same\n");
	}

	return 0;
}
