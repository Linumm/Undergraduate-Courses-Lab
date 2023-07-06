#include <stdio.h>

int main(void)
{
	int a;
	double b;
	scanf("%d %lf",&a,&b);
	printf("%10d %10d %10d \n", 2*a, 4*a, 8*a);
	printf("%10.2f %10.2f %10.2f \n", 2*b, 4*b, 8*b);

	return 0;
}
