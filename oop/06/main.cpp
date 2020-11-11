#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <deque>

template <typename T>
void f(T input)
{
    input.print();
};

class Printable
{
public:
    void print()
    {
        std::cout << "Alma" << std::endl;
    };
};

class NonPrintable
{
};

template <class T>
int k(T a)
{
    return a + 1;
};

template <>
int k(std::string)
{
    return 0;
};

int main()
{
    f(Printable());
    // f(NonPrintable());

    std::cout << k(5) << std::endl;
    std::cout << k<std::string>("ALma") << std::endl;

    std::list<int> myList = {1, 2, 3, 4, 5};
    myList.insert(std::next(myList.cbegin(), 3), 10);

    for (int i : myList)
    {
        std::cout << i << ", ";
    }
    std::cout << std::endl;

    std::vector<int> v = {1, 2, 3, 4, 5};
    std::cout << v[1] << std::endl;

    v.insert(v.cbegin() + 3, 8);

    for (int i : v)
    {
        std::cout << i << ", ";
    }

    std::cout << std::endl;

    return 0;
}