#include <iostream>
#include "Image.h"

int main()
{
	Image b(1,1);
	b.SetAll(0, 0, 0);
	b.SetPixel(0,0,0,0,0);
	for(int i = 0; i < 260; ++i)
	{
		b.ChangePixel(0,0,1,-1,1);
	}
	b.Export();
	return 0;
}