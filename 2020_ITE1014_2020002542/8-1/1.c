#include <stdio.h>

int add (int a, int b)
{
	return a+b;
}
int sub (int a, int b)
{
	return a-b;
}
int mul (int a, int b)
{
	return a*b;
}
double div (double a, double b)
{
	return a/b;
}
int mod( int a, int b)
{
	return a%b;
}
void printMsg()
{
	printf("completed\n");
}

int main (void)
{
	int a, b;
	scanf("%d", &a);
	scanf("%d", &b);
	printf("sum: %d\n", add(a, b));
	printf("difference: %d\n", sub(a, b));
	printf("product: %d\n", mul(a, b));
	a=(float)a, b=(float)b;
	printf("division: %f\n", div(a, b));
	a=(int)a, b=(int)b;
	printf("remainder: %d\n", mod(a, b));
	printMsg();

	return 0;
}
