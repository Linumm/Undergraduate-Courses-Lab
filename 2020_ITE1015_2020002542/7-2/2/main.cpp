#include <iostream>
#include "setfunc.h"
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int main(void) {
    string start, set0, set1, operate;
    while (true) {
        cin >> start;
        if (start=="0") break;
        getline(cin, set0, '}');
        cin >> operate;

        if (operate=="+") {
            getline(cin, set1, '}');
            printSet(getUnion(parseSet(set0), parseSet(set1)));
        }
        else if (operate=="*") {
            getline(cin, set1, '}');
            printSet(getIntersection(parseSet(set0), parseSet(set1)));
        }
        else if (operate=="-") {
            getline(cin, set1, '}');
            printSet(getDifference(parseSet(set0), parseSet(set1)));
        }
    }

    return 0;
}
