#include <iostream>
#include <cmath>
#include <string>
#define A 10;
#define N 20;
#define M_PI = 3.14;

int main()
{
    // Task 1
    //int rows = N;
    //for (int i = 0; i < rows; i++)
    //{
    //    double valOfSin = sin(i * (2 * 3.14) / rows);
    //    double val = valOfSin * (double)A;
    //    val += A;
    //    for (int j = 0; j < val; j++)
    //    {
    //        std::cout << ' ';
    //    }
    //    std::cout << "*\n";
    //}


    //// Task 2
    //std::cout << "Hello World!\n";
    //int a = 0, b = 0, c = 0;
    //std::cout << "A: ";
    //std::cin >> a;
    //std::cout << "B: ";
    //std::cin >> b;
    //std::cout << "C: ";
    //std::cin >> c;

    //std::cout << "Result: " << std::endl;
    //double D = (b * b) - (double)(4 * a * c);
    //if (D > 0){
    //    // 2 result
    //    double x1 = (-b + sqrt(D)) / (2 * b);
    //    double x2 = (-b - sqrt(D)) / (2 * b);
    //    std::cout << "X1: " << x1 << std::endl;
    //    std::cout << "X2: " << x2 << std::endl;
    //}
    //else if (D == 0) {
    //    // 1 result
    //    double x = -b / (2 * b);
    //    std::cout << "X: " << x << std::endl;
    //}
    //else {
    //    // no result
    //    std::cout << "There is not any real result" << std::endl;
    //}

    // Task 3
    std::string val = "";
    std::cout << "Rendszam: ";
    getline(std::cin, val);

    if (val == "k") {
        return 0;
    }

    if (val.length() != 7 && val.length() != 6) {
        std::cout << "Invalid length";
        return 1;
    }
    for (int i = 0; i <= 2; i++)
    {
        if (!isalpha(val[i])) {
            std::cout << "Invalid first secton. Only chars";
            return 1;
        }
    }
    if (val.length() == 7) {
        if (val[3] != '-' && val[3] != ' ') {
            std::cout << "Requires '-' char";
            return 1;
        }
    }
    int start = val.length() == 7 ? 4 : 3;
    int end = start + 3;
    for (int i = start; i < end; i++)
    {
        if (!isdigit(val[i])) {
            std::cout << "Invalid second secton. Only nums";
            return 1;
        }
    }
    std::cout << "Valid";
    return 0;
}
