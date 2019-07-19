#include <iostream>
#include "Image.h"

int main()
{
	Image b(5,6);
	b.SetAll(0,0,0);
	for(int i = 0; i < 260; ++i)
	{
		b.CyclePixel(0,0,1,1,1);
	}
	b.Export();
	return 0;
}