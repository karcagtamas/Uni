#include "Person.h"
#include "Soldier.h"
#include "Weapon.h"

int main()
{
    Person *person = new Person("Alma", "János", 45);

    person->Print();
    person->IncreaseAge();
    person->Print();

    Soldier *soldier = new Soldier("Hős", 120);
    Soldier *enemy = new Soldier("Enemy", 200);
    Weapon *weapon = new Weapon("Ágyú", 12, 120);
    Weapon *weapon2 = new Weapon("Nem Ágyú", 43, 31);
    soldier->addWeapon(weapon);
    soldier->print();
    enemy->addWeapon(weapon2);
    enemy->print();

    soldier->hit(*enemy);
    soldier->print();
    enemy->print();

    delete soldier;

    return 0;
}