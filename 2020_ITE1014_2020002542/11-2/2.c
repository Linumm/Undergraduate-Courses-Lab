#include <stdio.h>

typedef struct
{
	char name[7];
	int score;
} Person;

void printScoreStars(Person* array, int len);

int main(void)
{
	Person arr[3];
	for (int i=0; i<3; i++)
	{
		scanf("%s %d", &arr[i].name, &arr[i].score);
	}
	printScoreStars(arr, 3);

	return 0;
}

void printScoreStars(Person* array, int len)
{
	for (int m=0; m<len; m++)
	{
		printf("%-7s", array[m].name);
		for (int n=0; n<(array[m].score/5); n++)
		{
			printf("*");
		}
		printf("\n");
	}
}
