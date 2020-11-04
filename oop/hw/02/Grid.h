#pragma once

#include <vector>
#include "Cell.h"

class Grid
{
private:
    const unsigned int rows = 10;
    const unsigned int cols = 10;
    unsigned int round = 0;
    std::vector<std::vector<Cell>> grid;

    void display() const;
    void determineNextStatus();
    void commitNextStatus();
    bool gridIsEmpty() const;

public:
    Grid(const unsigned int rows, const unsigned int cols);
    void simulate();
};