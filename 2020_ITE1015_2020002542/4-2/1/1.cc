#include <iostream>
using namespace std;

typedef struct {
    string name;
    int age;
} Person;

int main(void) {

    int n;
    cin >> n;
    Person* parr=new Person[n];

    for (int i=0; i<n; i++) 
        cin >> parr[i].name >> parr[i].age;
    for (int i=0; i<n; i++)
        cout << "Name:" << parr[i].name << ", Age:" << parr[i].age << endl;

    delete[] parr;

    return 0;
}
