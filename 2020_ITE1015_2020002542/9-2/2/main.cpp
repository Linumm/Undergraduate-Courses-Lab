#include <iostream>
#include <vector>
#include "canvas.h"
#include <string>
using namespace std;

int main(void)
{
    size_t size_row; size_t size_col;
    cin >> size_col >> size_row;
    Canvas _canvas(size_row, size_col); //Set Canvas.
    _canvas.Clear(); //cout << "_canvas.Clear()" << endl;
    _canvas.Print(); //cout << "_canvas.Print()" << endl;

    vector<Shape*> save; //save Shape* here.
    vector<string> info;

    while (true) {
        string cmd;
        cin >> cmd;

        if (cmd=="quit")
            break;
        else if (cmd=="add") {
            string cmd_shape; int x; int y;
            int width; int height; char brush;
            cin >> cmd_shape >> x >> y;

            if (cmd_shape=="rect") { //add rectangle
                cin >> width >> height >> brush;
                Shape* saver = new Rectangle(width, height, x, y, brush);
                save.push_back(saver);
                info.push_back("rect "+to_string(x)+" "+to_string(y)+" "+to_string(width)+" "+to_string(height)+" "+brush);
            }
            else if (cmd_shape=="diamond") { //add diamond
                cin >> width >> brush;
                Shape* saver = new Diamond(width, x, y, brush);
                save.push_back(saver);
                info.push_back("diamond "+to_string(x)+" "+to_string(y)+" "+to_string(width)+" "+brush);
            }
            else if (cmd_shape=="tri_up") { //add UpTriangle
                cin >> height >> brush;
                Shape* saver = new UpTriangle(height, x, y, brush);
                save.push_back(saver);
                info.push_back("tri_up "+to_string(x)+" "+to_string(y)+" "+to_string(height)+" "+brush);
            }
            else if (cmd_shape=="tri_down") { //add DownTriangle
                cin >> height >> brush;
                Shape* saver = new DownTriangle(height, x, y, brush);
                save.push_back(saver);
                info.push_back("tri_down "+to_string(x)+" "+to_string(y)+" "+to_string(height)+" "+brush);
            }
        }
        else if (cmd=="delete") {
            int index; cin >> index;
            if (index >=0 && index <save.size()) {
                delete save[index]; //delete dy-allocated shape vari.
                save.erase(save.begin()+index); //erase Shape* vector[index]
                info.erase(info.begin()+index); //erase info[index]
            }
        }
        else if (cmd=="draw") {
            _canvas.Clear();
            for (int i=0; i<save.size(); i++)
                save[i]->Draw(&_canvas);
            _canvas.Print();
        }
        else if (cmd=="dump") {
            for (int i=0; i<save.size(); i++) {
                cout << i << " ";
                cout << info[i];
                cout << endl;
            }
        }
        else if (cmd=="resize") {
            cin >> size_col >> size_row;
            _canvas.Resize(size_col, size_row);
        }
    }

    for (int i=0; i<save.size(); i++)
        delete save[i];
    return 0;
}
