#pragma once

#include "Pixel.h"
#include <string>

class Image
{
	typedef unsigned char UCH;
	typedef unsigned int UINT;

	UINT width, height, rowsize, size, padding;

public:
	Pixel* array;//move

	Image();
	Image(UINT wArg, UINT hArg);
	Image(const Image& arg);
	Image operator=(const Image& arg);
	~Image();

	void Set();
	UINT GetWidth() const;
	UINT GetHeight() const;

	Pixel GetPixel(UINT xArg, UINT yArg) const;

	void SetPixel(short xArg, short yArg, short rArg, short gArg, short bArg);
	void ChangePixel(short xArg, short yArg, short rArg, short gArg, short bArg);
	void CyclePixel(short xArg, short yArg, short rArg, short gArg, short bArg);

	void Blur4();
	void Blur8();
	void SetAll(short rArg, short gArg, short bArg);
	void SetAllRand();
	void Export(std::string fileName = "default") const;
};
