#include <iostream>
#include <cstring>
#include "shapes.h"
using namespace std;

int main() {
    while (true) {
        string shape;
        cout << "shape?" << endl;
        cin >> shape;

        if (shape=="C") {
            double x; double y; double r;
            cin >> x >> y >> r;
            Circle cir;
            cir.calc(x, y, r);
        }

        else if (shape=="R") {
            double tlx; double tly; double brx; double bry;
            cin >> tlx >> tly >> brx >> bry;
            Rectangle rec;
            rec.calc(tlx, tly, brx, bry);
        }

        else if (shape=="Q")
            break;
    }
    return 0;
}
