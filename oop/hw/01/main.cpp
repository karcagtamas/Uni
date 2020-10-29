#include "Hero.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#define FILE "/home/karcagtamas/repos/Uni/oop/hw/01/heores.csv"

int main()
{
    std::vector<Hero *> heroes;
    std::ifstream myfile(FILE);
    srand(time(NULL));

    if (myfile.is_open())
    {
        std::string line = "";
        std::getline(myfile, line);
        while (std::getline(myfile, line))
        {
            std::stringstream sstream(line);
            std::string element;
            std::vector<std::string> t;
            while (std::getline(sstream, element, ','))
            {
                t.push_back(element);
            }
            heroes.push_back(new Hero(t[0], stoi(t[1]), stoi(t[2]), stoi(t[3]), stof(t[4]), stoi(t[5]), t[6]));
        }
        myfile.close();
    }
    else
    {
        std::cout << "Unable to open the file" << std::endl;
        return 1;
    }

    for (unsigned int i = 0; i < heroes.size(); i++)
    {
        std::cout << i + 1 << ". player:" << std::endl;
        heroes[i]->print();
    }

    unsigned int first = 0;
    unsigned int second = 1;
    std::cout << "Select 1. player: ";
    std::cin >> first;
    std::cout << "Select 2. player: ";
    std::cin >> second;

    if (first < 1 || second < 1 || first > heroes.size() || second > heroes.size())
    {
        return 1;
    }

    heroes[first - 1]->hit(heroes[second - 1])->printAsWinner();

    for (unsigned int i = 0; i < heroes.size(); i++)
    {
        delete heroes[i];
    }

    return 0;
}