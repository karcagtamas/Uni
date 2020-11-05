#pragma once

#include "Node.h"

template <class T>
class LinkedList
{
private:
    Node<T> *root;

public:
    void add();
    void remove();
    Node<T> *get();
};