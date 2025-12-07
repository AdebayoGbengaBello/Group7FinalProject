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

	/// <summary>
	/// Summary for adminEnrollment
	/// </summary>
	public ref class adminEnrollment : public System::Windows::Forms::Form
	{
		Database^ db = gcnew Database();
		User^ currentUser;
		int globalRegistrationID = -1;
	public:
		adminEnrollment(User^ user)
		{
			InitializeComponent();
			currentUser = user;
			//
			//TODO: Add the constructor code here
			//
			loadEnrollments();
		}
		void loadEnrollments() {
			try {
				db->Open();
				db->sqlCmd->CommandText = "SELECT cr.registrationID, cr.studentID, concat(u.firstName, ' ', u.lastName) as studentName, c.courseCode, c.courseTitle, cr.semester, cr.status FROM courseregistration cr JOIN student s ON cr.studentID = s.studentID JOIN user u ON s.studentID = u.dbID JOIN course c ON cr.courseID = c.courseID ORDER BY cr.registrationID DESC";
				db->sqlDR = db->sqlCmd->ExecuteReader();
				db->sqlDT->Clear();
				db->sqlDT->Load(db->sqlDR);
				dataGridView1->DataSource = db->sqlDT;
				dataGridView1->Columns[0]->Visible=false;
				dataGridView1->Columns[1]->Width = 80;
				dataGridView1->Columns[2]->Width = 200;
				dataGridView1->Columns[3]->Width = 80;
				dataGridView1->Columns[4]->Width = 250;
				dataGridView1->Columns[5]->Width = 100;
				dataGridView1->Columns[6]->Width = 100;
				db->sqlDR->Close();
				db->sqlCmd->Cancel();
				db->Close();
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~adminEnrollment()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel2;
	protected:
	private: System::Windows::Forms::Label^ lblWelcome;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ btnPayments;
	private: System::Windows::Forms::Button^ btnEnrollment;
	private: System::Windows::Forms::Button^ btnProgrammes;
	private: System::Windows::Forms::Label^ lblUser;
	private: System::Windows::Forms::Button^ btnCourses;
	private: System::Windows::Forms::Button^ btnDepartment;
	private: System::Windows::Forms::Button^ btnFaculty;
	private: System::Windows::Forms::Button^ btnStudents;

	private: System::Windows::Forms::Button^ btnID;

	private: System::Windows::Forms::TextBox^ txtSearch;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ btnReject;
	private: System::Windows::Forms::Button^ btnApprove;
	private: System::Windows::Forms::Button^ byCode;

	private: System::Windows::Forms::Button^ btnSemester;

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
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->lblWelcome = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->btnPayments = (gcnew System::Windows::Forms::Button());
			this->btnEnrollment = (gcnew System::Windows::Forms::Button());
			this->btnProgrammes = (gcnew System::Windows::Forms::Button());
			this->lblUser = (gcnew System::Windows::Forms::Label());
			this->btnCourses = (gcnew System::Windows::Forms::Button());
			this->btnDepartment = (gcnew System::Windows::Forms::Button());
			this->btnFaculty = (gcnew System::Windows::Forms::Button());
			this->btnStudents = (gcnew System::Windows::Forms::Button());
			this->btnID = (gcnew System::Windows::Forms::Button());
			this->txtSearch = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->btnReject = (gcnew System::Windows::Forms::Button());
			this->btnApprove = (gcnew System::Windows::Forms::Button());
			this->byCode = (gcnew System::Windows::Forms::Button());
			this->btnSemester = (gcnew System::Windows::Forms::Button());
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->Controls->Add(this->lblWelcome);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(280, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1911, 80);
			this->panel2->TabIndex = 3;
			// 
			// lblWelcome
			// 
			this->lblWelcome->AutoSize = true;
			this->lblWelcome->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblWelcome->ForeColor = System::Drawing::Color::Maroon;
			this->lblWelcome->Location = System::Drawing::Point(603, 9);
			this->lblWelcome->Name = L"lblWelcome";
			this->lblWelcome->Size = System::Drawing::Size(391, 45);
			this->lblWelcome->TabIndex = 0;
			this->lblWelcome->Text = L"Enrollment Management";
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
			this->panel1->Size = System::Drawing::Size(280, 1128);
			this->panel1->TabIndex = 2;
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
			// 
			// btnID
			// 
			this->btnID->BackColor = System::Drawing::Color::Maroon;
			this->btnID->FlatAppearance->BorderColor = System::Drawing::Color::Maroon;
			this->btnID->FlatAppearance->BorderSize = 0;
			this->btnID->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnID->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnID->ForeColor = System::Drawing::Color::White;
			this->btnID->Location = System::Drawing::Point(1224, 840);
			this->btnID->Name = L"btnID";
			this->btnID->Size = System::Drawing::Size(298, 50);
			this->btnID->TabIndex = 109;
			this->btnID->Text = L"By ID";
			this->btnID->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnID->UseVisualStyleBackColor = false;
			this->btnID->Click += gcnew System::EventHandler(this, &adminEnrollment::btnID_Click);
			// 
			// txtSearch
			// 
			this->txtSearch->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtSearch->Location = System::Drawing::Point(571, 941);
			this->txtSearch->Name = L"txtSearch";
			this->txtSearch->Size = System::Drawing::Size(605, 43);
			this->txtSearch->TabIndex = 107;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(377, 941);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(101, 37);
			this->label2->TabIndex = 106;
			this->label2->Text = L"Search:";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(324, 383);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 82;
			this->dataGridView1->RowTemplate->Height = 33;
			this->dataGridView1->Size = System::Drawing::Size(1754, 397);
			this->dataGridView1->TabIndex = 105;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &adminEnrollment::dataGridView1_CellContentClick);
			// 
			// btnReject
			// 
			this->btnReject->BackColor = System::Drawing::Color::Maroon;
			this->btnReject->FlatAppearance->BorderColor = System::Drawing::Color::Maroon;
			this->btnReject->FlatAppearance->BorderSize = 0;
			this->btnReject->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnReject->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnReject->ForeColor = System::Drawing::Color::White;
			this->btnReject->Location = System::Drawing::Point(1719, 295);
			this->btnReject->Name = L"btnReject";
			this->btnReject->Size = System::Drawing::Size(182, 56);
			this->btnReject->TabIndex = 103;
			this->btnReject->Text = L"Reject";
			this->btnReject->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnReject->UseVisualStyleBackColor = false;
			this->btnReject->Click += gcnew System::EventHandler(this, &adminEnrollment::btnReject_Click);
			// 
			// btnApprove
			// 
			this->btnApprove->BackColor = System::Drawing::Color::Maroon;
			this->btnApprove->FlatAppearance->BorderColor = System::Drawing::Color::Maroon;
			this->btnApprove->FlatAppearance->BorderSize = 0;
			this->btnApprove->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnApprove->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnApprove->ForeColor = System::Drawing::Color::White;
			this->btnApprove->Location = System::Drawing::Point(493, 295);
			this->btnApprove->Name = L"btnApprove";
			this->btnApprove->Size = System::Drawing::Size(182, 56);
			this->btnApprove->TabIndex = 102;
			this->btnApprove->Text = L"Approve";
			this->btnApprove->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnApprove->UseVisualStyleBackColor = false;
			this->btnApprove->Click += gcnew System::EventHandler(this, &adminEnrollment::btnApprove_Click);
			// 
			// byCode
			// 
			this->byCode->BackColor = System::Drawing::Color::Maroon;
			this->byCode->FlatAppearance->BorderColor = System::Drawing::Color::Maroon;
			this->byCode->FlatAppearance->BorderSize = 0;
			this->byCode->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->byCode->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->byCode->ForeColor = System::Drawing::Color::White;
			this->byCode->Location = System::Drawing::Point(1224, 1030);
			this->byCode->Name = L"byCode";
			this->byCode->Size = System::Drawing::Size(298, 50);
			this->byCode->TabIndex = 112;
			this->byCode->Text = L"By Course Code";
			this->byCode->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->byCode->UseVisualStyleBackColor = false;
			this->byCode->Click += gcnew System::EventHandler(this, &adminEnrollment::byCode_Click);
			// 
			// btnSemester
			// 
			this->btnSemester->BackColor = System::Drawing::Color::Maroon;
			this->btnSemester->FlatAppearance->BorderColor = System::Drawing::Color::Maroon;
			this->btnSemester->FlatAppearance->BorderSize = 0;
			this->btnSemester->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSemester->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSemester->ForeColor = System::Drawing::Color::White;
			this->btnSemester->Location = System::Drawing::Point(1224, 942);
			this->btnSemester->Name = L"btnSemester";
			this->btnSemester->Size = System::Drawing::Size(298, 50);
			this->btnSemester->TabIndex = 111;
			this->btnSemester->Text = L"By Semester";
			this->btnSemester->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnSemester->UseVisualStyleBackColor = false;
			this->btnSemester->Click += gcnew System::EventHandler(this, &adminEnrollment::btnSemester_Click);
			// 
			// adminEnrollment
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(2191, 1128);
			this->Controls->Add(this->byCode);
			this->Controls->Add(this->btnSemester);
			this->Controls->Add(this->btnID);
			this->Controls->Add(this->txtSearch);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->btnReject);
			this->Controls->Add(this->btnApprove);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"adminEnrollment";
			this->Text = L"adminEnrollment";
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if(e->RowIndex >=0){
			DataGridViewRow^ row = this->dataGridView1->Rows[e->RowIndex];
			globalRegistrationID = Int32::Parse(row->Cells[0]->Value->ToString());
		}
	}
	private: System::Void btnApprove_Click(System::Object^ sender, System::EventArgs^ e) {
		if (globalRegistrationID != -1) {
			try {
				db->Open();
				db->sqlCmd->CommandText = "UPDATE courseregistration SET status='Approved' WHERE registrationID=@registrationID";
				db->sqlCmd->Parameters->AddWithValue("@registrationID", globalRegistrationID);
				int result = db->sqlCmd->ExecuteNonQuery();
				if (result > 0) {
					MessageBox::Show("Enrollment approved successfully.");
					loadEnrollments();
					globalRegistrationID = -1;
				}
				else {
					MessageBox::Show("Failed to approve enrollment.");
				}
				db->sqlCmd->Parameters->Clear();
				db->Close();
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}
		}
		else {
			MessageBox::Show("Please select an enrollment to approve.");
		}
	}
	private: System::Void btnReject_Click(System::Object^ sender, System::EventArgs^ e) {
		if (globalRegistrationID != -1) {
			try {
				db->Open();
				db->sqlCmd->CommandText = "UPDATE courseregistration SET status='Rejected' WHERE registrationID=@registrationID";
				db->sqlCmd->Parameters->AddWithValue("@registrationID", globalRegistrationID);
				int result = db->sqlCmd->ExecuteNonQuery();
				if (result > 0) {
					MessageBox::Show("Enrollment rejected successfully.");
					loadEnrollments();
					globalRegistrationID = -1;
				}
				else {
					MessageBox::Show("Failed to reject enrollment.");
				}
				db->sqlCmd->Parameters->Clear();
				db->Close();
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}
		}
		else {
			MessageBox::Show("Please select an enrollment to reject.");
		}
	}
	private: System::Void btnID_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			db->Open();
			db->sqlCmd->CommandText = "SELECT cr.registrationID, cr.studentID, concat(u.firstName, ' ', u.lastName) as studentName, c.courseCode, c.courseTitle, cr.semester, cr.status FROM courseregistration cr JOIN student s ON cr.studentID = s.studentID JOIN user u ON s.studentID = u.dbID JOIN course c ON cr.courseID = c.courseID WHERE cr.studentID = @studentID ORDER BY cr.registrationID DESC";
			int searchID = Int32::Parse(txtSearch->Text);
			db->sqlCmd->Parameters->AddWithValue("@studentID", searchID);
			db->sqlDR = db->sqlCmd->ExecuteReader();
			db->sqlDT->Clear();
			db->sqlDT->Load(db->sqlDR);
			dataGridView1->DataSource = db->sqlDT;
			dataGridView1->Columns[0]->Visible = false;
			dataGridView1->Columns[1]->Width = 80;
			dataGridView1->Columns[2]->Width = 200;
			dataGridView1->Columns[3]->Width = 80;
			dataGridView1->Columns[4]->Width = 250;
			dataGridView1->Columns[5]->Width = 100;
			dataGridView1->Columns[6]->Width = 100;
			db->sqlDR->Close();
			db->sqlCmd->Parameters->Clear();
			db->Close();
		}
		catch (FormatException^) {
			MessageBox::Show("Please enter a valid Student ID.");
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}
	}
	private: System::Void btnSemester_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			db->Open();
			db->sqlCmd->CommandText = "SELECT cr.registrationID, cr.studentID, concat(u.firstName, ' ', u.lastName) as studentName, c.courseCode, c.courseTitle, cr.semester, cr.status FROM courseregistration cr JOIN student s ON cr.studentID = s.studentID JOIN user u ON s.studentID = u.dbID JOIN course c ON cr.courseID = c.courseID WHERE cr.semester = @semester ORDER BY cr.registrationID DESC";
			String^ searchSemester = txtSearch->Text;
			db->sqlCmd->Parameters->AddWithValue("@semester", searchSemester);
			db->sqlDR = db->sqlCmd->ExecuteReader();
			db->sqlDT->Clear();
			db->sqlDT->Load(db->sqlDR);
			dataGridView1->DataSource = db->sqlDT;
			dataGridView1->Columns[0]->Visible = false;
			dataGridView1->Columns[1]->Width = 80;
			dataGridView1->Columns[2]->Width = 200;
			dataGridView1->Columns[3]->Width = 80;
			dataGridView1->Columns[4]->Width = 250;
			dataGridView1->Columns[5]->Width = 100;
			dataGridView1->Columns[6]->Width = 100;
			db->sqlDR->Close();
			db->sqlCmd->Parameters->Clear();
			db->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}
	}
	private: System::Void byCode_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			db->Open();
			db->sqlCmd->CommandText = "SELECT cr.registrationID, cr.studentID, concat(u.firstName, ' ', u.lastName) as studentName, c.courseCode, c.courseTitle, cr.semester, cr.status FROM courseregistration cr JOIN student s ON cr.studentID = s.studentID JOIN user u ON s.studentID = u.dbID JOIN course c ON cr.courseID = c.courseID WHERE c.courseCode = @courseCode ORDER BY cr.registrationID DESC";
			String^ searchCourseCode = txtSearch->Text;
			db->sqlCmd->Parameters->AddWithValue("@courseCode", searchCourseCode);
			db->sqlDR = db->sqlCmd->ExecuteReader();
			db->sqlDT->Clear();
			db->sqlDT->Load(db->sqlDR);
			dataGridView1->DataSource = db->sqlDT;
			dataGridView1->Columns[0]->Visible = false;
			dataGridView1->Columns[1]->Width = 80;
			dataGridView1->Columns[2]->Width = 200;
			dataGridView1->Columns[3]->Width = 80;
			dataGridView1->Columns[4]->Width = 250;
			dataGridView1->Columns[5]->Width = 100;
			dataGridView1->Columns[6]->Width = 100;
			db->sqlDR->Close();
			db->sqlCmd->Parameters->Clear();
			db->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}
	}
};
}
