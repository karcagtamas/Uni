#pragma once
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <iostream>

class CsillagRombolo
{
private:
    const std::string name;
    const unsigned int minLegenyseg;
    const unsigned int maxLegenyseg;
    const unsigned int minLaser;
    const unsigned int maxLaser;
    unsigned int legenyseg;
    unsigned int laser;

protected:
    CsillagRombolo(const std::string &name, const unsigned int minLegenyseg, const unsigned int maxLegenyseg, const unsigned int minLaser, const unsigned int maxLaser, unsigned int legenyseg, unsigned int laser) : name(name), minLegenyseg(minLegenyseg), maxLegenyseg(maxLegenyseg), minLaser(minLaser), maxLaser(maxLaser), legenyseg(legenyseg), laser(laser) {}

public:
    virtual unsigned int tuzero() = 0;
    unsigned int getLegenyseg()
    {
        return legenyseg;
    }
    unsigned int getLaser()
    {
        return laser;
    }
    std::string getName()
    {
        return name;
    }
    void addLegenyseg(unsigned int legenyseg)
    {
        this->legenyseg += legenyseg;
    }
    void setLegenyseg(unsigned int legenyseg)
    {
        this->legenyseg = legenyseg;
    }
    void removeLegenyseg(unsigned int legenyseg)
    {
        this->legenyseg -= legenyseg;
    }
    bool checkUzemkepes()
    {
        return legenyseg >= minLegenyseg;
    }
    unsigned int getMaxLegenyseg()
    {
        return maxLegenyseg;
    }
    unsigned int getMinLegenyseg()
    {
        return minLegenyseg;
    }
    virtual bool operator==(const CsillagRombolo &v)
    {
        return this->getName() == v.name;
    }
    friend std::ostream &operator<<(std::ostream &os, CsillagRombolo *v)
    {
        os << "Name: " << v->name << " Legenyseg: " << v->legenyseg << " Min legénység: " << v->minLegenyseg << " Max legénység: " << v->maxLegenyseg << std::endl;
        return os;
    }
};

class Imperial : public CsillagRombolo
{
public:
    Imperial(const std::string &name, unsigned int legenyseg, unsigned int laser) : CsillagRombolo(name, 29000, 45000, 40, 80, legenyseg, laser) {}
    unsigned int tuzero() override
    {
        if (checkUzemkepes())
        {
            return 100 * getLaser();
        }
        return 0;
    }
    friend std::ostream &operator<<(std::ostream &os, Imperial &v)
    {
        os << "Name: " << v.getName() << " Legenyseg: " << v.getLegenyseg() << " Min legénység: " << v.getMinLegenyseg() << " Max legénység: " << v.getMaxLegenyseg() << std::endl;
        return os;
    }
};

class Executor : public CsillagRombolo
{
private:
    const unsigned int minIon;
    const unsigned int maxIon;
    unsigned int ion;

public:
    Executor(const std::string &name, unsigned int legenyseg, unsigned int laser, unsigned int ion) : CsillagRombolo(name, 50000, 350000, 1500, 2500, legenyseg, laser), minIon(200), maxIon(300), ion(ion) {}
    unsigned int tuzero() override
    {
        if (checkUzemkepes())
        {
            return 150 * getLaser() + 1000 * ion;
        }
        return 0;
    }
    friend std::ostream &operator<<(std::ostream &os, Executor &v)
    {
        os << "Name: " << v.getName() << " Legenyseg: " << v.getLegenyseg() << " Min legénység: " << v.getMinLegenyseg() << " Max legénység: " << v.getMaxLegenyseg() << std::endl;
        return os;
    }
};

class ErrorLegenyseg : public std::exception
{
private:
    std::string msg;

public:
    ErrorLegenyseg(const std::string &msg) : msg(msg) {}
    std::string getMsg() const
    {
        return msg;
    }
};

class ErrorTartalekos : public std::exception
{
private:
    std::string msg;

public:
    ErrorTartalekos(const std::string &msg) : msg(msg) {}
    std::string getMsg() const
    {
        return msg;
    }
};

