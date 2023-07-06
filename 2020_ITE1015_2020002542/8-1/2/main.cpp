#include <iostream>
#include "rect.h"
using namespace std;

int main(void)
{
    string cmd; int width_input; int height_input;
    while (true) {
        cin >> cmd;
        if (cmd=="quit")
            break;
        cin >> width_input;

        if (cmd=="nonsquare") {
            cin >> height_input;
            NonSquare nsq(width_input, height_input);
            nsq.print();
        }
        else if (cmd=="square") {
            Square sq(width_input);
            sq.print();
        }

    }

    return 0;
}
            
