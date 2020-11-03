#include <iostream>
#include <string>

class Base
{
public:
    virtual void print() { std::cout << "Base class print" << std::endl; }
};

class Derived : public Base
{
public:
    void print() override { std::cout << "Derived class print" << std::endl; }
    void special()
    {
        std::cout << "... I am special type of Base " << std::endl;
    }
};

void f(Base *b)
{
    Derived *test = dynamic_cast<Derived *>(b);
    if (test != nullptr)
    {
        test->special();
    }
    b->print();
}

int main()
{
    Base b;
    Derived d;
    f(&b);
    f(&d);
    return 0;
}