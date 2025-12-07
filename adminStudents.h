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
	/// Summary for adminStudents
	/// </summary>
	public ref class adminStudents : public System::Windows::Forms::Form
	{
		Database^ db = gcnew Database();
		User^ currentUser;
	private: System::Windows::Forms::Button^ btnPayments;
	private: System::Windows::Forms::Button^ btnEnrollment;
	private: System::Windows::Forms::Button^ btnDepartment;
		   int globalStudentID = -1;
	public:
		adminStudents(User^ user)
		{
			this->currentUser = user;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			lblUser->Text = "Hello " + currentUser->name;
			LevelBox->Items->Add("100");
			LevelBox->Items->Add("200");
			LevelBox->Items->Add("300");
			LevelBox->Items->Add("400");
			loadStudents();
		}
		void loadStudents() {
			try {
				db->Open();
				db->sqlCmd->CommandText = "SELECT s.studentID, u.firstName, u.lastName, s.currentLevel, u.email, s.enrollmentYear, s.expectedGraduation from student s JOIN user u ON s.studentID=u.dbID ORDER by s.studentID DESC";
				db->sqlDR = db->sqlCmd->ExecuteReader();
				db->sqlDT->Clear();
				db->sqlDT->Load(db->sqlDR);
				dataGridView1->DataSource = db->sqlDT;
				dataGridView1->Columns[0]->Width = 80;
				dataGridView1->Columns[1]->Width = 150;
				dataGridView1->Columns[2]->Width = 150;
				dataGridView1->Columns[3]->Width = 100;
				dataGridView1->Columns[4]->Width = 150;
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
		~adminStudents()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Label^ Position;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::TextBox^ txtAddress;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ txtGender;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::TextBox^ txtPhoneNumber;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ txtPassword;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ txtEmail;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ txtLastName;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ btnLevel;

	private: System::Windows::Forms::TextBox^ txtFirstName;
	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::Button^ btnID;
	private: System::Windows::Forms::Button^ btnName;
	private: System::Windows::Forms::TextBox^ txtSearch;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ btnDelete;
	private: System::Windows::Forms::Button^ btnUpdate;
	private: System::Windows::Forms::Button^ btnSave;

	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ lblWelcome;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ btnProgrammes;
	private: System::Windows::Forms::Label^ lblUser;
	private: System::Windows::Forms::Button^ btnCourses;
	private: System::Windows::Forms::Button^ btnDashboard;
	private: System::Windows::Forms::Button^ btnFaculty;



	private: System::Windows::Forms::TextBox^ txtEnrollment;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ txtGraduation;

	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::ComboBox^ LevelBox;



	private: System::Windows::Forms::Button^ btnYear;


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
			this->Position = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->txtAddress = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->txtGender = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->txtPhoneNumber = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txtEmail = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txtLastName = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->btnLevel = (gcnew System::Windows::Forms::Button());
			this->txtFirstName = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->btnID = (gcnew System::Windows::Forms::Button());
			this->btnName = (gcnew System::Windows::Forms::Button());
			this->txtSearch = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->btnUpdate = (gcnew System::Windows::Forms::Button());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->lblWelcome = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->btnDepartment = (gcnew System::Windows::Forms::Button());
			this->btnPayments = (gcnew System::Windows::Forms::Button());
			this->btnEnrollment = (gcnew System::Windows::Forms::Button());
			this->btnProgrammes = (gcnew System::Windows::Forms::Button());
			this->lblUser = (gcnew System::Windows::Forms::Label());
			this->btnCourses = (gcnew System::Windows::Forms::Button());
			this->btnDashboard = (gcnew System::Windows::Forms::Button());
			this->btnFaculty = (gcnew System::Windows::Forms::Button());
			this->txtEnrollment = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->txtGraduation = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->LevelBox = (gcnew System::Windows::Forms::ComboBox());
			this->btnYear = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// Position
			// 
			this->Position->AutoSize = true;
			this->Position->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Position->Location = System::Drawing::Point(1206, 266);
			this->Position->Name = L"Position";
			this->Position->Size = System::Drawing::Size(179, 37);
			this->Position->TabIndex = 91;
			this->Position->Text = L"Current Level:";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dateTimePicker1->Location = System::Drawing::Point(575, 401);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(445, 43);
			this->dateTimePicker1->TabIndex = 90;
			// 
			// txtAddress
			// 
			this->txtAddress->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtAddress->Location = System::Drawing::Point(575, 592);
			this->txtAddress->Name = L"txtAddress";
			this->txtAddress->Size = System::Drawing::Size(605, 43);
			this->txtAddress->TabIndex = 89;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(332, 592);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(117, 37);
			this->label10->TabIndex = 88;
			this->label10->Text = L"Address:";
			// 
			// txtGender
			// 
			this->txtGender->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtGender->Location = System::Drawing::Point(575, 530);
			this->txtGender->Name = L"txtGender";
			this->txtGender->Size = System::Drawing::Size(605, 43);
			this->txtGender->TabIndex = 87;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(332, 530);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(110, 37);
			this->label11->TabIndex = 86;
			this->label11->Text = L"Gender:";
			// 
			// txtPhoneNumber
			// 
			this->txtPhoneNumber->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtPhoneNumber->Location = System::Drawing::Point(575, 462);
			this->txtPhoneNumber->Name = L"txtPhoneNumber";
			this->txtPhoneNumber->Size = System::Drawing::Size(605, 43);
			this->txtPhoneNumber->TabIndex = 85;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(332, 462);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(202, 37);
			this->label12->TabIndex = 84;
			this->label12->Text = L"Phone Number:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(332, 395);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(172, 37);
			this->label7->TabIndex = 83;
			this->label7->Text = L"Date of Birth:";
			// 
			// txtPassword
			// 
			this->txtPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtPassword->Location = System::Drawing::Point(575, 329);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->PasswordChar = '*';
			this->txtPassword->Size = System::Drawing::Size(605, 43);
			this->txtPassword->TabIndex = 82;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(332, 335);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(134, 37);
			this->label6->TabIndex = 81;
			this->label6->Text = L"Password:";
			// 
			// txtEmail
			// 
			this->txtEmail->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtEmail->Location = System::Drawing::Point(575, 269);
			this->txtEmail->Name = L"txtEmail";
			this->txtEmail->Size = System::Drawing::Size(605, 43);
			this->txtEmail->TabIndex = 80;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(332, 269);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(88, 37);
			this->label5->TabIndex = 79;
			this->label5->Text = L"Email:";
			// 
			// txtLastName
			// 
			this->txtLastName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtLastName->Location = System::Drawing::Point(575, 207);
			this->txtLastName->Name = L"txtLastName";
			this->txtLastName->Size = System::Drawing::Size(605, 43);
			this->txtLastName->TabIndex = 78;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(332, 207);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(148, 37);
			this->label4->TabIndex = 77;
			this->label4->Text = L"Last Name:";
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
			this->btnLevel->Location = System::Drawing::Point(1643, 1211);
			this->btnLevel->Name = L"btnLevel";
			this->btnLevel->Size = System::Drawing::Size(236, 50);
			this->btnLevel->TabIndex = 76;
			this->btnLevel->Text = L"By Level";
			this->btnLevel->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnLevel->UseVisualStyleBackColor = false;
			this->btnLevel->Click += gcnew System::EventHandler(this, &adminStudents::btnLevel_Click);
			// 
			// txtFirstName
			// 
			this->txtFirstName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtFirstName->Location = System::Drawing::Point(575, 139);
			this->txtFirstName->Name = L"txtFirstName";
			this->txtFirstName->Size = System::Drawing::Size(605, 43);
			this->txtFirstName->TabIndex = 75;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(332, 139);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(150, 37);
			this->label3->TabIndex = 74;
			this->label3->Text = L"First Name:";
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
			this->btnID->TabIndex = 72;
			this->btnID->Text = L"By ID";
			this->btnID->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnID->UseVisualStyleBackColor = false;
			this->btnID->Click += gcnew System::EventHandler(this, &adminStudents::btnID_Click);
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
			this->btnName->TabIndex = 71;
			this->btnName->Text = L"By Name";
			this->btnName->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnName->UseVisualStyleBackColor = false;
			this->btnName->Click += gcnew System::EventHandler(this, &adminStudents::btnName_Click);
			// 
			// txtSearch
			// 
			this->txtSearch->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtSearch->Location = System::Drawing::Point(575, 1215);
			this->txtSearch->Name = L"txtSearch";
			this->txtSearch->Size = System::Drawing::Size(605, 43);
			this->txtSearch->TabIndex = 70;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(381, 1215);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(101, 37);
			this->label2->TabIndex = 69;
			this->label2->Text = L"Search:";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(331, 790);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 82;
			this->dataGridView1->RowTemplate->Height = 33;
			this->dataGridView1->Size = System::Drawing::Size(1797, 397);
			this->dataGridView1->TabIndex = 68;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &adminStudents::dataGridView1_CellContentClick);
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
			this->btnDelete->Location = System::Drawing::Point(1730, 702);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(182, 56);
			this->btnDelete->TabIndex = 66;
			this->btnDelete->Text = L"Delete";
			this->btnDelete->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnDelete->UseVisualStyleBackColor = false;
			this->btnDelete->Click += gcnew System::EventHandler(this, &adminStudents::btnDelete_Click);
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
			this->btnUpdate->Location = System::Drawing::Point(1093, 702);
			this->btnUpdate->Name = L"btnUpdate";
			this->btnUpdate->Size = System::Drawing::Size(182, 56);
			this->btnUpdate->TabIndex = 64;
			this->btnUpdate->Text = L"Update";
			this->btnUpdate->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnUpdate->UseVisualStyleBackColor = false;
			this->btnUpdate->Click += gcnew System::EventHandler(this, &adminStudents::btnUpdate_Click);
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
			this->btnSave->Location = System::Drawing::Point(500, 702);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(182, 56);
			this->btnSave->TabIndex = 63;
			this->btnSave->Text = L"Save";
			this->btnSave->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnSave->UseVisualStyleBackColor = false;
			this->btnSave->Click += gcnew System::EventHandler(this, &adminStudents::btnSave_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->Controls->Add(this->lblWelcome);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(279, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1878, 80);
			this->panel2->TabIndex = 67;
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
			this->lblWelcome->Size = System::Drawing::Size(343, 45);
			this->lblWelcome->TabIndex = 0;
			this->lblWelcome->Text = L"Student Management";
			this->lblWelcome->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Maroon;
			this->panel1->Controls->Add(this->btnDepartment);
			this->panel1->Controls->Add(this->btnPayments);
			this->panel1->Controls->Add(this->btnEnrollment);
			this->panel1->Controls->Add(this->btnProgrammes);
			this->panel1->Controls->Add(this->lblUser);
			this->panel1->Controls->Add(this->btnCourses);
			this->panel1->Controls->Add(this->btnDashboard);
			this->panel1->Controls->Add(this->btnFaculty);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(279, 1355);
			this->panel1->TabIndex = 65;
			// 
			// btnDepartment
			// 
			this->btnDepartment->FlatAppearance->BorderSize = 0;
			this->btnDepartment->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDepartment->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDepartment->ForeColor = System::Drawing::Color::White;
			this->btnDepartment->Location = System::Drawing::Point(27, 437);
			this->btnDepartment->Name = L"btnDepartment";
			this->btnDepartment->Size = System::Drawing::Size(228, 64);
			this->btnDepartment->TabIndex = 11;
			this->btnDepartment->Text = L"Departments";
			this->btnDepartment->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnDepartment->UseVisualStyleBackColor = true;
			this->btnDepartment->Click += gcnew System::EventHandler(this, &adminStudents::btnDepartment_Click);
			// 
			// btnPayments
			// 
			this->btnPayments->FlatAppearance->BorderSize = 0;
			this->btnPayments->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnPayments->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnPayments->ForeColor = System::Drawing::Color::White;
			this->btnPayments->Location = System::Drawing::Point(27, 838);
			this->btnPayments->Name = L"btnPayments";
			this->btnPayments->Size = System::Drawing::Size(228, 68);
			this->btnPayments->TabIndex = 10;
			this->btnPayments->Text = L"Payments";
			this->btnPayments->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnPayments->UseVisualStyleBackColor = true;
			this->btnPayments->Click += gcnew System::EventHandler(this, &adminStudents::btnPayments_Click);
			// 
			// btnEnrollment
			// 
			this->btnEnrollment->FlatAppearance->BorderSize = 0;
			this->btnEnrollment->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnEnrollment->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnEnrollment->ForeColor = System::Drawing::Color::White;
			this->btnEnrollment->Location = System::Drawing::Point(27, 757);
			this->btnEnrollment->Name = L"btnEnrollment";
			this->btnEnrollment->Size = System::Drawing::Size(182, 75);
			this->btnEnrollment->TabIndex = 9;
			this->btnEnrollment->Text = L"Enrollment";
			this->btnEnrollment->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnEnrollment->UseVisualStyleBackColor = true;
			this->btnEnrollment->Click += gcnew System::EventHandler(this, &adminStudents::btnEnrollment_Click);
			// 
			// btnProgrammes
			// 
			this->btnProgrammes->FlatAppearance->BorderSize = 0;
			this->btnProgrammes->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnProgrammes->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnProgrammes->ForeColor = System::Drawing::Color::White;
			this->btnProgrammes->Location = System::Drawing::Point(27, 637);
			this->btnProgrammes->Name = L"btnProgrammes";
			this->btnProgrammes->Size = System::Drawing::Size(206, 80);
			this->btnProgrammes->TabIndex = 6;
			this->btnProgrammes->Text = L"Programmes";
			this->btnProgrammes->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnProgrammes->UseVisualStyleBackColor = true;
			this->btnProgrammes->Click += gcnew System::EventHandler(this, &adminStudents::btnProgrammes_Click);
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
			this->btnCourses->Location = System::Drawing::Point(27, 536);
			this->btnCourses->Name = L"btnCourses";
			this->btnCourses->Size = System::Drawing::Size(182, 50);
			this->btnCourses->TabIndex = 4;
			this->btnCourses->Text = L"Courses";
			this->btnCourses->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnCourses->UseVisualStyleBackColor = true;
			this->btnCourses->Click += gcnew System::EventHandler(this, &adminStudents::btnCourses_Click);
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
			this->btnDashboard->Click += gcnew System::EventHandler(this, &adminStudents::btnDashboard_Click);
			// 
			// btnFaculty
			// 
			this->btnFaculty->FlatAppearance->BorderSize = 0;
			this->btnFaculty->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnFaculty->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnFaculty->ForeColor = System::Drawing::Color::White;
			this->btnFaculty->Location = System::Drawing::Point(27, 316);
			this->btnFaculty->Name = L"btnFaculty";
			this->btnFaculty->Size = System::Drawing::Size(182, 86);
			this->btnFaculty->TabIndex = 2;
			this->btnFaculty->Text = L"Faculty";
			this->btnFaculty->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnFaculty->UseVisualStyleBackColor = true;
			this->btnFaculty->Click += gcnew System::EventHandler(this, &adminStudents::btnFaculty_Click);
			// 
			// txtEnrollment
			// 
			this->txtEnrollment->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtEnrollment->Location = System::Drawing::Point(1449, 385);
			this->txtEnrollment->Name = L"txtEnrollment";
			this->txtEnrollment->Size = System::Drawing::Size(605, 43);
			this->txtEnrollment->TabIndex = 96;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(1206, 388);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(209, 37);
			this->label8->TabIndex = 95;
			this->label8->Text = L"Enrollment Year:";
			// 
			// txtGraduation
			// 
			this->txtGraduation->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtGraduation->Location = System::Drawing::Point(1449, 506);
			this->txtGraduation->Name = L"txtGraduation";
			this->txtGraduation->Size = System::Drawing::Size(605, 43);
			this->txtGraduation->TabIndex = 98;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(1206, 506);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(214, 37);
			this->label9->TabIndex = 97;
			this->label9->Text = L"Graduation Year:";
			// 
			// LevelBox
			// 
			this->LevelBox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LevelBox->FormattingEnabled = true;
			this->LevelBox->Location = System::Drawing::Point(1449, 266);
			this->LevelBox->Name = L"LevelBox";
			this->LevelBox->Size = System::Drawing::Size(603, 45);
			this->LevelBox->TabIndex = 99;
			// 
			// btnYear
			// 
			this->btnYear->BackColor = System::Drawing::Color::Maroon;
			this->btnYear->FlatAppearance->BorderColor = System::Drawing::Color::Maroon;
			this->btnYear->FlatAppearance->BorderSize = 0;
			this->btnYear->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnYear->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnYear->ForeColor = System::Drawing::Color::White;
			this->btnYear->Location = System::Drawing::Point(1907, 1211);
			this->btnYear->Name = L"btnYear";
			this->btnYear->Size = System::Drawing::Size(236, 50);
			this->btnYear->TabIndex = 101;
			this->btnYear->Text = L"By Grad Year";
			this->btnYear->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnYear->UseVisualStyleBackColor = false;
			this->btnYear->Click += gcnew System::EventHandler(this, &adminStudents::btnYear_Click);
			// 
			// adminStudents
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(2157, 1355);
			this->Controls->Add(this->btnYear);
			this->Controls->Add(this->LevelBox);
			this->Controls->Add(this->txtGraduation);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->txtEnrollment);
			this->Controls->Add(this->label8);
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
			this->Controls->Add(this->btnLevel);
			this->Controls->Add(this->txtFirstName);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->btnID);
			this->Controls->Add(this->btnName);
			this->Controls->Add(this->txtSearch);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->btnDelete);
			this->Controls->Add(this->btnUpdate);
			this->Controls->Add(this->btnSave);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"adminStudents";
			this->Text = L"adminStudents";
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
	private: System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			String^ firstName = txtFirstName->Text;
			String^ lastName = txtLastName->Text;
			String^ email = txtEmail->Text;
			String^ password = txtPassword->Text;
			DateTime dob = dateTimePicker1->Value;
			String^ formattedBirthDate = dob.ToString("yyyy-MM-dd");
			String^ phoneNumber = txtPhoneNumber->Text;
			String^ gender = txtGender->Text;
			String^ address = txtAddress->Text;
			String^ level = LevelBox->Text;
			String^ enrollmentYear = txtEnrollment->Text;
			String^ graduationYear = txtGraduation->Text;
			
			db->Open();
			db->sqlCmd->CommandText = "INSERT INTO user (firstName, lastName, email, password, dateOfBirth, gender, phoneNumber, address) VALUES (@fName, @lName, @email, @pwd, @DOB, @gender, @phone, @address)";
			db->sqlCmd->Parameters->AddWithValue("@fName", firstName);
			db->sqlCmd->Parameters->AddWithValue("@lName", lastName);
			db->sqlCmd->Parameters->AddWithValue("@email", email);
			db->sqlCmd->Parameters->AddWithValue("@pwd", password);
			db->sqlCmd->Parameters->AddWithValue("@DOB", formattedBirthDate);
			db->sqlCmd->Parameters->AddWithValue("@gender", gender);
			db->sqlCmd->Parameters->AddWithValue("@phone", phoneNumber);
			db->sqlCmd->Parameters->AddWithValue("@address", address);
			db->sqlCmd->ExecuteNonQuery();
			db->sqlCmd->Parameters->Clear();
			db->sqlCmd->CommandText = "INSERT INTO student (studentID, currentLevel, enrollmentYear, expectedGraduation) VALUES (LAST_INSERT_ID(), @level, @enrollYear, @gradYear)";
			db->sqlCmd->Parameters->AddWithValue("@level", level);
			db->sqlCmd->Parameters->AddWithValue("@enrollYear", enrollmentYear);
			db->sqlCmd->Parameters->AddWithValue("@gradYear", graduationYear);
			db->sqlCmd->ExecuteNonQuery();
			db->sqlCmd->Parameters->Clear();
			db->Close();
			MessageBox::Show("Student saved successfully.");
			loadStudents();

		}catch(FormatException^){
			MessageBox::Show("Invalid format. Please check your input.");
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error: " + ex->Message);
		}
	}
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (e->RowIndex>=0)
		{
			DataGridViewRow^ row = dataGridView1->Rows[e->RowIndex];
			txtFirstName->Text = row->Cells["firstName"]->Value->ToString();
			txtLastName->Text = row->Cells["lastName"]->Value->ToString();
			txtEmail->Text = row->Cells["email"]->Value->ToString();
			LevelBox->SelectedItem = row->Cells["currentLevel"]->Value->ToString();
			txtEnrollment->Text = row->Cells["enrollmentYear"]->Value->ToString();
			txtGraduation->Text = row->Cells["expectedGraduation"]->Value->ToString();
			globalStudentID = Convert::ToInt32(row->Cells["studentID"]->Value->ToString());
			try {
				db->Open();
				db->sqlCmd->CommandText = "SELECT * FROM user WHERE dbID = @userID";
				db->sqlCmd->Parameters->AddWithValue("@userID", globalStudentID);
				db->sqlDR = db->sqlCmd->ExecuteReader();
				db->sqlCmd->Parameters->Clear();
				db->sqlDR->Read();
				txtPassword->Text = db->sqlDR["password"]->ToString();
				DateTime dob = DateTime::Parse(db->sqlDR["dateOfBirth"]->ToString());
				dateTimePicker1->Value = dob;
				txtPhoneNumber->Text = db->sqlDR["phoneNumber"]->ToString();
				txtGender->Text = db->sqlDR["gender"]->ToString();
				txtAddress->Text = db->sqlDR["address"]->ToString();
				db->sqlDR->Close();

			}
			catch (Exception^ ex) {
				MessageBox::Show("Error: " + ex->Message);
			}
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
			String^ level = LevelBox->Text;
			String^ enrollmentYear = txtEnrollment->Text;
			String^ graduationYear = txtGraduation->Text;
			db->sqlCmd->CommandText = "UPDATE user SET firstName=@fName, lastName=@lName, email=@email, password=@pwd, dateOfBirth=@dob, gender=@gender, phoneNumber=@phone, address=@address WHERE dbID=@userID";
			db->sqlCmd->Parameters->AddWithValue("@fName", firstName);
			db->sqlCmd->Parameters->AddWithValue("@lName", lastName);
			db->sqlCmd->Parameters->AddWithValue("@email", email);
			db->sqlCmd->Parameters->AddWithValue("@pwd", password);
			db->sqlCmd->Parameters->AddWithValue("@dob", formattedBirthDate);
			db->sqlCmd->Parameters->AddWithValue("@gender", gender);
			db->sqlCmd->Parameters->AddWithValue("@phone", phoneNumber);
			db->sqlCmd->Parameters->AddWithValue("@address", address);
			db->sqlCmd->Parameters->AddWithValue("@userID", globalStudentID);
			db->sqlCmd->ExecuteNonQuery();
			db->sqlCmd->Parameters->Clear();
			db->sqlCmd->CommandText = "UPDATE student SET currentLevel=@level, enrollmentYear=@enrollYear, expectedGraduation=@gradYear WHERE studentID=@studentID";
			db->sqlCmd->Parameters->AddWithValue("@level", level);
			db->sqlCmd->Parameters->AddWithValue("@enrollYear", enrollmentYear);
			db->sqlCmd->Parameters->AddWithValue("@gradYear", graduationYear);
			db->sqlCmd->Parameters->AddWithValue("@studentID", globalStudentID);
			db->sqlCmd->ExecuteNonQuery();
			db->sqlCmd->Parameters->Clear();
			db->Close();
			loadStudents();
			MessageBox::Show("Student updated successfully.");
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error: " + ex->Message);
		}
	}
	private: System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			db->Open();
			db->sqlCmd->CommandText = "DELETE FROM student WHERE studentID=@studentID";
			db->sqlCmd->Parameters->AddWithValue("@studentID", globalStudentID);
			db->sqlCmd->ExecuteNonQuery();
			db->sqlCmd->Parameters->Clear();
			db->sqlCmd->CommandText = "DELETE FROM user WHERE dbID=@userID";
			db->sqlCmd->Parameters->AddWithValue("@userID", globalStudentID);
			db->sqlCmd->ExecuteNonQuery();
			db->sqlCmd->Parameters->Clear();
			db->Close();
			loadStudents();
			MessageBox::Show("Student deleted successfully.");
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error: " + ex->Message);
		}
	}
	private: System::Void btnID_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			int searchID = Convert::ToInt32(txtSearch->Text);
			db->Open();
			db->sqlCmd->CommandText = "SELECT s.studentID, u.firstName, u.lastName, u.email, s.currentLevel, s.enrollmentYear, s.expectedGraduation FROM student s JOIN user u ON s.studentID = u.dbID WHERE s.studentID = @searchID";
			db->sqlCmd->Parameters->AddWithValue("@searchID", searchID);
			db->sqlDR = db->sqlCmd->ExecuteReader();
			db->sqlDT->Clear();
			db->sqlDT->Load(db->sqlDR);
			dataGridView1->DataSource = db->sqlDT;
			dataGridView1->Columns[0]->Width = 80;
			dataGridView1->Columns[1]->Width = 150;
			dataGridView1->Columns[2]->Width = 150;
			dataGridView1->Columns[3]->Width = 100;
			dataGridView1->Columns[4]->Width = 150;
			dataGridView1->Columns[5]->Width = 100;
			dataGridView1->Columns[6]->Width = 100;
			db->sqlCmd->Parameters->Clear();
			db->Close();
		} catch(FormatException^) {
			MessageBox::Show("Invalid format. Please check your input.");
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error: " + ex->Message);
		}
	}
	private: System::Void btnName_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			String^ searchName = txtSearch->Text;
			db->Open();
			db->sqlCmd->CommandText = "SELECT s.studentID, u.firstName, u.lastName, u.email, s.currentLevel, s.enrollmentYear, s.expectedGraduation FROM student s JOIN user u ON s.studentID = u.dbID WHERE u.firstName LIKE @searchName OR u.lastName LIKE @searchName";
			db->sqlCmd->Parameters->AddWithValue("@searchName", "%" + searchName + "%");
			db->sqlDR = db->sqlCmd->ExecuteReader();
			db->sqlDT->Clear();
			db->sqlDT->Load(db->sqlDR);
			dataGridView1->DataSource = db->sqlDT;
			dataGridView1->Columns[0]->Width = 80;
			dataGridView1->Columns[1]->Width = 150;
			dataGridView1->Columns[2]->Width = 150;
			dataGridView1->Columns[3]->Width = 100;
			dataGridView1->Columns[4]->Width = 150;
			dataGridView1->Columns[5]->Width = 100;
			dataGridView1->Columns[6]->Width = 100;
			db->sqlCmd->Parameters->Clear();
			db->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error: " + ex->Message);
		}
	}
	private: System::Void btnLevel_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			String^ searchLevel = txtSearch->Text;
			db->Open();
			db->sqlCmd->CommandText = "SELECT s.studentID, u.firstName, u.lastName, u.email, s.currentLevel, s.enrollmentYear, s.expectedGraduation FROM student s JOIN user u ON s.studentID = u.dbID WHERE s.currentLevel = @searchLevel";
			db->sqlCmd->Parameters->AddWithValue("@searchLevel", searchLevel);
			db->sqlDR = db->sqlCmd->ExecuteReader();
			db->sqlDT->Clear();
			db->sqlDT->Load(db->sqlDR);
			dataGridView1->DataSource = db->sqlDT;
			dataGridView1->Columns[0]->Width = 80;
			dataGridView1->Columns[1]->Width = 150;
			dataGridView1->Columns[2]->Width = 150;
			dataGridView1->Columns[3]->Width = 100;
			dataGridView1->Columns[4]->Width = 150;
			dataGridView1->Columns[5]->Width = 100;
			dataGridView1->Columns[6]->Width = 100;
			db->sqlCmd->Parameters->Clear();
			db->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error: " + ex->Message);
		}
	}
	private: System::Void btnYear_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			String^ searchYear = txtSearch->Text;
			db->Open();
			db->sqlCmd->CommandText = "SELECT s.studentID, u.firstName, u.lastName, u.email, s.currentLevel, s.enrollmentYear, s.expectedGraduation FROM student s JOIN user u ON s.studentID = u.dbID WHERE s.expectedGraduation = @searchYear";
			db->sqlCmd->Parameters->AddWithValue("@searchYear", searchYear);
			db->sqlDR = db->sqlCmd->ExecuteReader();
			db->sqlDT->Clear();
			db->sqlDT->Load(db->sqlDR);
			dataGridView1->DataSource = db->sqlDT;
			dataGridView1->Columns[0]->Width = 80;
			dataGridView1->Columns[1]->Width = 150;
			dataGridView1->Columns[2]->Width = 150;
			dataGridView1->Columns[3]->Width = 100;
			dataGridView1->Columns[4]->Width = 150;
			dataGridView1->Columns[5]->Width = 100;
			dataGridView1->Columns[6]->Width = 100;
			db->sqlCmd->Parameters->Clear();
			db->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error: " + ex->Message);
		}
	}
	private: System::Void btnFaculty_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnCourses_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnDepartment_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnProgrammes_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnEnrollment_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnPayments_Click(System::Object^ sender, System::EventArgs^ e);
};
}
