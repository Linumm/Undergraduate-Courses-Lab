#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char*argv[]) {
    string str=argv[1];
    int n=atoi(argv[2]);
    for (int i=0; i<n; i++)
        cout << str << endl;

    return 0;
}
