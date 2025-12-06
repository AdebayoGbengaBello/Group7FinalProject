#include "facultyView.h"
#include "myCourses.h"

using namespace System;
using namespace System::Windows::Forms;

void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Group7FinalProject::facultyView frmfac;
	frmfac.ShowDialog();
	//User^ user = frmUser.user;
}
	