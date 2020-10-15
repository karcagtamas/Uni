#pragma once

#include <string>
#include <iostream>
#include "Weapon.h"

class Soldier
{
private:
    const std::string name;
    unsigned int hp;
    const unsigned int maxHp;
    Weapon *weapon;

public:
    Soldier(const std::string name, unsigned int hp);
    void hit(Soldier &other);
    void heal(Soldier &other);
    void addWeapon(Weapon *weapon);
    void print();
    ~Soldier();
};

