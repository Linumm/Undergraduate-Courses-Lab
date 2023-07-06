#include <iostream>
#include <vector>
using namespace std;

class B
{
public:
 virtual ~B() {}
};
class C : public B
{
public:
 void test_C() { std::cout << "C::test_C()" << std::endl; }
};
class D : public B
{
public:
 void test_D() { std::cout << "D::test_D()" << std::endl; }
};

int main(void)
{
    vector<B*> arr; string cmd;
    while (true) {
        cin >> cmd;
        if (cmd == "0") {
            for (int i=0; i<arr.size(); i++) {
                if (dynamic_cast<C*>(arr[i])) {
                    C* ptr= dynamic_cast<C*>(arr[i]);
                    ptr->test_C();
                }
                else if (dynamic_cast<D*>(arr[i])) {
                    D* ptr= dynamic_cast<D*>(arr[i]);
                    ptr->test_D();
                }
            }
            break;
        }
        else if (cmd =="B") {
            B* ptr= new B;
            arr.push_back(ptr);
        }
        else if (cmd =="C") {
            B* ptr= new C;
            arr.push_back(ptr);
        }
        else if (cmd =="D") {
            B* ptr= new D;
            arr.push_back(ptr);
        }
    }

    for (int i=0; i<arr.size(); i++)
        delete arr[i];
    return 0;
}
