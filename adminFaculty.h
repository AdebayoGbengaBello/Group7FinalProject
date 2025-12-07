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
	/// Summary for adminFaculty
	/// </summary>
	public ref class adminFaculty : public System::Windows::Forms::Form
	{
		Database^ db = gcnew Database();
	private: System::Windows::Forms::TextBox^ txtPosition;
	private: System::Windows::Forms::Label^ Position;
		   User^ currentUser;
	private: System::Windows::Forms::Button^ btnPayments;
	private: System::Windows::Forms::Button^ btnEnrollment;
	private: System::Windows::Forms::Button^ btnDepartments;

		   int globalFacultyID = -1;
	public:
		adminFaculty(User^ user)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->currentUser = user;
			lblUser->Text = "Hello " + currentUser->name;
			db->Open();
			String^ query = "SELECT deptName FROM Department";
			db->sqlCmd->CommandText = query;
			db->sqlDR = db->sqlCmd->ExecuteReader();
			while (db->sqlDR->Read()) {
				DepartmentBox->Items->Add(db->sqlDR->GetString("deptName"));
			}
			db->sqlDR->Close();
			db->Close();
			loadFaculty();
		}
		void loadFaculty() {
			try {
				db->Open();
				db->sqlCmd->CommandText = "SELECT f.facultyID, u.firstName, u.lastName, d.deptName, u.email, u.phoneNumber from faculty f JOIN user u ON f.facultyID=u.dbID JOIN department d ON f.deptID=d.deptID ORDER by f.facultyID DESC";
				db->sqlDR = db->sqlCmd->ExecuteReader();
				db->sqlDT->Clear();
				db->sqlDT->Load(db->sqlDR);
				dataGridView1->DataSource = db->sqlDT;
				dataGridView1->Columns[0]->Width = 50;
				dataGridView1->Columns[1]->Width = 200;
				dataGridView1->Columns[2]->Width = 200;
				dataGridView1->Columns[3]->Width = 200;
				dataGridView1->Columns[4]->Width = 200;
				dataGridView1->Columns[5]->Width = 200;
				db->sqlDR->Close();
				db->sqlCmd->Cancel();
				db->Close();
			}
			catch (Exception^ e) {
				MessageBox::Show("Database Connection Error: " + e->ToString(), "Data Load Error", MessageBoxButtons::OK,
					MessageBoxIcon::Warning);
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~adminFaculty()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnDepartment;
	private: System::Windows::Forms::TextBox^ txtFirstName;
	protected:


	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ComboBox^ DepartmentBox;
	private: System::Windows::Forms::Button^ btnID;
	private: System::Windows::Forms::Button^ btnName;
	private: System::Windows::Forms::TextBox^ txtSearch;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ btnDelete;
	private: System::Windows::Forms::Button^ btnUpdate;
	private: System::Windows::Forms::Button^ btnSave;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ lblWelcome;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ btnProgrammes;
	private: System::Windows::Forms::Label^ lblUser;
	private: System::Windows::Forms::Button^ btnCourses;
	private: System::Windows::Forms::Button^ btnDashboard;

	private: System::Windows::Forms::Button^ btnStudents;
	private: System::Windows::Forms::TextBox^ txtLastName;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ txtEmail;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ txtPassword;

	private: System::Windows::Forms::Label^ label6;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ txtAddress;





	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ txtGender;

	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::TextBox^ txtPhoneNumber;

	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;


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
			this->btnDepartment = (gcnew System::Windows::Forms::Button());
			this->txtFirstName = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->DepartmentBox = (gcnew System::Windows::Forms::ComboBox());
			this->btnID = (gcnew System::Windows::Forms::Button());
			this->btnName = (gcnew System::Windows::Forms::Button());
			this->txtSearch = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->btnUpdate = (gcnew System::Windows::Forms::Button());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->lblWelcome = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->btnDepartments = (gcnew System::Windows::Forms::Button());
			this->btnPayments = (gcnew System::Windows::Forms::Button());
			this->btnEnrollment = (gcnew System::Windows::Forms::Button());
			this->btnProgrammes = (gcnew System::Windows::Forms::Button());
			this->lblUser = (gcnew System::Windows::Forms::Label());
			this->btnCourses = (gcnew System::Windows::Forms::Button());
			this->btnDashboard = (gcnew System::Windows::Forms::Button());
			this->btnStudents = (gcnew System::Windows::Forms::Button());
			this->txtLastName = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtEmail = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->txtAddress = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->txtGender = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->txtPhoneNumber = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->txtPosition = (gcnew System::Windows::Forms::TextBox());
			this->Position = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnDepartment
			// 
			this->btnDepartment->BackColor = System::Drawing::Color::Maroon;
			this->btnDepartment->FlatAppearance->BorderColor = System::Drawing::Color::Maroon;
			this->btnDepartment->FlatAppearance->BorderSize = 0;
			this->btnDepartment->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDepartment->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDepartment->ForeColor = System::Drawing::Color::White;
			this->btnDepartment->Location = System::Drawing::Point(1643, 1211);
			this->btnDepartment->Name = L"btnDepartment";
			this->btnDepartment->Size = System::Drawing::Size(236, 50);
			this->btnDepartment->TabIndex = 44;
			this->btnDepartment->Text = L"By Department";
			this->btnDepartment->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnDepartment->UseVisualStyleBackColor = false;
			this->btnDepartment->Click += gcnew System::EventHandler(this, &adminFaculty::btnDepartment_Click);
			// 
			// txtFirstName
			// 
			this->txtFirstName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtFirstName->Location = System::Drawing::Point(635, 110);
			this->txtFirstName->Name = L"txtFirstName";
			this->txtFirstName->Size = System::Drawing::Size(605, 43);
			this->txtFirstName->TabIndex = 41;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(392, 110);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(150, 37);
			this->label3->TabIndex = 40;
			this->label3->Text = L"First Name:";
			// 
			// DepartmentBox
			// 
			this->DepartmentBox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DepartmentBox->FormattingEnabled = true;
			this->DepartmentBox->Location = System::Drawing::Point(635, 699);
			this->DepartmentBox->Name = L"DepartmentBox";
			this->DepartmentBox->Size = System::Drawing::Size(603, 45);
			this->DepartmentBox->TabIndex = 39;
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
			this->btnID->Location = System::Drawing::Point(1231, 1211);
			this->btnID->Name = L"btnID";
			this->btnID->Size = System::Drawing::Size(182, 50);
			this->btnID->TabIndex = 38;
			this->btnID->Text = L"By ID";
			this->btnID->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnID->UseVisualStyleBackColor = false;
			this->btnID->Click += gcnew System::EventHandler(this, &adminFaculty::btnID_Click);
			// 
			// btnName
			// 
			this->btnName->BackColor = System::Drawing::Color::Maroon;
			this->btnName->FlatAppearance->BorderColor = System::Drawing::Color::Maroon;
			this->btnName->FlatAppearance->BorderSize = 0;
			this->btnName->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnName->ForeColor = System::Drawing::Color::White;
			this->btnName->Location = System::Drawing::Point(1436, 1211);
			this->btnName->Name = L"btnName";
			this->btnName->Size = System::Drawing::Size(182, 50);
			this->btnName->TabIndex = 37;
			this->btnName->Text = L"By Name";
			this->btnName->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnName->UseVisualStyleBackColor = false;
			this->btnName->Click += gcnew System::EventHandler(this, &adminFaculty::btnName_Click);
			// 
			// txtSearch
			// 
			this->txtSearch->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtSearch->Location = System::Drawing::Point(575, 1215);
			this->txtSearch->Name = L"txtSearch";
			this->txtSearch->Size = System::Drawing::Size(605, 43);
			this->txtSearch->TabIndex = 36;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(381, 1215);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(101, 37);
			this->label2->TabIndex = 35;
			this->label2->Text = L"Search:";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(399, 869);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 82;
			this->dataGridView1->RowTemplate->Height = 33;
			this->dataGridView1->Size = System::Drawing::Size(1638, 297);
			this->dataGridView1->TabIndex = 34;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &adminFaculty::dataGridView1_CellContentClick);
			// 
			// btnDelete
			// 
			this->btnDelete->BackColor = System::Drawing::Color::Maroon;
			this->btnDelete->FlatAppearance->BorderColor = System::Drawing::Color::Maroon;
			this->btnDelete->FlatAppearance->BorderSize = 0;
			this->btnDelete->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDelete->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDelete->ForeColor = System::Drawing::Color::White;
			this->btnDelete->Location = System::Drawing::Point(1082, 781);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(182, 50);
			this->btnDelete->TabIndex = 32;
			this->btnDelete->Text = L"Delete";
			this->btnDelete->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnDelete->UseVisualStyleBackColor = false;
			this->btnDelete->Click += gcnew System::EventHandler(this, &adminFaculty::btnDelete_Click);
			// 
			// btnUpdate
			// 
			this->btnUpdate->BackColor = System::Drawing::Color::Maroon;
			this->btnUpdate->FlatAppearance->BorderColor = System::Drawing::Color::Maroon;
			this->btnUpdate->FlatAppearance->BorderSize = 0;
			this->btnUpdate->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnUpdate->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnUpdate->ForeColor = System::Drawing::Color::White;
			this->btnUpdate->Location = System::Drawing::Point(801, 781);
			this->btnUpdate->Name = L"btnUpdate";
			this->btnUpdate->Size = System::Drawing::Size(182, 50);
			this->btnUpdate->TabIndex = 30;
			this->btnUpdate->Text = L"Update";
			this->btnUpdate->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnUpdate->UseVisualStyleBackColor = false;
			this->btnUpdate->Click += gcnew System::EventHandler(this, &adminFaculty::btnUpdate_Click);
			// 
			// btnSave
			// 
			this->btnSave->BackColor = System::Drawing::Color::Maroon;
			this->btnSave->FlatAppearance->BorderColor = System::Drawing::Color::Maroon;
			this->btnSave->FlatAppearance->BorderSize = 0;
			this->btnSave->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSave->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSave->ForeColor = System::Drawing::Color::White;
			this->btnSave->Location = System::Drawing::Point(522, 781);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(182, 50);
			this->btnSave->TabIndex = 29;
			this->btnSave->Text = L"Save";
			this->btnSave->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnSave->UseVisualStyleBackColor = false;
			this->btnSave->Click += gcnew System::EventHandler(this, &adminFaculty::btnSave_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(392, 704);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(165, 37);
			this->label1->TabIndex = 28;
			this->label1->Text = L"Department:";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->Controls->Add(this->lblWelcome);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(279, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1797, 80);
			this->panel2->TabIndex = 33;
			// 
			// lblWelcome
			// 
			this->lblWelcome->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblWelcome->AutoSize = true;
			this->lblWelcome->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblWelcome->ForeColor = System::Drawing::Color::Maroon;
			this->lblWelcome->Location = System::Drawing::Point(369, 18);
			this->lblWelcome->Name = L"lblWelcome";
			this->lblWelcome->Size = System::Drawing::Size(332, 45);
			this->lblWelcome->TabIndex = 0;
			this->lblWelcome->Text = L"Faculty Management";
			this->lblWelcome->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Maroon;
			this->panel1->Controls->Add(this->btnDepartments);
			this->panel1->Controls->Add(this->btnPayments);
			this->panel1->Controls->Add(this->btnEnrollment);
			this->panel1->Controls->Add(this->btnProgrammes);
			this->panel1->Controls->Add(this->lblUser);
			this->panel1->Controls->Add(this->btnCourses);
			this->panel1->Controls->Add(this->btnDashboard);
			this->panel1->Controls->Add(this->btnStudents);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(279, 1284);
			this->panel1->TabIndex = 31;
			// 
			// btnDepartments
			// 
			this->btnDepartments->FlatAppearance->BorderSize = 0;
			this->btnDepartments->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDepartments->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDepartments->ForeColor = System::Drawing::Color::White;
			this->btnDepartments->Location = System::Drawing::Point(27, 417);
			this->btnDepartments->Name = L"btnDepartments";
			this->btnDepartments->Size = System::Drawing::Size(228, 64);
			this->btnDepartments->TabIndex = 11;
			this->btnDepartments->Text = L"Departments";
			this->btnDepartments->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnDepartments->UseVisualStyleBackColor = true;
			this->btnDepartments->Click += gcnew System::EventHandler(this, &adminFaculty::btnDepartments_Click);
			// 
			// btnPayments
			// 
			this->btnPayments->FlatAppearance->BorderSize = 0;
			this->btnPayments->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnPayments->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnPayments->ForeColor = System::Drawing::Color::White;
			this->btnPayments->Location = System::Drawing::Point(27, 830);
			this->btnPayments->Name = L"btnPayments";
			this->btnPayments->Size = System::Drawing::Size(228, 68);
			this->btnPayments->TabIndex = 10;
			this->btnPayments->Text = L"Payments";
			this->btnPayments->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnPayments->UseVisualStyleBackColor = true;
			this->btnPayments->Click += gcnew System::EventHandler(this, &adminFaculty::btnPayments_Click);
			// 
			// btnEnrollment
			// 
			this->btnEnrollment->FlatAppearance->BorderSize = 0;
			this->btnEnrollment->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnEnrollment->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnEnrollment->ForeColor = System::Drawing::Color::White;
			this->btnEnrollment->Location = System::Drawing::Point(27, 749);
			this->btnEnrollment->Name = L"btnEnrollment";
			this->btnEnrollment->Size = System::Drawing::Size(182, 75);
			this->btnEnrollment->TabIndex = 9;
			this->btnEnrollment->Text = L"Enrollment";
			this->btnEnrollment->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnEnrollment->UseVisualStyleBackColor = true;
			this->btnEnrollment->Click += gcnew System::EventHandler(this, &adminFaculty::btnEnrollment_Click);
			// 
			// btnProgrammes
			// 
			this->btnProgrammes->FlatAppearance->BorderSize = 0;
			this->btnProgrammes->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnProgrammes->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnProgrammes->ForeColor = System::Drawing::Color::White;
			this->btnProgrammes->Location = System::Drawing::Point(27, 624);
			this->btnProgrammes->Name = L"btnProgrammes";
			this->btnProgrammes->Size = System::Drawing::Size(206, 80);
			this->btnProgrammes->TabIndex = 6;
			this->btnProgrammes->Text = L"Programmes";
			this->btnProgrammes->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnProgrammes->UseVisualStyleBackColor = true;
			this->btnProgrammes->Click += gcnew System::EventHandler(this, &adminFaculty::btnProgrammes_Click);
			// 
			// lblUser
			// 
			this->lblUser->AutoSize = true;
			this->lblUser->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblUser->ForeColor = System::Drawing::Color::White;
			this->lblUser->Location = System::Drawing::Point(41, 63);
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
			this->btnCourses->Location = System::Drawing::Point(27, 523);
			this->btnCourses->Name = L"btnCourses";
			this->btnCourses->Size = System::Drawing::Size(182, 50);
			this->btnCourses->TabIndex = 4;
			this->btnCourses->Text = L"Courses";
			this->btnCourses->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnCourses->UseVisualStyleBackColor = true;
			this->btnCourses->Click += gcnew System::EventHandler(this, &adminFaculty::btnCourses_Click);
			// 
			// btnDashboard
			// 
			this->btnDashboard->FlatAppearance->BorderSize = 0;
			this->btnDashboard->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDashboard->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDashboard->ForeColor = System::Drawing::Color::White;
			this->btnDashboard->Location = System::Drawing::Point(27, 201);
			this->btnDashboard->Name = L"btnDashboard";
			this->btnDashboard->Size = System::Drawing::Size(197, 82);
			this->btnDashboard->TabIndex = 3;
			this->btnDashboard->Text = L"Dashboard";
			this->btnDashboard->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnDashboard->UseVisualStyleBackColor = true;
			this->btnDashboard->Click += gcnew System::EventHandler(this, &adminFaculty::btnDashboard_Click);
			// 
			// btnStudents
			// 
			this->btnStudents->FlatAppearance->BorderSize = 0;
			this->btnStudents->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnStudents->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnStudents->ForeColor = System::Drawing::Color::White;
			this->btnStudents->Location = System::Drawing::Point(27, 317);
			this->btnStudents->Name = L"btnStudents";
			this->btnStudents->Size = System::Drawing::Size(182, 50);
			this->btnStudents->TabIndex = 0;
			this->btnStudents->Text = L"Students";
			this->btnStudents->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnStudents->UseVisualStyleBackColor = true;
			this->btnStudents->Click += gcnew System::EventHandler(this, &adminFaculty::btnStudents_Click);
			// 
			// txtLastName
			// 
			this->txtLastName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtLastName->Location = System::Drawing::Point(635, 178);
			this->txtLastName->Name = L"txtLastName";
			this->txtLastName->Size = System::Drawing::Size(605, 43);
			this->txtLastName->TabIndex = 46;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(392, 178);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(148, 37);
			this->label4->TabIndex = 45;
			this->label4->Text = L"Last Name:";
			// 
			// txtEmail
			// 
			this->txtEmail->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtEmail->Location = System::Drawing::Point(635, 240);
			this->txtEmail->Name = L"txtEmail";
			this->txtEmail->Size = System::Drawing::Size(605, 43);
			this->txtEmail->TabIndex = 48;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(392, 240);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(88, 37);
			this->label5->TabIndex = 47;
			this->label5->Text = L"Email:";
			// 
			// txtPassword
			// 
			this->txtPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtPassword->Location = System::Drawing::Point(635, 300);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->PasswordChar = '*';
			this->txtPassword->Size = System::Drawing::Size(605, 43);
			this->txtPassword->TabIndex = 50;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(392, 306);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(134, 37);
			this->label6->TabIndex = 49;
			this->label6->Text = L"Password:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(392, 366);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(172, 37);
			this->label7->TabIndex = 51;
			this->label7->Text = L"Date of Birth:";
			// 
			// txtAddress
			// 
			this->txtAddress->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtAddress->Location = System::Drawing::Point(635, 563);
			this->txtAddress->Name = L"txtAddress";
			this->txtAddress->Size = System::Drawing::Size(605, 43);
			this->txtAddress->TabIndex = 58;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(392, 563);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(117, 37);
			this->label10->TabIndex = 57;
			this->label10->Text = L"Address:";
			// 
			// txtGender
			// 
			this->txtGender->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtGender->Location = System::Drawing::Point(635, 501);
			this->txtGender->Name = L"txtGender";
			this->txtGender->Size = System::Drawing::Size(605, 43);
			this->txtGender->TabIndex = 56;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(392, 501);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(110, 37);
			this->label11->TabIndex = 55;
			this->label11->Text = L"Gender:";
			// 
			// txtPhoneNumber
			// 
			this->txtPhoneNumber->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtPhoneNumber->Location = System::Drawing::Point(635, 433);
			this->txtPhoneNumber->Name = L"txtPhoneNumber";
			this->txtPhoneNumber->Size = System::Drawing::Size(605, 43);
			this->txtPhoneNumber->TabIndex = 54;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(392, 433);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(202, 37);
			this->label12->TabIndex = 53;
			this->label12->Text = L"Phone Number:";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dateTimePicker1->Location = System::Drawing::Point(635, 372);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(445, 43);
			this->dateTimePicker1->TabIndex = 59;
			// 
			// txtPosition
			// 
			this->txtPosition->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtPosition->Location = System::Drawing::Point(633, 629);
			this->txtPosition->Name = L"txtPosition";
			this->txtPosition->Size = System::Drawing::Size(605, 43);
			this->txtPosition->TabIndex = 61;
			// 
			// Position
			// 
			this->Position->AutoSize = true;
			this->Position->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Position->Location = System::Drawing::Point(390, 629);
			this->Position->Name = L"Position";
			this->Position->Size = System::Drawing::Size(118, 37);
			this->Position->TabIndex = 60;
			this->Position->Text = L"Position:";
			// 
			// adminFaculty
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(2076, 1284);
			this->Controls->Add(this->txtPosition);
			this->Controls->Add(this->Position);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->txtAddress);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->txtGender);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->txtPhoneNumber);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->txtPassword);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->txtEmail);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->txtLastName);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->btnDepartment);
			this->Controls->Add(this->txtFirstName);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->DepartmentBox);
			this->Controls->Add(this->btnID);
			this->Controls->Add(this->btnName);
			this->Controls->Add(this->txtSearch);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->btnDelete);
			this->Controls->Add(this->btnUpdate);
			this->Controls->Add(this->btnSave);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"adminFaculty";
			this->Text = L"adminFaculty";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void monthCalendar1_DateChanged(System::Object^ sender, System::Windows::Forms::DateRangeEventArgs^ e) {
	}
	private: System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			db->Open();
			String^ firstName = txtFirstName->Text;
			String^ lastName = txtLastName->Text;
			String^ email = txtEmail->Text;
			String^ password = txtPassword->Text;
			String^ gender = txtGender->Text;
			String^ phoneNumber = txtPhoneNumber->Text;
			String^ address = txtAddress->Text;
			DateTime birthDate = dateTimePicker1->Value;
			String^ formattedBirthDate = birthDate.ToString("yyyy-MM-dd");
			String^ department = DepartmentBox->SelectedItem->ToString();
			String^ position = txtPosition->Text;
			
			db->sqlCmd->CommandText = "INSERT INTO user (firstName, lastName, email, password, dateOfBirth, gender, phoneNumber, address) VALUES (@fname, @lname, @email, @pwd, @dob, @gender, @phone, @address)";
			db->sqlCmd->Parameters->AddWithValue("@fname", firstName);
			db->sqlCmd->Parameters->AddWithValue("@lname", lastName);
			db->sqlCmd->Parameters->AddWithValue("@email", email);
			db->sqlCmd->Parameters->AddWithValue("@pwd", password);
			db->sqlCmd->Parameters->AddWithValue("@dob", formattedBirthDate);
			db->sqlCmd->Parameters->AddWithValue("@gender", gender);
			db->sqlCmd->Parameters->AddWithValue("@phone", phoneNumber);
			db->sqlCmd->Parameters->AddWithValue("@address", address);
			db->sqlCmd->ExecuteNonQuery();
			db->sqlCmd->Parameters->Clear();
			db->sqlCmd->CommandText = "SELECT deptID FROM department WHERE deptName = @deptName";
			db->sqlCmd->Parameters->AddWithValue("@deptName", department);
			int deptID = (int)db->sqlCmd->ExecuteScalar();
			db->sqlCmd->Parameters->Clear();
			db->sqlCmd->CommandText = "INSERT INTO faculty (facultyID, deptID, position) VALUES (LAST_INSERT_ID(), @deptID, @position)";
			db->sqlCmd->Parameters->AddWithValue("@deptID", deptID);
			db->sqlCmd->Parameters->AddWithValue("@position", position);
			db->sqlCmd->ExecuteNonQuery();
			db->sqlCmd->Parameters->Clear();
			db->Close();
			MessageBox::Show("Faculty member added successfully.");
			loadFaculty();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error adding programme: " + ex->ToString(), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void btnUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			db->Open();
			String^ firstName = txtFirstName->Text;
			String^ lastName = txtLastName->Text;
			String^ email = txtEmail->Text;
			String^ password = txtPassword->Text;
			String^ gender = txtGender->Text;
			String^ phoneNumber = txtPhoneNumber->Text;
			String^ address = txtAddress->Text;
			DateTime birthDate = dateTimePicker1->Value;
			String^ formattedBirthDate = birthDate.ToString("yyyy-MM-dd");
			String^ department = DepartmentBox->SelectedItem->ToString();
			String^ position = txtPosition->Text;
			db->sqlCmd->CommandText = "UPDATE user SET firstName=@fname, lastName=@lname, email=@email, password=@pwd, dateOfBirth=@dob, gender=@gender, phoneNumber=@phone, address=@address WHERE dbID=@facultyID";
			db->sqlCmd->Parameters->AddWithValue("@fname", firstName);
			db->sqlCmd->Parameters->AddWithValue("@lname", lastName);
			db->sqlCmd->Parameters->AddWithValue("@email", email);
			db->sqlCmd->Parameters->AddWithValue("@pwd", password);
			db->sqlCmd->Parameters->AddWithValue("@dob", formattedBirthDate);
			db->sqlCmd->Parameters->AddWithValue("@gender", gender);
			db->sqlCmd->Parameters->AddWithValue("@phone", phoneNumber);
			db->sqlCmd->Parameters->AddWithValue("@address", address);
			db->sqlCmd->Parameters->AddWithValue("@facultyID", globalFacultyID);
			db->sqlCmd->ExecuteNonQuery();
			db->sqlCmd->Parameters->Clear();
			db->sqlCmd->CommandText = "SELECT deptID FROM department WHERE deptName = @deptName";
			db->sqlCmd->Parameters->AddWithValue("@deptName", department);
			int deptID = (int)db->sqlCmd->ExecuteScalar();
			db->sqlCmd->Parameters->Clear();
			db->sqlCmd->CommandText = "UPDATE faculty SET deptID=@deptID, position=@position WHERE facultyID=@facultyID";
			db->sqlCmd->Parameters->AddWithValue("@deptID", deptID);
			db->sqlCmd->Parameters->AddWithValue("@position", position);
			db->sqlCmd->Parameters->AddWithValue("@facultyID", globalFacultyID);
			db->sqlCmd->ExecuteNonQuery();
			db->sqlCmd->Parameters->Clear();
			db->Close();
			MessageBox::Show("Faculty member updated successfully.");
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error updating faculty: " + ex->ToString(), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

	}
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (e->RowIndex>=0)
		{
			DataGridViewRow^ row = dataGridView1->Rows[e->RowIndex];
			txtFirstName->Text = row->Cells["firstName"]->Value->ToString();
			txtLastName->Text = row->Cells["lastName"]->Value->ToString();
			txtEmail->Text = row->Cells["email"]->Value->ToString();
			txtPhoneNumber->Text = row->Cells["phoneNumber"]->Value->ToString();
			DepartmentBox->SelectedItem = row->Cells["deptName"]->Value->ToString();
			globalFacultyID = Convert::ToInt32(row->Cells["facultyID"]->Value);
			try {
				db->Open();
				db->sqlCmd->CommandText = "SELECT password, dateOfBirth, gender, address FROM user WHERE user.dbID=@facultyID";
				db->sqlCmd->Parameters->AddWithValue("@facultyID", globalFacultyID);
				MySqlDataReader^ reader = db->sqlCmd->ExecuteReader();
				reader->Read();
				txtPassword->Text = reader->GetString("password");
				dateTimePicker1->Value = reader->GetDateTime("dateOfBirth");
				txtGender->Text = reader->GetString("gender");
				txtAddress->Text = reader->GetString("address");
				reader->Close();
				db->sqlCmd->Parameters->Clear();
				db->sqlCmd->CommandText = "SELECT position FROM faculty WHERE facultyID=@facultyID";
				db->sqlCmd->Parameters->AddWithValue("@facultyID", globalFacultyID);
				reader = db->sqlCmd->ExecuteReader();
				reader->Read();
				txtPosition->Text = reader->GetString("position");
				db->sqlCmd->Parameters->Clear();
				db->Close();
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error fetching faculty details: " + ex->ToString(), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}
	private: System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			db->Open();
			db->sqlCmd->CommandText = "DELETE FROM faculty WHERE facultyID=@facultyID";
			db->sqlCmd->Parameters->AddWithValue("@facultyID", globalFacultyID);
			db->sqlCmd->ExecuteNonQuery();
			db->sqlCmd->Parameters->Clear();
			db->sqlCmd->CommandText = "DELETE FROM user WHERE dbID=@facultyID";
			db->sqlCmd->Parameters->AddWithValue("@facultyID", globalFacultyID);
			db->sqlCmd->ExecuteNonQuery();
			db->sqlCmd->Parameters->Clear();
			db->Close();
			MessageBox::Show("Faculty member deleted successfully.");
			loadFaculty();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error deleting faculty: " + ex->ToString(), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void btnID_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			db->Open();
			int searchID = Convert::ToInt32(txtSearch->Text);
			db->sqlCmd->CommandText = "SELECT f.facultyID, u.firstName, u.lastName, u.email, u.phoneNumber, d.deptName FROM faculty f JOIN user u ON f.facultyID = u.dbID JOIN department d ON f.deptID = d.deptID WHERE f.facultyID = @searchID";
			db->sqlCmd->Parameters->AddWithValue("@searchID", searchID);
			db->sqlDR = db->sqlCmd->ExecuteReader();
			db->sqlDT->Clear();
			db->sqlDT->Load(db->sqlDR);
			dataGridView1->DataSource = db->sqlDT;
			db->sqlCmd->Parameters->Clear();
			dataGridView1->Columns[0]->Width = 50;
			dataGridView1->Columns[1]->Width = 200;
			dataGridView1->Columns[2]->Width = 200;
			dataGridView1->Columns[3]->Width = 200;
			dataGridView1->Columns[4]->Width = 200;
			dataGridView1->Columns[5]->Width = 200;
			db->sqlDR->Close();
		}
		catch (FormatException^) {
			MessageBox::Show("Please enter an integer.", "Input Error", MessageBoxButtons::OK,
				MessageBoxIcon::Warning);
		}
		catch (Exception^ e) {
			MessageBox::Show("Database Connection Error: " + e->ToString(), "Data Load Error", MessageBoxButtons::OK,
				MessageBoxIcon::Warning);
		}
	}
	private: System::Void btnName_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			db->Open();
			String^ searchName = txtSearch->Text;
			db->sqlCmd->CommandText = "SELECT f.facultyID, u.firstName, u.lastName, u.email, u.phoneNumber, d.deptName FROM faculty f JOIN user u ON f.facultyID = u.dbID JOIN department d ON f.deptID = d.deptID WHERE u.firstName LIKE @searchName OR u.lastName LIKE @searchName";
			db->sqlCmd->Parameters->AddWithValue("@searchName", "%" + searchName + "%");
			db->sqlDR = db->sqlCmd->ExecuteReader();
			db->sqlDT->Clear();
			db->sqlDT->Load(db->sqlDR);
			dataGridView1->DataSource = db->sqlDT;
			db->sqlCmd->Parameters->Clear();
			dataGridView1->Columns[0]->Width = 50;
			dataGridView1->Columns[1]->Width = 200;
			dataGridView1->Columns[2]->Width = 200;
			dataGridView1->Columns[3]->Width = 200;
			dataGridView1->Columns[4]->Width = 200;
			dataGridView1->Columns[5]->Width = 200;
			db->sqlDR->Close();
		}
		catch (Exception^ e) {
			MessageBox::Show("Database Connection Error: " + e->ToString(), "Data Load Error", MessageBoxButtons::OK,
				MessageBoxIcon::Warning);
		}
	}
	private: System::Void btnDepartment_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			db->Open();
			String^ searchDept = txtSearch->Text;
			db->sqlCmd->CommandText = "SELECT f.facultyID, u.firstName, u.lastName, u.email, u.phoneNumber, d.deptName FROM faculty f JOIN user u ON f.facultyID = u.dbID JOIN department d ON f.deptID = d.deptID WHERE d.deptName LIKE @searchDept";
			db->sqlCmd->Parameters->AddWithValue("@searchDept", "%" + searchDept + "%");
			db->sqlDR = db->sqlCmd->ExecuteReader();
			db->sqlDT->Clear();
			db->sqlDT->Load(db->sqlDR);
			dataGridView1->DataSource = db->sqlDT;
			db->sqlCmd->Parameters->Clear();
			dataGridView1->Columns[0]->Width = 50;
			dataGridView1->Columns[1]->Width = 200;
			dataGridView1->Columns[2]->Width = 200;
			dataGridView1->Columns[3]->Width = 200;
			dataGridView1->Columns[4]->Width = 200;
			dataGridView1->Columns[5]->Width = 200;
			db->sqlDR->Close();
		}
		catch (Exception^ e) {
			MessageBox::Show("Database Connection Error: " + e->ToString(), "Data Load Error", MessageBoxButtons::OK,
				MessageBoxIcon::Warning);
		}
	}
	private: System::Void btnDashboard_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnStudents_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnDepartments_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnCourses_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnProgrammes_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnEnrollment_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnPayments_Click(System::Object^ sender, System::EventArgs^ e);
};
}
