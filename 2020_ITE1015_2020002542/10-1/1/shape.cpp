#include <iostream>
#include "shape.h"
using namespace std;

Shape::Shape(double width, double height)
{
    width_=width; height_=height; //Shape's member var initialize
}

Rectangle::Rectangle(double width, double height): Shape::Shape(width, height) {}

double Rectangle::getArea()
{ return (width_ * height_); }

Triangle::Triangle(double width, double height): Shape::Shape(width ,height) {}

double Triangle::getArea()
{ return (width_ * height_)/2; }
