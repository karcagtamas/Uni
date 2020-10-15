#include <string>

class Hero
{
private:
    const std::string name;
    unsigned int hp;
    const unsigned int minDPS;
    const unsigned int maxDPS;
    const float precision;
    const unsigned int specDPS;
    const std::string quote;

public:
    Hero(const std::string name, unsigned int hp, const unsigned int minDPS, const unsigned int maxDPS, const float precision, const unsigned int specDPS, const std::string quote) : name(name), hp(hp), minDPS(minDPS), maxDPS(maxDPS), precision(precision), specDPS(specDPS), quote(quote)
    {
    }
    void print();
    void printAsWinner();
    Hero *hit(Hero *attacked);

    unsigned int getDamage();
};