#include "adminDashboard.h"
#include "adminCourses.h"
#include "adminDepartment.h"
#include "adminProgrammes.h"
#include "adminFaculty.h"

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
}

