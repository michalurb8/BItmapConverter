#include <iostream>
#include <fstream>
#include <queue>

int main()
{
	typedef unsigned char UCH;
	std::ofstream output("image.bmp");
	std::ifstream input("values.txt");
	unsigned short WI, HE;
	input >> WI >> HE;
	const unsigned short ROWSIZE = (3*WI + 3 - (3*WI+3)%4);
	const unsigned short SIZE = 28 + HE * ROWSIZE;
	int temp;

	//HEADER
	temp = SIZE;

	output << 'B' << 'M';
	output << (UCH)(temp%256) << (UCH)((temp/=256)%256) << (UCH)((temp/=256)%256) << (UCH)(temp/=256);
	output << (UCH)(0) << (UCH)(0) << (UCH)(0) << (UCH)(0);
	output << (UCH)(28) << (UCH)(0) << (UCH)(0) << (UCH)(0);

	//DIB
	output << (UCH)(12) << (UCH)(0) << (UCH)(0) << (UCH)(0);
	output << (UCH)(WI%256) << (UCH)(WI/256);
	output << (UCH)(HE%256) << (UCH)(HE/256);
	output << (UCH)(1) << (UCH)(0);
	output << (UCH)(24) << (UCH)(0);
	output << (UCH)(0) << (UCH)(0);

	//ARRAY
	int count = 0;
	while(input >> std::hex >> temp)
	{
		output << UCH(temp);
		count++;
		if(count == 3*WI)
		{
			for(int i = 0; i < ROWSIZE - 3*WI; ++i)
			{
				output << (UCH)(0);
			}
			count = 0;
		}
	}
	output.close();
	return 0;
}
