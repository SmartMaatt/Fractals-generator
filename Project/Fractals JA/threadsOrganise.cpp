#include "threadsOrganise.h"
#include "additionalClasses.h"

/**
 * Konstruktor klasy ThreadsOrganise.
 */
ThreadsOrganise::ThreadsOrganise() {}

/**
 * Ocena wartości koloru piksela na podstawie przekazanych argumentów.
 *
 * @param complexNumber Obiekt liczby zespolonej przekazany do analizy.
 * @param max Maksymalna wartość głębokości nasycenia koloru piksela.
 * @param arg Obiekt liczby zespolonej przekazany w celu dodania odpowiedniej korekty.
 * @return Wartość głębokości nasycenia koloru piksela.
 */
unsigned ThreadsOrganise::Eval(const ComplexNumber complexNumber, unsigned max, const ComplexNumber arg) {

	ComplexNumber c = complexNumber;
	for (unsigned i = 0; i < max; i++)
	{
		if (c.Abs() > 2)
		{
			return i;
		}

		c.Pow();
		c.AddValue(arg);
	}
	return max;
}

/**
 * Oblicza przybliżoną wartość koloru częsci RGB przy pomocy interpolacji liniowej.
 *
 * @return Przybliżona wartość koloru części RGB.
 */
double ThreadsOrganise::Lerp(double x0, double y0, double x1, double y1, double t) {
	double m = (y1 - y0) / (x1 - x0);
	return y0 + t * m;
}

/**
 * Określa kolor jednej z wartości R,G lub B odnosząc się do przekazanej głębokości nasycenia koloru.
 *
 * @param calculatedColorDepth Głębokość nasycenia koloru
 * @param R Jeśli true, wtedy obliczana jest wartość pod element R piksela.
 * @param G Jeśli true, wtedy obliczana jest wartość pod element G piksela.
 * @param B Jeśli true, wtedy obliczana jest wartość pod element B piksela.
 * @return Wartość koloru części piksela w przedziale <0, 255>.
 */
int ThreadsOrganise::CompColor(unsigned calculatedColorDepth, bool R, bool G, bool B) {

	int Aq, Bq, Dq;
	if (R) {
		Aq = A_R;
		Bq = B_R;
		Dq = D_R;
	}
	else if (G) {
		Aq = A_G;
		Bq = B_G;
		Dq = D_G;
	}
	else if (B) {
		Aq = A_B;
		Bq = B_B;
		Dq = D_B;
	}

	if (calculatedColorDepth == colorDepth)
	{
		return Dq;
	}
	double rat = (double)calculatedColorDepth / colorDepth;
	double dc = Lerp(0, Aq, 1, Bq, rat);
	return (int)dc;
}

/**
 * Funkcja zarządzająca wywołaniem funkcji generowania fraktali c++ lub asm
 *
 * @param tuplePackage Obiekt krotki zawierający dane potrzebne do generowania piksela.
 */
void ThreadsOrganise::GenerateFractal(Object^ tuplePackage)
{
	double r = 0;
	double i = 0;
	ComplexNumber c = ComplexNumber();
	unsigned color = 0;

	// Rozpakowywanie przesłanej krotki.
	Tuple<FileOrganiser^, bool, int, int, AlgorythmData^>^ params = (Tuple<FileOrganiser^, bool, int, int, AlgorythmData^>^) tuplePackage; // krotka z parametrami

	// Inicjalizacja odpowiednich danych z odebranej krotki.
	FileOrganiser^ fileOrg = params->Item1;
	bool cpp = params->Item2;
	int x = params->Item3;
	int y = params->Item4;
	AlgorythmData^ AlData = params->Item5;

	// Obliczenie wartości liczby zespolonej.
	r = AlData->GetOffX() - AlData->GetScale() / 2 + AlData->GetScale() * x / AlData->GetWidth();
	i = AlData->GetOffY() - AlData->GetScale() / 2 + AlData->GetScale() * y / AlData->GetHeight();
	c.SetValue(r, i);

	if (AlData->GetMandel())
	{
		color = Eval(c, colorDepth, c);
	}
	else
	{
		ComplexNumber arg = ComplexNumber();
		arg.SetValue(AlData->GetCArgX(), AlData->GetCArgY());
		color = Eval(c, colorDepth, arg);
	}

	// Jeśli wybrano tryb cpp
	if (cpp)
	{
		CppFractalsGenerate(fileOrg->GetBmpData(), CompColor(color, true, false, false), CompColor(color, false, true, false), CompColor(color, false, false, true), x, y, AlData->GetWidth(), AlData->GetHeight());
	}
	else
	{
		AsmFractalsGenerate(fileOrg->GetBmpData(), CompColor(color, true, false, false), CompColor(color, false, true, false), CompColor(color, false, false, true), x, y, AlData->GetWidth(), AlData->GetHeight());
	}
}