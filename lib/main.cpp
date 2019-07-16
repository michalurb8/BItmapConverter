#include <iostream>
#include "Image.h"

int main()
{
	Image b(5,6);
	b.SetAll(100, 0, 100);
	b.SetPixel(0,0,255,255,255);
	b.SetPixel(4,0,255,0,255);
	b.SetPixel(0,5,255,255,0);
	b.SetPixel(4,5,0,255,255);
	b.Print();
	b.Export();
	return 0;
}