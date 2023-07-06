#include <iostream>
#include "number.h"
using namespace std;

int main(void)
{
    string cmd; int user_input;
    while (true) {
        cin >> cmd;
        if (cmd=="quit")
            break;

        cin >> user_input;
        if (cmd=="number") {
            Number num;
            num.setNumber(user_input);
            cout << "getNumber(): " << num.getNumber() << endl;
        }
        else if (cmd=="square") {
            Square sq;
            sq.setNumber(user_input);
            cout << "getNumber(): " << sq.getNumber() << endl;
            cout << "getSquare(): " << sq.getSquare() << endl;
        }
        else if (cmd=="cube") {
            Cube cb;
            cb.setNumber(user_input);
            cout << "getNumber(): " << cb.getNumber() << endl;
            cout << "getSquare(): " << cb.getSquare() << endl;
            cout << "getCube(): "   << cb.getCube()   << endl;
        }
    }

    return 0;
}
            
