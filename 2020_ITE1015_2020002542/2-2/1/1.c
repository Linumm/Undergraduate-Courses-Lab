#include <stdio.h>

void rotateLeft(int* pa, int* pb, int* pc)
{
    int temp;
    temp=*pc;
    *pc=*pa;
    *pa=*pb;
    *pb=temp;
}

void rotateRight(int* pa, int* pb, int* pc)
{
    int temp;
    temp=*pc;
    *pc=*pb;
    *pb=*pa;
    *pa=temp;
}

int main(void)
{
    int a=10, b=20, c=30;
    printf("%d:%d:%d\n", a, b, c);
    
    int inputValue;
    
    while (1)
    {
	scanf("%d", &inputValue);
	if (inputValue!=1 && inputValue!=2)
	    break;
	if (inputValue==1){
	    rotateLeft(&a, &b, &c);
	    printf("%d:%d:%d\n", a, b, c);}
	if (inputValue==2){
	    rotateRight(&a, &b, &c);
	    printf("%d:%d:%d\n", a, b, c);}
    }
    return 0;
}
