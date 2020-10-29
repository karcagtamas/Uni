#pragma once
#include "Person.h"
#include <string>

class PizzaRendeles
{
private:
    Person *person;
    std::string pizzaName;

public:
    PizzaRendeles(Person *person, const std::string &pizzaName) : person(person), pizzaName(pizzaName){};
    PizzaRendeles(const PizzaRendeles &other) : person(other.person), pizzaName(other.pizzaName){};
    PizzaRendeles &operator=(const PizzaRendeles &other);
    void print();
    std::string getPizzaName() const { return pizzaName; };
    friend std::ostream &operator<<(std::ostream &os, PizzaRendeles &p);
};