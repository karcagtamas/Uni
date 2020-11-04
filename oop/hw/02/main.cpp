#include <iostream>
#include <vector>

#include "Grid.h"

int main()
{
    std::cout << "Hello" << std::endl;

    unsigned int rows = 10;
    std::cout << "Rows: ";
    std::cin >> rows;

    unsigned int cols = 10;
    std::cout << "Cols: ";
    std::cin >> cols;

    Grid grid(rows, cols);
    grid.simulate();

    return 0;
}