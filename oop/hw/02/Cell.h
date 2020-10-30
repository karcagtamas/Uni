#pragma once

#include <vector>

#define DEATH 12

enum Status
{
    Alive,
    Dead
};

class Cell
{
private:
    Status status;
    Status nextStatus = Dead;
    unsigned int aliveCounter = 0;
    bool hasCancer = false;

public:
    Cell() : status(Dead){};
    Cell(Status status) : status(status){};
    bool getStatus() const { return status; };
    void commit();
    void determineNextStatus(const std::vector<Cell> neighbours);
    char print() const;
};