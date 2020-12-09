#pragma once
#include <string>

class Person
{
    std::string name;

public:
    Person(const std::string &name) : name(name) {}
    std::string getName() const
    {
        return name;
    }
};