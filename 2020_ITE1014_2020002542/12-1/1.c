#include <stdio.h>

#define PI 3.14

int main()
{
	double r;
	scanf("%lf", &r);
	printf("Perimeter: %f\n", 2*PI*r);
	printf("Area: %f\n", PI*r*r);

	return 0;
}

