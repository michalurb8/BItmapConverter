#include <fstream>
#include "Image.h"

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
	rowsize = width * 3 + 3 - (width * 3 - 1)%4; 	//size of one row in bytes
	padding = rowsize - 3 * width; 					//size of padding at the end of a pixel row
	size = rowsize * height; 						//size of the whole pixel array in bytes

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
void Image::SetPixel(UINT xArg, UINT yArg, UINT rArg, UINT gArg, UINT bArg)
{
	if(xArg >= width) return;
	if(yArg >= height) return;
	array[width * yArg + xArg].SetColor(rArg, gArg, bArg);
}
void Image::ChangePixel(UINT xArg, UINT yArg, UINT rArg, UINT gArg, UINT bArg)
{
	if(xArg >= width) xArg = width - 1;
	if(yArg >= height) yArg = height - 1;
	array[width * yArg + xArg].ChangeColor(rArg, gArg, bArg);
}
void Image::CyclePixel(UINT xArg, UINT yArg, UINT rArg, UINT gArg, UINT bArg)
{
	if(xArg >= width) xArg = width - 1;
	if(yArg >= height) yArg = height - 1;
	array[width * yArg + xArg].CycleColor(rArg, gArg, bArg);
}
void Image::SetAll(UINT rArg, UINT gArg, UINT bArg)
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
			output << this->GetPixel(x,y);
		}
		for(UINT j=0; j < padding; ++j)
		{
			output << std::ends;
		}
		if(!y) break;
	}
	output.close();
}