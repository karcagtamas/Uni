#pragma once

template <class T>
class Node
{
private:
    T obj;
    Node<T> *next;

public:
    Node<T>(T obj) : obj(obj), next(nullptr){};
    Node<T> *getNext() const
    {
        return next;
    };
    void setNext(Node<T> *next)
    {
        this->next = next;
    };
};