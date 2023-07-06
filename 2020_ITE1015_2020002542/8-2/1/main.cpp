#include <iostream>
#include "shapes.h"
#include <string>
using namespace std;

int main(void)
{
    string cmd; int x; int y; int width; int height; char letter;
    int canvas_width; int canvas_height;
    
    cin >> canvas_width >> canvas_height;

    while (true) {
        cin >> cmd;
        if (cmd=="quit")
            break;
        else if (cmd=="rect") {
            cin >> x >> y >> width >> height >> letter;
            Rectangle rect(width, height, canvas_width, canvas_height);

            cout << "Area: " << rect.GetArea() << endl;
            cout << "Perimeter: " << rect.GetPerimeter() << endl;
            rect.Draw(x, y, letter);
        }

        else if (cmd=="square") {
            cin >> x >> y >> width >> letter;
            Square sq(width, canvas_width, canvas_height);

            cout << "Area: " << sq.GetArea() << endl;
            cout << "Perimeter: " << sq.GetPerimeter() << endl;
            sq.Draw(x, y, letter);
        }

        else if (cmd=="diamond") {
            cin >> x >> y >> width >> letter;
            Diamond dia(width, canvas_width, canvas_height);

            cout << "Area: " << dia.GetArea() << endl;
            cout << "Perimeter: " << dia.GetPerimeter() << endl;
            dia.Draw(x, y, letter);
        }

        cout << endl;
    }
    return 0;
}
