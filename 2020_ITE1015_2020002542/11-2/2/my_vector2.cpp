#include <iostream>
#include "my_vector2.h"
using namespace std;

MyVector2::MyVector2() { a=NULL; }
MyVector2::MyVector2(int length)
{
    this->length = length+1;
    a = new double[this->length];
}

MyVector2::MyVector2(const MyVector2& mv)
{
    length = mv.length;
    a = mv.a;
}
MyVector2::~MyVector2() { delete[] a;}

MyVector2 MyVector2::operator+(const MyVector2& b)
{
    MyVector2 rt_Vec(length);
    for (int i=1; i<length; i++)
        rt_Vec.a[i] = a[i] + b.a[i];
    return rt_Vec;
}

MyVector2 MyVector2::operator-(const MyVector2& b)
{
    MyVector2 rt_Vec(length);
    for (int i=1; i<length; i++)
        rt_Vec.a[i] = a[i] - b.a[i];
    return rt_Vec;
}

MyVector2 MyVector2::operator+(const int b)
{
    MyVector2 rt_Vec(length);
    for (int i=1; i<length; i++)
        rt_Vec.a[i] = a[i] + b;
    return rt_Vec;
}

MyVector2 MyVector2::operator-(const int b)
{
    MyVector2 rt_Vec(length);
    for (int i=1; i<length; i++)
        rt_Vec.a[i] = a[i] - b;
    return rt_Vec;
}

//<< , >>
ostream& operator<< (ostream& out, MyVector2& b)
{
    for (int i=1; i<b.length-1; i++)
        out << b.a[i] << " ";
    return out;
}

istream& operator>> (istream& in, MyVector2& b)
{
    for (int i=1; i<b.length; i++)
        in >> b.a[i];
    return in;
}
