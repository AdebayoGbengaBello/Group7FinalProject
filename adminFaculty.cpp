#include "adminDashboard.h"
#include "adminCourses.h"
#include "adminDepartment.h"
#include "adminProgrammes.h"
#include "adminFaculty.h"
#include "adminStudents.h"
#include "adminEnrollment.h"
#include "adminPayments.h"

namespace Group7FinalProject {
	System::Void adminFaculty::btnDashboard_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Hide();
		adminDashboard^ dashboardForm = gcnew adminDashboard(currentUser);
		dashboardForm->ShowDialog();
		this->Close();
	}
	System::Void adminFaculty::btnDepartments_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Hide();
		adminDepartment^ departmentForm = gcnew adminDepartment(currentUser);
		departmentForm->ShowDialog();
		this->Close();
	}
	System::Void adminFaculty::btnProgrammes_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Hide();
		adminProgrammes^ programmesForm = gcnew adminProgrammes(currentUser);
		programmesForm->ShowDialog();
		this->Close();
	}
	System::Void adminFaculty::btnStudents_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Hide();
		adminStudents^ studentsForm = gcnew adminStudents(currentUser);
		studentsForm->ShowDialog();
		this->Close();
	}
	System::Void adminFaculty::btnEnrollment_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Hide();
		adminEnrollment^ enrollmentForm = gcnew adminEnrollment(currentUser);
		enrollmentForm->ShowDialog();
		this->Close();
	}
	System::Void adminFaculty::btnPayments_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Hide();
		adminPayments^ paymentsForm = gcnew adminPayments(currentUser);
		paymentsForm->ShowDialog();
		this->Close();
	}
	System::Void adminFaculty::btnCourses_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Hide();
		adminCourses^ coursesForm = gcnew adminCourses(currentUser);
		coursesForm->ShowDialog();
		this->Close();
	}
}

