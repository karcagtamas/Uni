class Square
{
    double width;
    double height;

public:
    Square(double width, double height) : width(width), height(height){};
    double Area();
    double Perimeter();
    bool CheckSides();
};