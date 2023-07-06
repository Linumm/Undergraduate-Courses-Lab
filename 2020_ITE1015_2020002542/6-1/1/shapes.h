//shapes.h header_file
class Circle
{
    private:
        double x; double y; double r;
        double area; double peri;
    public:
        void calc(double center_x, double center_y, double radius);
};

class Rectangle
{
    private:
        double tlx; double tly; double brx; double bry;
        double area; double peri;
    public:
        void calc(double x1, double y1, double x2, double y2);
};
