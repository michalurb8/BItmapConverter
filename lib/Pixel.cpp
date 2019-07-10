class Pixel
{
	typedef unsigned char UCH;
	typedef unsigned int UINT;
	UCH R, G, B;
	public:
	Pixel()
	{
		R = G = B = 0;
	}
	Pixel(UCH rArg, UCH gArg, UCH bArg)
	{
		R = rArg;
		G = gArg;
		B = bArg;
	}
	Pixel SetColor(UCH rArg, UCH gArg, UCH bArg)
	{
		R = rArg;
		G = gArg;
		B = bArg;
	}
	Pixel SetRed(UCH rArg)
	{
		R = rArg;
	}
	Pixel SetGreen(UCH gArg)
	{
		G = gArg;
	}
	Pixel SetBlue(UCH bArg)
	{
		B = bArg;
	}
	UCH GetRed()
	{
		return R;
	}
	UCH GetGreen()
	{
		return G;
	}
	UCH GetBlue()
	{
		return B;
	}
	UINT GetRedASCII()
	{
		return (UINT)R;
	}
	UINT GetGreenASCII()
	{
		return (UINT)G;
	}
	UINT GetBlueASCII()
	{
		return (UINT)B;
	}
};
