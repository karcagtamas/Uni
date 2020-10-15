#include "Weapon.h"

Weapon::Weapon(const std::string name, const unsigned int dmg, unsigned int ammo) : name(name), dmg(dmg), ammo(ammo)
{
}

Weapon::~Weapon()
{
}

void Weapon::shoot()
{
    this->ammo--;
}

void Weapon::print()
{
    std::cout << "Weapon: " << this->name << " | Weapon dmg: " << this->dmg << std::endl;
}

unsigned int Weapon::getDamage() const
{
    return this->dmg;
}