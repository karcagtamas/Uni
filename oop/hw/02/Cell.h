#pragma once

#include <vector>

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

public:
    Cell() : status(Dead){};
    Cell(Status status) : status(status){};
    bool getStatus() const { return status; };
    void commit();
    void determineNextStatus(std::vector<Cell> neighbours);
};