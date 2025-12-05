#include "adminDashboard.h"

using namespace System;
using namespace System::Windows::Forms;


void Main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    Group7FinalProject::adminDashboard form;
    Application::Run(% form);
}