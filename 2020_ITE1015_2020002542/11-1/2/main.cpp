#include <iostream>
#include "my_string2.h"
using namespace std;

int main(void)
{
    string cmd; MyString2 a; MyString2 b;
    while (true) {
        cin >> cmd; string oper; string letter;
        if (cmd == "quit")
            break;
        else if (cmd == "new") {
            cout << "enter a" << endl;
            cin >> a;
            cout << "enter b" << endl;
            cin >> b;
        }
        else if (cmd == "a") {
            cin >> oper;
            if (oper == "+") {
                cin >> letter;
                if (letter == "a") {
                    MyString2 temp(a + a);
                    cout << temp;
                }
                else if (letter == "b") {
                    MyString2 temp(a + b);
                    cout << temp;
                }
            }
            else if (oper == "*") {
                int num;
                cin >> num;
                MyString2 temp(a * num);
                cout << temp;
            }
        }

        else if (cmd == "b") {
            cin >> oper;
            if (oper == "+") {
                cin >> letter;
                if (letter == "a") {
                    MyString2 temp(b + a);
                    cout << temp;
                }
                else if (letter == "b") {
                    MyString2 temp(b + b);
                    cout << temp;
                }
            }
            else if (oper == "*") {
                int num;
                cin >> num;
                MyString2 temp(b * num);
                cout << temp;
            }
        }
    }
    return 0;
}
