#include "triangle.h"
#include "math.h"

double Triangle::Area()
{
    double s = this->Perimeter() / 2;
    return std::sqrt(s * (s - this->a) * (s - this->b) * (s - this->c));
}

double Triangle::Perimeter()
{
    return this->a + this->b + this->c;
}