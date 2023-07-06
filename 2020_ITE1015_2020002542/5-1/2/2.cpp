#include <iostream>
#include <string>
using namespace std;

struct Person {
    string name;
    double score;
};

int main(int argc, char* argv[]) {
    int n=(argc-1)/2;
    Person* array=new Person[n];
    for (int i=0; i<n; i++) {
        array[i].name=argv[2*i+1];
        array[i].score=stof(argv[2*i+2]);
    }

    for (int i=0; i<n; i++)
        cout << "Name:" << array[i].name << ", Score:" << array[i].score << endl;

    delete[] array;
    return 0;
}