class Flotta
{
private:
    std::vector<CsillagRombolo *> hajok;
    unsigned int rendelTartalekLegenyseg = 0;
    static Flotta *instance;
    Flotta() {}

public:
    static Flotta *getInstance()
    {
        if (!instance)
        {
            instance = new Flotta();
        }
        return instance;
    }
    static void freeInstance()
    {
        if (instance)
        {
            delete instance;
            instance = nullptr;
        }
    }
    Flotta(const Flotta &flotta) = delete;
    Flotta &operator=(const Flotta &flotta) = delete;
    void addCsillagrombolo(CsillagRombolo *csr)
    {
        hajok.push_back(csr);
    }
    void addCsillagromboloChecked(CsillagRombolo *csr)
    {
        CsillagRombolo *found = nullptr;
        for (auto h : hajok)
        {
            if (*h == *csr)
            {
                std::cout << "Alma";
                found = h;
            }
        }
        if (found != nullptr)
        {
            found->addLegenyseg(csr->getLegenyseg());
        }
        else
        {
            addCsillagrombolo(csr);
        }
    }
    CsillagRombolo *getCsillagRombolo(const std::string &name)
    {
        auto v = std::find_if(hajok.begin(), hajok.end(), [name](CsillagRombolo *csr) {
            return csr->getName() == name;
        });
        return *v;
    }
    unsigned int getQuantity()
    {
        return hajok.size();
    }
    void addTartalekLegenyseg(unsigned int legenyseg)
    {
        rendelTartalekLegenyseg = legenyseg;
    }
    unsigned int getTartalekLegenyseg()
    {
        return rendelTartalekLegenyseg;
    }
    void addLegenyseg(const std::string &name, unsigned int legenyseg)
    {
        addLegenyseg(getCsillagRombolo(name), legenyseg);
    }
    void addLegenyseg(CsillagRombolo *csr, unsigned int legenyseg)
    {
        rendelTartalekLegenyseg -= legenyseg;
        csr->addLegenyseg(legenyseg);
    }
    void addLegenysegChecked(CsillagRombolo *csr, unsigned int legenyseg)
    {
        if (legenyseg > rendelTartalekLegenyseg)
        {
            throw ErrorTartalekos("Tartalek cannot be less than zero");
        }
        if (csr->getMaxLegenyseg() < csr->getLegenyseg() + legenyseg)
        {
            throw ErrorLegenyseg("Legenyseg cannot be more than the maximum");
        }
        addLegenyseg(csr, legenyseg);
    }
    void tartalekbaHelyez(const std::string &name, unsigned int legenyseg)
    {
        tartalekbaHelyez(getCsillagRombolo(name), legenyseg);
    }
    void tartalekbaHelyez(CsillagRombolo *csr, unsigned int legenyseg)
    {
        csr->removeLegenyseg(legenyseg);
        rendelTartalekLegenyseg += legenyseg;
    }
    void tartalekbaHelyezChecked(CsillagRombolo *csr, unsigned int legenyseg)
    {
        if (csr->getMinLegenyseg() > csr->getLegenyseg() - legenyseg)
        {
            throw ErrorLegenyseg("Legenyseg cannot be less than the minimum");
        }
        tartalekbaHelyez(csr, legenyseg);
    }
    unsigned int getOsszesLegenyseg()
    {
        auto v = std::accumulate(hajok.begin(), hajok.end(), 0, [](int sum, CsillagRombolo *csr) {
            return sum += csr->getLegenyseg();
        });

        return v + rendelTartalekLegenyseg;
    }
    CsillagRombolo *checkImmobility()
    {
        for (auto csr : hajok)
        {
            if (!csr->checkUzemkepes())
            {
                return csr;
            }
        }
        return nullptr;
    }
    void removeTartalekosChecked(unsigned int legenyseg)
    {
        if (rendelTartalekLegenyseg < legenyseg)
        {
            throw ErrorTartalekos("Tartalek cannot be less than zero");
        }
        rendelTartalekLegenyseg -= legenyseg;
    }
    friend std::ostream &operator<<(std::ostream &os, const Flotta &flotta)
    {
        for (auto csr : flotta.hajok)
        {
            os << csr;
        }

        return os;
    }
};

Flotta *Flotta::instance = 0;
