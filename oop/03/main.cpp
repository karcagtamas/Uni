#include "Person.h"
#include "PizzaRendeles.h"
#include "LinkedList.h"

#include <iostream>

int main()
{
    Person janos("Jaons", "Csaba", 1970, Male);
    Person miklos("Miklos", "Csaba", 1989, Male);
    PizzaRendeles sonkas(&janos, "sonkas");
    PizzaRendeles szalami(&miklos, "szalami");
    sonkas.print();
    szalami.print();

    LinkedList<Person> linkedlist;
    linkedlist.addNext(&janos);
    linkedlist.print();
    linkedlist.addNext(&miklos);
    linkedlist.print();

    LinkedList<PizzaRendeles> linkedlist2;
    linkedlist2.addNext(&sonkas);
    linkedlist2.addNext(&szalami);
    linkedlist2.print();
    return 0;
}