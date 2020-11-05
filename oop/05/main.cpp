#include "Animal.h"
#include <iostream>

void print(Animal *animal)
{
    Dog *dog = dynamic_cast<Dog *>(animal);

    if (dog != nullptr)
    {
        std::cout << "Ő egy kutyaaaaaa" << std::endl;
    }
    else
    {
        std::cout << "Ő nem egy kutyaaaa. Csaló" << std::endl;
    }
}

void move(Animal *animal)
{
    animal->move();
}

int main()
{
    Dog dog("Kutya", 12.0, 2.0);
    Cat cat("Cic", 8.3, 13);
    Dackel dackel("igen", 32.1, 12.1);
    Dog *oDog = new Dog("Másik kuty", 12.3, 45.5);
    Cat *catty = new Cat("Catty", 1.89, 3.56);

    dog.speak();
    cat.speak();
    std::cout << "Dog chase cat: ";
    dog.chase(&cat);
    cat.roll();
    dackel.chase(&cat);
    dackel.print(std::cout);
    dackel.speak();

    std::cout << dog << std::endl;
    print(&dog);
    print(&cat);

    oDog->chase(catty);

    catty->move();
    move(catty);
    move(oDog);

    delete oDog;
    delete catty;

    return 0;
}