#pragma once

#include <string>
#include <iostream>

class Person
{
private:
    const std::string firstName;
    const std::string lastName;
    unsigned int age;

public:
    Person(const std::string firstName, const std::string lastName, unsigned int age) : firstName(firstName), lastName(lastName), age(age){};

    void IncreaseAge()
    {
        this->age++;
    };

    void Print()
    {
        std::cout << "First name: " << this->firstName << " Last name: " << this->lastName << " Age: " << this->age << std::endl;
    };

    ~Person()
    {
        std::cout << "End" << std::endl;
    }
};