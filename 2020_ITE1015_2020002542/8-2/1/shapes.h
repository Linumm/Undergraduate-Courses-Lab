#include <vector>
#include <string>
using namespace std;
class Shape {
    public:
        Shape();
        Shape(int shapeWidth, int shapeHeight);
        double GetArea();
        int GetPerimeter();
        void Draw(int canvas_width, int canvas_height);
    protected:
        int shape_w;
        int shape_h;
        vector<vector<string>> canvas;
        int canvas_w;
        int canvas_h;
};

class Rectangle: public Shape {
    public:
        Rectangle(int width, int height, int canvas_width, int canvas_height);
	double GetArea();
	int GetPerimeter();
	void Draw(int x_cord, int y_cord, char letter);
};

class Square: public Shape {
    public:
        Square(int width, int canvas_width, int canvas_height);
	double GetArea();
	int GetPerimeter();
	void Draw(int x_cord, int y_cord, char letter);
};

class Diamond: public Shape {
    public:
        Diamond(int width, int canvas_width, int canvas_height);
	double GetArea();
	int GetPerimeter();
	void Draw(int x_cord, int y_cord, char letter);
};
