#include "Test.h"
#include <iostream>

Test::Test(int x, int y):x(x), y(y){

}

void Test::Alma() {
	std::cout << x << " and " << y << std::endl;
}
