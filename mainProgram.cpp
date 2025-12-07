#include "mainLogin.h"

using namespace System;
using namespace System::Windows::Forms;

void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Group7FinalProject::mainLogin form;
	Application::Run(% form);
}