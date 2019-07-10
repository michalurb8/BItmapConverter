#include <iostream>
#include "Pixel.cpp"
class Image
{
	typedef unsigned char UCH;
	typedef unsigned int UINT;
	UINT width, height, rowsize, size, padding;
	public:
	Pixel* array;
	Image()
	{
		width = 4;
		height = 4;
		Set();
	}
	Image(UINT wArg, UINT hArg)
	{
		width = wArg;
		height = hArg;
		Set();
	}
	Image(const Image& arg)
	{
		width = arg.GetWidth();
		height = arg.GetHeight();
		Set();
	}
	Image operator=(const Image& arg)
	{
		std::cout<<"1 ";
		delete[] array;
		std::cout<<"2 ";
		width = arg.GetWidth();
		height = arg.GetHeight();
		Set();
	}
	~Image()
	{
		std::cout<<"1d ";
		delete[] array;
		std::cout<<"2d ";
	}
	void Set()
	{
		rowsize = width * 3 + 3 - (width * 3 - 1)%4;
		padding = rowsize - 3 * width;
		size = rowsize * height;
		array = new Pixel[size];
	}
	UINT GetWidth() const
	{
		return width;
	}
	UINT GetHeight() const
	{
		return height;
	}
};
