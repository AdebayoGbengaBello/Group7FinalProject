

#pragma once
#include "Database.h"

namespace Group7FinalProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	public ref class CourseRegistration : public System::Windows::Forms::Form
	{
	public:
		Database^ db = gcnew Database();
		int currentStudentID;

		CourseRegistration(int sID)
		{
			InitializeComponent();
			this->currentStudentID = sID;
			LoadAvailableCourses(""); // Default load (empty string = show all)
		}

	protected:
		~CourseRegistration()
		{
			if (components) delete components;
		}

	private: System::Windows::Forms::DataGridView^ gridCourses;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnRegister;
	private: System::Windows::Forms::Button^ btnRefresh;
	private: System::Windows::Forms::Label^ lblStatus;
	private: System::Windows::Forms::TextBox^ txtSearch;
	private: System::Windows::Forms::Button^ btnSearch;
	private: System::Windows::Forms::Label^ label2;
	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			   this->gridCourses = (gcnew System::Windows::Forms::DataGridView());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->btnRegister = (gcnew System::Windows::Forms::Button());
			   this->btnRefresh = (gcnew System::Windows::Forms::Button());
			   this->lblStatus = (gcnew System::Windows::Forms::Label());
			   this->txtSearch = (gcnew System::Windows::Forms::TextBox());
			   this->btnSearch = (gcnew System::Windows::Forms::Button());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridCourses))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // gridCourses
			   // 
			   this->gridCourses->AllowUserToAddRows = false;
			   this->gridCourses->AllowUserToDeleteRows = false;
			   this->gridCourses->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			   this->gridCourses->BackgroundColor = System::Drawing::Color::White;
			   dataGridViewCellStyle2->BackColor = System::Drawing::Color::LightGray;
			   dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			   this->gridCourses->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
			   this->gridCourses->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->gridCourses->Location = System::Drawing::Point(73, 258);
			   this->gridCourses->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			   this->gridCourses->MultiSelect = false;
			   this->gridCourses->Name = L"gridCourses";
			   this->gridCourses->ReadOnly = true;
			   this->gridCourses->RowHeadersWidth = 72;
			   this->gridCourses->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			   this->gridCourses->Size = System::Drawing::Size(1283, 665);
			   this->gridCourses->TabIndex = 0;
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold));
			   this->label1->Location = System::Drawing::Point(55, 37);
			   this->label1->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(459, 62);
			   this->label1->TabIndex = 1;
			   this->label1->Text = L"Course Registration";
			   // 
			   // btnRegister
			   // 
			   this->btnRegister->BackColor = System::Drawing::Color::Brown;
			   this->btnRegister->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnRegister->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
			   this->btnRegister->ForeColor = System::Drawing::Color::White;
			   this->btnRegister->Location = System::Drawing::Point(990, 960);
			   this->btnRegister->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			   this->btnRegister->Name = L"btnRegister";
			   this->btnRegister->Size = System::Drawing::Size(367, 92);
			   this->btnRegister->TabIndex = 2;
			   this->btnRegister->Text = L"Register Selected";
			   this->btnRegister->UseVisualStyleBackColor = false;
			   this->btnRegister->Click += gcnew System::EventHandler(this, &CourseRegistration::btnRegister_Click);
			   // 
			   // btnRefresh
			   // 
			   this->btnRefresh->Location = System::Drawing::Point(843, 172);
			   this->btnRefresh->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			   this->btnRefresh->Name = L"btnRefresh";
			   this->btnRefresh->Size = System::Drawing::Size(183, 55);
			   this->btnRefresh->TabIndex = 3;
			   this->btnRefresh->Text = L"Reset List";
			   this->btnRefresh->UseVisualStyleBackColor = true;
			   this->btnRefresh->Click += gcnew System::EventHandler(this, &CourseRegistration::btnRefresh_Click);
			   // 
			   // lblStatus
			   // 
			   this->lblStatus->AutoSize = true;
			   this->lblStatus->ForeColor = System::Drawing::Color::DimGray;
			   this->lblStatus->Location = System::Drawing::Point(73, 960);
			   this->lblStatus->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			   this->lblStatus->Name = L"lblStatus";
			   this->lblStatus->Size = System::Drawing::Size(471, 25);
			   this->lblStatus->TabIndex = 4;
			   this->lblStatus->Text = L"Select a course from the list above and click Register.";
			   // 
			   // txtSearch
			   // 
			   this->txtSearch->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			   this->txtSearch->Location = System::Drawing::Point(73, 175);
			   this->txtSearch->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			   this->txtSearch->Name = L"txtSearch";
			   this->txtSearch->Size = System::Drawing::Size(547, 42);
			   this->txtSearch->TabIndex = 1;
			   // 
			   // btnSearch
			   // 
			   this->btnSearch->BackColor = System::Drawing::Color::Brown;
			   this->btnSearch->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnSearch->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			   this->btnSearch->ForeColor = System::Drawing::Color::White;
			   this->btnSearch->Location = System::Drawing::Point(642, 172);
			   this->btnSearch->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			   this->btnSearch->Name = L"btnSearch";
			   this->btnSearch->Size = System::Drawing::Size(183, 55);
			   this->btnSearch->TabIndex = 2;
			   this->btnSearch->Text = L"Search";
			   this->btnSearch->UseVisualStyleBackColor = false;
			   this->btnSearch->Click += gcnew System::EventHandler(this, &CourseRegistration::btnSearch_Click);
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			   this->label2->Location = System::Drawing::Point(73, 138);
			   this->label2->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(171, 32);
			   this->label2->TabIndex = 0;
			   this->label2->Text = L"Search Course:";
			   // 
			   // CourseRegistration
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::Color::Snow;
			   this->ClientSize = System::Drawing::Size(1467, 1108);
			   this->Controls->Add(this->label2);
			   this->Controls->Add(this->txtSearch);
			   this->Controls->Add(this->btnSearch);
			   this->Controls->Add(this->lblStatus);
			   this->Controls->Add(this->btnRefresh);
			   this->Controls->Add(this->btnRegister);
			   this->Controls->Add(this->label1);
			   this->Controls->Add(this->gridCourses);
			   this->ForeColor = System::Drawing::SystemColors::ControlText;
			   this->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			   this->Name = L"CourseRegistration";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			   this->Text = L"Register for Courses";
			   this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &CourseRegistration::CourseRegistration_FormClosed);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridCourses))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

	private: void LoadAvailableCourses(String^ searchTerm) {
		try {
			db->Open();
			String^ query = "";

			if (String::IsNullOrEmpty(searchTerm)) {
				//Fetch the courses
				query = "SELECT courseID, courseCode, courseTitle, credit FROM Course";
				db->sqlCmd->CommandText = query;
				db->sqlCmd->Parameters->Clear();
			}
			else {
				//Fetch the courses based on the search term
				query = "SELECT courseID, courseCode, courseTitle, credit FROM Course WHERE courseTitle LIKE @search OR courseCode LIKE @search";
				db->sqlCmd->CommandText = query;
				db->sqlCmd->Parameters->Clear();
				db->sqlCmd->Parameters->AddWithValue("@search", "%" + searchTerm + "%");
			}

			MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter(db->sqlCmd);
			DataTable^ dt = gcnew DataTable();
			adapter->Fill(dt);

			gridCourses->DataSource = dt;

			if (gridCourses->Columns["courseID"] != nullptr) {
				gridCourses->Columns["courseID"]->Visible = false;
			}
			if (gridCourses->Columns["courseTitle"] != nullptr) gridCourses->Columns["courseTitle"]->HeaderText = "Course Title";
			if (gridCourses->Columns["credit"] != nullptr) gridCourses->Columns["credit"]->HeaderText = "Credit";

			db->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error loading courses: " + ex->Message);
			if (db->sqlConn->State == ConnectionState::Open) db->Close();
		}
	}

		   // Search button click
	private: System::Void btnSearch_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ term = txtSearch->Text->Trim();
		LoadAvailableCourses(term);
	}

		   //Reset / Refresh button click
	private: System::Void btnRefresh_Click(System::Object^ sender, System::EventArgs^ e) {
		txtSearch->Clear();       // Clear the text box
		LoadAvailableCourses(""); // Reload everything
	}

		   // Register button click
	private: System::Void btnRegister_Click(System::Object^ sender, System::EventArgs^ e) {
		if (gridCourses->SelectedRows->Count == 0) {
			MessageBox::Show("Please select a course first.");
			return;
		}

		// UPDATED: Fetching 'courseTitle' because that is what we selected in LoadAvailableCourses
		String^ courseIDStr = gridCourses->SelectedRows[0]->Cells["courseID"]->Value->ToString();
		String^ courseTitle = gridCourses->SelectedRows[0]->Cells["courseTitle"]->Value->ToString();
		int courseID = Convert::ToInt32(courseIDStr);

		try {
			db->Open();

			// 1. Check Duplicates in 'CourseRegistration' table
			// UPDATED: Using 'studentID' and 'courseID' columns
			String^ checkQuery = "SELECT COUNT(*) FROM CourseRegistration WHERE studentID = @sid AND courseID = @cid";
			db->sqlCmd->CommandText = checkQuery;
			db->sqlCmd->Parameters->Clear();
			db->sqlCmd->Parameters->AddWithValue("@sid", this->currentStudentID);
			db->sqlCmd->Parameters->AddWithValue("@cid", courseID);

			int count = Convert::ToInt32(db->sqlCmd->ExecuteScalar());

			if (count > 0) {
				MessageBox::Show("You are already registered for " + courseTitle);
				db->Close();
				return;
			}

			// 2. Insert into 'CourseRegistration'
			// UPDATED: Using 'status' column and setting it to 'In Progress'
			String^ insertQuery = "INSERT INTO CourseRegistration (studentID, courseID, status) VALUES (@sid, @cid, 'In Progress')";
			db->sqlCmd->CommandText = insertQuery;
			db->sqlCmd->Parameters->Clear();
			db->sqlCmd->Parameters->AddWithValue("@sid", this->currentStudentID);
			db->sqlCmd->Parameters->AddWithValue("@cid", courseID);

			db->sqlCmd->ExecuteNonQuery();

			MessageBox::Show("Successfully registered for: " + courseTitle);
			lblStatus->Text = "Last Action: Registered for " + courseTitle;

			db->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Registration Failed: " + ex->Message);
			if (db->sqlConn->State == ConnectionState::Open) db->Close();
		}
	}
	private: System::Void CourseRegistration_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		// this should have the code to reload the courses in the main student form
		this->Close();
	}
};
}

