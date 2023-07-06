#include <iostream>
#include <vector>
using namespace std;

class A {
    public:
        virtual string getTypeInfo()
        {return "This is an instance of class A";}
};
class B: public A {
    public:
        virtual string getTypeInfo()
        {return "This is an instance of class B";}
};
class C: public B {
    public:
        virtual string getTypeInfo()
        {return "This is an instance of class C";}
};

void printObjectTypeInfo(A* object)
{ cout << object->getTypeInfo() << endl; }

void printObjectTypeInfo(A& object)
{ cout << object.getTypeInfo() << endl; }

int main(void)
{
    A* pa= new A; A* pb= new B; A* pc= new C;
    vector<A*> arr;
    arr.push_back(pa); arr.push_back(pb); arr.push_back(pc);

    for (int i=0; i<arr.size(); i++) {
        printObjectTypeInfo(arr[i]);
        printObjectTypeInfo(*arr[i]);
    }

    delete pa; delete pb; delete pc;
    return 0;
}
