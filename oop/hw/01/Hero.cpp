#include "Hero.h"
#include <iostream>

void Hero::print()
{
    std::cout
        << "Name: " << this->name
        << " | HP: " << this->hp
        << " | Max DPS: " << this->maxDPS
        << " | Min DPS: " << this->minDPS
        << " | Precision: " << this->precision
        << " | Spec DPS: " << this->specDPS
        << " | Quote: " << this->quote
        << std::endl;
}

Hero *Hero::hit(Hero *attacked)
{
    const unsigned int damage = this->getDamage();
    std::cout << this->name << " attack by " << damage << std::endl;
    if (damage < attacked->hp)
    {
        attacked->hp -= damage;
        return attacked->hit(this);
    }
    else
    {
        attacked->hp = 0;
        return this;
    }
}

unsigned int Hero::getDamage()
{

    unsigned int spec = rand() % 100;
    if (spec < 5)
    {
        return this->specDPS;
    }

    return ((rand() % (this->maxDPS - this->minDPS)) + this->minDPS) * this->precision;
}

void Hero::printAsWinner()
{
    std::cout << "Winner is " << this->name << std::endl;
}