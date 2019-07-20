#include <iostream>
#include "Image.h"

int main()
{
	Image b(1000,1000);
	b.SetAll(0, 0, 0);
	for(int i = 0; i < 100000; ++i)
	{
		b.SetPixel(0,0,100,100,100);
	}
	b.Export();
	return 0;
}