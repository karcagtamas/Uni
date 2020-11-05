#pragma once

class Queue
{
public:
    virtual ~Queue(){};
    virtual void push() = 0;
    virtual void pop() = 0;
};
