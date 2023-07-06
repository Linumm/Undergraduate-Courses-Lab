#include <iostream>
#include <vector>
using namespace std;

class A {
    public:
        virtual string test() {return "A::test()";}
};
class B: public A {
    public:
        virtual string test() {return "B::test()";}
};
class C: public B {
    public:
        virtual string test() {return "C::test()";}
};

int main(void)
{
    vector<A*> arr;
    A* pa= new A; A* pb= new B; A* pc= new C;
    arr.push_back(pa); arr.push_back(pb); arr.push_back(pc);

    for (int i=0; i<arr.size(); i++)
        cout << arr[i]->test() << endl;

    delete pa; delete pb; delete pc;
    return 0;
}
