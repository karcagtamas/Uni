#include "LinkedList.h"

template <class T>
void LinkedList<T>::add(T element)
{
    if (root == nullptr)
    {
        root = new Node<T>(element);
    }
    else
    {
        Node<T> *current = root->getNext();
        while (current != nullptr)
        {
            current = current->getNext();
        }
        current->setNext(new Node<T>(element));
    }
}

template <class T>
Node<T> *LinkedList<T>::get() {}