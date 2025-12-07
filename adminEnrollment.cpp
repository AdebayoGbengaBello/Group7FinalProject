#include "adminDashboard.h"
#include "adminCourses.h"
#include "adminDepartment.h"
#include "adminProgrammes.h"
#include "adminFaculty.h"
#include "adminStudents.h"
#include "adminEnrollment.h"
#include "adminPayments.h"

namespace Group7FinalProject {
	System::Void adminEnrollment::btnDashboard_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Hide();
		adminDashboard^ dashboardForm = gcnew adminDashboard(currentUser);
		dashboardForm->ShowDialog();
		this->Close();
	}
	System::Void adminEnrollment::btnDepartment_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Hide();
		adminDepartment^ departmentForm = gcnew adminDepartment(currentUser);
		departmentForm->ShowDialog();
		this->Close();
	}
	System::Void adminEnrollment::btnProgrammes_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Hide();
		adminProgrammes^ programmesForm = gcnew adminProgrammes(currentUser);
		programmesForm->ShowDialog();
		this->Close();
	}
	System::Void adminEnrollment::btnFaculty_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Hide();
		adminFaculty^ facultyForm = gcnew adminFaculty(currentUser);
		facultyForm->ShowDialog();
		this->Close();
	}
	System::Void adminEnrollment::btnStudents_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Hide();
		adminStudents^ studentsForm = gcnew adminStudents(currentUser);
		studentsForm->ShowDialog();
		this->Close();
	}
	System::Void adminEnrollment::btnPayments_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Hide();
		adminPayments^ paymentsForm = gcnew adminPayments(currentUser);
		paymentsForm->ShowDialog();
		this->Close();
	}
	System::Void adminEnrollment::btnCourses_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Hide();
		adminCourses^ coursesForm = gcnew adminCourses(currentUser);
		coursesForm->ShowDialog();
		this->Close();
	}
}

