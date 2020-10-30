#include "Cell.h"
#include <iostream>

void Cell::commit()
{
    this->status = this->nextStatus;
    this->nextStatus = Dead;

    if (this->status == Dead && this->hasCancer)
    {
        this->hasCancer = false;
    }
}

void Cell::determineNextStatus(const std::vector<Cell> neighbours)
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
            this->aliveCounter++;
        }

        if (aliveCounter == DEATH && !this->hasCancer)
        {
            this->nextStatus = Dead;
        }
    }
    else if (status == Dead)
    {
        if (countOfAlive == 3)
        {
            this->nextStatus = Alive;
            this->hasCancer = rand() % 20 == 0;
            this->aliveCounter = 0;
        }
    }
}

char Cell::print() const
{
    return this->status == Dead ? ' ' : this->hasCancer ? '#' : '*';
}