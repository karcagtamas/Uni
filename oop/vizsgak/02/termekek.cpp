#include "termekek.h"
#include <algorithm>
#include <iterator>

Keszlet *Keszlet::instance = 0;

const std::string &Termek::getName() const
{
    return name;
}

void Keszlet::addTermek(Termek *termek, int darab)
{
    termeks.insert({termek, darab});
}

int Keszlet::getQuantity(Termek *termek) const
{
    if (termeks.find(termek) == termeks.end())
    {
        return 0;
    }
    return termeks.at(termek);
}

void Keszlet::rendel(Termek *termek, int darab)
{
    if (getQuantity(termek) >= darab)
    {
        termeks[termek] -= darab;
    }
}

void Keszlet::checkedRendel(Termek *termek, int darab)
{
    if (getQuantity(termek) >= darab)
    {
        termeks[termek] -= darab;
    }
    else
    {
        throw OutOfKeszletError("Out of stock");
    }
}

void Keszlet::addTermekChecked(Termek *termek, int darab)
{
    auto var = std::find_if(termeks.cbegin(), termeks.cend(), [termek](const std::pair<Termek *const, int> val) {
        return &termek == &val.first;
    });

    if (var != termeks.end())
    {
        termeks[(*var).first] += darab;
    }
    else
    {
        addTermek(termek, darab);
    }
}