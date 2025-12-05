#include "mainLogin.h"
#include "users.h"

using namespace System;
using namespace System::Windows::Forms;

void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	User^ user= gcnew User();


	Group7FinalProject::mainLogin form;
	Application::Run(% form);
}