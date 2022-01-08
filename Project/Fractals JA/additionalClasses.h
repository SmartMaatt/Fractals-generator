#pragma once
#include <iostream>

/**
 * Klasa będąca szablonem liczby zespolonej.
 */
class ComplexNumber
{
private:
	double x;
	double y;

public:
	ComplexNumber()
	{
		this->x = 0;
		this->y = 0;
	}

	ComplexNumber(double x, double y)
	{
		this->x = x;
		this->y = y;
	}

	void Pow()
	{
		double oldX = this->x;
		this->x = this->x * this->x + (this->y * this->y * (-1));
		this->y = 2 * oldX * this->y;
	}

	double Abs()
	{
		double value = (this->x * this->x) + (this->y * this->y);
		value = sqrt(value);
		return value;
	}

	void AddValue(ComplexNumber added)
	{
		this->x += added.GetX();
		this->y += added.GetY();
	}

	void SetValue(double x, double y) 
	{
		this->x = x;
		this->y = y;
	}

	double GetX() { return this->x; }
	double GetY() { return this->y; }

	void Debug()
	{
		std::cout << "z = " << this->x;

		if (this->y > 0)
		{
			std::cout << " + " << this->y << "i" << std::endl;
		}
		else if (this->y < 0)
		{
			std::cout << " - " << (this->y * (-1)) << "i" << std::endl;
		}
		else
		{
			std::cout << std::endl;
			return;
		}
	}
};


/**
 * Klasa przechowuje dane odnośnie aktualnego obrazu wyjściowego oraz jego parametrów.
 */
public ref class AlgorythmData 
{
private:
	unsigned width;
	unsigned height;
	double scale;

	bool mandel;
	double cArgX;
	double cArgY;

	double offX;
	double offY;

public:
	AlgorythmData()
	{
		this->width = 0;
		this->height = 0;
		this->scale = 0;

		this->mandel = false;
		this->cArgX = 0;
		this->cArgY = 0;

		this->offX = 0;
		this->offY = 0;
	}

	// Settery
	void SetWidth(unsigned width) { this->width = width; }
	void SetHeight(unsigned height) { this->height = height; }
	void SetScale(double scale) { this->scale = scale; }
	void SetMandel(bool mandel) { this->mandel = mandel; }
	void SetCArgX(double x) { this->cArgX = x; }
	void SetCArgY(double y) { this->cArgY = y; }
	void SetOffX(double offX) { this->offX = offX; }
	void SetOffY(double offY) { this->offY = offY; }

	// Gettery
	unsigned GetWidth() { return this->width; }
	unsigned GetHeight() { return this->height; }
	double GetScale() { return this->scale; }
	bool GetMandel() { return this->mandel; }
	double GetCArgX() { return this->cArgX; }
	double GetCArgY() { return this->cArgY; }
	double GetOffX() { return this->offX; }
	double GetOffY() { return this->offY; }
};