#include <iostream>
#include <iomanip>
#include "Pixel.h"

Pixel::Pixel()
{
	R = G = B = 0;
}
Pixel::Pixel(UCH rArg, UCH gArg, UCH bArg)
{
	R = rArg;
	G = gArg;
	B = bArg;
}
Pixel Pixel::SetColor(UCH rArg, UCH gArg, UCH bArg)
{
	R = (UCH)rArg;
	G = (UCH)gArg;
	B = (UCH)bArg;
}
Pixel Pixel::ChangeColor(UCH rArg, UCH gArg, UCH bArg)
{
	R = rArg > 255 - R ? 255 : R + rArg; 
	G = gArg > 255 - G ? 255 : G + gArg; 
	B = bArg > 255 - B ? 255 : B + bArg; 
	return *this;
}
Pixel Pixel::CycleColor(UCH rArg, UCH gArg, UCH bArg)
{
	R += (UCH)rArg;
	G += (UCH)gArg;
	B += (UCH)bArg;
	return *this;
}
Pixel Pixel::SetRed(UCH rArg)
{
	R = rArg;
	return *this;
}
Pixel Pixel::SetGreen(UCH gArg)
{
	G = gArg;
	return *this;
}
Pixel Pixel::SetBlue(UCH bArg)
{
	B = bArg;
}
Pixel::UCH Pixel::GetRed() const
{
	return R;
}
Pixel::UCH Pixel::GetGreen() const
{
	return G;
}
Pixel::UCH Pixel::GetBlue() const
{
	return B;
}
Pixel::UINT Pixel::GetRedASCII() const
{
	return (UINT)R;
}
Pixel::UINT Pixel::GetGreenASCII() const
{
	return (UINT)G;
}
Pixel::UINT Pixel::GetBlueASCII() const
{
	return (UINT)B;
}
void Pixel::Print() const
{
	std::cout << std::setw(3) << std::left << UINT(R) << " ";
	std::cout << std::setw(3) << std::left << UINT(G) << " ";
	std::cout << std::setw(3) << std::left << UINT(B) << " ";
	std::cout << "  ";
}
std::ostream& operator<<(std::ostream& ss, const Pixel& arg)
{
	ss << arg.GetBlue() << arg.GetGreen() << arg.GetRed();
	return ss;
}