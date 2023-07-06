#include <iostream>
#include "sorted.h"
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    string user_input; SortedArray sa;
    while (true) {
        cin >> user_input;
        if  (user_input=="ascend") {
            vector<int> temp=sa.GetSortedAscending();
            vector<int>::iterator it;
            for (it=temp.begin(); it!=temp.end(); it++)
                cout << *it << " ";
            cout << endl;
        }
        else if (user_input=="descend") {
            vector<int> temp=sa.GetSortedDescending();
            vector<int>::iterator it;
            for (it=temp.begin(); it!=temp.end(); it++)
                cout << *it << " ";
            cout << endl;
        }
        else if (user_input=="max")
            cout << sa.GetMax() << endl;
        else if (user_input=="min")
            cout << sa.GetMin() << endl;
        else if (user_input=="quit")
            break;
        else
            sa.AddNumber(stoi(user_input));
    }
    
    return 0;
}

