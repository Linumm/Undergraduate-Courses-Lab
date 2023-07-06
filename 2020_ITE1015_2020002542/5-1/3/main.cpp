#include <iostream>
#include "minmax.h"
using namespace std;

int to_int(char *str) {
    int n=0; int i=0; int sign=1;

    if (*str=='-') {
        sign=-1;
        i=1;
    }

    while (*(str+i)) {
        n= n*10+ (*(str+i))-'0';
        i++;
    }
    n*=sign;
    return n;
}

int main(int argc, char* argv[]) {
    int n= argc-1;
    int min, max;
    int* array=new int[n];

    for (int i=0; i<n; i++)
        array[i]=to_int(argv[i+1]);

    getMinMax(array, n, min, max);

    cout << "min: " << min << endl;
    cout << "max: " << max << endl;

    delete[] array;
    return 0;
}
    
