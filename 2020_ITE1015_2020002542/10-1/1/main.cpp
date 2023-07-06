#include <iostream>
#include "shape.h"
#include <vector>
using namespace std;

int main(void)
{
    vector<Shape*> arr; string cmd;
    int width; int height;
    while (true) {
        cin >> cmd;
        if (cmd == "0") {
            for (int i=0; i<arr.size(); i++)
                cout << arr[i]->getArea() << endl;
            break;
        }
        else if (cmd == "r") {
            cin >> width >> height;
            Shape* ptr= new Rectangle(width, height);
            arr.push_back(ptr);
        }
        else if (cmd== "t") {
            cin >> width >> height;
            Shape* ptr= new Triangle(width, height);
            arr.push_back(ptr);
        }
    }

    for (int i=0; i<arr.size(); i++)
        delete arr[i];
    return 0;
}
