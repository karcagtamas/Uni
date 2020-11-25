#include <iostream>
#include "Test.h"
#include "Children.h"
#define COUNT 10
#define LENGTH 5
#define VECTORS 2
#define VECTOR_DIMENSION 3

int main()
{
	Test test(10, 12);
	test.Alma();

	Children child(10, 43, 100000);
	child.Alma();


	// Task 1 - array
    int sum = 0;
    int count = COUNT;
	int x;
	int t[COUNT];
	for (int i = 0; i < count; i++)
	{
		std::cout << "Number " << i + 1 << ": ";
		std::cin >> x;
		sum += x;
		t[i] = x;
	}
	double avg = sum / (double)count;
	std::cout << "\nAvg: " << avg << std::endl;
	for (int i = 0; i < count; i++)
	{
		if (t[i] < avg) {
			std::cout << t[i] << std::endl;
		}
	}

	// Task 2 - vektor
	int vectors[VECTORS][VECTOR_DIMENSION];
	for (int i = 0; i < VECTORS; i++)
	{
		std::cout << "Vector " << i + 1 << ":" << std::endl;
		for (int j = 0; j < VECTOR_DIMENSION; j++)
		{
			std::cout << "Value " << j + 1 << ": ";
			std::cin >> vectors[i][j];
		}
	}

	std::cout << "Sum: " << "(" << vectors[0][0] + vectors[1][0] << ", " << vectors[0][1] + vectors[1][1] << ", " << vectors[0][2] + vectors[1][2] << ")" << std::endl;
	std::cout << "Sub: " << "(" << vectors[0][0] - vectors[1][0] << ", " << vectors[0][1] - vectors[1][1] << ", " << vectors[0][2] - vectors[1][2] << ")" << std::endl;

	// Task - 3

	int nums[COUNT];
	for (int i = 0; i < COUNT; i++)
	{
		std::cout << "Number " << i + 1 << ": ";
		std::cin >> nums[i];
	}
	int x1 = 0;
	int countOfX = 0;
	do
	{
		std::cout << "Number X: ";
		std::cin >> x1;
		countOfX = 0;
		for (int i = 0; i < COUNT; i++)
		{
			if (nums[i] == x1) {
				countOfX++;
			}
		}
	} while (countOfX > 0);

	// Task 4

	int nums2[COUNT];
	for (int i = 0; i < COUNT; i++)
	{
		std::cout << "Number " << i + 1 << ": ";
		std::cin >> nums2[i];
	}

	int c1 = 0;
	int c2 = 0;
	int temp = 0;
	bool numsAreValid = true;
	do
	{
		std::cout << "Number C1: ";
		std::cin >> c1;

		std::cout << "Number C2: ";
		std::cin >> c2;

		if (c1 < 1 || c1 > 10 || c2 < 1 || c2 > 10) {
			numsAreValid = false;
		}
		else {
			temp = nums2[c1 - 1];
			nums2[c1 - 1] = nums2[c2 - 1];
			nums2[c2 - 1] = temp;
		}
	} while (numsAreValid);

	// Task 5

	int nums3[LENGTH];
	for (int i = 0; i < LENGTH; i++)
	{
		std::cout << "Number " << i + 1 << ": ";
		std::cin >> nums3[i];
	}

	int shiftNum = 0;
	std::cout << "Shift :";
	std::cin >> shiftNum;

	for (int c = 0; c < abs(shiftNum); c++)
	{
		if (shiftNum > 0) {
			int next = nums3[0];
			int prev = nums3[0];
			for (int i = 0; i < LENGTH; i++)
			{
				if (i < LENGTH - 1) {
					prev = next;
					next = nums3[i + 1];
					nums3[i + 1] = prev;
				}
				else {
					prev  = next;
					next = nums3[0];
					nums3[0] = prev;
				}
			}
		}
		else {
			int next = nums3[LENGTH - 1];
			int prev = nums3[LENGTH - 1];
			for (int i = LENGTH - 1; i >= 0; i--)
			{
				if (i > 0) {
					prev = next;
					next = nums3[i - 1];
					nums3[i - 1] = prev;
				}
				else {
					prev = next;
					next = nums3[LENGTH - 1];
					nums3[LENGTH - 1] = prev;
				}
			}
		}
	}
	for (int i = 0; i < LENGTH; i++)
	{
		std::cout << nums3[i] << " ";
	}
}