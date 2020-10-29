#include "Grid.h"
#include "Cell.h"
#include <iostream>
#include <string>

Grid::Grid(unsigned int rows, unsigned int cols) : rows(rows), cols(cols)
{
    srand(time(NULL));
    for (unsigned int i = 0; i < rows; i++)
    {
        std::vector<Cell> row;
        for (unsigned int j = 0; j < cols; j++)
        {
            const bool alive = rand() % 2;
            row.push_back(Cell(alive));
        }
        grid.push_back(row);
    }
    display();
    simulate();
};

void Grid::simulate()
{
    round++;
    display();
    if (round < 20)
    {
        simulate();
    }
}

void Grid::display()
{
    system("clear");
    std::cout << "Round: " << (round == 0 ? "Start" : std::to_string(round)) << std::endl;
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < cols; j++)
        {
            std::cout << (grid[i][j].isEmpty() ? " " : "*");
        }

        std::cout << std::endl;
    }
}