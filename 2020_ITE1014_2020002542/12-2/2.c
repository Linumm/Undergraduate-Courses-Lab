#include <stdio.h>
#include <string.h>

int main()
{
	char list[10][21];
	int i=0;
	int check=1;

	while (1)
	{
		printf("Enter a word (Enter 'end' to quit): ");
		scanf("%s", list[i]);
		if (strcmp(list[i], "end")==0)
		{
			break;
		}
		for (int x=0; x<i; x++)
		{
			if (strcmp(list[x], list[i])==0)
			{
				printf("This word already exist. PLease enter another word.\n");
				i--;
				break;
			}
		}
		i++;
	}

	printf("%d words in the list:\n", i);
	for (int p=0; p<i; p++)
	{
		printf("%s ", list[p]);
	}
	printf("\n");

	char schinput[21];
	check=1;

	while (1)
	{
		printf("Enter a word to search (Enter 'end' to quit): ");
		scanf("%s", schinput);
		if (strcmp(schinput, "end")==0)
		{
			break;
		}
		for (int m=0; m<i; m++)
		{
			if (strcmp(list[m], schinput)==0)
			{
				check=0;
				break;
			}
		}
		if (check==0)
		{
			printf("This word is in the list.\n");
		}
		else
		{
			printf("This word is NOT in the list.\n");
		}
		check=1;
	}
	
	return 0;
}
