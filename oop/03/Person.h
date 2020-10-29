#pragma once

#include <string>
#include <iostream>

enum Gender
{
    Male,
    Female
};

class Person
{
private:
    std::string firstName;
    std::string lastName;
    unsigned int birthYear;
    Gender gender;

public:
    Person(std::string firstName, std::string lastName, unsigned int birthYear, Gender gender) : firstName(firstName), lastName(lastName), birthYear(birthYear), gender(gender){};
    Person(const Person &p);
    Person &operator=(const Person &p);
    std::string getFirstName() const { return firstName; };
    void setFirstName(const std::string &firstName) { this->firstName = firstName; };
    std::string getLastName() const { return lastName; };
    void setLastName(const std::string &lastName) { this->lastName = lastName; };
    unsigned int getBirthYear() const { return birthYear; };
    void setBirthYear(unsigned int birthYear) { this->birthYear = birthYear; };
    Gender getGender() const { return gender; };
    void setGender(Gender gender) { this->gender = gender; };
    friend std::ostream &operator<<(std::ostream &os, const Person &p);
};