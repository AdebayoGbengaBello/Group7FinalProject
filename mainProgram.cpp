#include "StudentLoginForm.h"
#include "StudentSignupForm.h"

using namespace System;
using namespace System::Windows::Forms;


int main(array<String^>^ args) {
	// 
	Application::EnableVisualStyles;
	// 
	Application::SetCompatibleTextRenderingDefault(false);

	Group7FinalProject::StudentLoginForm loginForm;
	Group7FinalProject::StudentSignupForm signupForm;
	loginForm.ShowDialog();


	// create a student Class For this part 

	// Put the logic to redirect the student to his custome dashboard and not print the 
	// successfull Auth message but print it when the auth goes bad

};