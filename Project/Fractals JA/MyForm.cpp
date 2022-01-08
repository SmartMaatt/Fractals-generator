#include "MyForm.h"
#include <stdio.h>
#include <iostream>
#include <windows.h>

using namespace System;
using namespace std;

[STAThreadAttribute]
int main()
{
	Windows::Forms::Application::Run(gcnew FractalsJA::MyForm());
	return 0;
}