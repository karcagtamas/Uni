#pragma once

#include <string>
#include <map>

class Termek
{
    std::string name;
    double cost;

public:
    Termek(const std::string &name, double cost) : name(name), cost{cost} {};
    const std::string &getName() const;
    virtual bool operator==(Termek &t)
    {
        return name == t.name;
    };
};

class Laptop : public Termek
{
public:
    Laptop(const std::string &name, double cost) : Termek(name, cost){};
};

class Mobil : public Termek
{
    std::string imei;

public:
    Mobil(const std::string &name, double cost, const std::string &imei) : Termek(name, cost), imei(imei){};
    std::string getImei() const
    {
        return imei;
    };
    virtual bool operator==(Termek &t) override
    {
        Mobil *m = dynamic_cast<Mobil *>(&t);
        return Termek::operator==(t) && m != nullptr && imei == m->getImei();
    };
};

class OutOfKeszletError : public std::exception
{
    std::string err;

public:
    OutOfKeszletError(const std::string &err) : err(err){};
    const std::string &getMsg() const
    {
        return err;
    };
};

class Keszlet
{
private:
    static Keszlet *instance;
    Keszlet(){};
    std::map<Termek *, int> termeks;

public:
    Keszlet(const Keszlet &keszlet) = delete;
    Keszlet &operator=(const Keszlet &keszlet) = delete;
    static Keszlet *GetInstance()
    {
        if (instance == nullptr)
        {
            instance = new Keszlet;
        }
        return instance;
    };
    void addTermek(Termek *termek, int darab);
    int getQuantity(Termek *termek) const;
    void rendel(Termek *termek, int darab);
    void checkedRendel(Termek *termek, int darab);
    void addTermekChecked(Termek *termek, int darab);
    ~Keszlet(){};
};