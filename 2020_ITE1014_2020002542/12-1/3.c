#include <stdio.h>

void printString(const char* str)
{
	printf("%s\n", str);
}

int main()
{
	void (*pS) (const char*);
	pS=printString;

	char str[]="One";
	pS(str);
		
	return 0;
}
