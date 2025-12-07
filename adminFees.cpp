#include "adminFees.h"
#include "adminDashboard.h"
#include "adminCourses.h"
#include "adminDepartment.h"
#include "adminProgrammes.h"
#include "adminFaculty.h"
#include "adminStudents.h"
#include "adminEnrollment.h"
#include "adminPayments.h"

namespace Group7FinalProject {
	System::Void adminFees::btnDashboard_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Hide();
		adminDashboard^ dashboardForm = gcnew adminDashboard(this->currentUser);
		dashboardForm->ShowDialog();
	}
	System::Void adminFees::btnCourses_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Hide();
		adminCourses^ courseForm = gcnew adminCourses(this->currentUser);
		courseForm->ShowDialog();
	}
	System::Void adminFees::btnDepartments_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Hide();
		adminDepartment^ deptForm = gcnew adminDepartment(this->currentUser);
		deptForm->ShowDialog();
	}
	System::Void adminFees::btnFaculty_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Hide();
		adminFaculty^ facultyForm = gcnew adminFaculty(this->currentUser);
		facultyForm->ShowDialog();
	}
	System::Void adminFees::btnStudents_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Hide();
		adminStudents^ studentForm = gcnew adminStudents(this->currentUser);
		studentForm->ShowDialog();
	}
	System::Void adminFees::btnEnrollment_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Hide();
		adminEnrollment^ enrollmentForm = gcnew adminEnrollment(this->currentUser);
		enrollmentForm->ShowDialog();
	}
	System::Void adminFees::btnPayments_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Hide();
		adminPayments^ paymentsForm = gcnew adminPayments(this->currentUser);
		paymentsForm->ShowDialog();
	}
}

