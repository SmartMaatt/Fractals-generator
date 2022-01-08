#include "fileOrganise.h"

/**
 * Konstruktor klasy FileOrganiser
 */
FileOrganiser::FileOrganiser()
{
	this->height = 0;
	this->width = 0;
	this->bmpData = nullptr;
}

/**
 * Alokuje tablicę przechowującą obraz wynikowy w oparciu o podane wymiary
 *
 * @param height Wysokość obrazu wynikowego.
 * @param width Szerokość obrazu wynikowego.
 */
void FileOrganiser::InsertData(int width, int height)
{
	this->height = height;
	this->width = width;

	if ((height > 0) && (width > 0))
	{
		bmpData = new unsigned char[height * width * 3];
	}
	else
	{
		this->bmpData = nullptr;
	}
}

/**
 * Metoda obsługuje wywołanie okna dialogowego, zapis tablicy bajtów do pliku bmp oraz walidację błędów.
 *
 * @param sender Obiekt wywołujący akcję.
 * @param e Argumenty wydarzenia.
 * @return W przypadku powodzenia operacji zapisu zwracana jest nazwa pliku, w przeciwnym wypadku jest to kod błędu.
 */
String^ FileOrganiser::SaveFile(System::Object^ sender, System::EventArgs^ e)
{
	Stream^ myStream;
	SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();  // Utworzenie okna dialogowego

	saveFileDialog->Filter = "bmp files (*.bmp)|*.bmp";
	saveFileDialog->FilterIndex = 1;

	if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		if ((myStream = saveFileDialog->OpenFile()) != nullptr)
		{
			String^ file_adres = saveFileDialog->FileName;	// Odczyt adres pliku
			myStream->Close();

			// Konwersja System::String na std::string
			string loaded_adres_std = msclr::interop::marshal_as<string>(file_adres);
			// Konwersja na char*
			const char *cfilename = loaded_adres_std.c_str();

			int filesize = 54 + 3 * width * height;

			unsigned char bmpfileheader[14] = { 'B','M', 0,0,0,0, 0,0,0,0, 54,0,0,0 };
			unsigned char bmpinfoheader[40] = { 40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0, 24,0 };
			unsigned char bmppad[3] = { 0,0,0 };

			bmpfileheader[2] = (unsigned char)(filesize);
			bmpfileheader[3] = (unsigned char)(filesize >> 8);
			bmpfileheader[4] = (unsigned char)(filesize >> 16);
			bmpfileheader[5] = (unsigned char)(filesize >> 24);

			bmpinfoheader[4] = (unsigned char)(width);
			bmpinfoheader[5] = (unsigned char)(width >> 8);
			bmpinfoheader[6] = (unsigned char)(width >> 16);
			bmpinfoheader[7] = (unsigned char)(width >> 24);
			bmpinfoheader[8] = (unsigned char)(height);
			bmpinfoheader[9] = (unsigned char)(height >> 8);
			bmpinfoheader[10] = (unsigned char)(height >> 16);
			bmpinfoheader[11] = (unsigned char)(height >> 24);

			FILE *f = fopen(cfilename, "wb");
			fwrite(bmpfileheader, 1, 14, f);
			fwrite(bmpinfoheader, 1, 40, f);
			for (int i = 0; i < height; i++)
			{
				fwrite(bmpData + (width * (height - i - 1) * 3), 3, width, f);
				fwrite(bmppad, 1, (4 - (width * 3) % 4) % 4, f);
			}

			fclose(f);
		}
		else
		{
			//Błąd podczas próby wprowadzania danych do pliku bmp
			return "Error2";
		}
	}
	else
	{
		// Błąd podczas próby wyświetlenia okna dialogowego
		return "Error1";
	}

	return saveFileDialog->FileName;
}

/**
 * Usuwa dynamicznie zaalokowaną pamięć obrazu wynikowego.
 */
void FileOrganiser::DeleteData()
{
	this->width = 0;
	this->height = 0;

	if (this->bmpData)
	{
		delete[] this->bmpData;
		this->bmpData = nullptr;
	}
}

// Gettery
unsigned char* FileOrganiser::GetBmpData() { return this->bmpData; }
int FileOrganiser::GetWidth() { return this->width; }
int FileOrganiser::GetHeight() { return this->height; }