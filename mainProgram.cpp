<<<<<<< HEAD
#include "facultyView.h"
#include "myCourses.h"
=======
#include "mainLogin.h"
>>>>>>> origin/master

using namespace System;
using namespace System::Windows::Forms;

<<<<<<< HEAD
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Group7FinalProject::facultyView frmfac;
	frmfac.ShowDialog();
	//User^ user = frmUser.user;
}
	
=======
[STAThread]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);


	Group7FinalProject::mainLogin form;
	Application::Run(% form);
}
>>>>>>> origin/master
