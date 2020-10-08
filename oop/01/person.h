#pragma once

#include <string>

class Person
{
    std::string name;
    unsigned short age;

public:
    Person(std::string name, unsigned short age) : name(name), age(age){};
    void Print();
    unsigned short GetAge() const { return age; };
    std::string GetName() const { return name; };
    void IncreaseAge();
    void SetName(const std::string name) { this->name = name; };
};