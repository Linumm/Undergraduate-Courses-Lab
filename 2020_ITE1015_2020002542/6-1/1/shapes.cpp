#include "shapes.h"
#include <cmath>
#include <iostream>
using namespace std;

void Circle::calc(double center_x, double center_y, double radius)
{
    x=center_x; y=center_y; r=radius;
    area=(3.14)*r*r; peri=2*(3.14)*r;
    cout << "area: " << area << ", perimeter: " << peri << endl;
}

void Rectangle::calc(double x1, double y1, double x2, double y2)
{
    tlx=x1; tly=y1; brx=x2; bry=y2;
    area=abs(tlx-brx)*abs(tly-bry);
    peri=2*abs(tlx-brx)+2*abs(tly-bry);

    cout << "area: " << area << ", perimeter: " << peri << endl;
}

