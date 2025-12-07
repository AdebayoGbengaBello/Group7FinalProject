#pragma once
#include "users.h"
#include "myCourses.h"

namespace Group7FinalProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for gradeSub
	/// </summary>
	public ref class gradeSub : public System::Windows::Forms::Form
	{
		User^ currentUser;
	public:
		gradeSub(User^ user)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			currentUser = user;
			LoadFacultyCourses();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~gradeSub()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ comboBoxCourse;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ comboBoxStudent;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ txtGrade;
	private: System::Windows::Forms::Button^ btnSaveGrade;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(gradeSub::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBoxCourse = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBoxStudent = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtGrade = (gcnew System::Windows::Forms::TextBox());
			this->btnSaveGrade = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Century Schoolbook", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label1->Location = System::Drawing::Point(12, 10);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(65, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Course:";
			this->label1->Click += gcnew System::EventHandler(this, &gradeSub::label1_Click);
			// 
			// comboBoxCourse
			// 
			this->comboBoxCourse->FormattingEnabled = true;
			this->comboBoxCourse->Location = System::Drawing::Point(82, 11);
			this->comboBoxCourse->Name = L"comboBoxCourse";
			this->comboBoxCourse->Size = System::Drawing::Size(312, 21);
			this->comboBoxCourse->TabIndex = 1;
			this->comboBoxCourse->SelectedIndexChanged += gcnew System::EventHandler(this, &gradeSub::comboBoxCourse_SelectedIndexChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Century Schoolbook", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label2->Location = System::Drawing::Point(11, 43);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(72, 20);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Student:";
			// 
			// comboBoxStudent
			// 
			this->comboBoxStudent->FormattingEnabled = true;
			this->comboBoxStudent->Location = System::Drawing::Point(82, 44);
			this->comboBoxStudent->Name = L"comboBoxStudent";
			this->comboBoxStudent->Size = System::Drawing::Size(282, 21);
			this->comboBoxStudent->TabIndex = 3;
			this->comboBoxStudent->SelectedIndexChanged += gcnew System::EventHandler(this, &gradeSub::comboBoxStudent_SelectedIndexChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Century Schoolbook", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label3->Location = System::Drawing::Point(12, 77);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(58, 20);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Grade:";
			// 
			// txtGrade
			// 
			this->txtGrade->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtGrade->Location = System::Drawing::Point(82, 77);
			this->txtGrade->Name = L"txtGrade";
			this->txtGrade->Size = System::Drawing::Size(62, 21);
			this->txtGrade->TabIndex = 5;
			// 
			// btnSaveGrade
			// 
			this->btnSaveGrade->Font = (gcnew System::Drawing::Font(L"Century Schoolbook", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSaveGrade->Location = System::Drawing::Point(237, 125);
			this->btnSaveGrade->Name = L"btnSaveGrade";
			this->btnSaveGrade->Size = System::Drawing::Size(114, 42);
			this->btnSaveGrade->TabIndex = 6;
			this->btnSaveGrade->Text = L"Save Grade Change";
			this->btnSaveGrade->UseVisualStyleBackColor = true;
			this->btnSaveGrade->Click += gcnew System::EventHandler(this, &gradeSub::btnSaveGrade_Click);
			// 
			// gradeSub
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Maroon;
			this->ClientSize = System::Drawing::Size(572, 331);
			this->Controls->Add(this->btnSaveGrade);
			this->Controls->Add(this->txtGrade);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->comboBoxStudent);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->comboBoxCourse);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"gradeSub";
			this->Text = L"Grade Submission";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private: void LoadFacultyCourses()
		{
			String^ connStr = "datasource=localhost;port=3306;username=root;password=;database=universitydb";

			try
			{
				int facultyID = safe_cast<int>(currentUser->dbID);
				String^ sql = "SELECT courseID, courseCode, courseTitle FROM course WHERE facultyID=@facultyID";

				DataTable^ dt = gcnew DataTable();
				MySqlConnection^ conn = gcnew MySqlConnection(connStr);
				MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);
				cmd->Parameters->AddWithValue("@facultyID", facultyID);

				MySqlDataAdapter^ da = gcnew MySqlDataAdapter(cmd);
				da->Fill(dt);

				// Create display column such as "BIT101 - Intro to IT"
				if (!dt->Columns->Contains("display"))
				{
					dt->Columns->Add("display", String::typeid);

					for each (DataRow ^ row in dt->Rows)
					{
						row["display"] = row["courseCode"]->ToString() + " - " + row["courseTitle"]->ToString();
					}
				}

				comboBoxCourse->DisplayMember = "display";
				comboBoxCourse->ValueMember = "courseID";
				comboBoxCourse->DataSource = dt;
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("Error loading courses: " + ex->Message);
			}
		}


	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void comboBoxCourse_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (comboBoxCourse->SelectedValue == nullptr)
			return;

		int courseID = safe_cast<int>(comboBoxCourse->SelectedValue);
		String^ connStr = "datasource=localhost;port=3306;username=root;password="";database=universitydb";

		try
		{
			String^ sql =
				"SELECT u.dbID AS StudentDbID, u.firstName, u.lastName "
				"FROM courseregistration cr "
				"INNER JOIN student s ON cr.studentID = s.studentID "
				"INNER JOIN user u ON s.studentID = u.dbID "
				"WHERE cr.courseID=@courseID";

			DataTable^ dt = gcnew DataTable();
			MySqlConnection^ conn = gcnew MySqlConnection(connStr);
			MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);
			cmd->Parameters->AddWithValue("@courseID", courseID);

			MySqlDataAdapter^ da = gcnew MySqlDataAdapter(cmd);
			da->Fill(dt);

			// Add display column for student names
			if (!dt->Columns->Contains("display"))
			{
				dt->Columns->Add("display", String::typeid);

				for each (DataRow ^ row in dt->Rows)
				{
					row["display"] = row["firstName"]->ToString() + " " + row["lastName"]->ToString();
				}
			}

			comboBoxStudent->DisplayMember = "display";
			comboBoxStudent->ValueMember = "StudentDbID";
			comboBoxStudent->DataSource = dt;
		}
		catch (Exception^ ex)
		{
			MessageBox::Show("Error loading students: " + ex->Message);
		}
	}
private: System::Void comboBoxStudent_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void btnSaveGrade_Click(System::Object^ sender, System::EventArgs^ e) {
	if (comboBoxCourse->SelectedValue == nullptr || comboBoxStudent->SelectedValue == nullptr || txtGrade->Text->Length == 0)
	{
		MessageBox::Show("Please select a course, a student, and enter a grade.", "Input Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}

	int courseID = safe_cast<int>(comboBoxCourse->SelectedValue);
	int studentID = safe_cast<int>(comboBoxStudent->SelectedValue);
	String^ grade = txtGrade->Text;

	String^ connStr = "datasource=localhost;port=3306;username=root;password="";database=universitydb";

	try
	{
		MySqlConnection^ conn = gcnew MySqlConnection(connStr);

		// Check if grade already exists (update)
		MySqlCommand^ checkCmd = gcnew MySqlCommand(
			"SELECT gradeID FROM grade WHERE studentID=@studentID AND courseID=@courseID",
			conn
		);
		checkCmd->Parameters->AddWithValue("@studentID", studentID);
		checkCmd->Parameters->AddWithValue("@courseID", courseID);

		conn->Open();
		Object^ result = checkCmd->ExecuteScalar();

		if (result != nullptr)
		{
			// UPDATE
			MySqlCommand^ updateCmd = gcnew MySqlCommand(
				"UPDATE grade SET letterGrade=@grade WHERE studentID=@studentID AND courseID=@courseID",
				conn
			);
			updateCmd->Parameters->AddWithValue("@grade", grade);
			updateCmd->Parameters->AddWithValue("@studentID", studentID);
			updateCmd->Parameters->AddWithValue("@courseID", courseID);

			updateCmd->ExecuteNonQuery();
			conn->Close();

			MessageBox::Show("Grade updated successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else
		{
			// INSERT NEW
			MySqlCommand^ insertCmd = gcnew MySqlCommand(
				"INSERT INTO grade (studentID, courseID, letterGrade) VALUES (@studentID, @courseID, @grade)",
				conn
			);
			insertCmd->Parameters->AddWithValue("@grade", grade);
			insertCmd->Parameters->AddWithValue("@studentID", studentID);
			insertCmd->Parameters->AddWithValue("@courseID", courseID);

			insertCmd->ExecuteNonQuery();
			conn->Close();

			MessageBox::Show("Grade saved successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}
	catch (Exception^ ex)
	{
		MessageBox::Show("Error saving grade: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
};
}
