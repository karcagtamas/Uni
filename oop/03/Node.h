#pragma once

#include "LinkedList.h"
#include "Person.h"
#include <iostream>

template <class T>
class Node;
template <class T>
std::ostream &operator<<(std::ostream &out, const Node<T> &);
template <class T>
class Node
{
private:
    Node *next;
    T *data;

public:
    Node(T *data) : next(nullptr), data(data){};
    void setNext(Node *next) { this->next = next; };
    Node *getNext() const { return next; };
    T *getData() const { return data; };
    friend std::ostream &operator<<(std::ostream &os, Node<T> &n)
    {
        os
            << *n.getData();
        return os;
    };

    // friend LinkedList;
};