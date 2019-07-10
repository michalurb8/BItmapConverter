#include <iostream>
#include "Image.cpp"

int main()
{
	Image a(5, 6);
	Image c;
	c=a;
	Image b=c;
	return 0;
}
