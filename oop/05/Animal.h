#pragma once

#include <iostream>
#include <string>

class Animal
{
private:
    const std::string name;
    double weight;
    double height;

public:
    Animal(const std::string name, double weight, double height) : name(name), weight(weight), height(height){};
    virtual ~Animal(){};
    virtual void speak() = 0;
    virtual void print(std::ostream &stream) const
    {
        stream << "Name: " << name << " Weight: " << weight << " Height: " << height << std::endl;
    }
    friend std::ostream &operator<<(std::ostream &os, const Animal &animal)
    {
        animal.print(os);
        return os;
    };
    virtual void move() const
    {
        std::cout << "Move animal" << std::endl;
    };
};

class Cat : public Animal
{
private:
public:
    Cat(const std::string name, double weight, double height) : Animal(name, weight, height){};
    void speak() override
    {
        std::cout << "Meow" << std::endl;
    };
    void roll()
    {
        std::cout << "Rollin" << std::endl;
    }
    virtual void move() const override
    {
        std::cout << "Move cat" << std::endl;
    };
};

class Dog : public Animal
{
private:
public:
    Dog(const std::string name, double weight, double height) : Animal(name, weight, height){};
    void speak() override final
    {
        std::cout << "Wau" << std::endl;
    };

    void chase(Cat *cat)
    {
        cat->speak();
    }
};

class Dackel : public Dog
{
public:
    Dackel(const std::string name, double weight, double height) : Dog(name, weight, height){};
};