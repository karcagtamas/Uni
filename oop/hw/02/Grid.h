#pragma once

#include <vector>
#include "Cell.h"

class Grid
{
private:
    unsigned int rows = 10;
    unsigned int cols = 10;
    unsigned int round = 0;
    std::vector<std::vector<Cell>> grid;

    void display();
    void simulate();

public:
    Grid(unsigned int rows, unsigned int cols);
};