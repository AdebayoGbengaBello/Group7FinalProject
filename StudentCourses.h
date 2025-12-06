#pragma once
#include "Database.h"

namespace Group7FinalProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for StudentCourses
	/// </summary>
	public ref class StudentCourses : public System::Windows::Forms::Form
	{
	public:
		Database^ db = gcnew Database();
		DataTable^ dtCourses = gcnew DataTable();
		int currentStudentID = 2;

		StudentCourses(/*int userID*/)
		{
			//currentStudentID = userID;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			LoadStudentCourses();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~StudentCourses()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^ cmbSemester;
	protected:
	private: System::Windows::Forms::TextBox^ txtSearch;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Label^ label2;

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
			this->AutoScroll = true;
			this->cmbSemester = (gcnew System::Windows::Forms::ComboBox());
			this->txtSearch = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// cmbSemester
			// 
			this->cmbSemester->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->cmbSemester->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.14286F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cmbSemester->FormattingEnabled = true;
			this->cmbSemester->Location = System::Drawing::Point(900, 142);
			this->cmbSemester->Name = L"cmbSemester";
			this->cmbSemester->Size = System::Drawing::Size(189, 38);
			this->cmbSemester->TabIndex = 13;
			this->cmbSemester->Text = L"  Fall 2025";
			// 
			// txtSearch
			// 
			this->txtSearch->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtSearch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtSearch->Location = System::Drawing::Point(96, 143);
			this->txtSearch->Name = L"txtSearch";
			this->txtSearch->Size = System::Drawing::Size(384, 39);
			this->txtSearch->TabIndex = 12;
			this->txtSearch->Text = L" Search courses..";
			this->txtSearch->TextChanged += gcnew System::EventHandler(this, &StudentCourses::txtSearch_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.14286F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(44, 37);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(291, 55);
			this->label1->TabIndex = 11;
			this->label1->Text = L"My Courses";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(54, 234);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 72;
			this->dataGridView1->RowTemplate->Height = 31;
			this->dataGridView1->Size = System::Drawing::Size(1035, 565);
			this->dataGridView1->TabIndex = 10;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.14286F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(36, 143);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(55, 39);
			this->label2->TabIndex = 14;
			this->label2->Text = L"🔍";

			// 
			// StudentCourses
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1148, 1066);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->cmbSemester);
			this->Controls->Add(this->txtSearch);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"StudentCourses";
			this->Text = L"StudentCourses";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: void LoadStudentCourses() {
		try {
			db->Open();

			// Join Registration -> Course -> Faculty -> User (to get Instructor Name)
			String^ query = "SELECT c.courseCode AS 'Course Code', c.courseTitle AS 'Title', "
				"CONCAT(u.firstName, ' ', u.lastName) AS 'Instructor', "
				"c.credit AS 'Credits', cr.status AS 'Grade' "
				"FROM CourseRegistration cr "
				"JOIN Course c ON cr.courseID = c.courseID "
				"LEFT JOIN Faculty f ON c.facultyID = f.facultyID "
				"LEFT JOIN User u ON f.facultyID = u.dbID "
				"WHERE cr.studentID = " + currentStudentID;

			db->sqlDA = gcnew MySql::Data::MySqlClient::MySqlDataAdapter(query, db->sqlConn);
			dtCourses = gcnew DataTable();
			db->sqlDA->Fill(dtCourses);

			// Bind to Grid
			dataGridView1->DataSource = dtCourses;

			db->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error loading courses: " + ex->Message);
			if (db->sqlConn->State == ConnectionState::Open) db->Close();
		}
	}
private: System::Void txtSearch_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	try {
		String^ searchValue = txtSearch->Text->Trim();

		// If search is "Search courses.." placeholder, do nothing
		if (searchValue == "Search courses.." || String::IsNullOrEmpty(searchValue)) {
			(safe_cast<DataTable^>(dataGridView1->DataSource))->DefaultView->RowFilter = "";
		}
		else {
			// Filter by Course Code OR Title
			String^ filter = "[Course Code] LIKE '%" + searchValue + "%' OR [Title] LIKE '%" + searchValue + "%'";
			(safe_cast<DataTable^>(dataGridView1->DataSource))->DefaultView->RowFilter = filter;
		}
	}
	catch (Exception^) {
		// Ignore errors during typing
	}
}
};
}
