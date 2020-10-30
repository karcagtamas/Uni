#include "Grid.h"
#include "Cell.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>

#define LIMIT 300000
#define ROUND 1000

Grid::Grid(unsigned int rows, unsigned int cols) : rows(rows), cols(cols)
{
    srand(time(NULL));
    for (unsigned int i = 0; i < rows; i++)
    {
        std::vector<Cell> row;
        for (unsigned int j = 0; j < cols; j++)
        {
            const Status status = rand() % 2 == 0 ? Dead : Alive;
            row.push_back(Cell(status));
        }
        grid.push_back(row);
    }
    simulate();
};

void Grid::simulate()
{
    round++;
    display();
    determineNextStatus();
    commitNextStatus();
    if (!gridIsEmpty() || round < ROUND)
    {
        usleep(LIMIT);
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
            std::cout << (grid[i][j].getStatus() == Dead ? " " : "*");
        }

        std::cout << std::endl;
    }
}

void Grid::determineNextStatus()
{
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < cols; j++)
        {
            std::vector<Cell> cells;
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    if (!(x == 0 && y == 0))
                    {
                        if (i + x >= 0 && i + x < rows && j + y >= 0 && j + y < cols)
                        {
                            cells.push_back(grid[i + x][j + y]);
                        }
                    }
                }
            }
            grid[i][j].determineNextStatus(cells);
        }
    }
}

void Grid::commitNextStatus()
{
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < cols; j++)
        {
            grid[i][j].commit();
        }
    }
}

bool Grid::gridIsEmpty()
{
    unsigned int count = 0;
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < cols; j++)
        {
            if (grid[i][j].getStatus() == Alive)
            {
                count++;
            }
        }
    }
    return count == 0;
}