#include <stdio.h>
#include <string.h>

int palindrome(char arr1[]);
int main(void)
{
	char arr1[50];
	scanf("%s", arr1);
	if (palindrome(arr1)==0)
	{
		printf("This is not a palindrome.\n");
	}
	else
	{
		printf("THis is a palindrome.\n");
	}

	return 0;
}

int palindrome(char arr1[])
{
	char arr2[50];
	for (int i=0; i<strlen(arr1); i++)
	{
		arr2[i]=arr1[strlen(arr1)-(i+1)];
	}
	if (strcmp(arr1, arr2)==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
