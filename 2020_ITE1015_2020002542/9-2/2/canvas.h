#include <vector>
using namespace std;
class Canvas {
    public:
        Canvas(size_t row, size_t col);
        ~Canvas();
// Change this canvas size to(w * h). Preserve already existing shapes on the canvas.
        void Resize(size_t w, size_t h);
// Dot with the brush at (x,y). If (x,y) is outside the canvas, just ignore it.
        bool DrawPixel(int x, int y, char brush); 
//Print out the canvas
        void Print();
// Erase all (initialize with '.')
        void Clear();
    private:
        size_t canvas_r;
        size_t canvas_c;
	std::vector<vector<string>> canvasVec; 

// Define data member to save drawn shapes (note the resize function)
};
class Shape {
    public:
	virtual ~Shape();
        virtual void Draw(Canvas* canvas);
    protected:
        int shape_w;
        int shape_h;
	int x; int y;
        char brush;
};
class Rectangle : public Shape
{
    public:
        Rectangle(int width, int height, int x_, int y_, char brush_);
	~Rectangle();
	void Draw(Canvas* canvas);
};

class UpTriangle : public Shape
{
    public:
        UpTriangle(int height, int x_, int y_, char brush_);
	~UpTriangle();
	void Draw(Canvas* canvas);
};

class DownTriangle : public Shape
{
    public:
        DownTriangle(int height, int x_, int y_, char brush_);
	~DownTriangle();
	void Draw(Canvas* canvas);
};

class Diamond : public Shape
{
    public:
        Diamond(int width, int x_, int y_, char brush_);
	~Diamond();
	void Draw(Canvas* canvas);
};
