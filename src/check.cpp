#include <iostream>
#include <iomanip>
#include <fstream>

int main()
{
	std::ifstream input("image.bmp");
	unsigned char element;
	int i=0;
	while(input >> std::noskipws >> element)
	{
		++i;
		std::cout << std::setw(3) << std::left << (unsigned int)(element) << " ";
		if(i == 28 || i==14) std::cout << std::endl;
		if(i>28 && (i-28)%16 ==0)std::cout << std::endl;
		else if(i>28 && ((i-28)%16)%3 ==0)std::cout << "   ";
	}
	std::cout << std::endl << i << std::endl;
	return 0;
}
