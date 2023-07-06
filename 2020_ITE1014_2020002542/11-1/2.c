#include <stdio.h>

struct nameage
{
	char name[50];
	int age;
};
typedef struct nameage Na;

int main(void)
{
	Na info1;
	scanf("%s %d", &info1.name, &info1.age);
	printf("name: %s\n", info1.name);
	printf("age: %d\n", info1.age);

	return 0;
}
