#include "adminDepartment.h"
#include "adminDashboard.h"
#include "adminCourses.h"

namespace Group7FinalProject {

System::Void adminDepartment::btnDashboard_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Hide();
    adminDashboard^ dashboardForm = gcnew adminDashboard(currentUser);
    dashboardForm->ShowDialog();
    this->Close();
}

System::Void adminDepartment::btnCourses_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Hide();
    adminCourses^ coursesForm = gcnew adminCourses(currentUser);
    coursesForm->ShowDialog();
    this->Close();
}

}

