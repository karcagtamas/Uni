#pragma once

#include "LinkedList.h"
#include "Queue.h"

template <class T>
class FIFOList : public LinkedList<T>, public Queue
{
    void push() override{

    };

    void pop() override{

    };
};