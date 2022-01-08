#pragma once
#include <string>
#include <bitset>
#include <direct.h>
#include <msclr\marshal_cppstd.h>

using namespace std;
using namespace System;
using namespace System::IO;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/**
 * Klasa zarządzająca zapisem fraktalu do pliku, przechowując tymczasowy plik wynikowy w postaci tablicy bajtów.
 * Zawiera metody zapisu oraz operacji na danych obrazu.
 */
public ref class FileOrganiser
{
private:
	int width, height;
	unsigned char* bmpData;

	const int BYTES_PER_PIXEL = 3; /// red, green, & blue
	const int FILE_HEADER_SIZE = 14;
	const int INFO_HEADER_SIZE = 40;

public:
	FileOrganiser();
	void InsertData(int width, int height);

	String^ SaveFile(System::Object^ sender, System::EventArgs^ e);
	void DeleteData();

	unsigned char* GetBmpData();
	int GetWidth();
	int GetHeight();
};