#pragma once
#include <string.h>
#include <chrono>
#include <msclr\marshal_cppstd.h>
#include "fileOrganise.h"
#include "threadsOrganise.h"
#include "additionalClasses.h"

namespace FractalsJA
{
	using namespace msclr::interop;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace std;
	using namespace std::chrono;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		FileOrganiser^ fileOrg;	// Definicja klasy FileOrganiser
		MyForm(void)
		{
			InitializeComponent();
			fileOrg = gcnew FileOrganiser();	// Utworzenie obiektu zarządzania plikiem zdjęcia.
			thOrg = gcnew ThreadsOrganise();	// Utworzenie obiektu zarządzania wątkami.

			// Wykrycie dostępnych wątków
			threadsNumericUpDown->Value = Environment::ProcessorCount;	// Wprowadzenie rekomentowanej liczby wątków do suwaka dostępnego w UI.
			consoleTextBox->Text = "Zalecana liczba watkow: " + Environment::ProcessorCount.ToString();
		}

	protected:
		~MyForm()
		{
			fileOrg->DeleteData();
			if (components)
			{
				delete components;
			}
		}

	private:
		ThreadsOrganise^ thOrg;
		System::Windows::Forms::Button^  deleteButton;
		System::Windows::Forms::TextBox^  offsetTextBox;
		System::Windows::Forms::Label^  label3;
		System::Windows::Forms::TextBox^  iterationTextBox;
		System::Windows::Forms::Label^  label2;
		System::Windows::Forms::TextBox^  sizeTextBox;
		System::Windows::Forms::Label^  MainLabel;
		System::Windows::Forms::Panel^  panelLogo;
		System::Windows::Forms::NumericUpDown^  threadsNumericUpDown;
		System::Windows::Forms::GroupBox^  groupBox3;
		System::Windows::Forms::Button^  saveButton;
		System::Windows::Forms::RadioButton^  cppRadioButton;
		System::Windows::Forms::Label^  label1;
		System::Windows::Forms::RadioButton^  asmRadioButton;
		System::Windows::Forms::GroupBox^  groupBox1;
		System::Windows::Forms::Panel^  panelButtons;
		System::Windows::Forms::GroupBox^  groupBox2;
		System::Windows::Forms::Button^  EDButton;
		System::Windows::Forms::Panel^  panelBottom;
		System::Windows::Forms::Button^  generateButton;
		System::Windows::Forms::Label^  InfoLabel1;
		System::Windows::Forms::TextBox^  consoleTextBox;
		System::Windows::Forms::Panel^  panelControl;
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obsługi projektanta — nie należy modyfikować
		/// jej zawartości w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->deleteButton = (gcnew System::Windows::Forms::Button());
			this->offsetTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->iterationTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->sizeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->MainLabel = (gcnew System::Windows::Forms::Label());
			this->panelLogo = (gcnew System::Windows::Forms::Panel());
			this->threadsNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->saveButton = (gcnew System::Windows::Forms::Button());
			this->cppRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->asmRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->panelButtons = (gcnew System::Windows::Forms::Panel());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->EDButton = (gcnew System::Windows::Forms::Button());
			this->panelBottom = (gcnew System::Windows::Forms::Panel());
			this->generateButton = (gcnew System::Windows::Forms::Button());
			this->InfoLabel1 = (gcnew System::Windows::Forms::Label());
			this->consoleTextBox = (gcnew System::Windows::Forms::TextBox());
			this->panelControl = (gcnew System::Windows::Forms::Panel());
			this->panelLogo->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->threadsNumericUpDown))->BeginInit();
			this->groupBox3->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->panelButtons->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->panelBottom->SuspendLayout();
			this->panelControl->SuspendLayout();
			this->SuspendLayout();
			// 
			// deleteButton
			// 
			this->deleteButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->deleteButton->Enabled = false;
			this->deleteButton->Location = System::Drawing::Point(255, 7);
			this->deleteButton->Name = L"deleteButton";
			this->deleteButton->Size = System::Drawing::Size(104, 39);
			this->deleteButton->TabIndex = 17;
			this->deleteButton->Text = L"Delete data";
			this->deleteButton->UseVisualStyleBackColor = true;
			this->deleteButton->Click += gcnew System::EventHandler(this, &MyForm::deleteButton_Click);
			// 
			// offsetTextBox
			// 
			this->offsetTextBox->Location = System::Drawing::Point(9, 128);
			this->offsetTextBox->Name = L"offsetTextBox";
			this->offsetTextBox->Size = System::Drawing::Size(197, 22);
			this->offsetTextBox->TabIndex = 5;
			this->offsetTextBox->Text = L"0,0";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(9, 108);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(68, 17);
			this->label3->TabIndex = 4;
			this->label3->Text = L"OffX,OffY";
			// 
			// iterationTextBox
			// 
			this->iterationTextBox->Location = System::Drawing::Point(9, 83);
			this->iterationTextBox->Name = L"iterationTextBox";
			this->iterationTextBox->Size = System::Drawing::Size(197, 22);
			this->iterationTextBox->TabIndex = 3;
			this->iterationTextBox->Text = L"mandelbrot";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 63);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(139, 17);
			this->label2->TabIndex = 2;
			this->label2->Text = L"mandelbrot or Cx+Cy";
			// 
			// sizeTextBox
			// 
			this->sizeTextBox->Location = System::Drawing::Point(9, 38);
			this->sizeTextBox->Name = L"sizeTextBox";
			this->sizeTextBox->Size = System::Drawing::Size(197, 22);
			this->sizeTextBox->TabIndex = 1;
			this->sizeTextBox->Text = L"150,150,2.5";
			// 
			// MainLabel
			// 
			this->MainLabel->AutoSize = true;
			this->MainLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->MainLabel->Location = System::Drawing::Point(18, 9);
			this->MainLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->MainLabel->Name = L"MainLabel";
			this->MainLabel->Size = System::Drawing::Size(136, 32);
			this->MainLabel->TabIndex = 14;
			this->MainLabel->Text = L"Fractals JA";
			// 
			// panelLogo
			// 
			this->panelLogo->Controls->Add(this->MainLabel);
			this->panelLogo->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelLogo->Location = System::Drawing::Point(0, 0);
			this->panelLogo->Margin = System::Windows::Forms::Padding(0);
			this->panelLogo->Name = L"panelLogo";
			this->panelLogo->Size = System::Drawing::Size(792, 50);
			this->panelLogo->TabIndex = 25;
			// 
			// threadsNumericUpDown
			// 
			this->threadsNumericUpDown->Location = System::Drawing::Point(8, 22);
			this->threadsNumericUpDown->Margin = System::Windows::Forms::Padding(4);
			this->threadsNumericUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 64, 0, 0, 0 });
			this->threadsNumericUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->threadsNumericUpDown->Name = L"threadsNumericUpDown";
			this->threadsNumericUpDown->ReadOnly = true;
			this->threadsNumericUpDown->Size = System::Drawing::Size(95, 22);
			this->threadsNumericUpDown->TabIndex = 5;
			this->threadsNumericUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->threadsNumericUpDown);
			this->groupBox3->Location = System::Drawing::Point(12, 235);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(224, 50);
			this->groupBox3->TabIndex = 8;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Threads:";
			// 
			// saveButton
			// 
			this->saveButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->saveButton->Enabled = false;
			this->saveButton->Location = System::Drawing::Point(133, 7);
			this->saveButton->Name = L"saveButton";
			this->saveButton->Size = System::Drawing::Size(104, 39);
			this->saveButton->TabIndex = 16;
			this->saveButton->Text = L"Save data";
			this->saveButton->UseVisualStyleBackColor = true;
			this->saveButton->Click += gcnew System::EventHandler(this, &MyForm::saveButton_Click);
			// 
			// cppRadioButton
			// 
			this->cppRadioButton->AutoSize = true;
			this->cppRadioButton->Checked = true;
			this->cppRadioButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->cppRadioButton->Dock = System::Windows::Forms::DockStyle::Left;
			this->cppRadioButton->Location = System::Drawing::Point(61, 18);
			this->cppRadioButton->Margin = System::Windows::Forms::Padding(0);
			this->cppRadioButton->Name = L"cppRadioButton";
			this->cppRadioButton->Size = System::Drawing::Size(54, 29);
			this->cppRadioButton->TabIndex = 7;
			this->cppRadioButton->TabStop = true;
			this->cppRadioButton->Text = L"C++";
			this->cppRadioButton->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(128, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Width,Height,Scale";
			// 
			// asmRadioButton
			// 
			this->asmRadioButton->AutoSize = true;
			this->asmRadioButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->asmRadioButton->Dock = System::Windows::Forms::DockStyle::Left;
			this->asmRadioButton->Location = System::Drawing::Point(3, 18);
			this->asmRadioButton->Margin = System::Windows::Forms::Padding(0);
			this->asmRadioButton->Name = L"asmRadioButton";
			this->asmRadioButton->Size = System::Drawing::Size(58, 29);
			this->asmRadioButton->TabIndex = 6;
			this->asmRadioButton->Text = L"ASM";
			this->asmRadioButton->UseVisualStyleBackColor = true;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->offsetTextBox);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->iterationTextBox);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->sizeTextBox);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(12, 5);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(224, 168);
			this->groupBox1->TabIndex = 10;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Data:";
			// 
			// panelButtons
			// 
			this->panelButtons->Controls->Add(this->groupBox1);
			this->panelButtons->Controls->Add(this->groupBox2);
			this->panelButtons->Controls->Add(this->groupBox3);
			this->panelButtons->Dock = System::Windows::Forms::DockStyle::Left;
			this->panelButtons->Location = System::Drawing::Point(0, 50);
			this->panelButtons->Margin = System::Windows::Forms::Padding(0);
			this->panelButtons->Name = L"panelButtons";
			this->panelButtons->Padding = System::Windows::Forms::Padding(20, 10, 10, 10);
			this->panelButtons->Size = System::Drawing::Size(260, 357);
			this->panelButtons->TabIndex = 26;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->cppRadioButton);
			this->groupBox2->Controls->Add(this->asmRadioButton);
			this->groupBox2->Location = System::Drawing::Point(12, 179);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(224, 50);
			this->groupBox2->TabIndex = 9;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Mode:";
			// 
			// EDButton
			// 
			this->EDButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->EDButton->Enabled = false;
			this->EDButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->EDButton->ForeColor = System::Drawing::Color::Green;
			this->EDButton->Location = System::Drawing::Point(639, 6);
			this->EDButton->Margin = System::Windows::Forms::Padding(4);
			this->EDButton->Name = L"EDButton";
			this->EDButton->Size = System::Drawing::Size(130, 37);
			this->EDButton->TabIndex = 12;
			this->EDButton->Text = L"Encrypting";
			this->EDButton->UseVisualStyleBackColor = true;
			// 
			// panelBottom
			// 
			this->panelBottom->Controls->Add(this->deleteButton);
			this->panelBottom->Controls->Add(this->saveButton);
			this->panelBottom->Controls->Add(this->EDButton);
			this->panelBottom->Controls->Add(this->generateButton);
			this->panelBottom->Location = System::Drawing::Point(288, 247);
			this->panelBottom->Name = L"panelBottom";
			this->panelBottom->Size = System::Drawing::Size(376, 53);
			this->panelBottom->TabIndex = 30;
			// 
			// generateButton
			// 
			this->generateButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->generateButton->Location = System::Drawing::Point(12, 6);
			this->generateButton->Name = L"generateButton";
			this->generateButton->Size = System::Drawing::Size(104, 39);
			this->generateButton->TabIndex = 15;
			this->generateButton->Text = L"Generate";
			this->generateButton->UseVisualStyleBackColor = true;
			this->generateButton->Click += gcnew System::EventHandler(this, &MyForm::generateButton_Click);
			// 
			// InfoLabel1
			// 
			this->InfoLabel1->AutoSize = true;
			this->InfoLabel1->BackColor = System::Drawing::Color::Transparent;
			this->InfoLabel1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->InfoLabel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->InfoLabel1->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->InfoLabel1->Location = System::Drawing::Point(288, 60);
			this->InfoLabel1->Margin = System::Windows::Forms::Padding(0);
			this->InfoLabel1->Name = L"InfoLabel1";
			this->InfoLabel1->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->InfoLabel1->Size = System::Drawing::Size(151, 20);
			this->InfoLabel1->TabIndex = 22;
			this->InfoLabel1->Text = L"Operation Status";
			// 
			// consoleTextBox
			// 
			this->consoleTextBox->Location = System::Drawing::Point(288, 93);
			this->consoleTextBox->Margin = System::Windows::Forms::Padding(4);
			this->consoleTextBox->Multiline = true;
			this->consoleTextBox->Name = L"consoleTextBox";
			this->consoleTextBox->ReadOnly = true;
			this->consoleTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->consoleTextBox->Size = System::Drawing::Size(483, 130);
			this->consoleTextBox->TabIndex = 17;
			// 
			// panelControl
			// 
			this->panelControl->BackColor = System::Drawing::SystemColors::Control;
			this->panelControl->Controls->Add(this->panelBottom);
			this->panelControl->Controls->Add(this->InfoLabel1);
			this->panelControl->Controls->Add(this->panelButtons);
			this->panelControl->Controls->Add(this->consoleTextBox);
			this->panelControl->Controls->Add(this->panelLogo);
			this->panelControl->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelControl->Location = System::Drawing::Point(0, 0);
			this->panelControl->Margin = System::Windows::Forms::Padding(0);
			this->panelControl->Name = L"panelControl";
			this->panelControl->Size = System::Drawing::Size(792, 407);
			this->panelControl->TabIndex = 29;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(792, 353);
			this->Controls->Add(this->panelControl);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"FractalsJA";
			this->panelLogo->ResumeLayout(false);
			this->panelLogo->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->threadsNumericUpDown))->EndInit();
			this->groupBox3->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->panelButtons->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->panelBottom->ResumeLayout(false);
			this->panelControl->ResumeLayout(false);
			this->panelControl->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

		/**
		 * Metoda zostaje wywoływana w momencie wciśnięcia przycisku "Generate".
		 * W przypadku spełnienia wszystkich warunktów, wywołuje główny algorytm programu.
		 */
	private: System::Void generateButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if ((sizeTextBox->Text != "") && (iterationTextBox->Text != "") && (offsetTextBox->Text != ""))
		{
			if (asmRadioButton->Checked)
			{
				// Sprawdzenie dostępności poleceń wektorowych.
				if (!CheckMMXCapability())
				{
					MessageBox::Show("Twoj procesor nie posiada CPUID lub MMX dlatego nie mozesz uzyc trybu ASM!", "ASM error!");
					return;
				}
			}

			bool sizeBool = false;
			bool iteratorBool = false;
			bool offsetBool = false;
			AlgorythmData^ AlData = gcnew AlgorythmData();

			// Przeszukanie oraz stwierdzenie poprawności danych wartości z pola tekstowego nr 1 -> Width, Height, Scale.
			string sizeContent = msclr::interop::marshal_as<string>(sizeTextBox->Text);
			if (strspn(sizeContent.c_str(), "0123456789.,") == sizeContent.size() && sizeContent.size() > 4)
			{
				int posOne = 0;
				int posTwo = 0;
				bool second = false;

				// Przeszukiwanie ciągu.
				for (int i = 0; i < sizeContent.size(); i++)
				{
					if ((sizeContent.at(i) == ',') && !second)
					{
						posOne = i + 1;
						second = true;
					}

					if ((sizeContent.at(i) == ',') && second)
					{
						posTwo = i + 1;
					}
				}

				if (second && (posOne > 1) && (posTwo <= (sizeContent.size() - 1)) && (posOne != posTwo - 1))
				{
					AlData->SetWidth(atoi(sizeContent.substr(0, posOne - 1).c_str()));
					AlData->SetHeight(atoi(sizeContent.substr(posOne, (sizeContent.size() - (posTwo - posOne))).c_str()));
					AlData->SetScale(atof(sizeContent.substr(posTwo, sizeContent.size() - posTwo).c_str()));
					sizeBool = true;
					consoleTextBox->Text = "Width:" + AlData->GetWidth() + " Height:" + AlData->GetHeight() + " Size:" + AlData->GetScale();
				}
				else
				{
					consoleTextBox->Text = "Pole wymiarow: bledna skladnia!";
				}
			}
			else
			{
				consoleTextBox->Text = "Pole wymierow: niepoprawne znaki lub zbyt krotka dlugosc!";
			}


			// Przeszukanie oraz stwierdzenie poprawności danych wartości z pola tekstowego nr 2 -> "Mandelbrot" lub wartości liczby zespolonej.
			string iterationContent = msclr::interop::marshal_as<string>(iterationTextBox->Text);
			if (iterationTextBox->Text == "mandelbrot")
			{
				consoleTextBox->Text += "\r\nFraktal: Mandelbrot";
				AlData->SetMandel(true);
				iteratorBool = true;
			}
			else if (strspn(iterationContent.c_str(), "0123456789.+") == iterationContent.size() && iterationContent.size() > 2)
			{
				int pos = 0;
				// Przeszukiwanie ciągu.
				for (int i = 0; i < iterationContent.size(); i++)
				{
					if (iterationContent.at(i) == '+')
					{
						pos = i + 1;
					}
				}

				if ((pos > 1) && (pos <= (iterationContent.size() - 1)))
				{
					double xNew = stod(iterationContent.substr(0, pos - 1).c_str());
					double yNew = stod(iterationContent.substr(pos, iterationContent.size() - pos).c_str());
					AlData->SetCArgX(xNew);
					AlData->SetCArgY(yNew);
					consoleTextBox->Text += "\r\nFraktal: Julii\r\nC:" + xNew + "+" + yNew + "i";
					iteratorBool = true;
				}
				else
				{
					consoleTextBox->Text += "\r\nPole iterator: bledna skladnia!";
				}
			}
			else
			{
				consoleTextBox->Text += "\r\nPole iterator: niepoprawne znaki lub zbyt krotka dlugosc!";
			}


			// Przeszukanie oraz stwierdzenie poprawności danych wartości z pola tekstowego nr 3 -> Wartości offset'u OffX, OffY.
			string offsetContent = msclr::interop::marshal_as<string>(offsetTextBox->Text);
			if (strspn(offsetContent.c_str(), "0123456789.,") == offsetContent.size() && offsetContent.size() > 2)
			{
				int pos = 0;
				// Przeszukiwanie ciągu.
				for (int i = 0; i < offsetContent.size(); i++)
				{
					if (offsetContent.at(i) == ',') {
						pos = i + 1;
					}
				}

				if ((pos > 1) && (pos <= (offsetContent.size() - 1)))
				{
					AlData->SetOffX(stod(offsetContent.substr(0, pos - 1).c_str()));
					AlData->SetOffY(stod(offsetContent.substr(pos, offsetContent.size() - pos).c_str()));
					consoleTextBox->Text += "\r\noffX:" + AlData->GetOffX() + " offY:" + AlData->GetOffY();
					offsetBool = true;
				}
				else
				{
					consoleTextBox->Text += "\r\nPole offset: błedna skladnia!";
				}
			}
			else
			{
				consoleTextBox->Text += "\r\nPole offset: niepoprawne znaki lub zbyt krotka dlugosc!";
			}


			// Główna część algorytmu wykonywana jedynie jeśli wszystkie wprowadzone dane są poprawne.
			if (sizeBool && iteratorBool && offsetBool)
			{
				// Podanie szerokości oraz wysokości
				int width = AlData->GetWidth();
				int height = AlData->GetHeight();
				fileOrg->InsertData(width, height);

				int threadCounter = 0;													// Inicjalizacja licznika wątków.
				int threadMax = Decimal::ToInt32(threadsNumericUpDown->Value);			// Liczba wątków wybrana przez użytkownika.
				Generic::List<Thread^>^ threadList = gcnew Generic::List<Thread^>();	// Lista do przechowywania aktualnie obsługiwanych wątków.

				// Rozpoczęcie zegara do zliczania czasu wykonania.
				auto start = high_resolution_clock::now();

				consoleTextBox->Text += "\r\n\r\nGenerowanie...";
				consoleTextBox->Refresh();

				// Główna pętla programu wywołująca zarządzanie wątkami.
				for (int x = 0; x < width; x++)
				{
					for (int y = 0; y < height; y++)
					{
						// Obsługa wątków.
						if (threadCounter < threadMax)
						{
							// Dodanie wątku do listy std.
							threadList->Add(gcnew Thread(gcnew ParameterizedThreadStart(thOrg, &ThreadsOrganise::GenerateFractal)));

							// Spakowanie parametrów do jednej krotki ponieważ wątki przyjmują jeden parametr.
							Tuple<FileOrganiser^, bool, int, int, AlgorythmData^>^ parameter = gcnew Tuple<FileOrganiser^, bool, int, int, AlgorythmData^>
								(fileOrg, cppRadioButton->Checked, x, y, AlData);

							threadList[threadCounter]->Start(parameter);	// Dodanie parametru i wystartowanie wątku.
							threadCounter++;								// Zwiększenie liczby aktualnie wykonywanych wątków.
						}
						else
						{
							bool found = false;
							// Oczekiwanie na wolny wątek do przejęcia.
							while (!found)
							{
								// Pętla krążąca po wątkach do momentu znalezienie wolnego.
								for (int i = 0; i < threadMax; i++)
								{
									// Sprawdzenie czy wątek jest wolmy.
									if (!threadList[i]->IsAlive)
									{
										found = true;
										// Utworzenie nowego wątku na wolnym miejscu.
										threadList[i] = gcnew Thread(gcnew ParameterizedThreadStart(thOrg, &ThreadsOrganise::GenerateFractal));
										// Spakowanie parametrów do jednej krotki ponieważ wątki przyjmują jeden parametr.
										Tuple<FileOrganiser^, bool, int, int, AlgorythmData^>^ parameter = gcnew Tuple<FileOrganiser^, bool, int, int, AlgorythmData^>
											(fileOrg, cppRadioButton->Checked, x, y, AlData);

										// Dodanie parametru i wystartowanie wątku.
										threadList[i]->Start(parameter);

									}
									if (found)
									{
										break;
									}
								}
							}
						}
					}
				}

				// Pętla zarząda dezaktywacją bierzących wątków.
				for (int i = 0; i < threadList->Count; i++)
				{
					threadList[i]->Join();
				}

				auto stop = high_resolution_clock::now();							// Zatrzymanie zegara zliczającego czas wykonania.
				auto duration = duration_cast<microseconds>(stop - start);			// Obliczenie czasu potrzebnego za wykonanie zadania.
				String^ time = gcnew String(to_string(duration.count()).c_str());	// Zapis wartości czasu do string'a.
				consoleTextBox->Text += "\r\nWykonano w: " + time + "ms";			// Zapis czasu wykonania na okno powiadomień.
				saveButton->Enabled = true;											// Odblokowanie przycisku zapisu.
				deleteButton->Enabled = true;										// Odblokowanie przycisku usuwania.
				generateButton->Enabled = false;									// Zablokowanie przycisku generowania.
			}
		}
		else
		{
			consoleTextBox->Text += "\r\nWypelnij wszystkie pola!";
		}
	}


			 /**
			  * Metoda zostaje wywoływana w momencie wciśnięcia przycisku "Save data".
			  * W przypadku spełnienia wszystkich warunktów, zapisuje dane fraktalu do pliku BMP.
			  */
	private: System::Void saveButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		String^ filePath = fileOrg->SaveFile(sender, e);	// Zapis pliku .bmp do katalogu wybranego przez użytkownika.

		// Zarządzanie błedami i wyświetlanie stosownego komunikatu.
		if (filePath->CompareTo("Error1") == 0)
		{
			return;
		}
		else if (filePath->CompareTo("Error2") == 0)
		{
			consoleTextBox->Text += "\r\nNie mozna otworzyc pliku!";
		}
		else
		{
			fileOrg->DeleteData();
			generateButton->Enabled = true;
			saveButton->Enabled = false;
			deleteButton->Enabled = false;
			consoleTextBox->Text = "Plik zdjecia zostal poprawnie wygenerowany pod sciezka:\r\n" + filePath;
		}
	}


			 /**
			  * Metoda zostaje wywoływana w momencie wciśnięcia przycisku "Delete data".
			  * Usuwa zaalokowaną pamięć oraz przywraca aplikację do stanu domyślnego.
			  */
	private: System::Void deleteButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		fileOrg->DeleteData();
		generateButton->Enabled = true;
		saveButton->Enabled = false;
		deleteButton->Enabled = false;
		consoleTextBox->Text = "Dane wygenerowanego fraktala zostaly usuniete!";
	}
	};
}
