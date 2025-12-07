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
	/// Summary for adminCourses
	/// </summary>
	public ref class adminCourses : public System::Windows::Forms::Form
	{
		Database^ db = gcnew Database();
		int globalCourseID = -1;
	private: System::Windows::Forms::ComboBox^ SemesterBox;

	private: System::Windows::Forms::Label^ label7;
		   User^ currentUser;
	public:
		adminCourses(User^ user)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->currentUser = user;
			lblUser->Text = "Hello " + currentUser->name;
			db->Open();
			db->sqlCmd->CommandText= "SELECT progID, progName FROM programme";
			db->sqlDR = db->sqlCmd->ExecuteReader();
			DataTable^ progTable = gcnew DataTable();
			progTable->Load(db->sqlDR);
			ProgrammeBox->DataSource = progTable;
			ProgrammeBox->ValueMember = "progID";
			ProgrammeBox->DisplayMember = "progName";
			db->sqlDR->Close();
			db->Close();
			LevelBox->Items->Add("100");
			LevelBox->Items->Add("200");
			LevelBox->Items->Add("300");
			LevelBox->Items->Add("400");
			SemesterBox->Items->Add("Spring");
			SemesterBox->Items->Add("Fall");
			SemesterBox->Items->Add("Summer");
			CreditBox->Items->Add("1");
			CreditBox->Items->Add("2");
			CreditBox->Items->Add("3");
			CreditBox->Items->Add("4");
			db->Open();
			db->sqlCmd->CommandText = "SELECT f.facultyID, concat(u.firstName, ' ',u.lastName) as fName FROM faculty f JOIN user u ON f.facultyID=u.dbID";
			db->sqlDR = db->sqlCmd->ExecuteReader();
			DataTable^ facultyTable = gcnew DataTable();
			facultyTable->Load(db->sqlDR);
			FacultyBox->DataSource = facultyTable;
			FacultyBox->ValueMember = "facultyID";
			FacultyBox->DisplayMember = "fName";
			db->sqlDR->Close();
			db->Close();
			loadCourses();
		}
		void loadCourses() {
			try
			{
				db->Open();
				db->sqlCmd->CommandText = "SELECT c.courseID,c.courseCode, c.CourseTitle, c.level, p.progName, concat(u.firstName, ' ', u.lastName) as Faculty, c.semester, c.credit, c.progID, c.facultyID FROM course c JOIN programme p ON c.progID=p.progID JOIN user u ON u.dbID=c.facultyID";
				db->sqlDR = db->sqlCmd->ExecuteReader();
				db->sqlDT->Clear();
				db->sqlDT->Load(db->sqlDR);
				dataGridView1->DataSource = db->sqlDT;
				dataGridView1->Columns[0]->Visible = false;
				dataGridView1->Columns[1]->Width = 80;
				dataGridView1->Columns[2]->Width = 150;
				dataGridView1->Columns[3]->Width = 50;
				dataGridView1->Columns[4]->Width = 200;
				dataGridView1->Columns[5]->Width = 150;
				dataGridView1->Columns[6]->Width = 80;
				dataGridView1->Columns[7]->Width = 50;
				dataGridView1->Columns[8]->Visible = false;
				dataGridView1->Columns[9]->Visible = false;
				db->sqlDR->Close();
				db->sqlCmd->Cancel();
				db->Close();
			}
			catch (Exception^ e)
			{
				MessageBox::Show("Error: " + e->Message);
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~adminCourses()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnProgram;
	protected:

	private: System::Windows::Forms::ComboBox^ CreditBox;
	protected:

	private: System::Windows::Forms::Label^ Program;
	private: System::Windows::Forms::TextBox^ txtCourseCode;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ComboBox^ ProgrammeBox;
	private: System::Windows::Forms::Button^ btnCode;
	private: System::Windows::Forms::Button^ btnTitle;



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
	private: System::Windows::Forms::Button^ btnFaculty;
	private: System::Windows::Forms::Button^ btnStudents;
	private: System::Windows::Forms::ComboBox^ LevelBox;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ txtCourseTitle;

	private: System::Windows::Forms::Label^ label5;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::ComboBox^ FacultyBox;
	private: System::Windows::Forms::Button^ btnLevel;


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
			this->btnProgram = (gcnew System::Windows::Forms::Button());
			this->CreditBox = (gcnew System::Windows::Forms::ComboBox());
			this->Program = (gcnew System::Windows::Forms::Label());
			this->txtCourseCode = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->ProgrammeBox = (gcnew System::Windows::Forms::ComboBox());
			this->btnCode = (gcnew System::Windows::Forms::Button());
			this->btnTitle = (gcnew System::Windows::Forms::Button());
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
			this->btnProgrammes = (gcnew System::Windows::Forms::Button());
			this->lblUser = (gcnew System::Windows::Forms::Label());
			this->btnCourses = (gcnew System::Windows::Forms::Button());
			this->btnDashboard = (gcnew System::Windows::Forms::Button());
			this->btnFaculty = (gcnew System::Windows::Forms::Button());
			this->btnStudents = (gcnew System::Windows::Forms::Button());
			this->LevelBox = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtCourseTitle = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->FacultyBox = (gcnew System::Windows::Forms::ComboBox());
			this->btnLevel = (gcnew System::Windows::Forms::Button());
			this->SemesterBox = (gcnew System::Windows::Forms::ComboBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnProgram
			// 
			this->btnProgram->BackColor = System::Drawing::Color::Maroon;
			this->btnProgram->FlatAppearance->BorderColor = System::Drawing::Color::Maroon;
			this->btnProgram->FlatAppearance->BorderSize = 0;
			this->btnProgram->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnProgram->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnProgram->ForeColor = System::Drawing::Color::White;
			this->btnProgram->Location = System::Drawing::Point(1643, 1147);
			this->btnProgram->Name = L"btnProgram";
			this->btnProgram->Size = System::Drawing::Size(236, 50);
			this->btnProgram->TabIndex = 44;
			this->btnProgram->Text = L"By Programme";
			this->btnProgram->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnProgram->UseVisualStyleBackColor = false;
			this->btnProgram->Click += gcnew System::EventHandler(this, &adminCourses::btnProgram_Click);
			// 
			// CreditBox
			// 
			this->CreditBox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CreditBox->FormattingEnabled = true;
			this->CreditBox->Location = System::Drawing::Point(637, 419);
			this->CreditBox->Name = L"CreditBox";
			this->CreditBox->Size = System::Drawing::Size(167, 45);
			this->CreditBox->TabIndex = 43;
			// 
			// Program
			// 
			this->Program->AutoSize = true;
			this->Program->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Program->Location = System::Drawing::Point(392, 419);
			this->Program->Name = L"Program";
			this->Program->Size = System::Drawing::Size(195, 37);
			this->Program->TabIndex = 42;
			this->Program->Text = L"Course Credits:";
			// 
			// txtCourseCode
			// 
			this->txtCourseCode->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtCourseCode->Location = System::Drawing::Point(637, 293);
			this->txtCourseCode->Name = L"txtCourseCode";
			this->txtCourseCode->Size = System::Drawing::Size(605, 43);
			this->txtCourseCode->TabIndex = 41;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(392, 119);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(162, 37);
			this->label3->TabIndex = 40;
			this->label3->Text = L"Programme:";
			// 
			// ProgrammeBox
			// 
			this->ProgrammeBox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ProgrammeBox->FormattingEnabled = true;
			this->ProgrammeBox->Location = System::Drawing::Point(639, 111);
			this->ProgrammeBox->Name = L"ProgrammeBox";
			this->ProgrammeBox->Size = System::Drawing::Size(603, 45);
			this->ProgrammeBox->TabIndex = 39;
			// 
			// btnCode
			// 
			this->btnCode->BackColor = System::Drawing::Color::Maroon;
			this->btnCode->FlatAppearance->BorderColor = System::Drawing::Color::Maroon;
			this->btnCode->FlatAppearance->BorderSize = 0;
			this->btnCode->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCode->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCode->ForeColor = System::Drawing::Color::White;
			this->btnCode->Location = System::Drawing::Point(1231, 1147);
			this->btnCode->Name = L"btnCode";
			this->btnCode->Size = System::Drawing::Size(182, 50);
			this->btnCode->TabIndex = 38;
			this->btnCode->Text = L"By Code";
			this->btnCode->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnCode->UseVisualStyleBackColor = false;
			this->btnCode->Click += gcnew System::EventHandler(this, &adminCourses::btnCode_Click);
			// 
			// btnTitle
			// 
			this->btnTitle->BackColor = System::Drawing::Color::Maroon;
			this->btnTitle->FlatAppearance->BorderColor = System::Drawing::Color::Maroon;
			this->btnTitle->FlatAppearance->BorderSize = 0;
			this->btnTitle->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnTitle->ForeColor = System::Drawing::Color::White;
			this->btnTitle->Location = System::Drawing::Point(1436, 1147);
			this->btnTitle->Name = L"btnTitle";
			this->btnTitle->Size = System::Drawing::Size(182, 50);
			this->btnTitle->TabIndex = 37;
			this->btnTitle->Text = L"By Title";
			this->btnTitle->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnTitle->UseVisualStyleBackColor = false;
			this->btnTitle->Click += gcnew System::EventHandler(this, &adminCourses::btnTitle_Click);
			// 
			// txtSearch
			// 
			this->txtSearch->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtSearch->Location = System::Drawing::Point(575, 1151);
			this->txtSearch->Name = L"txtSearch";
			this->txtSearch->Size = System::Drawing::Size(605, 43);
			this->txtSearch->TabIndex = 36;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(381, 1151);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(101, 37);
			this->label2->TabIndex = 35;
			this->label2->Text = L"Search:";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(399, 639);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 82;
			this->dataGridView1->RowTemplate->Height = 33;
			this->dataGridView1->Size = System::Drawing::Size(1678, 457);
			this->dataGridView1->TabIndex = 34;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &adminCourses::dataGridView1_CellContentClick);
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
			this->btnDelete->Location = System::Drawing::Point(1060, 569);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(182, 50);
			this->btnDelete->TabIndex = 32;
			this->btnDelete->Text = L"Delete";
			this->btnDelete->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnDelete->UseVisualStyleBackColor = false;
			this->btnDelete->Click += gcnew System::EventHandler(this, &adminCourses::btnDelete_Click);
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
			this->btnUpdate->Location = System::Drawing::Point(779, 569);
			this->btnUpdate->Name = L"btnUpdate";
			this->btnUpdate->Size = System::Drawing::Size(182, 50);
			this->btnUpdate->TabIndex = 30;
			this->btnUpdate->Text = L"Update";
			this->btnUpdate->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnUpdate->UseVisualStyleBackColor = false;
			this->btnUpdate->Click += gcnew System::EventHandler(this, &adminCourses::btnUpdate_Click);
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
			this->btnSave->Location = System::Drawing::Point(500, 569);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(182, 50);
			this->btnSave->TabIndex = 29;
			this->btnSave->Text = L"Save";
			this->btnSave->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnSave->UseVisualStyleBackColor = false;
			this->btnSave->Click += gcnew System::EventHandler(this, &adminCourses::btnSave_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(392, 293);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(175, 37);
			this->label1->TabIndex = 28;
			this->label1->Text = L"Course Code:";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->Controls->Add(this->lblWelcome);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(279, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1866, 80);
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
			this->lblWelcome->Size = System::Drawing::Size(405, 45);
			this->lblWelcome->TabIndex = 0;
			this->lblWelcome->Text = L"Programme Management";
			this->lblWelcome->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Maroon;
			this->panel1->Controls->Add(this->btnProgrammes);
			this->panel1->Controls->Add(this->lblUser);
			this->panel1->Controls->Add(this->btnCourses);
			this->panel1->Controls->Add(this->btnDashboard);
			this->panel1->Controls->Add(this->btnFaculty);
			this->panel1->Controls->Add(this->btnStudents);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(279, 1282);
			this->panel1->TabIndex = 31;
			// 
			// btnProgrammes
			// 
			this->btnProgrammes->FlatAppearance->BorderSize = 0;
			this->btnProgrammes->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnProgrammes->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnProgrammes->ForeColor = System::Drawing::Color::White;
			this->btnProgrammes->Location = System::Drawing::Point(27, 639);
			this->btnProgrammes->Name = L"btnProgrammes";
			this->btnProgrammes->Size = System::Drawing::Size(206, 80);
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
			this->btnCourses->Location = System::Drawing::Point(27, 538);
			this->btnCourses->Name = L"btnCourses";
			this->btnCourses->Size = System::Drawing::Size(182, 50);
			this->btnCourses->TabIndex = 4;
			this->btnCourses->Text = L"Courses";
			this->btnCourses->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnCourses->UseVisualStyleBackColor = true;
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
			// 
			// btnFaculty
			// 
			this->btnFaculty->FlatAppearance->BorderSize = 0;
			this->btnFaculty->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnFaculty->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnFaculty->ForeColor = System::Drawing::Color::White;
			this->btnFaculty->Location = System::Drawing::Point(27, 409);
			this->btnFaculty->Name = L"btnFaculty";
			this->btnFaculty->Size = System::Drawing::Size(182, 86);
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
			this->btnStudents->Location = System::Drawing::Point(27, 317);
			this->btnStudents->Name = L"btnStudents";
			this->btnStudents->Size = System::Drawing::Size(182, 50);
			this->btnStudents->TabIndex = 0;
			this->btnStudents->Text = L"Students";
			this->btnStudents->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnStudents->UseVisualStyleBackColor = true;
			// 
			// LevelBox
			// 
			this->LevelBox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LevelBox->FormattingEnabled = true;
			this->LevelBox->Location = System::Drawing::Point(637, 171);
			this->LevelBox->Name = L"LevelBox";
			this->LevelBox->Size = System::Drawing::Size(167, 45);
			this->LevelBox->TabIndex = 46;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(392, 171);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(84, 37);
			this->label4->TabIndex = 45;
			this->label4->Text = L"Level:";
			// 
			// txtCourseTitle
			// 
			this->txtCourseTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtCourseTitle->Location = System::Drawing::Point(637, 357);
			this->txtCourseTitle->Name = L"txtCourseTitle";
			this->txtCourseTitle->Size = System::Drawing::Size(605, 43);
			this->txtCourseTitle->TabIndex = 48;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(392, 357);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(163, 37);
			this->label5->TabIndex = 47;
			this->label5->Text = L"Course Title:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(392, 490);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(105, 37);
			this->label6->TabIndex = 49;
			this->label6->Text = L"Faculty:";
			// 
			// FacultyBox
			// 
			this->FacultyBox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FacultyBox->FormattingEnabled = true;
			this->FacultyBox->Location = System::Drawing::Point(639, 490);
			this->FacultyBox->Name = L"FacultyBox";
			this->FacultyBox->Size = System::Drawing::Size(603, 45);
			this->FacultyBox->TabIndex = 50;
			// 
			// btnLevel
			// 
			this->btnLevel->BackColor = System::Drawing::Color::Maroon;
			this->btnLevel->FlatAppearance->BorderColor = System::Drawing::Color::Maroon;
			this->btnLevel->FlatAppearance->BorderSize = 0;
			this->btnLevel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnLevel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnLevel->ForeColor = System::Drawing::Color::White;
			this->btnLevel->Location = System::Drawing::Point(1902, 1147);
			this->btnLevel->Name = L"btnLevel";
			this->btnLevel->Size = System::Drawing::Size(175, 50);
			this->btnLevel->TabIndex = 51;
			this->btnLevel->Text = L"By Level";
			this->btnLevel->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnLevel->UseVisualStyleBackColor = false;
			this->btnLevel->Click += gcnew System::EventHandler(this, &adminCourses::btnLevel_Click);
			// 
			// SemesterBox
			// 
			this->SemesterBox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SemesterBox->FormattingEnabled = true;
			this->SemesterBox->Location = System::Drawing::Point(637, 238);
			this->SemesterBox->Name = L"SemesterBox";
			this->SemesterBox->Size = System::Drawing::Size(233, 45);
			this->SemesterBox->TabIndex = 53;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(392, 238);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(131, 37);
			this->label7->TabIndex = 52;
			this->label7->Text = L"Semester:";
			// 
			// adminCourses
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(2145, 1282);
			this->Controls->Add(this->SemesterBox);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->btnLevel);
			this->Controls->Add(this->FacultyBox);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->txtCourseTitle);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->LevelBox);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->btnProgram);
			this->Controls->Add(this->CreditBox);
			this->Controls->Add(this->Program);
			this->Controls->Add(this->txtCourseCode);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->ProgrammeBox);
			this->Controls->Add(this->btnCode);
			this->Controls->Add(this->btnTitle);
			this->Controls->Add(this->txtSearch);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->btnDelete);
			this->Controls->Add(this->btnUpdate);
			this->Controls->Add(this->btnSave);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"adminCourses";
			this->Text = L"adminCourses";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void btnDashboard_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void btnDepartment_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e) {
			try {
				int programmeID = Convert::ToInt32(ProgrammeBox->SelectedValue);
				int courseLevel = Convert::ToInt32(LevelBox->Text);
				int facultyID = Convert::ToInt32(FacultyBox->SelectedValue);
				String^ courseCode = txtCourseCode->Text;
				String^ courseTitle = txtCourseTitle->Text;
				int courseCredits = Convert::ToInt32(CreditBox->Text);
				String^ semester = SemesterBox->Text->ToString();

				db->Open();
				db->sqlCmd->CommandText = "INSERT INTO course (progID, facultyID, courseCode, courseTitle, level, semester, credit) VALUES (@progID, @facultyID, @cCode, @cTitle, @level, @sem, @credit)";
				db->sqlCmd->Parameters->AddWithValue("@progID",programmeID);
				db->sqlCmd->Parameters->AddWithValue("@facultyID", facultyID);
				db->sqlCmd->Parameters->AddWithValue("@cCode", courseCode);
				db->sqlCmd->Parameters->AddWithValue("@cTitle", courseTitle);
				db->sqlCmd->Parameters->AddWithValue("@level", courseLevel);
				db->sqlCmd->Parameters->AddWithValue("@sem", semester);
				db->sqlCmd->Parameters->AddWithValue("@credit", courseCredits);
				db->sqlCmd->ExecuteNonQuery();
				db->sqlCmd->Parameters->Clear();
				db->Close();
				loadCourses();
				MessageBox::Show("Course saved successfully.");

			} catch (System::Exception^ ex) {
				MessageBox::Show(ex->Message, L"Error:", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		private: System::Void btnUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
			try {
				int programmeID = Convert::ToInt32(ProgrammeBox->SelectedValue);
				int courseLevel = Convert::ToInt32(LevelBox->Text);
				int facultyID = Convert::ToInt32(FacultyBox->SelectedValue);
				String^ courseCode = txtCourseCode->Text;
				String^ courseTitle = txtCourseTitle->Text;
				int courseCredits = Convert::ToInt32(CreditBox->Text);
				String^ semester = SemesterBox->Text->ToString();
				db->Open();
				db->sqlCmd->CommandText = "UPDATE course SET progID=@progID, facultyID=@facultyID, courseTitle=@cTitle, level=@level, semester=@sem, credit=@credit WHERE courseCode=@cCode";
				db->sqlCmd->Parameters->AddWithValue("@progID", programmeID);
				db->sqlCmd->Parameters->AddWithValue("@facultyID", facultyID);
				db->sqlCmd->Parameters->AddWithValue("@cCode", courseCode);
				db->sqlCmd->Parameters->AddWithValue("@cTitle", courseTitle);
				db->sqlCmd->Parameters->AddWithValue("@level", courseLevel);
				db->sqlCmd->Parameters->AddWithValue("@sem", semester);
				db->sqlCmd->Parameters->AddWithValue("@credit", courseCredits);
				db->sqlCmd->ExecuteNonQuery();
				db->sqlCmd->Parameters->Clear();
				db->Close();
				loadCourses();
				MessageBox::Show("Course updated successfully.");
			}
			catch (System::Exception^ ex) {
				MessageBox::Show(ex->Message, L"Error:", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
			if (e->RowIndex>=0)
			{
				DataGridViewRow^ row = this->dataGridView1->Rows[e->RowIndex];
				globalCourseID = Convert::ToInt32(row->Cells["courseID"]->Value->ToString());
				LevelBox->Text = row->Cells["level"]->Value->ToString();
				txtCourseCode->Text = row->Cells["courseCode"]->Value->ToString();
				txtCourseTitle->Text = row->Cells["courseTitle"]->Value->ToString();
				CreditBox->Text = row->Cells["credit"]->Value->ToString();
				ProgrammeBox->SelectedValue = row->Cells["progID"]->Value->ToString();
				FacultyBox->SelectedValue = row->Cells["facultyID"]->Value->ToString();
				SemesterBox->Text = row->Cells["semester"]->Value->ToString();
			}
		}
	private: System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			db->Open();
			db->sqlCmd->CommandText = "DELETE FROM course WHERE courseID=@cID";
			db->sqlCmd->Parameters->AddWithValue("@cID", globalCourseID);
			db->sqlCmd->ExecuteNonQuery();
			db->sqlCmd->Parameters->Clear();
			db->Close();
			loadCourses();
			MessageBox::Show("Course deleted successfully.");
		}
		catch (System::Exception^ ex) {
			MessageBox::Show(ex->Message, L"Error:", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void btnCode_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			String^ searchTerm = txtSearch->Text;
			db->Open();
			db->sqlCmd->CommandText = "SELECT c.courseID, c.courseCode, c.CourseTitle, c.level, p.progName, concat(u.firstName, ' ', u.lastName) as Faculty, c.semester, c.credit, c.progID, c.facultyID FROM course c JOIN programme p ON c.progID = p.progID JOIN user u ON u.dbID = c.facultyID WHERE c.courseCode LIKE @searchTerm";
			db->sqlCmd->Parameters->AddWithValue("@searchTerm", "%" + searchTerm + "%");
			db->sqlDA->SelectCommand = db->sqlCmd;
			db->sqlDA->Fill(db->sqlDT);
			dataGridView1->DataSource = db->sqlDT;
			dataGridView1->Columns[0]->Visible = false;
			dataGridView1->Columns[1]->Width = 80;
			dataGridView1->Columns[2]->Width = 150;
			dataGridView1->Columns[3]->Width = 50;
			dataGridView1->Columns[4]->Width = 200;
			dataGridView1->Columns[5]->Width = 150;
			dataGridView1->Columns[6]->Width = 80;
			dataGridView1->Columns[7]->Width = 50;
			dataGridView1->Columns[8]->Visible = false;
			dataGridView1->Columns[9]->Visible = false;
			db->sqlCmd->Parameters->Clear();
			db->Close();
		}
		catch (System::Exception^ ex) {
			MessageBox::Show(ex->Message, L"Error:", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void btnTitle_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			String^ searchTerm = txtSearch->Text;
			db->Open();
			db->sqlCmd->CommandText = "SELECT c.courseID, c.courseCode, c.CourseTitle, c.level, p.progName, concat(u.firstName, ' ', u.lastName) as Faculty, c.semester, c.credit, c.progID, c.facultyID FROM course c JOIN programme p ON c.progID = p.progID JOIN user u ON u.dbID = c.facultyID WHERE c.courseTitle LIKE @searchTerm";
			db->sqlCmd->Parameters->AddWithValue("@searchTerm", "%" + searchTerm + "%");
			db->sqlDA->SelectCommand = db->sqlCmd;
			db->sqlDA->Fill(db->sqlDT);
			dataGridView1->DataSource = db->sqlDT;
			dataGridView1->Columns[0]->Visible = false;
			dataGridView1->Columns[1]->Width = 80;
			dataGridView1->Columns[2]->Width = 150;
			dataGridView1->Columns[3]->Width = 50;
			dataGridView1->Columns[4]->Width = 200;
			dataGridView1->Columns[5]->Width = 150;
			dataGridView1->Columns[6]->Width = 80;
			dataGridView1->Columns[7]->Width = 50;
			dataGridView1->Columns[8]->Visible = false;
			dataGridView1->Columns[9]->Visible = false;
			db->sqlCmd->Parameters->Clear();
			db->Close();
		}
		catch (System::Exception^ ex) {
			MessageBox::Show(ex->Message, L"Error:", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void btnProgram_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			String^ searchTerm = txtSearch->Text;
			db->Open();
			db->sqlCmd->CommandText = "SELECT c.courseID, c.courseCode, c.CourseTitle, c.level, p.progName, concat(u.firstName, ' ', u.lastName) as Faculty, c.semester, c.credit, c.progID, c.facultyID FROM course c JOIN programme p ON c.progID = p.progID JOIN user u ON u.dbID = c.facultyID WHERE p.progName LIKE @searchTerm";
			db->sqlCmd->Parameters->AddWithValue("@searchTerm", "%" + searchTerm + "%");
			db->sqlDA->SelectCommand = db->sqlCmd;
			db->sqlDA->Fill(db->sqlDT);
			dataGridView1->DataSource = db->sqlDT;
			dataGridView1->Columns[0]->Visible = false;
			dataGridView1->Columns[1]->Width = 80;
			dataGridView1->Columns[2]->Width = 150;
			dataGridView1->Columns[3]->Width = 50;
			dataGridView1->Columns[4]->Width = 200;
			dataGridView1->Columns[5]->Width = 150;
			dataGridView1->Columns[6]->Width = 80;
			dataGridView1->Columns[7]->Width = 50;
			dataGridView1->Columns[8]->Visible = false;
			dataGridView1->Columns[9]->Visible = false;
			db->sqlCmd->Parameters->Clear();
			db->Close();
		}
		catch (System::Exception^ ex) {
			MessageBox::Show(ex->Message, L"Error:", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void btnLevel_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			String^ searchTerm = txtSearch->Text;
			db->Open();
			db->sqlCmd->CommandText = "SELECT c.courseID, c.courseCode, c.CourseTitle, c.level, p.progName, concat(u.firstName, ' ', u.lastName) as Faculty, c.semester, c.credit, c.progID, c.facultyID FROM course c JOIN programme p ON c.progID = p.progID JOIN user u ON u.dbID = c.facultyID WHERE c.level LIKE @searchTerm";
			db->sqlCmd->Parameters->AddWithValue("@searchTerm", "%" + searchTerm + "%");
			db->sqlDA->SelectCommand = db->sqlCmd;
			db->sqlDA->Fill(db->sqlDT);
			dataGridView1->DataSource = db->sqlDT;
			dataGridView1->Columns[0]->Visible = false;
			dataGridView1->Columns[1]->Width = 80;
			dataGridView1->Columns[2]->Width = 150;
			dataGridView1->Columns[3]->Width = 50;
			dataGridView1->Columns[4]->Width = 200;
			dataGridView1->Columns[5]->Width = 150;
			dataGridView1->Columns[6]->Width = 80;
			dataGridView1->Columns[7]->Width = 50;
			dataGridView1->Columns[8]->Visible = false;
			dataGridView1->Columns[9]->Visible = false;
			db->sqlCmd->Parameters->Clear();
			db->Close();
		}
		catch (System::Exception^ ex) {
			MessageBox::Show(ex->Message, L"Error:", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
};
}
