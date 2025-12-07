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
	/// Summary for adminFees
	/// </summary>
	public ref class adminFees : public System::Windows::Forms::Form
	{
		Database^ db = gcnew Database();
		User^ currentUser;
	public:
		adminFees(User^ user)
		{
			this->currentUser = user;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			lblUser->Text = "Hello " + currentUser->name;
			loadFees();

		}
		void loadFees()
		{
			try {
				db->Open();
				String^ query = "SELECT * FROM fees";
				db->sqlCmd->CommandText = query;
				db->sqlDR = db->sqlCmd->ExecuteReader();
				db->sqlDT->Clear();
				db->sqlDT->Load(db->sqlDR);
				dataGridView1->DataSource = db->sqlDT;
				db->sqlDR->Close();
				db->Close();
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error loading fee data: " + ex->Message);
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~adminFees()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::Label^ label5;

	private: System::Windows::Forms::TextBox^ txtBill;

	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::Button^ btnID;

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
	private: System::Windows::Forms::Button^ btnDepartments;
	private: System::Windows::Forms::Button^ btnPayments;
	private: System::Windows::Forms::Button^ btnEnrollment;
	private: System::Windows::Forms::Label^ lblUser;
	private: System::Windows::Forms::Button^ btnCourses;
	private: System::Windows::Forms::Button^ btnDashboard;
	private: System::Windows::Forms::Button^ btnFaculty;
	private: System::Windows::Forms::Button^ btnStudents;
	private: System::Windows::Forms::TextBox^ txtStudentID;
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
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txtBill = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->btnID = (gcnew System::Windows::Forms::Button());
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
			this->txtStudentID = (gcnew System::Windows::Forms::TextBox());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(392, 332);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(134, 37);
			this->label5->TabIndex = 42;
			this->label5->Text = L"Due Date:";
			// 
			// txtBill
			// 
			this->txtBill->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtBill->Location = System::Drawing::Point(637, 206);
			this->txtBill->Name = L"txtBill";
			this->txtBill->Size = System::Drawing::Size(605, 43);
			this->txtBill->TabIndex = 41;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(392, 206);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(161, 37);
			this->label3->TabIndex = 40;
			this->label3->Text = L"Bill Amount:";
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
			this->btnID->Location = System::Drawing::Point(1231, 1119);
			this->btnID->Name = L"btnID";
			this->btnID->Size = System::Drawing::Size(182, 50);
			this->btnID->TabIndex = 38;
			this->btnID->Text = L"By ID";
			this->btnID->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnID->UseVisualStyleBackColor = false;
			this->btnID->Click += gcnew System::EventHandler(this, &adminFees::btnID_Click);
			// 
			// txtSearch
			// 
			this->txtSearch->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtSearch->Location = System::Drawing::Point(575, 1123);
			this->txtSearch->Name = L"txtSearch";
			this->txtSearch->Size = System::Drawing::Size(605, 43);
			this->txtSearch->TabIndex = 36;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(381, 1123);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(101, 37);
			this->label2->TabIndex = 35;
			this->label2->Text = L"Search:";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(446, 570);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 82;
			this->dataGridView1->RowTemplate->Height = 33;
			this->dataGridView1->Size = System::Drawing::Size(1379, 498);
			this->dataGridView1->TabIndex = 34;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &adminFees::dataGridView1_CellContentClick);
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
			this->btnDelete->Location = System::Drawing::Point(1060, 482);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(182, 50);
			this->btnDelete->TabIndex = 32;
			this->btnDelete->Text = L"Delete";
			this->btnDelete->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnDelete->UseVisualStyleBackColor = false;
			this->btnDelete->Click += gcnew System::EventHandler(this, &adminFees::btnDelete_Click);
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
			this->btnUpdate->Location = System::Drawing::Point(779, 482);
			this->btnUpdate->Name = L"btnUpdate";
			this->btnUpdate->Size = System::Drawing::Size(182, 50);
			this->btnUpdate->TabIndex = 30;
			this->btnUpdate->Text = L"Update";
			this->btnUpdate->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnUpdate->UseVisualStyleBackColor = false;
			this->btnUpdate->Click += gcnew System::EventHandler(this, &adminFees::btnUpdate_Click);
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
			this->btnSave->Location = System::Drawing::Point(500, 482);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(182, 50);
			this->btnSave->TabIndex = 29;
			this->btnSave->Text = L"Save";
			this->btnSave->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnSave->UseVisualStyleBackColor = false;
			this->btnSave->Click += gcnew System::EventHandler(this, &adminFees::btnSave_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(392, 91);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(140, 37);
			this->label1->TabIndex = 28;
			this->label1->Text = L"StudentID:";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->Controls->Add(this->lblWelcome);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(279, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1827, 80);
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
			this->lblWelcome->Size = System::Drawing::Size(278, 45);
			this->lblWelcome->TabIndex = 0;
			this->lblWelcome->Text = L"Fee Management";
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
			this->panel1->Size = System::Drawing::Size(279, 1250);
			this->panel1->TabIndex = 31;
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
			this->btnDepartments->Click += gcnew System::EventHandler(this, &adminFees::btnDepartments_Click);
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
			this->btnPayments->Click += gcnew System::EventHandler(this, &adminFees::btnPayments_Click);
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
			this->btnEnrollment->Click += gcnew System::EventHandler(this, &adminFees::btnEnrollment_Click);
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
			this->btnCourses->Click += gcnew System::EventHandler(this, &adminFees::btnCourses_Click);
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
			this->btnDashboard->Click += gcnew System::EventHandler(this, &adminFees::btnDashboard_Click);
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
			this->btnFaculty->Click += gcnew System::EventHandler(this, &adminFees::btnFaculty_Click);
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
			this->btnStudents->Click += gcnew System::EventHandler(this, &adminFees::btnStudents_Click);
			// 
			// txtStudentID
			// 
			this->txtStudentID->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtStudentID->Location = System::Drawing::Point(637, 91);
			this->txtStudentID->Name = L"txtStudentID";
			this->txtStudentID->Size = System::Drawing::Size(605, 43);
			this->txtStudentID->TabIndex = 45;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dateTimePicker1->Location = System::Drawing::Point(637, 338);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(416, 31);
			this->dateTimePicker1->TabIndex = 46;
			// 
			// adminFees
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(2106, 1250);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->txtStudentID);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->txtBill);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->btnID);
			this->Controls->Add(this->txtSearch);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->btnDelete);
			this->Controls->Add(this->btnUpdate);
			this->Controls->Add(this->btnSave);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"adminFees";
			this->Text = L"adminFees";
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
			String^ studentID = txtStudentID->Text;
			String^ billAmount = txtBill->Text;
			String^ dueDate = dateTimePicker1->Value.ToString("yyyy-MM-dd");
			String^ query = "INSERT INTO fees (studentID, totalAmountBilled, dueDate) VALUES (@StudentID, @TotalAmountBilled, @DueDate)";
			db->sqlCmd->CommandText = query;
			db->sqlCmd->Parameters->Clear();
			db->sqlCmd->Parameters->AddWithValue("@StudentID", studentID);
			db->sqlCmd->Parameters->AddWithValue("@TotalAmountBilled", billAmount);
			db->sqlCmd->Parameters->AddWithValue("@DueDate", dueDate);
			int result = db->sqlCmd->ExecuteNonQuery();
			if (result > 0) {
				MessageBox::Show("Fee record saved successfully.");
				loadFees();
			}
			else {
				MessageBox::Show("Failed to save fee record.");
			}
			db->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error saving fee record: " + ex->Message);
		}
	}
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if(e->RowIndex >=0){
			DataGridViewRow^ row = dataGridView1->Rows[e->RowIndex];
			txtStudentID->Text = row->Cells["studentID"]->Value->ToString();
			txtBill->Text = row->Cells["totalAmountBilled"]->Value->ToString();
			dateTimePicker1->Value = Convert::ToDateTime(row->Cells["dueDate"]->Value);
		}
	}
	private: System::Void btnUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			db->Open();
			String^ studentID = txtStudentID->Text;
			String^ billAmount = txtBill->Text;
			String^ dueDate = dateTimePicker1->Value.ToString("yyyy-MM-dd");
			String^ query = "UPDATE fees SET totalAmountBilled = @TotalAmountBilled, dueDate = @DueDate WHERE studentID = @StudentID";
			db->sqlCmd->CommandText = query;
			db->sqlCmd->Parameters->Clear();
			db->sqlCmd->Parameters->AddWithValue("@StudentID", studentID);
			db->sqlCmd->Parameters->AddWithValue("@TotalAmountBilled", billAmount);
			db->sqlCmd->Parameters->AddWithValue("@DueDate", dueDate);
			int result = db->sqlCmd->ExecuteNonQuery();
			if (result > 0) {
				MessageBox::Show("Fee record updated successfully.");
				loadFees();
			}
			else {
				MessageBox::Show("Failed to update fee record.");
			}
			db->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error updating fee record: " + ex->Message);
		}
	}
	private: System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			db->Open();
			String^ studentID = txtStudentID->Text;
			String^ query = "DELETE FROM fees WHERE studentID = @StudentID";
			db->sqlCmd->CommandText = query;
			db->sqlCmd->Parameters->Clear();
			db->sqlCmd->Parameters->AddWithValue("@StudentID", studentID);
			int result = db->sqlCmd->ExecuteNonQuery();
			if (result > 0) {
				MessageBox::Show("Fee record deleted successfully.");
				loadFees();
			}
			else {
				MessageBox::Show("Failed to delete fee record.");
			}
			db->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error deleting fee record: " + ex->Message);
		}
	}
	private: System::Void btnID_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			db->Open();
			String^ searchTerm = txtSearch->Text;
			String^ query = "SELECT * FROM fees WHERE studentID LIKE @SearchTerm";
			db->sqlCmd->CommandText = query;
			db->sqlCmd->Parameters->Clear();
			db->sqlCmd->Parameters->AddWithValue("@SearchTerm", "%" + searchTerm + "%");
			db->sqlDR = db->sqlCmd->ExecuteReader();
			db->sqlDT->Clear();
			db->sqlDT->Load(db->sqlDR);
			dataGridView1->DataSource = db->sqlDT;
			db->sqlDR->Close();
			db->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error searching fee records: " + ex->Message);
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
