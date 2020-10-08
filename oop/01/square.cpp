#include "square.h"

double Square::Area()
{
    return this->width * this->height;
}

double Square::Perimeter()
{
    return 2 * (this->width + this->height);
}

bool Square::CheckSides()
{
    return this->width > 0 && this->height > 0;
}