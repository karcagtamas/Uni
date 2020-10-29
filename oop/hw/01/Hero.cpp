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
    const unsigned int dealedDamage = damage >= attacked->hp ? attacked->hp : damage;

    attacked->hp -= dealedDamage;
    std::cout << this->name << " caused " << dealedDamage << " to " << attacked->name << " Remaining HP: " << attacked->hp << std::endl;
    return attacked->hp == 0 ? this : attacked->hit(this);
}

unsigned int Hero::getDamage()
{

    unsigned int spec = rand() % 100;
    if (spec < 5)
    {
        return this->specDPS;
    }

    if (this->maxDPS == this->minDPS)
    {
        return this->precision * this->maxDPS;
    }

    return this->precision * ((rand() % (this->maxDPS - this->minDPS)) + this->minDPS);
}

void Hero::printAsWinner()
{
    std::cout << "Winner is " << this->name << std::endl;
}