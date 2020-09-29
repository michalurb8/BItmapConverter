#include <fstream>
#include "Image.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

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
	srand(time(NULL));
	rowsize = width * 3 + 3 - (width * 3 - 1)%4; 	//size of one row in bytes
	padding = rowsize - 3 * width; 			//size of padding at the end of a pixel row
	size = rowsize * height; 			//size of the whole pixel array in bytes

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

Pixel Image::GetPixel(UINT xArg, UINT yArg) const
{
	return array[width * yArg + xArg];
}

void Image::SetPixel(short xArg, short yArg, short rArg, short gArg, short bArg)
{
	if(xArg >= (short)width || xArg<0) return;
	if(yArg >= (short)height || yArg<0) return;
	array[width * yArg + xArg].SetColor(rArg, gArg, bArg);
}

void Image::ChangePixel(short xArg, short yArg, short rArg, short gArg, short bArg)
{
	if(xArg >= (short)width || xArg<0) return;
	if(yArg >= (short)height || yArg<0) return;
	array[width * yArg + xArg].ChangeColor(rArg, gArg, bArg);
}

void Image::CyclePixel(short xArg, short yArg, short rArg, short gArg, short bArg)
{
	if(xArg >= (short)width || xArg<0) return;
	if(yArg >= (short)height || yArg<0) return;
	array[width * yArg + xArg].CycleColor(rArg, gArg, bArg);
}

void Image::SetAllRand()
{
	for(UINT i = 0; i < height*width; ++i)
	{
		array[i].SetColor(rand()%256, rand()%256, rand()%256);
	}
}

void Image::SetAll(short rArg, short gArg, short bArg)
{
	for(UINT i = 0; i < height*width; ++i)
	{
		array[i].SetColor(rArg, gArg, bArg);
	}
}

void Image::Export(std::string name) const
{
	std::ofstream output(name + ".bmp");
	//header
	output << "BM";
	output << UCH(size%256);
	output << UCH((size/256)%256);
	output << UCH((size/256/256)%256);
	output << UCH(size/256/256/256);
	output << std::ends << std::ends << std::ends << std::ends;
	output << UCH(28) << std::ends << std::ends << std::ends;
	//DIB header
	output << UCH(12) << std::ends << std::ends << std::ends;
	output << UCH(width%256) << UCH(width/256);
	output << UCH(height%256) << UCH(height/256);
	output << UCH(1) << UCH(0);
	output << UCH(24) << UCH(0);
	output << std::ends << std::ends;
	//pixel array
	for(UINT y = height - 1;; --y)
	{
		for(UINT x = 0; x < width; ++x)
		{
			auto pix = this->GetPixel(x,y);
			output << UCH(pix.B) << UCH(pix.G) << UCH(pix.R);
		}
		for(UINT j = 0; j < padding; ++j)
		{
			output << std::ends;
		}
		if(!y) break;
	}
	output.close();
}
