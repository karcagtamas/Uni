#include "Soldier.h"

Soldier::Soldier(const std::string name, unsigned int hp) : name(name), hp(hp), maxHp(hp)
{
    this->weapon = nullptr;
}

Soldier::~Soldier()
{
    delete this->weapon;
}

void Soldier::hit(Soldier &other)
{
    unsigned int dmg = 5;
    if (weapon != nullptr)
    {
        dmg = weapon->getDamage();
    }

    if (other.hp > dmg)
    {
        other.hp -= dmg;
    }
    else
    {
        other.hp = 0;
    }
}

void Soldier::heal(Soldier &other)
{
    other.hp += 100;
}

void Soldier::addWeapon(Weapon *weapon)
{
    this->weapon = weapon;
}

void Soldier::print()
{
    std::cout << "Name: " << this->name << " | HP: " << this->hp << std::endl;
    if (weapon != nullptr)
    {
        this->weapon->print();
    }
}