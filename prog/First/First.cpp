#include "pch.h"
#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
	int z = 10;
	for (int i = 1; i <= z; i++)
	{
		std::cout << i * i << "\n";
	}
	std::cout << '\n';

	// Task 1 - Input, 2x
	int input;
	std::cout << "1. task \n" << "Please give a number: ";
	std::cin >> input;
	std::cout << input * 2 << "\n";

	// Task 2 - 2 number, addition, multiplication, substract
	int a = 0;
	int b = 0;
	std::cout << "2. task \n";
	std::cout << "A: ";
	std::cin >> a; 
	std::cout << "B: ";
	std::cin >> b;
	int add = a + b;
	int multi = a * b;
	int sub = multi - add;
	std::cout << "Addition: " << add << "\nMulti: " << multi << "\nSub: " << sub;

	// Task 3 - abs
	int c;
	std::cout << "\n3. task\nNumber: ";
	std::cin >> c;
	int res = c;
	if (c < 0) {
		res = -c;
	}
	std::cout << "Abs: " << res;

	// Task 4 - Conditional
	int x;
	int y;
	std::cout << "\n4. task\n";
	std::cout << "X: ";
	std::cin >> x;
	std::cout << "Y: ";
	std::cin >> y;

	if (x > y) {
		std::cout << "Sub: " << x - y << '\n';
	}
	if (x < 10 && y < 10) {
		std::cout << "Multi: " << x * y << '\n';
	}

	// Task 5 - Loops
	int n = 0;
	std::cout << "\n5. task\n";
	do {
		std::cout << "N: ";
		std::cin >> n;
	} while (n <= 0);
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 0) {
			std::cout << i << " ";
		}
		sum += i;
	}
	std::cout << "Sum: " << sum;	

	// Task 6 - Intervall
	int intStart = 0;
	int intEnd = 0;
	std::cout << "\n6. task\n";
	std::cout << "Intervall start: ";
	std::cin >> intStart;
	std::cout << "Intervall end: ";
	std::cin >> intEnd;

	if (intStart < intEnd) {
		for (int i = intStart + 1; i < intEnd; i++)
		{
			std::cout << i << " ";
		}
	}
	else {
		for (int i = intStart - 1; i > intEnd; i--)
		{
			std::cout << i << " ";
		}
	}

	// Task 7 - Fakt
	int state = 0;
	std::cout << "\n7. task\n";
	std::cout << "State: ";
	std::cin >> state;

	int fakt = 1;
	std::cout << "Fakt: ";
	for (int i = state; i >= 1; i--)
	{
		if (i == 1) {
			std::cout << i;
		}
		else {
			std::cout << i << " * ";
			fakt *= i;
		}
	}
	std::cout << " = " << fakt;

	// Task 8 - FizzBuzz
	std::cout << "\n8. task FizzBuzz Game (1 - 100): ";
	for (int i = 1; i <= 100; i++)
	{
		if (i % 3 == 0 && i % 5 == 0) {
			std::cout << " FizzBuzz ";
		}
		else if (i % 3 == 0) {
			std::cout << " Fizz ";
		}
		else if (i % 5 == 0){
			std::cout << " Buzz ";
		}
		else {
			std::cout << " " << i << " ";
		}
	}

	// Task 9 - Prime
	std::cout << "\n9. task\n";
	int number = 0;
	std::cout << "Number: ";
	std::cin >> number;
	bool prim = true;

	for (int i = 2; (i < number / 2) && prim; i++)
	{
		if (number % i == 0) {
			prim = false;
		}
	}

	if (prim) {
		std::cout << number << " is prime";
	}
	else {
		std::cout << number << " is not prime";
	}

	std::cout << "\n\n";
	return 0;
}