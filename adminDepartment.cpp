#include "adminDepartment.h"
#include "adminDashboard.h"
#include "adminCourses.h"
#include "adminEnrollment.h"
#include "adminFaculty.h"
#include "adminPayments.h"
#include "adminProgrammes.h"
#include "adminStudents.h"

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
System::Void adminDepartment::btnProgrammes_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Hide();
    adminProgrammes^ programmesForm = gcnew adminProgrammes(currentUser);
    programmesForm->ShowDialog();
    this->Close();
}
System::Void adminDepartment::btnFaculty_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Hide();
    adminFaculty^ facultyForm = gcnew adminFaculty(currentUser);
    facultyForm->ShowDialog();
    this->Close();
}
System::Void adminDepartment::btnStudents_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Hide();
    adminStudents^ studentsForm = gcnew adminStudents(currentUser);
    studentsForm->ShowDialog();
    this->Close();
}
System::Void adminDepartment::btnEnrollment_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Hide();
    adminEnrollment^ enrollmentForm = gcnew adminEnrollment(currentUser);
    enrollmentForm->ShowDialog();
    this->Close();
}
System::Void adminDepartment::btnPayments_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Hide();
    adminPayments^ paymentsForm = gcnew adminPayments(currentUser);
    paymentsForm->ShowDialog();
    this->Close();
}

}

