#include <iostream>
#include "message.h"
#include <vector>
#include <string>
using namespace std;

int main(void) {
    string cmd, text; int phone_num; MessageBook mb;
    while (true) {
        cin >> cmd; //first receive command like 'add', 'delete' etc.
        if (cmd=="add") {
            cin >> phone_num;
            getline(cin, text);
            mb.AddMessage(phone_num, text);
        }
        else if (cmd=="delete") {
            cin >> phone_num;
            mb.DeleteMessage(phone_num);
        }
        else if (cmd=="print") {
            cin >> phone_num;
            cout << mb.GetMessage(phone_num) << endl;
        }
        else if (cmd=="list") {
            vector<int> temp=mb.GetNumbers();
            for (vector<int>::iterator it=temp.begin(); it!=temp.end(); it++) 
                cout << *it << ":" << mb.GetMessage(*it) << endl;
            cout << endl;
        }
        else if (cmd=="quit")
            break;

    }

    return 0;
}
