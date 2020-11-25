// Practice2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>
int main()
{
    // Task 1 - larger, lower, equal
    int num1;
    int num2;
    std::cout << "Give a number please: ";
    std::cin >> num1;
    std::cout << "Give another number please: ";
    std::cin >> num2;

    if (num1 > num2) {
        std::cout << "First is bigger than the second";
    }
    else if (num1 < num2) {
        std::cout << "First is lower than the second";
    }
    else {
        std::cout << "Two numbers are equal";
    }
    
    std::cout << "\n";
    // Task 2 - input while is not equal

    int prev;
    int current;
    std::cout << "Give a number please: ";
    std::cin >> current;
    int count = 1;
    int countOfEven = 0;
    if (current % 2 == 0) {
        countOfEven = 1;
    }
    do
    {
        prev = current;
        std::cout << "Give a number please: ";
        std::cin >> current;
        count++;
        if (current % 2 == 0) {
            countOfEven++;
        }
    } while (prev != current);
    std::cout << "\n";

    std::cout << "Count: " << count << std::endl;
    std::cout << "Count of even: " << countOfEven << std::endl;

    // Task 3 - square
    /*string b = "asd";
    cout << b;*/
    int sq = 0;
    do
    {
        std::cout << "Width of squeare: ";
        std::cin >> sq;
    } while (sq <= 0);

    for (int i = 1; i <= sq; i++)
    {
        for (int j = 1; j <= sq; j++)
        {
            if (i == 1 || j == 1 || i == sq || j == sq || i == j || i + j == sq + 1) {
                std::cout << "*";
            }
            else {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }

    // Task 4 - Stairs
    int height = 0;
    do
    {
        std::cout << "Heigth of stairs: ";
        std::cin >> height;
    } while (height <= 0);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            std::cout << "*";
        }
        std::cout << "\n";
    }

    std::cout << "\n";
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (height - 1 - j <= i) {
                std::cout << "*";
            }
            else {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }

    std::cout << "\n";

    // Task 5 - menu
    int item = 0;
    std::cout << "Sum (1) - Multi (2) - Sq (3) - Row(4)" << std::endl;
    std::cout << "Menu element: ";
    std::cin >> item;
    int a;
    int b;
    switch (item)
    {
        case 1: 
            std::cout << "Sum" << std::endl;
            std::cout << "A: ";
            std::cin >> a;
            std::cout << "B: ";
            std::cin >> b;
            std::cout << "Sum: " << a + b;
            break;
        case 2: 
            std::cout << "Multi" << std::endl;
            std::cout << "A: ";
            std::cin >> a;
            std::cout << "B: ";
            std::cin >> b;
            std::cout << "Multi: " << a * b;
            break;
        case 3: 
            std::cout << "Sq" << std::endl;
            std::cout << "A: ";
            std::cin >> a;
            std::cout << "B: ";
            std::cin >> b;
            std::cout << "Sq: " << pow(a, b);
            break;
        case 4:
            std::cout << "Row" << std::endl;
            int a0;
            int d;
            int n;
            int an;
            std::cout << "A0: ";
            std::cin >> a0;
            std::cout << "D: ";
            std::cin >> d;
            std::cout << "N: ";
            std::cin >> n;
            an = a0 + d * n - 1;
            std::cout << "An: " << an;
            break;
        default:
            return 1;
            break;
    }

    return 0;
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
