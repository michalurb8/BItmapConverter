#include "Image.h"
int main()  
{
	Image example(50,50);
	example.SetAll(50,0,50);
	example.SetPixel(5,1,255,255,255);
	for(int x=10; x<60; ++x)
	{
		example.ChangePixel(x,8,100,100,100);
	}
	example.Export("example");
	return 0;
}
