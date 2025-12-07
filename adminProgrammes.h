#pragma once
#include "Database.h"
#include "users.h"

namespace Group7FinalProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for adminProgrammes
	/// </summary>
	public ref class adminProgrammes : public System::Windows::Forms::Form
	{
		Database^ db = gcnew Database();
		User^ currentUser;
	private: System::Windows::Forms::Button^ btnDepartment;
	private: System::Windows::Forms::Button^ btnPayments;
	private: System::Windows::Forms::Button^ btnEnrollment;
	private: System::Windows::Forms::Button^ btnDepartments;

		   int globalprogID = -1;
	public:
		adminProgrammes(User^ user)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->currentUser = user;
			lblUser->Text = "Hello " + currentUser->name;
			ProgrammeTypeBox->Items->Add("Bsc");
			ProgrammeTypeBox->Items->Add("BA");
			ProgrammeTypeBox->Items->Add("PhD");
			ProgrammeTypeBox->Items->Add("Msc");
			ProgrammeTypeBox->Items->Add("MA");
			db->Open();
			String^ query = "SELECT deptName FROM Department";
			db->sqlCmd->CommandText = query;
			db->sqlDR = db->sqlCmd->ExecuteReader();
			while (db->sqlDR->Read()) {
				DepartmentBox->Items->Add(db->sqlDR->GetString("deptName"));
			}
			db->sqlDR->Close();
			db->Close();
			LoadProgrammes();
		}
		void LoadProgrammes() {
			try {
				db->Open();
				db->sqlCmd->CommandText = "SELECT p.progID, d.deptName , p.progName, p. programmeType FROM programme p JOIN department d ON p.deptID= d.deptID ORDER By progID DESC";
				db->sqlDR = db->sqlCmd->ExecuteReader();
				db->sqlDT->Clear();
				db->sqlDT->Load(db->sqlDR);
				dataGridView1->DataSource = db->sqlDT;
				dataGridView1->Columns[0]->Width = 50;
				dataGridView1->Columns[1]->Width = 200;
				dataGridView1->Columns[2]->Width = 200;
				dataGridView1->Columns[3]->Width = 200;
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
		~adminProgrammes()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnID;
	protected:
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

	private: System::Windows::Forms::Label^ lblUser;
	private: System::Windows::Forms::Button^ btnCourses;
	private: System::Windows::Forms::Button^ btnDashboard;
	private: System::Windows::Forms::Button^ btnFaculty;
	private: System::Windows::Forms::Button^ btnStudents;
	private: System::Windows::Forms::ComboBox^ DepartmentBox;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ txtProgramme;
	private: System::Windows::Forms::Label^ Program;
	private: System::Windows::Forms::ComboBox^ ProgrammeTypeBox;



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
			this->lblUser = (gcnew System::Windows::Forms::Label());
			this->btnCourses = (gcnew System::Windows::Forms::Button());
			this->btnDashboard = (gcnew System::Windows::Forms::Button());
			this->btnFaculty = (gcnew System::Windows::Forms::Button());
			this->btnStudents = (gcnew System::Windows::Forms::Button());
			this->DepartmentBox = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtProgramme = (gcnew System::Windows::Forms::TextBox());
			this->Program = (gcnew System::Windows::Forms::Label());
			this->ProgrammeTypeBox = (gcnew System::Windows::Forms::ComboBox());
			this->btnDepartment = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
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
			this->btnID->Location = System::Drawing::Point(1231, 1175);
			this->btnID->Name = L"btnID";
			this->btnID->Size = System::Drawing::Size(182, 50);
			this->btnID->TabIndex = 21;
			this->btnID->Text = L"By ID";
			this->btnID->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnID->UseVisualStyleBackColor = false;
			this->btnID->Click += gcnew System::EventHandler(this, &adminProgrammes::btnID_Click);
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
			this->btnName->Location = System::Drawing::Point(1436, 1175);
			this->btnName->Name = L"btnName";
			this->btnName->Size = System::Drawing::Size(182, 50);
			this->btnName->TabIndex = 20;
			this->btnName->Text = L"By Name";
			this->btnName->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnName->UseVisualStyleBackColor = false;
			this->btnName->Click += gcnew System::EventHandler(this, &adminProgrammes::btnName_Click);
			// 
			// txtSearch
			// 
			this->txtSearch->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtSearch->Location = System::Drawing::Point(575, 1179);
			this->txtSearch->Name = L"txtSearch";
			this->txtSearch->Size = System::Drawing::Size(605, 43);
			this->txtSearch->TabIndex = 19;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(381, 1179);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(101, 37);
			this->label2->TabIndex = 18;
			this->label2->Text = L"Search:";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(446, 626);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 82;
			this->dataGridView1->RowTemplate->Height = 33;
			this->dataGridView1->Size = System::Drawing::Size(1379, 498);
			this->dataGridView1->TabIndex = 17;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &adminProgrammes::dataGridView1_CellContentClick);
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
			this->btnDelete->Location = System::Drawing::Point(1060, 538);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(182, 50);
			this->btnDelete->TabIndex = 15;
			this->btnDelete->Text = L"Delete";
			this->btnDelete->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnDelete->UseVisualStyleBackColor = false;
			this->btnDelete->Click += gcnew System::EventHandler(this, &adminProgrammes::btnDelete_Click);
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
			this->btnUpdate->Location = System::Drawing::Point(779, 538);
			this->btnUpdate->Name = L"btnUpdate";
			this->btnUpdate->Size = System::Drawing::Size(182, 50);
			this->btnUpdate->TabIndex = 13;
			this->btnUpdate->Text = L"Update";
			this->btnUpdate->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnUpdate->UseVisualStyleBackColor = false;
			this->btnUpdate->Click += gcnew System::EventHandler(this, &adminProgrammes::btnUpdate_Click);
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
			this->btnSave->Location = System::Drawing::Point(500, 538);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(182, 50);
			this->btnSave->TabIndex = 12;
			this->btnSave->Text = L"Save";
			this->btnSave->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnSave->UseVisualStyleBackColor = false;
			this->btnSave->Click += gcnew System::EventHandler(this, &adminProgrammes::btnSave_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(392, 147);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(165, 37);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Department:";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->Controls->Add(this->lblWelcome);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(279, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1631, 80);
			this->panel2->TabIndex = 16;
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
			this->lblWelcome->Size = System::Drawing::Size(405, 45);
			this->lblWelcome->TabIndex = 0;
			this->lblWelcome->Text = L"Programme Management";
			this->lblWelcome->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Maroon;
			this->panel1->Controls->Add(this->btnDepartments);
			this->panel1->Controls->Add(this->btnPayments);
			this->panel1->Controls->Add(this->btnEnrollment);
			this->panel1->Controls->Add(this->lblUser);
			this->panel1->Controls->Add(this->btnCourses);
			this->panel1->Controls->Add(this->btnDashboard);
			this->panel1->Controls->Add(this->btnFaculty);
			this->panel1->Controls->Add(this->btnStudents);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(279, 1258);
			this->panel1->TabIndex = 14;
			// 
			// btnDepartments
			// 
			this->btnDepartments->FlatAppearance->BorderSize = 0;
			this->btnDepartments->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDepartments->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDepartments->ForeColor = System::Drawing::Color::White;
			this->btnDepartments->Location = System::Drawing::Point(27, 477);
			this->btnDepartments->Name = L"btnDepartments";
			this->btnDepartments->Size = System::Drawing::Size(228, 64);
			this->btnDepartments->TabIndex = 11;
			this->btnDepartments->Text = L"Departments";
			this->btnDepartments->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnDepartments->UseVisualStyleBackColor = true;
			this->btnDepartments->Click += gcnew System::EventHandler(this, &adminProgrammes::btnDepartments_Click);
			// 
			// btnPayments
			// 
			this->btnPayments->FlatAppearance->BorderSize = 0;
			this->btnPayments->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnPayments->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnPayments->ForeColor = System::Drawing::Color::White;
			this->btnPayments->Location = System::Drawing::Point(27, 726);
			this->btnPayments->Name = L"btnPayments";
			this->btnPayments->Size = System::Drawing::Size(228, 68);
			this->btnPayments->TabIndex = 10;
			this->btnPayments->Text = L"Payments";
			this->btnPayments->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnPayments->UseVisualStyleBackColor = true;
			this->btnPayments->Click += gcnew System::EventHandler(this, &adminProgrammes::btnPayments_Click);
			// 
			// btnEnrollment
			// 
			this->btnEnrollment->FlatAppearance->BorderSize = 0;
			this->btnEnrollment->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnEnrollment->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnEnrollment->ForeColor = System::Drawing::Color::White;
			this->btnEnrollment->Location = System::Drawing::Point(27, 645);
			this->btnEnrollment->Name = L"btnEnrollment";
			this->btnEnrollment->Size = System::Drawing::Size(182, 75);
			this->btnEnrollment->TabIndex = 9;
			this->btnEnrollment->Text = L"Enrollment";
			this->btnEnrollment->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnEnrollment->UseVisualStyleBackColor = true;
			this->btnEnrollment->Click += gcnew System::EventHandler(this, &adminProgrammes::btnEnrollment_Click);
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
			this->btnCourses->Location = System::Drawing::Point(27, 571);
			this->btnCourses->Name = L"btnCourses";
			this->btnCourses->Size = System::Drawing::Size(182, 50);
			this->btnCourses->TabIndex = 4;
			this->btnCourses->Text = L"Courses";
			this->btnCourses->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnCourses->UseVisualStyleBackColor = true;
			this->btnCourses->Click += gcnew System::EventHandler(this, &adminProgrammes::btnCourses_Click);
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
			this->btnDashboard->Click += gcnew System::EventHandler(this, &adminProgrammes::btnDashboard_Click);
			// 
			// btnFaculty
			// 
			this->btnFaculty->FlatAppearance->BorderSize = 0;
			this->btnFaculty->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnFaculty->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnFaculty->ForeColor = System::Drawing::Color::White;
			this->btnFaculty->Location = System::Drawing::Point(27, 373);
			this->btnFaculty->Name = L"btnFaculty";
			this->btnFaculty->Size = System::Drawing::Size(182, 86);
			this->btnFaculty->TabIndex = 2;
			this->btnFaculty->Text = L"Faculty";
			this->btnFaculty->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnFaculty->UseVisualStyleBackColor = true;
			this->btnFaculty->Click += gcnew System::EventHandler(this, &adminProgrammes::btnFaculty_Click);
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
			this->btnStudents->Click += gcnew System::EventHandler(this, &adminProgrammes::btnStudents_Click);
			// 
			// DepartmentBox
			// 
			this->DepartmentBox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DepartmentBox->FormattingEnabled = true;
			this->DepartmentBox->Location = System::Drawing::Point(639, 139);
			this->DepartmentBox->Name = L"DepartmentBox";
			this->DepartmentBox->Size = System::Drawing::Size(603, 45);
			this->DepartmentBox->TabIndex = 22;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(392, 262);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(162, 37);
			this->label3->TabIndex = 23;
			this->label3->Text = L"Programme:";
			// 
			// txtProgramme
			// 
			this->txtProgramme->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtProgramme->Location = System::Drawing::Point(637, 262);
			this->txtProgramme->Name = L"txtProgramme";
			this->txtProgramme->Size = System::Drawing::Size(605, 43);
			this->txtProgramme->TabIndex = 24;
			// 
			// Program
			// 
			this->Program->AutoSize = true;
			this->Program->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Program->Location = System::Drawing::Point(392, 388);
			this->Program->Name = L"Program";
			this->Program->Size = System::Drawing::Size(225, 37);
			this->Program->TabIndex = 25;
			this->Program->Text = L"Programme Type:";
			// 
			// ProgrammeTypeBox
			// 
			this->ProgrammeTypeBox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ProgrammeTypeBox->FormattingEnabled = true;
			this->ProgrammeTypeBox->Location = System::Drawing::Point(637, 388);
			this->ProgrammeTypeBox->Name = L"ProgrammeTypeBox";
			this->ProgrammeTypeBox->Size = System::Drawing::Size(167, 45);
			this->ProgrammeTypeBox->TabIndex = 26;
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
			this->btnDepartment->Location = System::Drawing::Point(1643, 1175);
			this->btnDepartment->Name = L"btnDepartment";
			this->btnDepartment->Size = System::Drawing::Size(236, 50);
			this->btnDepartment->TabIndex = 27;
			this->btnDepartment->Text = L"By Department";
			this->btnDepartment->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnDepartment->UseVisualStyleBackColor = false;
			this->btnDepartment->Click += gcnew System::EventHandler(this, &adminProgrammes::btnDepartment_Click);
			// 
			// adminProgrammes
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1910, 1258);
			this->Controls->Add(this->btnDepartment);
			this->Controls->Add(this->ProgrammeTypeBox);
			this->Controls->Add(this->Program);
			this->Controls->Add(this->txtProgramme);
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
			this->Name = L"adminProgrammes";
			this->Text = L"adminProgrammes";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			db->Open();
			String^ selectedDept = DepartmentBox->SelectedItem->ToString();
			db->sqlCmd->CommandText = "SELECT deptID FROM department WHERE deptName=@deptName";
			db->sqlCmd->Parameters->AddWithValue("@deptName", selectedDept);
			int deptID = (int)db->sqlCmd->ExecuteScalar();
			db->sqlCmd->Parameters->Clear();
			String^ progName = txtProgramme->Text;
			String^ progType = ProgrammeTypeBox->SelectedItem->ToString();
			db->sqlCmd->CommandText = "INSERT INTO programme (deptID, progName, programmeType) VALUES (@deptID, @progName, @progType)";
			db->sqlCmd->Parameters->AddWithValue("@deptID", deptID);
			db->sqlCmd->Parameters->AddWithValue("@progName", progName);
			db->sqlCmd->Parameters->AddWithValue("@progType", progType);
			db->sqlCmd->ExecuteNonQuery();
			db->sqlCmd->Parameters->Clear();
			db->Close();
			MessageBox::Show("Programme added successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
			LoadProgrammes();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error adding programme: " + ex->ToString(), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (e->RowIndex >= 0) {
			DataGridViewRow^ row = dataGridView1->Rows[e->RowIndex];
			globalprogID = Convert::ToInt32(row->Cells["progID"]->Value);
			DepartmentBox->SelectedItem = row->Cells["deptName"]->Value->ToString();
			txtProgramme->Text = row->Cells["progName"]->Value->ToString();
			ProgrammeTypeBox->SelectedItem = row->Cells["programmeType"]->Value->ToString();
		}
	}
	private: System::Void btnUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
		if (globalprogID == -1) {
			MessageBox::Show("Please select a programme to update.", "No Selection", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		try {
			db->Open();
			String^ selectedDept = DepartmentBox->SelectedItem->ToString();
			db->sqlCmd->CommandText = "SELECT deptID FROM department WHERE deptName=@deptName";
			db->sqlCmd->Parameters->AddWithValue("@deptName", selectedDept);
			int deptID = (int)db->sqlCmd->ExecuteScalar();
			db->sqlCmd->Parameters->Clear();
			String^ progName = txtProgramme->Text;
			String^ progType = ProgrammeTypeBox->SelectedItem->ToString();
			db->sqlCmd->CommandText = "UPDATE programme SET deptID=@deptID, progName=@progName, programmeType=@progType WHERE progID=@progID";
			db->sqlCmd->Parameters->AddWithValue("@deptID", deptID);
			db->sqlCmd->Parameters->AddWithValue("@progName", progName);
			db->sqlCmd->Parameters->AddWithValue("@progType", progType);
			db->sqlCmd->Parameters->AddWithValue("@progID", globalprogID);
			db->sqlCmd->ExecuteNonQuery();
			db->sqlCmd->Parameters->Clear();
			db->Close();
			MessageBox::Show("Programme updated successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
			LoadProgrammes();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error updating programme: " + ex->ToString(), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e) {
		if (globalprogID == -1) {
			MessageBox::Show("Please select a programme to delete.", "No Selection", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		try {
			db->Open();
			db->sqlCmd->CommandText = "DELETE FROM programme WHERE progID=@progID";
			db->sqlCmd->Parameters->AddWithValue("@progID", globalprogID);
			db->sqlCmd->ExecuteNonQuery();
			db->sqlCmd->Parameters->Clear();
			db->Close();
			MessageBox::Show("Programme deleted successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
			LoadProgrammes();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error deleting programme: " + ex->ToString(), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void btnID_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			db->Open();
			int searchID = Convert::ToInt32(txtSearch->Text);
			db->sqlCmd->CommandText = "SELECT p.progID, d.deptName , p.progName, p. programmeType FROM programme p JOIN department d ON p.deptID= d.deptID WHERE p.progID=@progID";
			db->sqlCmd->Parameters->AddWithValue("@progID", searchID);
			db->sqlCmd->Parameters->Clear();
			db->sqlDR = db->sqlCmd->ExecuteReader();
			db->sqlDT->Clear();
			db->sqlDT->Load(db->sqlDR);
			dataGridView1->DataSource = db->sqlDT;
			dataGridView1->Columns[0]->Width = 50;
			dataGridView1->Columns[1]->Width = 200;
			dataGridView1->Columns[2]->Width = 200;
			dataGridView1->Columns[3]->Width = 200;
			db->sqlDR->Close();
			db->Close();
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
			db->sqlCmd->CommandText = "SELECT p.progID, d.deptName , p.progName, p. programmeType FROM programme p JOIN department d ON p.deptID= d.deptID WHERE p.progName LIKE @progName";
			db->sqlCmd->Parameters->Clear();
			db->sqlCmd->Parameters->AddWithValue("@progName", "%" + searchName + "%");
			db->sqlDR = db->sqlCmd->ExecuteReader();
			db->sqlDT->Clear();
			db->sqlDT->Load(db->sqlDR);
			dataGridView1->DataSource = db->sqlDT;
			dataGridView1->Columns[0]->Width = 50;
			dataGridView1->Columns[1]->Width = 200;
			dataGridView1->Columns[2]->Width = 200;
			dataGridView1->Columns[3]->Width = 200;
			db->sqlDR->Close();
			db->Close();
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
			db->sqlCmd->CommandText = "SELECT p.progID, d.deptName , p.progName, p. programmeType FROM programme p JOIN department d ON p.deptID= d.deptID WHERE d.deptName LIKE @deptName";
			db->sqlCmd->Parameters->Clear();
			db->sqlCmd->Parameters->AddWithValue("@deptName", "%" + searchDept + "%");
			db->sqlDR = db->sqlCmd->ExecuteReader();
			db->sqlDT->Clear();
			db->sqlDT->Load(db->sqlDR);
			dataGridView1->DataSource = db->sqlDT;
			dataGridView1->Columns[0]->Width = 50;
			dataGridView1->Columns[1]->Width = 200;
			dataGridView1->Columns[2]->Width = 200;
			dataGridView1->Columns[3]->Width = 200;
			db->sqlDR->Close();
			db->Close();
		}
		catch (Exception^ e) {
			MessageBox::Show("Database Connection Error: " + e->ToString(), "Data Load Error", MessageBoxButtons::OK,
				MessageBoxIcon::Warning);
		}
	}
	private: System::Void btnDashboard_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnStudents_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnFaculty_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnCourses_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnDepartments_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnEnrollment_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnPayments_Click(System::Object^ sender, System::EventArgs^ e);
};
}
