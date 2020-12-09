#include <iostream>
#include <string>
#include "person.h"

int main()
{
    Person *person = new Person("Name");
    std::cout << "Hello " << person->getName() << std::endl;
    delete person;
    return 0;
}