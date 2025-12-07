#include "adminDashboard.h"
#include "adminCourses.h"
#include "adminDepartment.h"
#include "adminProgrammes.h"
#include "adminFaculty.h"
#include "adminStudents.h"
#include "adminEnrollment.h"
#include "adminPayments.h"

namespace Group7FinalProject {
	System::Void adminPayments::btnDashboard_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Hide();
		adminDashboard^ dashboardForm = gcnew adminDashboard(currentUser);
		dashboardForm->ShowDialog();
		this->Close();
	}
	System::Void adminPayments::btnCourses_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Hide();
		adminCourses^ coursesForm = gcnew adminCourses(currentUser);
		coursesForm->ShowDialog();
		this->Close();
	}
	System::Void adminPayments::btnDepartment_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Hide();
		adminDepartment^ departmentForm = gcnew adminDepartment(currentUser);
		departmentForm->ShowDialog();
		this->Close();
	}
	System::Void adminPayments::btnProgrammes_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Hide();
		adminProgrammes^ programmesForm = gcnew adminProgrammes(currentUser);
		programmesForm->ShowDialog();
		this->Close();
	}
	System::Void adminPayments::btnFaculty_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Hide();
		adminFaculty^ facultyForm = gcnew adminFaculty(currentUser);
		facultyForm->ShowDialog();
		this->Close();
	}
	System::Void adminPayments::btnStudents_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Hide();
		adminStudents^ studentsForm = gcnew adminStudents(currentUser);
		studentsForm->ShowDialog();
		this->Close();
	}
	System::Void adminPayments::btnEnrollment_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Hide();
		adminEnrollment^ enrollmentForm = gcnew adminEnrollment(currentUser);
		enrollmentForm->ShowDialog();
		this->Close();
	}
}

