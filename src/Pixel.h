#pragma once
#include <ostream>

struct Pixel
{
	typedef unsigned char UCH;
	UCH R, G, B;
	Pixel();
	Pixel(UCH rArg, UCH gArg, UCH bArg);
	void SetColor(UCH rArg, UCH gArg, UCH bArg);
	void ChangeColor(UCH rArg, UCH gArg, UCH bArg);
	void CycleColor(UCH rArg, UCH gArg, UCH bArg);
	void Print() const;
	friend std::ostream& operator<<(std::ostream& ss, const Pixel& arg);
};

std::ostream& operator<<(std::ostream& ss, const Pixel& arg);