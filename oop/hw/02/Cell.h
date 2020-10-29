#pragma once

class Cell
{
private:
    bool empty;

public:
    Cell() : empty(true){};
    Cell(bool empty) : empty(empty){};
    bool isEmpty() const { return empty; };
};