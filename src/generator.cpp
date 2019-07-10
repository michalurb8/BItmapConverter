#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <ctime>
#include <cmath>

int main()
{
	typedef unsigned char UCH;
	srand(time(NULL));
	std::ofstream out("values.txt");
	const int WI = 500, HE = 500;
	int xpos = WI/2, ypos = HE/2;
	int inc = 15;
	UCH* array = new UCH[WI*HE*3];
	for(int i = 0; i< WI*HE*3; i+=3)
	{
		array[i] = (UCH)(0);
		array[i+1] = (UCH)(0);
		array[i+2] = (UCH)(0);
	}
	out << WI << " " << HE << std::endl;
	while(xpos >= 0 && ypos >= 0 && xpos < WI && ypos < HE)
	{
		UCH& ref = array[WI*3*ypos + 3*xpos];
		if(ref + inc > 255) ref = 255;
		else ref += inc;
		UCH& ref2 = array[WI*3*(HE-ypos-1) + 3*xpos +1];
		if(ref2 + inc > 255) ref2 = 255;
		else ref2 += inc;
		xpos += rand()%3 - 1;
		ypos += rand()%3 - 1;
	}
	for (int i = 0; i < HE; ++i)
	{
		for(int j=0; j < WI; ++j)
		{
			out << std::setw(3) << std::left << std::hex << (unsigned int)array[WI*3*i + j*3 + 2] << " ";
			out << std::setw(3) << std::left << std::hex << (unsigned int)array[WI*3*i + j*3 + 1] << " ";
			out << std::setw(3) << std::left << std::hex << (unsigned int)array[WI*3*i + j*3 + 0] << " ";
		}
		out << std::endl;
	}
}
