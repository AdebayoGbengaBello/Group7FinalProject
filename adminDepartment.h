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
	/// Summary for adminDepartment
	/// </summary>
	public ref class adminDepartment : public System::Windows::Forms::Form
	{
		Database^ db = gcnew Database();
		int globalDeptID = -1;
	private: System::Windows::Forms::Button^ btnPayments;
	private: System::Windows::Forms::Button^ btnEnrollment;
		   User^ currentUser;
	public:
		adminDepartment(User^ user)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			LoadDepartments();
			this->currentUser = user;
			lblUser->Text = "Hello " + currentUser->name;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~adminDepartment()
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
	private: System::Windows::Forms::Button^ btnProgrammes;
	private: System::Windows::Forms::Label^ lblUser;
	private: System::Windows::Forms::Button^ btnCourses;
	private: System::Windows::Forms::Button^ btnDashboard;

	private: System::Windows::Forms::Button^ btnFaculty;
	private: System::Windows::Forms::Button^ btnStudents;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnSave;
	private: System::Windows::Forms::TextBox^ txtDepartment;
	private: System::Windows::Forms::Button^ btnUpdate;
	private: System::Windows::Forms::Button^ btnDelete;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::TextBox^ txtSearch;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btnID;
	private: System::Windows::Forms::Button^ btnName;



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
			this->btnDashboard = (gcnew System::Windows::Forms::Button());
			this->btnFaculty = (gcnew System::Windows::Forms::Button());
			this->btnStudents = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->btnID = (gcnew System::Windows::Forms::Button());
			this->btnName = (gcnew System::Windows::Forms::Button());
			this->txtSearch = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->btnUpdate = (gcnew System::Windows::Forms::Button());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->txtDepartment = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->Controls->Add(this->lblWelcome);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(279, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1069, 80);
			this->panel2->TabIndex = 4;
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
			this->lblWelcome->Size = System::Drawing::Size(408, 45);
			this->lblWelcome->TabIndex = 0;
			this->lblWelcome->Text = L"Department Management";
			this->lblWelcome->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Maroon;
			this->panel1->Controls->Add(this->btnPayments);
			this->panel1->Controls->Add(this->btnEnrollment);
			this->panel1->Controls->Add(this->btnProgrammes);
			this->panel1->Controls->Add(this->lblUser);
			this->panel1->Controls->Add(this->btnCourses);
			this->panel1->Controls->Add(this->btnDashboard);
			this->panel1->Controls->Add(this->btnFaculty);
			this->panel1->Controls->Add(this->btnStudents);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(279, 1229);
			this->panel1->TabIndex = 3;
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
			this->btnPayments->Click += gcnew System::EventHandler(this, &adminDepartment::btnPayments_Click);
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
			this->btnEnrollment->Click += gcnew System::EventHandler(this, &adminDepartment::btnEnrollment_Click);
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
			this->btnProgrammes->Click += gcnew System::EventHandler(this, &adminDepartment::btnProgrammes_Click);
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
			this->btnCourses->Click += gcnew System::EventHandler(this, &adminDepartment::btnCourses_Click);
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
			this->btnDashboard->Click += gcnew System::EventHandler(this, &adminDepartment::btnDashboard_Click);
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
			this->btnFaculty->Click += gcnew System::EventHandler(this, &adminDepartment::btnFaculty_Click);
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
			this->btnStudents->Click += gcnew System::EventHandler(this, &adminDepartment::btnStudents_Click);
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::White;
			this->panel3->Controls->Add(this->btnID);
			this->panel3->Controls->Add(this->btnName);
			this->panel3->Controls->Add(this->txtSearch);
			this->panel3->Controls->Add(this->label2);
			this->panel3->Controls->Add(this->dataGridView1);
			this->panel3->Controls->Add(this->btnDelete);
			this->panel3->Controls->Add(this->btnUpdate);
			this->panel3->Controls->Add(this->btnSave);
			this->panel3->Controls->Add(this->txtDepartment);
			this->panel3->Controls->Add(this->label1);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel3->Location = System::Drawing::Point(279, 80);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(1069, 1149);
			this->panel3->TabIndex = 5;
			this->panel3->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &adminDepartment::panel3_Paint);
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
			this->btnID->Location = System::Drawing::Point(797, 864);
			this->btnID->Name = L"btnID";
			this->btnID->Size = System::Drawing::Size(182, 50);
			this->btnID->TabIndex = 9;
			this->btnID->Text = L"By ID";
			this->btnID->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnID->UseVisualStyleBackColor = false;
			this->btnID->Click += gcnew System::EventHandler(this, &adminDepartment::btnID_Click);
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
			this->btnName->Location = System::Drawing::Point(797, 979);
			this->btnName->Name = L"btnName";
			this->btnName->Size = System::Drawing::Size(182, 50);
			this->btnName->TabIndex = 8;
			this->btnName->Text = L"By Name";
			this->btnName->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnName->UseVisualStyleBackColor = false;
			this->btnName->Click += gcnew System::EventHandler(this, &adminDepartment::btnName_Click);
			// 
			// txtSearch
			// 
			this->txtSearch->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtSearch->Location = System::Drawing::Point(172, 923);
			this->txtSearch->Name = L"txtSearch";
			this->txtSearch->Size = System::Drawing::Size(605, 43);
			this->txtSearch->TabIndex = 7;
			this->txtSearch->TextChanged += gcnew System::EventHandler(this, &adminDepartment::textBox1_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(55, 926);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(101, 37);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Search:";
			this->label2->Click += gcnew System::EventHandler(this, &adminDepartment::label2_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(94, 329);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 82;
			this->dataGridView1->RowTemplate->Height = 33;
			this->dataGridView1->Size = System::Drawing::Size(820, 498);
			this->dataGridView1->TabIndex = 5;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &adminDepartment::dataGridView1_CellContentClick);
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
			this->btnDelete->Location = System::Drawing::Point(660, 195);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(182, 50);
			this->btnDelete->TabIndex = 4;
			this->btnDelete->Text = L"Delete";
			this->btnDelete->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnDelete->UseVisualStyleBackColor = false;
			this->btnDelete->Click += gcnew System::EventHandler(this, &adminDepartment::btnDelete_Click);
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
			this->btnUpdate->Location = System::Drawing::Point(388, 195);
			this->btnUpdate->Name = L"btnUpdate";
			this->btnUpdate->Size = System::Drawing::Size(182, 50);
			this->btnUpdate->TabIndex = 3;
			this->btnUpdate->Text = L"Update";
			this->btnUpdate->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnUpdate->UseVisualStyleBackColor = false;
			this->btnUpdate->Click += gcnew System::EventHandler(this, &adminDepartment::btnUpdate_Click);
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
			this->btnSave->Location = System::Drawing::Point(103, 195);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(182, 50);
			this->btnSave->TabIndex = 2;
			this->btnSave->Text = L"Save";
			this->btnSave->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnSave->UseVisualStyleBackColor = false;
			this->btnSave->Click += gcnew System::EventHandler(this, &adminDepartment::btnSave_Click);
			// 
			// txtDepartment
			// 
			this->txtDepartment->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtDepartment->Location = System::Drawing::Point(237, 104);
			this->txtDepartment->Name = L"txtDepartment";
			this->txtDepartment->Size = System::Drawing::Size(605, 43);
			this->txtDepartment->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(55, 98);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(165, 37);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Department:";
			// 
			// adminDepartment
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1348, 1229);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"adminDepartment";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"adminDepartment";
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void panel3_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		}
		private: System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ department = txtDepartment->Text->Trim();
			if (department == "") {
				MessageBox::Show("Please Enter Department", "Data Entry Error", MessageBoxButtons::OK,
					MessageBoxIcon::Warning);
				return;
			}
			try {
				db->Open();
				db->sqlCmd->CommandText = "SELECT * FROM department where deptName=@dept";
				db->sqlCmd->Parameters->Clear();
				db->sqlCmd->Parameters->AddWithValue("@dept", department);
				db->sqlDR = db->sqlCmd->ExecuteReader();
				if (db->sqlDR->Read()) {
					MessageBox::Show("Department Already Exist", "Data Entry Error", MessageBoxButtons::OK,
						MessageBoxIcon::Warning);
					db->sqlDR->Close();
					db->sqlCmd->Cancel();
				}
				else {
					db->sqlDR->Close();
					db->sqlCmd->Cancel();
					db->sqlCmd->CommandText = "INSERT INTO department(deptName) VALUES (@department)";
					db->sqlCmd->Parameters->Clear();
					db->sqlCmd->Parameters->AddWithValue("@department", department);
					db->sqlCmd->ExecuteNonQuery();
					LoadDepartments();
					MessageBox::Show("Department is saved successfully");
				}
				txtDepartment->Text = "";
				db->Close();
			}
			catch (Exception^ e) {
				MessageBox::Show("Database Connection Error: " + e->ToString(), "Data Entry Error", MessageBoxButtons::OK,
					MessageBoxIcon::Warning);
			}
		}
		void LoadDepartments() {
			try {
				db->Open();
				db->sqlCmd->CommandText = "SELECT * FROM department ORDER By deptID DESC";
				db->sqlDR = db->sqlCmd->ExecuteReader();
				db->sqlDT->Clear();
				db->sqlDT->Load(db->sqlDR);
				dataGridView1->DataSource = db->sqlDT;
				dataGridView1->Columns[0]->Width = 50;
				dataGridView1->Columns[1]->Width = 500;
				db->sqlDR->Close();
				db->sqlCmd->Cancel();
				db->Close();
			}
			catch (Exception^ e) {
				MessageBox::Show("Database Connection Error: " + e->ToString(), "Data Load Error", MessageBoxButtons::OK,
					MessageBoxIcon::Warning);
			}
		}
		private: System::Void btnUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ department = txtDepartment->Text->Trim();
			if (department == "") {
				MessageBox::Show("Please Enter Department", "Data Entry Error", MessageBoxButtons::OK,
					MessageBoxIcon::Warning);
				return;
			}
			if (globalDeptID == -1) {
				MessageBox::Show("Please Select Department to Update", "Data Entry Error", MessageBoxButtons::OK,
					MessageBoxIcon::Warning);
				return;
			}
			try {
				db->Open();
				db->sqlCmd->CommandText = "UPDATE department SET deptName=@department WHERE deptID=@deptID";
				db->sqlCmd->Parameters->Clear();
				db->sqlCmd->Parameters->AddWithValue("@department", department);
				db->sqlCmd->Parameters->AddWithValue("@deptID", globalDeptID);
				db->sqlCmd->ExecuteNonQuery();
				LoadDepartments();
				MessageBox::Show("Department is updated successfully");
				txtDepartment->Text = "";
				globalDeptID = -1;
				db->Close();
			}
			catch (Exception^ e) {
				MessageBox::Show("Database Connection Error: " + e->ToString(), "Data Entry Error", MessageBoxButtons::OK,
					MessageBoxIcon::Warning);
			}
		}
		private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
			if (e->RowIndex >= 0) {
				DataGridViewRow^ row = dataGridView1->Rows[e->RowIndex];
				globalDeptID = Convert::ToInt32(row->Cells[0]->Value);
				txtDepartment->Text = row->Cells[1]->Value->ToString();
			}
		}
		private: System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e) {
			if (globalDeptID == -1) {
				MessageBox::Show("Please Select Department to Delete", "Data Entry Error", MessageBoxButtons::OK,
					MessageBoxIcon::Warning);
				return;
			}
			try {
				db->Open();
				db->sqlCmd->CommandText = "DELETE FROM department WHERE deptID=@deptID";
				db->sqlCmd->Parameters->Clear();
				db->sqlCmd->Parameters->AddWithValue("@deptID", globalDeptID);
				db->sqlCmd->ExecuteNonQuery();
				LoadDepartments();
				MessageBox::Show("Department is deleted successfully");
				txtDepartment->Text = "";
				globalDeptID = -1;
				db->Close();
			}
			catch (Exception^ e) {
				MessageBox::Show("Database Connection Error: " + e->ToString(), "Data Entry Error", MessageBoxButtons::OK,
					MessageBoxIcon::Warning);
			}
		}
		private: System::Void btnID_Click(System::Object^ sender, System::EventArgs^ e) {
			try {
				int deptID = Convert::ToInt32(txtSearch->Text->Trim());
				db->Open();
				db->sqlCmd->CommandText = "SELECT * FROM department WHERE deptID =@deptID";
				db->sqlCmd->Parameters->Clear();
				db->sqlCmd->Parameters->AddWithValue("@deptID", deptID);
				db->sqlDR = db->sqlCmd->ExecuteReader();
				db->sqlDT->Clear();
				db->sqlDT->Load(db->sqlDR);
				dataGridView1->DataSource = db->sqlDT;
				dataGridView1->Columns[0]->Width = 50;
				dataGridView1->Columns[1]->Width = 500;
				db->sqlDR->Close();
				db->sqlCmd->Cancel();
				db->Close();
			}catch (System::FormatException^) {
				MessageBox::Show("Please enter a valid Department ID", "Input Error", MessageBoxButtons::OK,
					MessageBoxIcon::Warning);
			}
			catch (Exception^ e) {
				MessageBox::Show("Database Connection Error: " + e->ToString(), "Data Load Error", MessageBoxButtons::OK,
					MessageBoxIcon::Warning);
			}
		}

		private: System::Void btnName_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ deptName = txtSearch->Text->Trim();
			try {
				db->Open();
				db->sqlCmd->CommandText = "SELECT * FROM department WHERE deptName LIKE @deptName";
				db->sqlCmd->Parameters->Clear();
				db->sqlCmd->Parameters->AddWithValue("@deptName", "%" + deptName + "%");
				db->sqlDR = db->sqlCmd->ExecuteReader();
				db->sqlDT->Clear();
				db->sqlDT->Load(db->sqlDR);
				dataGridView1->DataSource = db->sqlDT;
				dataGridView1->Columns[0]->Width = 50;
				dataGridView1->Columns[1]->Width = 500;
				db->sqlDR->Close();
				db->sqlCmd->Cancel();
				db->Close();
			}
			catch (Exception^ e) {
				MessageBox::Show("Database Connection Error: " + e->ToString(), "Data Load Error", MessageBoxButtons::OK,
					MessageBoxIcon::Warning);
			}
		}
		private: System::Void btnDashboard_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void btnCourses_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void btnStudents_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void btnFaculty_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void btnPayments_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void btnProgrammes_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void btnEnrollment_Click(System::Object^ sender, System::EventArgs^ e);
};
}
