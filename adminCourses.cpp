#include "adminCourses.h"
#include "adminDashboard.h"
#include "adminDepartment.h"
#include "adminProgrammes.h"
#include "adminFaculty.h"
#include "adminStudents.h"
#include "adminEnrollment.h"
#include "adminPayments.h"

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
    System::Void adminCourses::btnProgrammes_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Hide();
        adminProgrammes^ programmesForm = gcnew adminProgrammes(this->currentUser);
        programmesForm->ShowDialog();
        this->Close();
    }
    System::Void adminCourses::btnFaculty_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Hide();
        adminFaculty^ facultyForm = gcnew adminFaculty(this->currentUser);
        facultyForm->ShowDialog();
        this->Close();
    }
    System::Void adminCourses::btnStudents_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Hide();
        adminStudents^ studentsForm = gcnew adminStudents(this->currentUser);
        studentsForm->ShowDialog();
        this->Close();
	}
    System::Void adminCourses::btnEnrollment_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Hide();
        adminEnrollment^ enrollmentForm = gcnew adminEnrollment(this->currentUser);
        enrollmentForm->ShowDialog();
        this->Close();
    }
    System::Void adminCourses::btnPayments_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Hide();
        adminPayments^ paymentsForm = gcnew adminPayments(this->currentUser);
        paymentsForm->ShowDialog();
        this->Close();
	}
}

