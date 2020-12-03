#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Clonable
{
public:
    virtual ~Clonable() = default;
    virtual Clonable *clone() const = 0;
};

class ClonableString : public Clonable
{
    string value;

public:
    ClonableString(const string &value) : value(value) {}
    std::string getString() const
    {
        return value;
    }
    ClonableString *clone() const override
    {
        return new ClonableString(string(value));
    }
};

class ClonableNumber : public Clonable
{
    double value;

public:
    ClonableNumber(double value) : value(value) {}
    double getNumber() const
    {
        return value;
    }
    ClonableNumber *clone() const override
    {
        return new ClonableNumber(value);
    }
};

class CloneContainer
{
    std::vector<Clonable *> elements;

public:
    void push_back(const Clonable &clonable)
    {
        elements.push_back(clonable.clone());
    }
    ~CloneContainer()
    {
        for (auto el : elements)
        {
            delete el;
        }
    }
    Clonable &operator[](size_t index)
    {
        return *elements[index];
    }
    size_t size() const
    {
        return elements.size();
    }
};

int main()
{
    const ClonableString str1("szo");
    const ClonableString str2("szoveg");
    const ClonableString str3("word");

    const ClonableNumber num1(4.2);
    const ClonableNumber num2(-6.66);

    CloneContainer clones;
    clones.push_back(str1);
    clones.push_back(num1);
    clones.push_back(str2);
    cout << clones.size() << " clones have been made\n";

    Clonable &i1 = clones[0];
    string testStr = dynamic_cast<ClonableString *>(&i1)->getString();
    cout << "Item 1: " << testStr << endl;

    ClonableNumber *i2 = dynamic_cast<ClonableNumber *>(&clones[1]);
    cout << "Item 2: " << i2->getNumber() << endl;

    ClonableString &i3 = dynamic_cast<ClonableString &>(clones[2]);
    cout << "Item 3: " << i3.getString() << endl;

    clones.push_back(str3);
    clones.push_back(num2);
    cout << clones.size() << " clones have been made\n";

    ClonableString *i4 = dynamic_cast<ClonableString *>(&clones[3]);
    cout << "Item 4: " << i4->getString() << endl;

    ClonableNumber &i5 = dynamic_cast<ClonableNumber &>(clones[4]);
    cout << "Item 5: " << i5.getNumber() << endl;
}