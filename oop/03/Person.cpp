#include "Person.h"
#include <iostream>

Person::Person(const Person &p) : firstName(p.firstName), lastName(p.lastName), birthYear(p.birthYear), gender(p.gender)
{
}

Person &Person::operator=(const Person &p)
{
    setFirstName(p.firstName);
    setLastName(p.lastName);
    setBirthYear(p.birthYear);
    setGender(p.gender);
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Person &p)
{
    os << p.getFirstName() << p.getLastName();
    return os;
}