#include <exception>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <sstream>
#include <fstream>

class ExistsException : public std::exception
{
private:
    std::string msg;

public:
    ExistsException(const std::string &msg) : msg(msg){};
};

std::vector<int> myvector;

class Alma
{
public:
    int a = 0;
};
std::list<Alma> mylist;

class Telepules
{
public:
    std::string getNev() const;
    std::string getHossusag() const;
    std::string getSzelesseg() const;
    void print() const;
};

class Tarolo
{
};

class Megfigyelo
{
public:
    virtual void ujelem(const Telepules &telep, unsigned int num) const = 0;
    ~Megfigyelo() {}
};

class MegfigyelNev : public Megfigyelo
{
    std::string nev;

public:
    MegfigyelNev(const std::string &nev) : nev(nev){};
    virtual void ujelem(const Telepules &telep, unsigned int num) const override
    {
        if (nev == telep.getNev())
        {
            std::cout << "Nev: " << telep.getNev() << "Hosszusag: " << telep.getHossusag() << "Szelesseg: " << telep.getSzelesseg() << std::endl;
        }
    }
};

class MegfigyelMeret : public Megfigyelo
{
    int number;
    Tarolo *tarolo;

public:
    MegfigyelMeret(int number, Tarolo *tarolo) : number(number), tarolo(tarolo){
                                                                     // tarolo->regisztral(this);
                                                                 };
    virtual void ujelem(const Telepules &telep, unsigned int num) const override
    {
        if (num == number)
        {
            //tarolo->print();
        }
    }
};

class MegfigyelBackup : public Megfigyelo
{
    Tarolo *tarolo;

public:
    MegfigyelBackup(Tarolo *tarolo) : tarolo(tarolo){};
    virtual void ujelem(const Telepules &telep, unsigned int num) const override
    {
        // tarolo->hozzaad(telep);
    }
};

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
}
