#include <iostream>
#include <vector>
#include "canvas.h"
using namespace std;
//================================================= Class <Canvas>
Canvas::Canvas(size_t row, size_t col)
{    
    canvas_r=row; canvas_c=col;
}

Canvas::~Canvas() {};

void Canvas::Resize(size_t w, size_t h)
{
    canvas_r=h; canvas_c=w;
    Clear();
}

bool Canvas::DrawPixel(int x, int y, char brush)
{
    if (x<=canvas_c && x>=1) {
        if (y<=canvas_r && y>=1) {
            canvasVec[y][x]=brush;
            return true;
        }
    }
    else
        return false;
}

void Canvas::Print()
{
    for (int i=0; i<canvasVec.size(); i++) {
        for (int j=0; j<canvasVec[i].size(); j++) 
            cout << canvasVec[i][j];
        cout << endl;
    }
}

void Canvas::Clear()
{
    canvasVec.clear();
    canvasVec.resize(canvas_r+1);
    for (int i=0; i<canvas_r+1; i++)
        canvasVec[i].resize(canvas_c+1);

    canvasVec[0][0]=' ';

    for (int i=0; i<canvas_c; i++) //seg error here.
        if (i>9) 
            canvasVec[0][i+1]=to_string(i-10);
        else 
            canvasVec[0][i+1]=to_string(i);
    for (int j=0; j<canvas_r; j++) {
        for (int dot=0; dot<canvas_c; dot++)
            canvasVec[j+1][dot+1]='.';
        if (j>9)
            canvasVec[j+1][0]=to_string(j-10);
        else
            canvasVec[j+1][0]=to_string(j);
    }
}
//==============================================class <Shape>
Shape::~Shape() {}
void Shape::Draw(Canvas* canvas) {}
//==============================================class <Rectangle>
Rectangle::Rectangle(int width, int height, int x_, int y_, char brush_)
{
    shape_w=width; shape_h=height; x=x_; y=y_; brush=brush_;
}
Rectangle::~Rectangle() {}

void Rectangle::Draw(Canvas* canvas)
{
    for (int i=1; i<shape_h+1; i++) {
        for (int j=1; j<shape_w+1; j++)
            (*canvas).DrawPixel(x+j, y+i, brush);
    }
}
//===============================================class <UpTriangle>
UpTriangle::UpTriangle(int height, int x_, int y_, char brush_)
{
    shape_h=height; x=x_; y=y_; brush=brush_;
}
UpTriangle::~UpTriangle() {}

void UpTriangle::Draw(Canvas* canvas)
{
    for (int i=0; i<shape_h; i++) {
        for (int j=0; j<shape_h-i; j++) {
            (*canvas).DrawPixel(x+i+1, y+j+i+1, brush);
            (*canvas).DrawPixel(x-i+1, y+j+i+1, brush);
        }
    }
}
//===============================================class <DownTriangle>
DownTriangle::DownTriangle(int height, int x_, int y_, char brush_)
{
    shape_h=height; x=x_; y=y_; brush=brush_;
}
DownTriangle::~DownTriangle() {}

void DownTriangle::Draw(Canvas* canvas)
{
    for (int i=0; i<shape_h; i++) {
        for (int j=0; j<shape_h-i; j++) {
            (*canvas).DrawPixel(x+i+1, y-j-i+1, brush);
            (*canvas).DrawPixel(x-i+1, y-j-i+1, brush);
        }
    }
}
//===============================================class <Diamond>
Diamond::Diamond(int width, int x_, int y_, char brush_)
{
    shape_w=(2*width+1); x=x_; y=y_; brush=brush_;
}
Diamond::~Diamond() {}

void Diamond::Draw(Canvas* canvas)
{
    for (int i=0; i<shape_w+1; i++) {
        for (int j=0; j<shape_w-(2*i); j++) {
            (*canvas).DrawPixel(x+i+1, y+j+i+1, brush);
            (*canvas).DrawPixel(x-i+1, y+j+i+1, brush);
        }
    }
}
