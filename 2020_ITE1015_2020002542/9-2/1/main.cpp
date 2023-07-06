#include <iostream>
#include "animal.h"
#include <vector>
using namespace std;

int main(void)
{
    vector<Animal*> animals; string cmd;
    while (true)
    {
        cin >> cmd;
        if (cmd=="0")
            break;
        else if (cmd=="z") {
            string name; int age; int numStripes;
            cin >> name >> age >> numStripes;

            Animal* pz= new Zebra(name, age, numStripes);
            animals.push_back(pz);
        }
        else if (cmd=="c") {
            string name; int age; string favoriteToy;
            cin >> name >> age >> favoriteToy;

            Animal* pc= new Cat(name, age, favoriteToy);
            animals.push_back(pc);
        }
    }

    for (int i=0; i<animals.size(); i++)
        animals[i]->printInfo();
    for (int i=0; i<animals.size(); i++)
        delete animals[i];
    
    return 0;
}
