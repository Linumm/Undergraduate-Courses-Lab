#include <iostream>
#include "animal.h"
using namespace std;
//--------------------------------------------class <Animal>
Animal::Animal(string name_, int age_)
{
    name=name_; age=age_;
}

void Animal::printInfo() {}

//--------------------------------------------class <Zebra>
Zebra::Zebra(string name_, int age_, int numStripe_): Animal(name_, age_)
{ numStripes = numStripe_; }

void Zebra::printInfo()
{
    cout << "Zebra, Name: " << name;
    cout << ", Age: " << age << ", Number of stripes: " << numStripes << endl;
}

//--------------------------------------------class <Cat>
Cat::Cat(string name_, int age_, string favoriteToy_): Animal(name_,age_)
{ favoriteToy = favoriteToy_; }

void Cat::printInfo()
{
    cout << "Cat, Name: " << name;
    cout << ", Age: " << age << ", Favorite toy: " << favoriteToy << endl;
}

