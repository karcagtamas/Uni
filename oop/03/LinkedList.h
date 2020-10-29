#pragma once
#include "Node.h"
#include "Person.h"
#include <iostream>

template <class T>
class LinkedList
{
private:
    Node<T> *root;
    Node<T> *last;

public:
    LinkedList() : root(nullptr), last(nullptr){};
    void addNext(T *data)
    {
        if (root == nullptr)
        {
            last = new Node<T>(data);
            root = last;
        }
        else
        {
            last->setNext(new Node<T>(data));
            last = nullptr;
        }
    }
    void print()
    {
        for (Node<T> *node = root; node != nullptr; node = node->getNext())
        {
            std::cout << *node << std::endl;
        }
    };
    ~LinkedList()
    {
        for (Node<T> *node = root; node != nullptr;)
        {
            Node<T> *temp = node;
            node = node->getNext();
            delete temp;
        }
    };
};