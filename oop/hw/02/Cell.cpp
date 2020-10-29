#include "Cell.h"

void Cell::commit()
{
    this->status = this->nextStatus;
    this->nextStatus = Dead;
}

void Cell::determineNextStatus(std::vector<Cell> neighbours)
{
    unsigned int countOfAlive = 0;

    for (unsigned int i = 0; i < neighbours.size(); i++)
    {
        if (neighbours[i].getStatus() == Alive)
        {
            countOfAlive++;
        }
    }
    if (status == Alive)
    {
        if (countOfAlive == 2 || countOfAlive == 3)
        {
            this->nextStatus = Alive;
        }
    }
    else if (status == Dead)
    {
        if (countOfAlive == 3)
        {
            this->nextStatus = Alive;
        }
    }
}