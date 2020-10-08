#include "person.h"
#include <iostream>

void Person::Print()
{
    std::cout << "Name: " << this->name << " Age: " << this->age << std::endl;
}

void Person::IncreaseAge()
{
    this->age++;
}