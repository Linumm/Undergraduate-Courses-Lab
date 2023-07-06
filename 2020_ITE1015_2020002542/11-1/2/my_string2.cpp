#include <iostream>
#include "my_string2.h"
#include <string>
using namespace std;

MyString2::MyString2() {}
MyString2::MyString2(const MyString2& my_string2)
{
    str=my_string2.str;
}

MyString2 MyString2::operator+(const MyString2& b)
{
    MyString2 rt_MyString2;
    rt_MyString2.str= str + b.str;

    return rt_MyString2;
}

MyString2 MyString2::operator*(const int b)
{
    MyString2 rt_MyString2;
    for (int i=0; i<b; i++)
        rt_MyString2.str += str;
    return rt_MyString2;
}

ostream& operator<<(ostream& out, MyString2& my_string)
{
    out << my_string.str << endl;
    return out;
}

istream& operator>>(istream& in, MyString2& my_string)
{
    in >> my_string.str;
    return in;
}
