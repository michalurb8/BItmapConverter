#include <iostream>
#include "Image.h"

int main()
{
	Image a(5, 6);
	Image c;
	c=a;
	Image b=c;
	b.SetPixel(0,0,255,255,255);
	b.SetPixel(4,0,255,0,255);
	b.SetPixel(0,5,255,255,0);
	b.SetPixel(4,5,0,255,255);
	b.Print();
	b.Export("abecede");
	return 0;
}