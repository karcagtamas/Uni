#include "PizzaRendeles.h"
#include <iostream>

PizzaRendeles &PizzaRendeles::operator=(const PizzaRendeles &other)
{
    this->person = other.person;
    // this->pizzaName = other.pizzaName;
    return *this;
}

void PizzaRendeles::print()
{
    std::cout << person->getFirstName() << " Pizza: " << this->pizzaName << std::endl;
}

std::ostream &operator<<(std::ostream &os, PizzaRendeles &p)
{
    os << p.getPizzaName();
    return os;
}