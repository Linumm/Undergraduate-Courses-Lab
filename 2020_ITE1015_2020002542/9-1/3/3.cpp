#include <iostream>
#include <vector>
using namespace std;

class A {//------------------------------------------<class A>
    private:
        int* memberA;
    public:
        A(int num) {
            memberA = new int(num);
            cout << "new memberA" << endl;
        }
        virtual ~A() {
            delete memberA;
            cout << "delete memberA" << endl;
        }
        virtual void print() {
            cout << "*memberA " << *memberA << endl;
        }
};

class B: public A {//--------------------------------<class B>
    private:
        double* memberB;
    public:
        B(double num): A(1) {
            memberB = new double(num);
            cout << "new memberB" << endl;
        }
        virtual ~B() {
            delete memberB;
            cout << "delete memberB" << endl;
        }
        virtual void print() {
            A::print();
            cout << "*memberB " << *memberB << endl;
        }
};

class C: public B {//--------------------------------<class C>
    private:
        string* memberC;
    public:
        C(const string& str): B(1.1) {
            memberC = new string(str);
            cout << "new memberC" << endl;
        }
        virtual ~C() {
            delete memberC;
            cout << "delete memberC" << endl;
        }
        virtual void print() {
            B::print();
            cout << "*memberC " << *memberC << endl;
        }
};
//---------------------------------------------------<main function>
int main(void)
{
    int num1; double num2; string str;
    cin >> num1 >> num2 >> str;

    A* pa=new A(num1); A* pb=new B(num2); A* pc=new C(str);
    vector<A*> arr;
    arr.push_back(pa); arr.push_back(pb); arr.push_back(pc);

    for (int i=0; i<arr.size(); i++)
        arr[i]->print();

    delete pa; delete pb; delete pc;
    return 0;
}

