#include <iostream>
#include "person.h"
#include "triangle.h"
#include "square.h"
#include "circle.h"

int main()
{
    std::cout << "Hello World!" << std::endl;
    Person *person = new Person("Józsi", 12);
    person->Print();
    person->IncreaseAge();
    person->Print();

    Person person3("Alnma", 30);
    person3.Print();
    person3.IncreaseAge();
    person3.SetName("Körte");
    person3.Print();

    Triangle tri(3, 4, 5);
    std::cout << tri.Perimeter() << std::endl;
    std::cout << tri.Area() << std::endl;

    Square sq(12, 12);
    std::cout << sq.Perimeter() << std::endl;
    std::cout << sq.Area() << std::endl;

    Circle cir(12);
    std::cout << cir.Perimeter() << std::endl;
    std::cout << cir.Area() << std::endl;

    return 0;
}