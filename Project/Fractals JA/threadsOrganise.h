#pragma once
#include <msclr\marshal_cppstd.h>
#include "fileOrganise.h"
#include "cppFractals.h"

extern "C" bool CheckMMXCapability();
extern "C" void AsmFractalsGenerate(unsigned char* bmpData, int r, int g, int b, int x, int y, int width, int height);

using namespace std;
using namespace System;

/**
 * Klasa kontroluje wywoływanie wątków oraz rozdysponowywanie danych pomiędzy nimi.
 */
public ref class ThreadsOrganise
{
private:
	int colorDepth = 64;

	// Próbki kolorów wynikowego zdjęcia.
	// Tło
	int A_R = 153;
	int A_G = 217;
	int A_B = 255;

	// Czarny
	int B_R = 255;
	int B_G = 102;
	int B_B = 102;

	// Biały
	int D_R = 23;
	int D_G = 23;
	int D_B = 23;

public:
	ThreadsOrganise();
	void GenerateFractal(Object^ parameter);

	unsigned Eval(const ComplexNumber comp, unsigned max, const ComplexNumber arg);
	double Lerp(double x0, double y0, double x1, double y1, double t);
	int CompColor(unsigned val, bool R, bool G, bool B);
};