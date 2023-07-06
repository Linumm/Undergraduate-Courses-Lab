#include "shapes.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Shape Class-------
Shape::Shape() {}
Shape::Shape(int shapeWidth, int shapeHeight)
{
    shape_w=shapeWidth;
    shape_h=shapeHeight;
}

double Shape::GetArea() //subclass's getarea->by overriding
{
    return (shape_w)*(shape_h);
}

int Shape::GetPerimeter() //subclass's getPeri-> by overriding
{
    return 2*((shape_w)+(shape_h));
}

void Shape::Draw(int canvas_width, int canvas_height) 
{
    canvas.clear();
    canvas.resize((canvas_width)+1); //canvas vector resize
    for (int p=0; p<canvas_width+1; p++)
        canvas[p].resize((canvas_height)+1);

    canvas[0][0]=' '; //fill canvas

    for (int i=0; i<canvas_width; i++)
        canvas[0][i+1]=to_string(i);

    for (int j=0; j<canvas_height; j++) {
        for (int dot=0; dot<canvas_width; dot++)
            canvas[j+1][dot+1]='.';
        canvas[j+1][0]=to_string(j);
    }
}

//Rectangle Class----
Rectangle::Rectangle(int width, int height, int canvas_width, int canvas_height):
    Shape(width, height) {canvas_w=canvas_width; canvas_h=canvas_height;}

double Rectangle::GetArea() {return Shape::GetArea();}
int Rectangle::GetPerimeter() {return Shape::GetPerimeter();}

void Rectangle::Draw(int x_cord, int y_cord, char letter)
{
    Shape::Draw(canvas_w, canvas_h);//fill canvas(vector)

    for (int row=1; row<shape_h+1; row++) {
        if (y_cord+row>canvas_h)
            break;
        for (int col=1; col<shape_w+1; col++) {
            if (x_cord+col>canvas_w)
                break;
            canvas[y_cord+row][x_cord+col]=letter;
        }
    } cout << endl;

    for (int i=0; i<canvas.size(); i++) { //print out canvas
        for (int j=0; j<canvas[i].size(); j++)
            cout << canvas[i][j];
        cout << endl;
    }
}

//Square Class------
Square::Square(int width, int canvas_width, int canvas_height): Shape(width, width)
{canvas_w=canvas_width; canvas_h=canvas_height;}

double Square::GetArea() {return Shape::GetArea();}
int Square::GetPerimeter() {return Shape::GetPerimeter();}

void Square::Draw(int x_cord, int y_cord, char letter)
{
    Shape::Draw(canvas_w, canvas_h); //same with rectangle.

    for (int row=1; row<shape_h+1; row++) {
        if (y_cord+row>canvas_h)
            break;
        for (int col=1; col<shape_w+1; col++) {
            if (x_cord+col>canvas_w)
                break;
            canvas[y_cord+row][x_cord+col]=letter;
        }
    }

    for (int i=0; i<canvas.size(); i++) {
        for (int j=0; j<canvas[i].size(); j++)
            cout << canvas[i][j];
        cout << endl;
    }
}

//Diamond Class-----
Diamond::Diamond(int width, int canvas_width, int canvas_height): Shape(2*width+1, 2*width+1)
{canvas_w=canvas_width; canvas_h=canvas_height;}

double Diamond::GetArea() {return (Shape::GetArea())/2;}
int Diamond::GetPerimeter() {return 4*((shape_w-1)/2+1);}

void Diamond::Draw(int x_cord, int y_cord, char letter)
{
    Shape::Draw(canvas_w, canvas_h);
    for (int i=0; i<shape_w+1; i++) {
        for (int j=0; j<shape_w-(2*i); j++) {
            if (y_cord+j+i+1<=canvas_h && x_cord+i+1<=canvas_w)
                canvas[y_cord+j+i+1][x_cord+i+1]=letter;
            if (y_cord+j+i+1<=canvas_h && x_cord-i+1>=1)
                canvas[y_cord+j+i+1][x_cord-i+1]=letter;
        }
    }
    cout << endl; 
    for (int i=0; i<canvas.size(); i++) {
        for (int j=0; j<canvas[i].size(); j++)
            cout << canvas[i][j];
        cout << endl;
    }
}
