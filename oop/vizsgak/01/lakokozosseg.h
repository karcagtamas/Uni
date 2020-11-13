#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <numeric>

class Tarstulajdonos
{
protected:
    std::string nev;
    int tulajdon;

public:
    Tarstulajdonos(std::string nev, int tulajdon) : nev(nev), tulajdon(tulajdon){};
    virtual void print() = 0;
    virtual void print(int inc) = 0;
    int getTulajdon() const { return tulajdon; };
};

class BekesTulajdonos : public Tarstulajdonos
{
public:
    BekesTulajdonos(std::string nev, int tulajdon) : Tarstulajdonos(nev, tulajdon){};
    void print() override
    {
        print(0);
    };

    void print(int inc) override
    {
        std::cout << "Bekes tulajdonos : " << this->nev << " - " << (this->tulajdon + inc) << " / 10 000" << std::endl;
    };
};

class Kozgyules;

class PereskedoTulajdonos : public Tarstulajdonos
{
public:
    PereskedoTulajdonos(std::string nev, int tulajdon) : Tarstulajdonos(nev, tulajdon){};
    void print() override
    {
        print(0);
    };
    void print(int inc) override
    {
        std::cout << "Pereskedo tulajdonos : " << this->nev << " - " << (this->tulajdon + inc) << " / 10 000" << std::endl;
    };
    void orditozik(Kozgyules *kgy);
};

class Meghatalmazas
{
private:
    Tarstulajdonos *ki;
    Tarstulajdonos *kinek;

public:
    Meghatalmazas(Tarstulajdonos *ki, Tarstulajdonos *kinek) : ki(ki), kinek(kinek){};
    Tarstulajdonos *getKi() { return ki; };
    Tarstulajdonos *getKinek() { return kinek; };
};

class Kozgyules
{
private:
    int ev;
    int honap;
    int nap;
    std::vector<Tarstulajdonos *> resztvevok;
    std::vector<Meghatalmazas *> meghatalmazasok;
    int orditozok = 0;

    class SumJelenlevos
    {
    public:
        int operator()(int acc, Tarstulajdonos *tp)
        {
            return acc + tp->getTulajdon();
        }
    };

    class SumMeghatis
    {
    private:
        Tarstulajdonos *meghatalmazott;

    public:
        SumMeghatis(Tarstulajdonos *meghatalmazott) : meghatalmazott(meghatalmazott){};
        int operator()(int acc, Meghatalmazas *m)
        {
            if (meghatalmazott == m->getKinek())
            {
                return acc + m->getKi()->getTulajdon();
            }
            else
            {
                return acc;
            }
        }
    };

public:
    Kozgyules(int ev, int honap, int nap) : ev(ev), honap(honap), nap(nap){};
    void addJelenlevo(Tarstulajdonos *jelenlevo)
    {
        resztvevok.push_back(jelenlevo);
    };
    void printJelenlevok()
    {
        for (auto i : resztvevok)
        {
            i->print();
        }
    };
    void printLetszam()
    {
        std::cout << std::accumulate(resztvevok.begin(), resztvevok.end(), 0, SumJelenlevos()) << std::endl;
    };
    void submitMeghatalmazas(Meghatalmazas *meghatalmazas)
    {
        meghatalmazasok.push_back(meghatalmazas);
    };
    void printJelenlevokWithProxies()
    {
        for (auto i : resztvevok)
        {
            int inc = std::accumulate(meghatalmazasok.begin(), meghatalmazasok.end(), 0, SumMeghatis(i));
            i->print(inc);
        }
    };
    void addOrditozo()
    {
        orditozok++;
    };
    int getOrditozok() const
    {
        return orditozok;
    };
};

void PereskedoTulajdonos::orditozik(Kozgyules *kgy)
{
    kgy->addOrditozo();
};

class Tarsashaz
{
private:
    std::vector<Tarstulajdonos *> tulajdonosok;
    Kozgyules *prev;

public:
    void addTulajdonos(Tarstulajdonos *tulaj)
    {
        tulajdonosok.push_back(tulaj);
    };
    void holdKozgyules(Kozgyules *kozgy)
    {
        int peresked = 0;
        int bekes = 0;
        for (auto i : tulajdonosok)
        {
            BekesTulajdonos *bekest = dynamic_cast<BekesTulajdonos *>(i);
            if (bekest != nullptr)
            {
                bekes++;
                if (prev != nullptr && prev->getOrditozok() >= 2)
                {
                    if (bekes % 4 == 0)
                    {
                        kozgy->addJelenlevo(i);
                    }
                }
                else
                {
                    if (bekes % 3 == 0)
                    {
                        kozgy->addJelenlevo(i);
                    }
                }
            }
            else
            {
                PereskedoTulajdonos *peres = dynamic_cast<PereskedoTulajdonos *>(i);
                if (peres != nullptr)
                {
                    peresked++;

                    if (peresked % 2 == 0)
                    {
                        kozgy->addJelenlevo(i);
                    }
                }
            }
        }
    };
    void setPreviousKozgyules(Kozgyules *kgy)
    {
        this->prev = kgy;
    };
};
