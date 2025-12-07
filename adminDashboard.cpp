#include "adminDashboard.h"
#include "adminCourses.h"
#include "adminDepartment.h"
#include "adminProgrammes.h"
#include "adminFaculty.h"
#include "adminStudents.h"
#include "adminEnrollment.h"
#include "adminPayments.h"
#include "adminFees.h"

namespace Group7FinalProject {

    System::Void adminDashboard::btnCourses_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Hide();
        adminCourses^ courseForm = gcnew adminCourses(this->currentUser);
        courseForm->ShowDialog();
    }

    System::Void adminDashboard::btnDepartment_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Hide();
        adminDepartment^ deptForm = gcnew adminDepartment(this->currentUser);
        deptForm->ShowDialog();
    }
    System::Void adminDashboard::btnProgrammes_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Hide();
        adminProgrammes^ progForm = gcnew adminProgrammes(this->currentUser);
        progForm->ShowDialog();

    }
    System::Void adminDashboard::btnFaculty_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Hide();
        adminFaculty^ facultyForm = gcnew adminFaculty(this->currentUser);
        facultyForm->ShowDialog();
	}
    System::Void adminDashboard::btnStudents_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Hide();
        adminStudents^ studentForm = gcnew adminStudents(this->currentUser);
        studentForm->ShowDialog();
	}
    System::Void adminDashboard::btnEnrollment_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Hide();
        adminEnrollment^ enrollmentForm = gcnew adminEnrollment(this->currentUser);
        enrollmentForm->ShowDialog();
	}
    System::Void adminDashboard::btnPayments_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Hide();
        adminPayments^ paymentsForm = gcnew adminPayments(this->currentUser);
        paymentsForm->ShowDialog();
	}
    System::Void adminDashboard::btnFees_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Hide();
        adminFees^ feesForm = gcnew adminFees(this->currentUser);
        feesForm->ShowDialog();
	}
}

