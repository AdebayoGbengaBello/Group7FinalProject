#include "adminCourses.h"
#include "adminDashboard.h"
#include "adminDepartment.h"

namespace Group7FinalProject {

System::Void adminCourses::btnDashboard_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Hide();
    adminDashboard^ dashboardForm = gcnew adminDashboard(this->currentUser);
    dashboardForm->ShowDialog();
    this->Close();
}

System::Void adminCourses::btnDepartment_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Hide();
    adminDepartment^ departmentForm = gcnew adminDepartment(this->currentUser);
    departmentForm->ShowDialog();
    this->Close();
}

}

