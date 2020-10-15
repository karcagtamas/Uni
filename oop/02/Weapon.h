#pragma once

#include <string>
#include <iostream>

class Weapon
{
private:
    const std::string name;
    const unsigned int dmg;
    unsigned int ammo;

public:
    Weapon(const std::string name, const unsigned int dmg, unsigned int ammo);
    void shoot();
    void print();
    unsigned int getDamage() const;
    ~Weapon();
};
