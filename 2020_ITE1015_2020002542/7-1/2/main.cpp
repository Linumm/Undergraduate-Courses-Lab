#include <iostream>
#include "intset.h"
#include <vector>
using namespace std;

int main(void) {
    string cmd; int num; IntegerSet intset;
    while (true) {
        cin >> cmd;
        if (cmd=="quit")
            break;
        else if (cmd=="add") {
            cin >> num;
            intset.AddNumber(num);
            vector<int> main_vec=intset.GetAll();
            for (int i=0; i<(int)main_vec.size(); i++)
                cout << main_vec[i] << " ";
        }
        else if (cmd=="del") {
            cin >> num;
            intset.DeleteNumber(num);
            vector<int> main_vec=intset.GetAll();
            for (int i=0; i<(int)main_vec.size(); i++)
                cout << main_vec[i] << " ";
        }
        else if (cmd=="get") {
            cin >> num;
            cout << intset.GetItem(num) << endl;
        }
        cout << endl;
    }

    return 0;
}

