#include "Pixel.h"

Pixel::Pixel() : R(0), G(0), B(0) {}
Pixel::Pixel(UCH rArg, UCH gArg, UCH bArg) : R(rArg), G(gArg), B(bArg) {}
void Pixel::SetColor(UCH rArg, UCH gArg, UCH bArg)
{
	R = rArg;
	G = gArg;
	B = bArg;
}
void Pixel::ChangeColor(UCH rArg, UCH gArg, UCH bArg) //add until 255 reached
{
	if(R + rArg < 0) R = 0;
	else if (R + rArg > 255) R = 255;
	else R = R + rArg;
	if(G + gArg < 0) G = 0;
	else if (G + gArg > 255) G = 255;
	else G = G + gArg;
	if(B + bArg < 0) B = 0;
	else if (B + bArg > 255) B = 255;
	else B = B + bArg;
}
void Pixel::CycleColor(UCH rArg, UCH gArg, UCH bArg) //add modulo 255
{
	R += rArg;
	G += gArg;
	B += bArg;
}
std::ostream& operator<<(std::ostream& ss, const Pixel& arg)
{
	ss << arg.B << arg.G << arg.R;
	return ss;
}