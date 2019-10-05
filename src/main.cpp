#include "Image.h"

int main()
{
	Image example(50, 50);
	example.SetAll(0, 0, 50);
	example.SetPixel(5,1,255,255,255);
	for(int i = 0; i < 50; ++i)
	{
		example.ChangePixel(0,0,1,-1,1);
	}
	example.Export("example");
	return 0;
}
