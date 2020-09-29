#pragma once
#include <ostream>

struct Pixel
{
	short R, G, B;

	Pixel();
	Pixel(short rArg, short gArg, short bArg);

	void SetColor(short rArg, short gArg, short bArg);
	void ChangeColor(short rArg, short gArg, short bArg);
	void CycleColor(short rArg, short gArg, short bArg);

	friend std::ostream& operator<<(std::ostream& ss, const Pixel& arg);
};

std::ostream& operator<<(std::ostream& ss, const Pixel& arg);
void crop(short& value);
