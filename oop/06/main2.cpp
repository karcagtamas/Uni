#include <iostream>
#include <vector>
#include <deque>

template <typename T>
class Node
{
    T val;
    std::vector<Node<T> *> children;

public:
    Node(T v) : val(v){};
    const std::vector<Node<T> *> &getChildren() const
    {
        return children;
    }
    void print()
    {
        std::cout << val << std::endl;
    }
    void addChild(Node<T> *ch)
    {
        children.push_back(ch);
    }
};

template <class C>

class Tree
{
    Node<C> *root;

public:
    Tree(Node<C> *root) : root(root){};
    void szellessegiPrint()
    {
        std::deque<Node<C> *> visited = {root};
        while (visited.size() > 0)
        {
            Node<C> *val = visited.back();
            val->print();
            visited.pop_back();
            for (Node<C> *p : val->getChildren())
            {
                visited.push_front(p);
            }
        }
    }
    void melysegiPrint()
    {
        std::deque<Node<C> *> visited = {root};
        while (visited.size() > 0)
        {
            Node<C> *val = visited.back();
            val->print();
            visited.pop_back();
            for (Node<C> *p : val->getChildren())
            {
                visited.push_back(p);
            }
        }
    }
};

int main()
{
    Node<int> rootOfTree(5);
    Node<int> level11(6);
    Node<int> level12(7);
    Node<int> level21(2);
    Node<int> level22(3);
    rootOfTree.addChild(&level11);
    rootOfTree.addChild(&level12);
    level11.addChild(&level21);
    level11.addChild(&level22);

    Tree<int> tree(&rootOfTree);
    tree.szellessegiPrint();
    std::cout << std::endl;
    tree.melysegiPrint();
    return 0;
}