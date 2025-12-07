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
	/// Summary for adminPaymentsh
	/// </summary>
	public ref class adminPayments : public System::Windows::Forms::Form
	{
		Database^ db = gcnew Database();
		User^ currentUser;
	private: System::Windows::Forms::Button^ btnDashboard;
		   int globalPaymentID = -1;
	public:
		adminPayments(User^ user)
		{
			currentUser = user;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			lblUser->Text = "Hello " + currentUser->name;
			loadPayments();

		}
		void loadPayments() {
			try {
				db->Open();
				db->sqlCmd->CommandText = "SELECT p.transactionID, p.studentID, concat(u.firstName, ' ', u.lastName) as studentName, p.amount, p.transactionDate, p.description, p.status FROM paymenttransaction p JOIN student s ON p.studentID = s.studentID JOIN user u ON s.studentID = u.dbID ORDER BY p.transactionID DESC";
				db->sqlDR = db->sqlCmd->ExecuteReader();
				db->sqlDT->Clear();
				db->sqlDT->Load(db->sqlDR);
				dataGridView1->DataSource = db->sqlDT;
				dataGridView1->Columns[0]->Width = 80;
				dataGridView1->Columns[1]->Width = 80;
				dataGridView1->Columns[2]->Width = 200;
				dataGridView1->Columns[3]->Width = 100;
				dataGridView1->Columns[4]->Width = 150;
				dataGridView1->Columns[5]->Width = 100;
				dataGridView1->Columns[6]->Width = 100;
				dataGridView1->Columns[0]->HeaderText = "Transaction ID";
				dataGridView1->Columns[1]->HeaderText = "Student ID";
				dataGridView1->Columns[2]->HeaderText = "Student Name";
				dataGridView1->Columns[3]->HeaderText = "Amount";
				dataGridView1->Columns[4]->HeaderText = "Transaction Date";
				dataGridView1->Columns[5]->HeaderText = "Description";
				dataGridView1->Columns[6]->HeaderText = "Status";
				dataGridView1->AutoResizeRows();
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
		~adminPayments()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnStatus;
	protected:

	private: System::Windows::Forms::Button^ btnSID;

	protected:

	private: System::Windows::Forms::Button^ btnID;
	private: System::Windows::Forms::TextBox^ txtSearch;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ btnReject;
	private: System::Windows::Forms::Button^ btnApprove;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ lblWelcome;
	private: System::Windows::Forms::Panel^ panel1;

	private: System::Windows::Forms::Button^ btnEnrollment;
	private: System::Windows::Forms::Button^ btnProgrammes;
	private: System::Windows::Forms::Label^ lblUser;
	private: System::Windows::Forms::Button^ btnCourses;
	private: System::Windows::Forms::Button^ btnDepartment;
	private: System::Windows::Forms::Button^ btnFaculty;
	private: System::Windows::Forms::Button^ btnStudents;

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
			this->btnStatus = (gcnew System::Windows::Forms::Button());
			this->btnSID = (gcnew System::Windows::Forms::Button());
			this->btnID = (gcnew System::Windows::Forms::Button());
			this->txtSearch = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->btnReject = (gcnew System::Windows::Forms::Button());
			this->btnApprove = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->lblWelcome = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->btnDashboard = (gcnew System::Windows::Forms::Button());
			this->btnEnrollment = (gcnew System::Windows::Forms::Button());
			this->btnProgrammes = (gcnew System::Windows::Forms::Button());
			this->lblUser = (gcnew System::Windows::Forms::Label());
			this->btnCourses = (gcnew System::Windows::Forms::Button());
			this->btnDepartment = (gcnew System::Windows::Forms::Button());
			this->btnFaculty = (gcnew System::Windows::Forms::Button());
			this->btnStudents = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnStatus
			// 
			this->btnStatus->BackColor = System::Drawing::Color::Maroon;
			this->btnStatus->FlatAppearance->BorderColor = System::Drawing::Color::Maroon;
			this->btnStatus->FlatAppearance->BorderSize = 0;
			this->btnStatus->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnStatus->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnStatus->ForeColor = System::Drawing::Color::White;
			this->btnStatus->Location = System::Drawing::Point(1215, 1058);
			this->btnStatus->Name = L"btnStatus";
			this->btnStatus->Size = System::Drawing::Size(298, 50);
			this->btnStatus->TabIndex = 122;
			this->btnStatus->Text = L"By Status";
			this->btnStatus->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnStatus->UseVisualStyleBackColor = false;
			this->btnStatus->Click += gcnew System::EventHandler(this, &adminPayments::btnStatus_Click);
			// 
			// btnSID
			// 
			this->btnSID->BackColor = System::Drawing::Color::Maroon;
			this->btnSID->FlatAppearance->BorderColor = System::Drawing::Color::Maroon;
			this->btnSID->FlatAppearance->BorderSize = 0;
			this->btnSID->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSID->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSID->ForeColor = System::Drawing::Color::White;
			this->btnSID->Location = System::Drawing::Point(1215, 970);
			this->btnSID->Name = L"btnSID";
			this->btnSID->Size = System::Drawing::Size(298, 50);
			this->btnSID->TabIndex = 121;
			this->btnSID->Text = L"By Student ID";
			this->btnSID->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnSID->UseVisualStyleBackColor = false;
			this->btnSID->Click += gcnew System::EventHandler(this, &adminPayments::btnSID_Click);
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
			this->btnID->Location = System::Drawing::Point(1215, 868);
			this->btnID->Name = L"btnID";
			this->btnID->Size = System::Drawing::Size(298, 50);
			this->btnID->TabIndex = 120;
			this->btnID->Text = L"By ID";
			this->btnID->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnID->UseVisualStyleBackColor = false;
			this->btnID->Click += gcnew System::EventHandler(this, &adminPayments::btnID_Click);
			// 
			// txtSearch
			// 
			this->txtSearch->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtSearch->Location = System::Drawing::Point(562, 969);
			this->txtSearch->Name = L"txtSearch";
			this->txtSearch->Size = System::Drawing::Size(605, 43);
			this->txtSearch->TabIndex = 119;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(368, 969);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(101, 37);
			this->label2->TabIndex = 118;
			this->label2->Text = L"Search:";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(502, 433);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 82;
			this->dataGridView1->RowTemplate->Height = 33;
			this->dataGridView1->Size = System::Drawing::Size(1261, 397);
			this->dataGridView1->TabIndex = 117;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &adminPayments::dataGridView1_CellContentClick);
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
			this->btnReject->Location = System::Drawing::Point(1331, 312);
			this->btnReject->Name = L"btnReject";
			this->btnReject->Size = System::Drawing::Size(182, 56);
			this->btnReject->TabIndex = 116;
			this->btnReject->Text = L"Reject";
			this->btnReject->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnReject->UseVisualStyleBackColor = false;
			this->btnReject->Click += gcnew System::EventHandler(this, &adminPayments::btnReject_Click);
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
			this->btnApprove->Location = System::Drawing::Point(758, 312);
			this->btnApprove->Name = L"btnApprove";
			this->btnApprove->Size = System::Drawing::Size(182, 56);
			this->btnApprove->TabIndex = 115;
			this->btnApprove->Text = L"Approve";
			this->btnApprove->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnApprove->UseVisualStyleBackColor = false;
			this->btnApprove->Click += gcnew System::EventHandler(this, &adminPayments::btnApprove_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->Controls->Add(this->lblWelcome);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(280, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1713, 80);
			this->panel2->TabIndex = 114;
			// 
			// lblWelcome
			// 
			this->lblWelcome->AutoSize = true;
			this->lblWelcome->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblWelcome->ForeColor = System::Drawing::Color::Maroon;
			this->lblWelcome->Location = System::Drawing::Point(603, 9);
			this->lblWelcome->Name = L"lblWelcome";
			this->lblWelcome->Size = System::Drawing::Size(371, 45);
			this->lblWelcome->TabIndex = 0;
			this->lblWelcome->Text = L"Payments Management";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Maroon;
			this->panel1->Controls->Add(this->btnDashboard);
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
			this->panel1->Size = System::Drawing::Size(280, 1279);
			this->panel1->TabIndex = 113;
			// 
			// btnDashboard
			// 
			this->btnDashboard->FlatAppearance->BorderSize = 0;
			this->btnDashboard->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDashboard->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDashboard->ForeColor = System::Drawing::Color::White;
			this->btnDashboard->Location = System::Drawing::Point(24, 157);
			this->btnDashboard->Name = L"btnDashboard";
			this->btnDashboard->Size = System::Drawing::Size(197, 82);
			this->btnDashboard->TabIndex = 9;
			this->btnDashboard->Text = L"Dashboard";
			this->btnDashboard->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnDashboard->UseVisualStyleBackColor = true;
			this->btnDashboard->Click += gcnew System::EventHandler(this, &adminPayments::btnDashboard_Click);
			// 
			// btnEnrollment
			// 
			this->btnEnrollment->FlatAppearance->BorderSize = 0;
			this->btnEnrollment->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnEnrollment->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnEnrollment->ForeColor = System::Drawing::Color::White;
			this->btnEnrollment->Location = System::Drawing::Point(24, 702);
			this->btnEnrollment->Name = L"btnEnrollment";
			this->btnEnrollment->Size = System::Drawing::Size(182, 75);
			this->btnEnrollment->TabIndex = 7;
			this->btnEnrollment->Text = L"Enrollment";
			this->btnEnrollment->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnEnrollment->UseVisualStyleBackColor = true;
			this->btnEnrollment->Click += gcnew System::EventHandler(this, &adminPayments::btnEnrollment_Click);
			// 
			// btnProgrammes
			// 
			this->btnProgrammes->FlatAppearance->BorderSize = 0;
			this->btnProgrammes->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnProgrammes->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnProgrammes->ForeColor = System::Drawing::Color::White;
			this->btnProgrammes->Location = System::Drawing::Point(24, 614);
			this->btnProgrammes->Name = L"btnProgrammes";
			this->btnProgrammes->Size = System::Drawing::Size(228, 68);
			this->btnProgrammes->TabIndex = 6;
			this->btnProgrammes->Text = L"Programmes";
			this->btnProgrammes->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnProgrammes->UseVisualStyleBackColor = true;
			this->btnProgrammes->Click += gcnew System::EventHandler(this, &adminPayments::btnProgrammes_Click);
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
			this->btnCourses->Location = System::Drawing::Point(24, 533);
			this->btnCourses->Name = L"btnCourses";
			this->btnCourses->Size = System::Drawing::Size(182, 75);
			this->btnCourses->TabIndex = 4;
			this->btnCourses->Text = L"Courses";
			this->btnCourses->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnCourses->UseVisualStyleBackColor = true;
			this->btnCourses->Click += gcnew System::EventHandler(this, &adminPayments::btnCourses_Click);
			// 
			// btnDepartment
			// 
			this->btnDepartment->FlatAppearance->BorderSize = 0;
			this->btnDepartment->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDepartment->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDepartment->ForeColor = System::Drawing::Color::White;
			this->btnDepartment->Location = System::Drawing::Point(24, 446);
			this->btnDepartment->Name = L"btnDepartment";
			this->btnDepartment->Size = System::Drawing::Size(228, 64);
			this->btnDepartment->TabIndex = 3;
			this->btnDepartment->Text = L"Departments";
			this->btnDepartment->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnDepartment->UseVisualStyleBackColor = true;
			this->btnDepartment->Click += gcnew System::EventHandler(this, &adminPayments::btnDepartment_Click);
			// 
			// btnFaculty
			// 
			this->btnFaculty->FlatAppearance->BorderSize = 0;
			this->btnFaculty->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnFaculty->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnFaculty->ForeColor = System::Drawing::Color::White;
			this->btnFaculty->Location = System::Drawing::Point(24, 359);
			this->btnFaculty->Name = L"btnFaculty";
			this->btnFaculty->Size = System::Drawing::Size(182, 81);
			this->btnFaculty->TabIndex = 2;
			this->btnFaculty->Text = L"Faculty";
			this->btnFaculty->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnFaculty->UseVisualStyleBackColor = true;
			this->btnFaculty->Click += gcnew System::EventHandler(this, &adminPayments::btnFaculty_Click);
			// 
			// btnStudents
			// 
			this->btnStudents->FlatAppearance->BorderSize = 0;
			this->btnStudents->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnStudents->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnStudents->ForeColor = System::Drawing::Color::White;
			this->btnStudents->Location = System::Drawing::Point(24, 270);
			this->btnStudents->Name = L"btnStudents";
			this->btnStudents->Size = System::Drawing::Size(182, 66);
			this->btnStudents->TabIndex = 0;
			this->btnStudents->Text = L"Students";
			this->btnStudents->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnStudents->UseVisualStyleBackColor = true;
			this->btnStudents->Click += gcnew System::EventHandler(this, &adminPayments::btnStudents_Click);
			// 
			// adminPayments
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1993, 1279);
			this->Controls->Add(this->btnStatus);
			this->Controls->Add(this->btnSID);
			this->Controls->Add(this->btnID);
			this->Controls->Add(this->txtSearch);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->btnReject);
			this->Controls->Add(this->btnApprove);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"adminPayments";
			this->Text = L"adminPaymentsh";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnApprove_Click(System::Object^ sender, System::EventArgs^ e) {
		if (globalPaymentID != -1) {
			try {
				db->Open();
				db->sqlCmd->CommandText = "UPDATE paymenttransaction SET status = 'Approved' WHERE transactionID = @paymentID";
				db->sqlCmd->Parameters->AddWithValue("@paymentID", globalPaymentID);
				int result = db->sqlCmd->ExecuteNonQuery();
				if (result > 0) {
					MessageBox::Show("Payment approved successfully.");
					loadPayments();
					globalPaymentID = -1;
				}
				else {
					MessageBox::Show("Failed to approve payment.");
				}
				db->sqlCmd->Parameters->Clear();
				db->Close();
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}
		}
		else {
			MessageBox::Show("Please select a payment to approve.");
		}
	}
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (e->RowIndex >= 0) {
			DataGridViewRow^ row = this->dataGridView1->Rows[e->RowIndex];
			globalPaymentID = Int32::Parse(row->Cells[0]->Value->ToString());
		}
	}
	private: System::Void btnReject_Click(System::Object^ sender, System::EventArgs^ e) {
		if (globalPaymentID != -1) {
			try {
				db->Open();
				db->sqlCmd->CommandText = "UPDATE paymenttransaction SET status = 'Rejected' WHERE transactionID = @paymentID";
				db->sqlCmd->Parameters->AddWithValue("@paymentID", globalPaymentID);
				int result = db->sqlCmd->ExecuteNonQuery();
				if (result > 0) {
					MessageBox::Show("Payment rejected successfully.");
					loadPayments();
					globalPaymentID = -1;
				}
				else {
					MessageBox::Show("Failed to reject payment.");
				}
				db->sqlCmd->Parameters->Clear();
				db->Close();
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}
		}
		else {
			MessageBox::Show("Please select a payment to reject.");
		}
	}
	private: System::Void btnID_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ searchTerm = txtSearch->Text->Trim();
		if (searchTerm != "") {
			try {
				db->Open();
				db->sqlCmd->CommandText = "SELECT p.transactionID, p.studentID, concat(u.firstName, ' ', u.lastName) as studentName, p.amount, p.transactionDate, p.description, p.status FROM paymenttransaction p JOIN student s ON p.studentID = s.studentID JOIN user u ON s.studentID = u.dbID WHERE p.transactionID = @searchTerm ORDER BY p.transactionID DESC";
				db->sqlCmd->Parameters->AddWithValue("@searchTerm", searchTerm);
				db->sqlDR = db->sqlCmd->ExecuteReader();
				db->sqlDT->Clear();
				db->sqlDT->Load(db->sqlDR);
				dataGridView1->DataSource = db->sqlDT;
				dataGridView1->AutoResizeRows();
				db->sqlDR->Close();
				db->sqlCmd->Parameters->Clear();
				db->Close();
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}
		}
		else {
			loadPayments();
		}
	}

	private: System::Void btnSID_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ searchTerm = txtSearch->Text->Trim();
		if (searchTerm != "") {
			try {
				db->Open();
				db->sqlCmd->CommandText = "SELECT p.transactionID, p.studentID, concat(u.firstName, ' ', u.lastName) as studentName, p.amount, p.transactionDate, p.description, p.status FROM paymenttransaction p JOIN student s ON p.studentID = s.studentID JOIN user u ON s.studentID = u.dbID WHERE p.studentID = @searchTerm ORDER BY p.transactionID DESC";
				db->sqlCmd->Parameters->AddWithValue("@searchTerm", searchTerm);
				db->sqlDR = db->sqlCmd->ExecuteReader();
				db->sqlDT->Clear();
				db->sqlDT->Load(db->sqlDR);
				dataGridView1->DataSource = db->sqlDT;
				dataGridView1->AutoResizeRows();
				db->sqlDR->Close();
				db->sqlCmd->Parameters->Clear();
				db->Close();
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}
		}
		else {
			loadPayments();
		}
	}
	private: System::Void btnStatus_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ searchTerm = txtSearch->Text->Trim();
		if (searchTerm != "") {
			try {
				db->Open();
				db->sqlCmd->CommandText = "SELECT p.transactionID, p.studentID, concat(u.firstName, ' ', u.lastName) as studentName, p.amount, p.transactionDate, p.description, p.status FROM paymenttransaction p JOIN student s ON p.studentID = s.studentID JOIN user u ON s.studentID = u.dbID WHERE p.status = @searchTerm ORDER BY p.transactionID DESC";
				db->sqlCmd->Parameters->AddWithValue("@searchTerm", searchTerm);
				db->sqlDR = db->sqlCmd->ExecuteReader();
				db->sqlDT->Clear();
				db->sqlDT->Load(db->sqlDR);
				dataGridView1->DataSource = db->sqlDT;
				dataGridView1->AutoResizeRows();
				db->sqlDR->Close();
				db->sqlCmd->Parameters->Clear();
				db->Close();
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}
		}
		else {
			loadPayments();
		}
	}
	private: System::Void btnDashboard_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnStudents_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnFaculty_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnDepartment_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnCourses_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnProgrammes_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnEnrollment_Click(System::Object^ sender, System::EventArgs^ e);
};
}
