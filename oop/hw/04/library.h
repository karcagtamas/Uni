#pragma once

#include <string>
#include <vector>

class Publication
{
private:
    std::string title;

public:
    Publication(const std::string &title) : title(title){};
    const std::string getTitle() const { return title; };
    virtual void print() = 0;
    virtual ~Publication(){};
};

class Magazine : public Publication
{
private:
    int year;
    int num;

public:
    Magazine(const std::string &title, int year, int num) : Publication(title), year(year), num(num){};
    void print() override
    {
        std::cout << "\"" << getTitle() << "\", vol. " << year << " no. " << num << std::endl;
    };
    ~Magazine(){};
};

class Book : public Publication
{
private:
    std::string writer;

public:
    Book(const std::string &title, const std::string &writer) : Publication(title), writer(writer){};
    void print() override
    {
        std::cout << "\"" << getTitle() << "\" by " << writer << std::endl;
    };
    ~Book(){};
};

class Library
{
private:
    std::vector<void (*)(Magazine *)> functions;
    std::vector<Publication *> publications;

public:
    void addMagazineEventHandler(void(fn)(Magazine *))
    {
        functions.push_back(fn);
    };
    void addPublication(Publication *pub)
    {
        publications.push_back(pub);

        Magazine *mag = dynamic_cast<Magazine *>(pub);

        if (mag != nullptr)
        {
            for (auto fn : functions)
            {
                fn(mag);
            }
        }
    };
    void print() const
    {
        for (auto pub : publications)
        {
            pub->print();
        }
    };
    ~Library()
    {
        for (auto pub : publications)
        {
            delete pub;
        }
    };
};
