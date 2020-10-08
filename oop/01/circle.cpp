#include "circle.h"
#include "math.h"

double Circle::Area()
{
    return std::pow(this->r, 2) * M_PI;
}

double Circle::Perimeter()
{
    return 2 * this->r * M_PI;
}

bool Circle::CheckR()
{
    return this->r > 0;
}