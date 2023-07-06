#include <stdio.h>

void square(double* pnum)
{
	*pnum=(*pnum)*(*pnum);
}

int main(void)
{
	double dvar;
	scanf("%lf", &dvar);
	square(&dvar);
	printf("%f\n", dvar);

	return 0;
}
