#include <iostream>
#include <vector>
#include <string>

class Lamp
{
    std::string name;
    bool state;

protected:
    virtual void print()
    {
        std::cout << name << " turned " << (state ? "ON" : "OFF") << std::endl;
    }

public:
    Lamp(const std::string &name) : name(name), state(false) {}
    bool isOn() const
    {
        return state;
    }
    void turnOn()
    {
        if (!state)
        {
            state = true;
            print();
        }
    }
    void turnOff()
    {
        if (state)
        {
            state = false;
            print();
        }
    }
    std::string getName() const
    {
        return name;
    }
    virtual ~Lamp() {}
};

class RGBLamp : public Lamp
{
    int r;
    int g;
    int b;

protected:
    virtual void print() override
    {
        std::cout << getName() << " in color rgb(" << r << ","
                  << g
                  << ","
                  << b
                  << ") turned " << (isOn() ? "ON" : "OFF") << std::endl;
    }

public:
    RGBLamp(const std::string &name) : Lamp(name), r(255), g(255), b(255) {}
    int getRed() const
    {
        return isOn() ? r : 0;
    }
    int getBlue() const
    {
        return isOn() ? b : 0;
    }
    int getGreen() const
    {
        return isOn() ? g : 0;
    }

    void setColor(int red, int green, int blue)
    {
        r = red;
        g = green;
        b = blue;
    }
};

class Room
{
    std::vector<Lamp *> lamps;

public:
    void add(Lamp *l)
    {
        lamps.push_back(l);
    }
    void clear()
    {
        for (auto l : lamps)
        {
            delete l;
        }
        lamps.clear();
    }
    int lampCount()
    {
        return lamps.size();
    }

    Lamp &operator[](int index)
    {
        return *lamps[index];
    }

    void setAllLamps(bool on)
    {
        for (auto l : lamps)
        {
            if (on)
            {
                l->turnOn();
            }
            else
            {
                l->turnOff();
            }
        }
    }

    void setColor(int red, int green, int blue)
    {
        for (auto l : lamps)
        {
            RGBLamp *rgb = dynamic_cast<RGBLamp *>(l);
            if (rgb == nullptr)
            {
                l->turnOff();
            }
            else
            {
                rgb->setColor(red, green, blue);
            }
        }
    }

    ~Room()
    {
        for (auto l : lamps)
        {
            delete l;
        }
    }
};

int main()
{
    using namespace std;
    Room r;
    if (r.lampCount() != 0)
        cout << "Hiba: ures szobaban nem lehet lampa\n";
    r.add(new Lamp("Desk lamp"));
    if (r.lampCount() != 1)
        cout << "Hiba: nem 1 lampa van a szobaban\n";
    r[0].turnOn();
    if (!r[0].isOn())
        cout << "Hiba: nincs felkapcsolva a lampa\n";
    r.setAllLamps(false);
    r.add(new RGBLamp("Ceiling lamp"));
    if (r.lampCount() != 2)
        cout << "Hiba: nem 2 lampa van a szobaban\n";
    r[1].turnOn();
    if (!r[1].isOn())
        cout << "Hiba: nincs felkapcsolva a 2. lampa\n";
    r.add(new RGBLamp("Kitchen lamp"));
    if (r.lampCount() != 3)
        cout << "Hiba: nem 3 lampa van a szobaban\n";
    r.setAllLamps(true);
    r.add(new Lamp("Reading lamp"));
    if (r.lampCount() != 4)
        cout << "Hiba: nem 4 lampa van a szobaban\n";
    r.setAllLamps(false);
    r.setAllLamps(true);
    r.clear();
    if (r.lampCount() != 0)
        cout << "Hiba: kiuritett szobaban nem lehet lampa\n";
    RGBLamp *rl = new RGBLamp("Bedside lamp");
    rl->setColor(64, 12, 36);
    r.add(rl);
    if (rl->getRed() != 0 || rl->getGreen() != 0 || rl->getBlue() != 0)
        cout << "Hiba: a kikapcsolt lampa szine nem fekete.\n";
    r.setAllLamps(true);
    if (rl->getRed() != 64 || rl->getGreen() != 12 || rl->getBlue() != 36)
        cout << "Hiba: az RGB lampa nem a kert szinu.\n";
    r.add(new Lamp("Floor lamp"));
    if (r.lampCount() != 2)
        cout << "Hiba: nem 2 lampa van a szobaban\n";
    r.setAllLamps(true);
    r.setAllLamps(false);
}