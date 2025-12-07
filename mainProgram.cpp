#include "StudentMain.h"

using namespace System;
using namespace System::Windows::Forms;


int main(array<String^>^ args) {
	// 
	Application::EnableVisualStyles;
	// 
	Application::SetCompatibleTextRenderingDefault(false);
	Group7FinalProject::StudentMain studentDashboard(2); // Pass a dummy user ID for now
	//loginForm.ShowDialog();
     
	Application::Run(% studentDashboard);

	// create a student Class For this part 

	// Put the logic to redirect the student to his custome dashboard and not print the 
	// successfull Auth message but print it when the auth goes bad

	return 0;
};