#pragma once
#include "users.h"
#include "Database.h"
namespace Group7FinalProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for adminDashboard
	/// </summary>
	public ref class adminDashboard : public System::Windows::Forms::Form
	{
	private:
		Database^ db = gcnew Database();
		User^ currentUser;
	private: System::Windows::Forms::Button^ btnPayments;
	private: System::Windows::Forms::Button^ btnEnrollment;
	private: System::Windows::Forms::Button^ btnProgrammes;

	public:
		adminDashboard(User^ User)
		{
			InitializeComponent();
			this->currentUser = User;
			lblUser->Text = "Hello " + currentUser->name;
		}

		int GetCount(String^ tableName) {
			int count = 0;
			try {
				db->Open();
				String^ query = "SELECT COUNT(*) FROM " + tableName;
				db->sqlCmd->CommandText = query;
				count = Convert::ToInt32(db->sqlCmd->ExecuteScalar());
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error: " + ex->Message);
			}
			finally {
				db->Close();
			}
			return count;
		}

		void LoadChart() {
			try {
				db->Open();
				String^ query = "SELECT c.courseCode, COUNT(r.studentID) as Total "
					"FROM Course c "
					"LEFT JOIN CourseRegistration r ON c.courseID = r.courseID "
					"GROUP BY c.courseCode LIMIT 5";
				db->sqlCmd->CommandText = query;
				db->sqlDA->SelectCommand = db->sqlCmd;
				db->sqlDA->Fill(db->sqlDT);

				this->chart1->Series[0]->Points->Clear();
				this->chart1->Series[0]->Name = "Registrations";
				this->chart1->Series[0]->Color = System::Drawing::Color::Brown; // Ashesi Red-ish

				for (int i = 0; i < db->sqlDT->Rows->Count; i++) {
					DataRow^ row = db->sqlDT->Rows[i];
					String^ code = row["courseCode"]->ToString();
					int total = Convert::ToInt32(row["Total"]);
					this->chart1->Series[0]->Points->AddXY(code, total);
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show("Chart Error: " + ex->Message);
			}
			finally {
				db->Close();
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~adminDashboard()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Button^ btnStudents;
	private: System::Windows::Forms::Button^ btnCourses;

	private: System::Windows::Forms::Button^ btnDepartment;

	private: System::Windows::Forms::Button^ btnFaculty;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lblStudentCount;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::Label^ lblCourseCount;


	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Label^ lblFacultyCount;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::Label^ lblWelcome;
	private: System::Windows::Forms::Label^ lblUser;




	protected:





	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->btnPayments = (gcnew System::Windows::Forms::Button());
			this->btnEnrollment = (gcnew System::Windows::Forms::Button());
			this->btnProgrammes = (gcnew System::Windows::Forms::Button());
			this->lblUser = (gcnew System::Windows::Forms::Label());
			this->btnCourses = (gcnew System::Windows::Forms::Button());
			this->btnDepartment = (gcnew System::Windows::Forms::Button());
			this->btnFaculty = (gcnew System::Windows::Forms::Button());
			this->btnStudents = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->lblWelcome = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->lblCourseCount = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->lblFacultyCount = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->lblStudentCount = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->panel6->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Maroon;
			this->panel1->Controls->Add(this->btnPayments);
			this->panel1->Controls->Add(this->btnEnrollment);
			this->panel1->Controls->Add(this->btnProgrammes);
			this->panel1->Controls->Add(this->lblUser);
			this->panel1->Controls->Add(this->btnCourses);
			this->panel1->Controls->Add(this->btnDepartment);
			this->panel1->Controls->Add(this->btnFaculty);
			this->panel1->Controls->Add(this->btnStudents);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(280, 922);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &adminDashboard::panel1_Paint);
			// 
			// btnPayments
			// 
			this->btnPayments->FlatAppearance->BorderSize = 0;
			this->btnPayments->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnPayments->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnPayments->ForeColor = System::Drawing::Color::White;
			this->btnPayments->Location = System::Drawing::Point(26, 661);
			this->btnPayments->Name = L"btnPayments";
			this->btnPayments->Size = System::Drawing::Size(228, 68);
			this->btnPayments->TabIndex = 8;
			this->btnPayments->Text = L"Payments";
			this->btnPayments->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnPayments->UseVisualStyleBackColor = true;
			this->btnPayments->Click += gcnew System::EventHandler(this, &adminDashboard::btnPayments_Click);
			// 
			// btnEnrollment
			// 
			this->btnEnrollment->FlatAppearance->BorderSize = 0;
			this->btnEnrollment->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnEnrollment->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnEnrollment->ForeColor = System::Drawing::Color::White;
			this->btnEnrollment->Location = System::Drawing::Point(26, 580);
			this->btnEnrollment->Name = L"btnEnrollment";
			this->btnEnrollment->Size = System::Drawing::Size(182, 75);
			this->btnEnrollment->TabIndex = 7;
			this->btnEnrollment->Text = L"Enrollment";
			this->btnEnrollment->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnEnrollment->UseVisualStyleBackColor = true;
			this->btnEnrollment->Click += gcnew System::EventHandler(this, &adminDashboard::btnEnrollment_Click);
			// 
			// btnProgrammes
			// 
			this->btnProgrammes->FlatAppearance->BorderSize = 0;
			this->btnProgrammes->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnProgrammes->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnProgrammes->ForeColor = System::Drawing::Color::White;
			this->btnProgrammes->Location = System::Drawing::Point(26, 492);
			this->btnProgrammes->Name = L"btnProgrammes";
			this->btnProgrammes->Size = System::Drawing::Size(228, 68);
			this->btnProgrammes->TabIndex = 6;
			this->btnProgrammes->Text = L"Programmes";
			this->btnProgrammes->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnProgrammes->UseVisualStyleBackColor = true;
			this->btnProgrammes->Click += gcnew System::EventHandler(this, &adminDashboard::btnProgrammes_Click);
			// 
			// lblUser
			// 
			this->lblUser->AutoSize = true;
			this->lblUser->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblUser->ForeColor = System::Drawing::Color::White;
			this->lblUser->Location = System::Drawing::Point(35, 35);
			this->lblUser->Name = L"lblUser";
			this->lblUser->Size = System::Drawing::Size(90, 37);
			this->lblUser->TabIndex = 5;
			this->lblUser->Text = L"label2";
			// 
			// btnCourses
			// 
			this->btnCourses->FlatAppearance->BorderSize = 0;
			this->btnCourses->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCourses->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCourses->ForeColor = System::Drawing::Color::White;
			this->btnCourses->Location = System::Drawing::Point(26, 411);
			this->btnCourses->Name = L"btnCourses";
			this->btnCourses->Size = System::Drawing::Size(182, 75);
			this->btnCourses->TabIndex = 4;
			this->btnCourses->Text = L"Courses";
			this->btnCourses->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnCourses->UseVisualStyleBackColor = true;
			this->btnCourses->Click += gcnew System::EventHandler(this, &adminDashboard::btnCourses_Click);
			// 
			// btnDepartment
			// 
			this->btnDepartment->FlatAppearance->BorderSize = 0;
			this->btnDepartment->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDepartment->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDepartment->ForeColor = System::Drawing::Color::White;
			this->btnDepartment->Location = System::Drawing::Point(26, 324);
			this->btnDepartment->Name = L"btnDepartment";
			this->btnDepartment->Size = System::Drawing::Size(228, 64);
			this->btnDepartment->TabIndex = 3;
			this->btnDepartment->Text = L"Departments";
			this->btnDepartment->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnDepartment->UseVisualStyleBackColor = true;
			this->btnDepartment->Click += gcnew System::EventHandler(this, &adminDashboard::btnDepartment_Click);
			// 
			// btnFaculty
			// 
			this->btnFaculty->FlatAppearance->BorderSize = 0;
			this->btnFaculty->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnFaculty->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnFaculty->ForeColor = System::Drawing::Color::White;
			this->btnFaculty->Location = System::Drawing::Point(26, 237);
			this->btnFaculty->Name = L"btnFaculty";
			this->btnFaculty->Size = System::Drawing::Size(182, 81);
			this->btnFaculty->TabIndex = 2;
			this->btnFaculty->Text = L"Faculty";
			this->btnFaculty->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnFaculty->UseVisualStyleBackColor = true;
			this->btnFaculty->Click += gcnew System::EventHandler(this, &adminDashboard::btnFaculty_Click);
			// 
			// btnStudents
			// 
			this->btnStudents->FlatAppearance->BorderSize = 0;
			this->btnStudents->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnStudents->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnStudents->ForeColor = System::Drawing::Color::White;
			this->btnStudents->Location = System::Drawing::Point(26, 148);
			this->btnStudents->Name = L"btnStudents";
			this->btnStudents->Size = System::Drawing::Size(182, 66);
			this->btnStudents->TabIndex = 0;
			this->btnStudents->Text = L"Students";
			this->btnStudents->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnStudents->UseVisualStyleBackColor = true;
			this->btnStudents->Click += gcnew System::EventHandler(this, &adminDashboard::btnStudents_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->Controls->Add(this->lblWelcome);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(280, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1258, 80);
			this->panel2->TabIndex = 1;
			// 
			// lblWelcome
			// 
			this->lblWelcome->AutoSize = true;
			this->lblWelcome->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblWelcome->ForeColor = System::Drawing::Color::Maroon;
			this->lblWelcome->Location = System::Drawing::Point(283, 19);
			this->lblWelcome->Name = L"lblWelcome";
			this->lblWelcome->Size = System::Drawing::Size(418, 45);
			this->lblWelcome->TabIndex = 0;
			this->lblWelcome->Text = L"Administration Dashboard";
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->chart1);
			this->panel3->Controls->Add(this->panel6);
			this->panel3->Controls->Add(this->panel5);
			this->panel3->Controls->Add(this->panel4);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel3->Location = System::Drawing::Point(280, 80);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(1258, 842);
			this->panel3->TabIndex = 2;
			this->panel3->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &adminDashboard::panel3_Paint);
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			this->chart1->Dock = System::Windows::Forms::DockStyle::Bottom;
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(0, 370);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(1258, 472);
			this->chart1->TabIndex = 3;
			this->chart1->Text = L"chart1";
			// 
			// panel6
			// 
			this->panel6->BackColor = System::Drawing::Color::White;
			this->panel6->Controls->Add(this->lblCourseCount);
			this->panel6->Controls->Add(this->label5);
			this->panel6->Cursor = System::Windows::Forms::Cursors::Default;
			this->panel6->Location = System::Drawing::Point(700, 68);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(250, 140);
			this->panel6->TabIndex = 2;
			// 
			// lblCourseCount
			// 
			this->lblCourseCount->AutoSize = true;
			this->lblCourseCount->Font = (gcnew System::Drawing::Font(L"Segoe UI", 19.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCourseCount->Location = System::Drawing::Point(-12, 53);
			this->lblCourseCount->Name = L"lblCourseCount";
			this->lblCourseCount->Size = System::Drawing::Size(272, 71);
			this->lblCourseCount->TabIndex = 1;
			this->lblCourseCount->Text = L"Loading...";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::Gray;
			this->label5->Location = System::Drawing::Point(16, 16);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(174, 37);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Total Courses";
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::White;
			this->panel5->Controls->Add(this->lblFacultyCount);
			this->panel5->Controls->Add(this->label3);
			this->panel5->Cursor = System::Windows::Forms::Cursors::Default;
			this->panel5->Location = System::Drawing::Point(365, 68);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(250, 140);
			this->panel5->TabIndex = 1;
			// 
			// lblFacultyCount
			// 
			this->lblFacultyCount->AutoSize = true;
			this->lblFacultyCount->Font = (gcnew System::Drawing::Font(L"Segoe UI", 19.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblFacultyCount->Location = System::Drawing::Point(-12, 53);
			this->lblFacultyCount->Name = L"lblFacultyCount";
			this->lblFacultyCount->Size = System::Drawing::Size(272, 71);
			this->lblFacultyCount->TabIndex = 1;
			this->lblFacultyCount->Text = L"Loading...";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Gray;
			this->label3->Location = System::Drawing::Point(16, 16);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(163, 37);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Total Faculty";
			this->label3->Click += gcnew System::EventHandler(this, &adminDashboard::label3_Click);
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::White;
			this->panel4->Controls->Add(this->lblStudentCount);
			this->panel4->Controls->Add(this->label1);
			this->panel4->Cursor = System::Windows::Forms::Cursors::Default;
			this->panel4->Location = System::Drawing::Point(26, 68);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(250, 140);
			this->panel4->TabIndex = 0;
			// 
			// lblStudentCount
			// 
			this->lblStudentCount->AutoSize = true;
			this->lblStudentCount->Font = (gcnew System::Drawing::Font(L"Segoe UI", 19.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblStudentCount->Location = System::Drawing::Point(-12, 53);
			this->lblStudentCount->Name = L"lblStudentCount";
			this->lblStudentCount->Size = System::Drawing::Size(272, 71);
			this->lblStudentCount->TabIndex = 1;
			this->lblStudentCount->Text = L"Loading...";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Gray;
			this->label1->Location = System::Drawing::Point(16, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(210, 37);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Total Enrollment";
			// 
			// adminDashboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ClientSize = System::Drawing::Size(1538, 922);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"adminDashboard";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"adminDashboard";
			this->Load += gcnew System::EventHandler(this, &adminDashboard::adminDashboard_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void btnStudents_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void panel3_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		}
		private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void adminDashboard_Load(System::Object^ sender, System::EventArgs^ e) {
			lblStudentCount->Text = GetCount("Student").ToString();
			lblFacultyCount->Text = GetCount("Faculty").ToString();
			lblCourseCount->Text = GetCount("Course").ToString();

			LoadChart();
		}
		private: System::Void btnCourses_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void btnDepartment_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void btnProgrammes_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void btnFaculty_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		}
		private: System::Void btnEnrollment_Click(System::Object^ sender, System::EventArgs^ e); 
		private: System::Void btnPayments_Click(System::Object^ sender, System::EventArgs^ e);
};
}
