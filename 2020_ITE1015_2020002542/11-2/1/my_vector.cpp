#include <iostream>
#include "my_vector.h"
using namespace std;

MyVector::MyVector() {}
MyVector::MyVector(int length)
{
    this->length = length+1;
    a = new double[this->length];
}

MyVector::~MyVector() { delete[] a; }

MyVector& MyVector::operator=(const MyVector& b)
{
    length = b.length;
    a = b.a;
    return *this;
}

MyVector MyVector::operator+(const MyVector& b)
{
    MyVector rt_Vec(length);
    for (int i=1; i<length; i++)
        rt_Vec.a[i] = a[i] + b.a[i];
    return rt_Vec;
}

MyVector MyVector::operator-(const MyVector& b)
{
    MyVector rt_Vec(length);
    for (int i=1; i<length; i++)
        rt_Vec.a[i] = a[i] - b.a[i];
    return rt_Vec;
}

MyVector MyVector::operator+(const int b)
{
    MyVector rt_Vec(length);
    for (int i=1; i<length; i++)
        rt_Vec.a[i] = a[i] + b;
    return rt_Vec;
}

MyVector MyVector::operator-(const int b)
{
    MyVector rt_Vec(length);
    for (int i=1; i<length; i++)
        rt_Vec.a[i] = a[i] - b;
    return rt_Vec;
}

//<< , >>
ostream& operator<< (ostream& out, MyVector& b)
{
    for (int i=1; i<b.length-1; i++)
        out << b.a[i] << " ";
    return out;
}

istream& operator>> (istream& in, MyVector& b)
{
    for (int i=1; i<b.length; i++)
        in >> b.a[i];
    return in;
}
