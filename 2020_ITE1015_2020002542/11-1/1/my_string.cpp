#include <iostream>
#include "my_string.h"
#include <string>
using namespace std;

MyString& MyString::operator=(const MyString& b)
{
    MyString rt_MyString;
    rt_MyString.str = b.str;

    return rt_MyString;
}

MyString MyString::operator+(const MyString& b)
{
    MyString rt_MyString;
    rt_MyString.str = str + b.str;

    return rt_MyString;
}

MyString MyString::operator*(const int b)
{
    MyString rt_MyString;
    for (int i=0; i<b; i++)
        rt_MyString.str += str;
    return rt_MyString;
}

ostream& operator<<(ostream& out, MyString& my_string)
{
    out << my_string.str << endl;
    return out;
}

istream& operator>>(istream& in, MyString& my_string)
{
    in >> my_string.str;
    return in;
}
