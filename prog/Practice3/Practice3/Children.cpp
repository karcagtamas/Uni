#include "Children.h"
#include <iostream>

Children::Children(int x, int y, int z) : Test(x, y), nyelescukorka(z) {
}

void Children::Alma() {
	std::cout << "Nyelescikorkak: " << nyelescukorka << std::endl;
	std::cout << "Hmmm.... ez nem eleeee5g :)" << std::endl;
}