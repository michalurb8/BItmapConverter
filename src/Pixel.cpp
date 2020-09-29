#include "Pixel.h"
#include <iostream>

Pixel::Pixel() : R(0), G(0), B(0) {}
Pixel::Pixel(short rArg, short gArg, short bArg) : R(rArg), G(gArg), B(bArg) {}

void Pixel::SetColor(short rArg, short gArg, short bArg)
{
	R = rArg;
	G = gArg;
	B = bArg;
	crop(R);
	crop(G);
	crop(B);
}

void Pixel::ChangeColor(short rArg, short gArg, short bArg) //change but stay at limit
{
	R += rArg;
	G += gArg;
	B += bArg;
	crop(R);
	crop(G);
	crop(B);
}

void Pixel::CycleColor(short rArg, short gArg, short bArg) //add modulo 255
{
	R += rArg;
	G += gArg;
	B += bArg;
	R %= 256;
	G %= 256;
	B %= 256;
}

void crop(short& value)
{
	if(value<0) value=0;
	if(value>255) value=255;
}
