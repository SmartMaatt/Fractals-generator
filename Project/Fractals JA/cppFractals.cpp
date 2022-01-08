#include "cppFractals.h"

void CppFractalsGenerate(unsigned char* bmpData, int r, int g, int b, int x, int y, int width, int height)
{
	int index = (x + ((height - 1) - y) * width) * 3;
	bmpData[index + 2] = (unsigned char)r;
	bmpData[index + 1] = (unsigned char)g;
	bmpData[index] = (unsigned char)b;
}