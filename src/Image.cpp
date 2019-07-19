#include <iostream>
#include <fstream>
#include "Image.h"

Image::Image()
{
	width = 1;
	height = 1;
	Set();
}
Image::Image(UINT wArg, UINT hArg)
{
	if(!wArg) wArg = 1;
	if(!hArg) hArg = 1;
	width = wArg;
	height = hArg;
	Set();
}
Image::Image(const Image& arg)
{
	width = arg.GetWidth();
	height = arg.GetHeight();
	Set();
}
Image Image::operator=(const Image& arg)
{
	delete[] array;
	width = arg.GetWidth();
	height = arg.GetHeight();
	Set();
	return *this;
}
Image::~Image()
{
	delete[] array;
}
void Image::Set()
{
	rowsize = width * 3 + 3 - (width * 3 - 1)%4;
	padding = rowsize - 3 * width;
	size = rowsize * height;

	array = new Pixel[width * height];
}
Image::UINT Image::GetWidth() const
{
	return width;
}
Image::UINT Image::GetHeight() const
{
	return height;
}
void Image::Print() const
{
	for(int i = 0; i < height; ++i)
	{
		for(int j = 0; j < width; ++j)
		{
			array[width * i + j].Print();
		}
		std::cout << std::endl;
	}
}
Pixel Image::GetPixel(UINT xArg, UINT yArg) const
{
	return array[width * yArg + xArg];
}
Image Image::SetPixel(UINT xArg, UINT yArg, UINT rArg, UINT gArg, UINT bArg)
{
	if(xArg >= width) xArg = width - 1;
	if(yArg >= height) yArg = height - 1;
	array[width * yArg + xArg].SetColor(rArg, gArg, bArg);
	return *this;
}
Image Image::ChangePixel(UINT xArg, UINT yArg, UINT rArg, UINT gArg, UINT bArg)
{
	if(xArg >= width) xArg = width - 1;
	if(yArg >= height) yArg = height - 1;
	array[width * yArg + xArg].ChangeColor(rArg, gArg, bArg);
	return *this;
}
Image Image::CyclePixel(UINT xArg, UINT yArg, UINT rArg, UINT gArg, UINT bArg)
{
	if(xArg >= width) xArg = width - 1;
	if(yArg >= height) yArg = height - 1;
	array[width * yArg + xArg].CycleColor(rArg, gArg, bArg);
	return *this;
}
Image Image::SetAll(UINT rArg, UINT gArg, UINT bArg)
{
	for(int y = 0; y < height; ++y)
	{
		for(int x = 0; x < width; ++x)
		{
			array[width * y + x].SetColor(rArg, gArg, bArg);
		}
	}
	return *this;
}
void Image::Export(std::string name) const
{
	std::ofstream output(name + ".bmp");
	output << "BM";
	output << UCH(size%256);
	output << UCH((size/256)%256);
	output << UCH((size/256/256)%256);
	output << UCH(size/256/256/256);
	output << std::ends << std::ends << std::ends << std::ends;
	output << UCH(28) << std::ends << std::ends << std::ends;
	output << UCH(12) << std::ends << std::ends << std::ends;
	output << UCH(width%256) << UCH(width/256);
	output << UCH(height%256) << UCH(height/256);
	output << UCH(1) << UCH(0);
	output << UCH(24) << UCH(0);
	output << std::ends << std::ends;
	for(int y = height - 1; y >= 0; --y)
	{
		for(int x = 0; x < width; ++x)
		{
			output << this->GetPixel(x,y);
		}
		for(int j=0; j < padding; ++j)
		{
			output << std::ends;
		}
	}
	output.close();
}