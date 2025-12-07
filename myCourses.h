#pragma once
#include "users.h"

namespace Group7FinalProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;


	/// <summary>
	/// Summary for myCourses
	/// </summary>
	public ref class myCourses : public System::Windows::Forms::Form
	{
		User^ currentUser;
	public:
		myCourses(User^ user)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			currentUser = user;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~myCourses()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ comboBoxCourse;










	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Label^ label3;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(myCourses::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBoxCourse = (gcnew System::Windows::Forms::ComboBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label1->Location = System::Drawing::Point(24, 35);
			this->label1->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(733, 63);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Course Content Management";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F));
			this->label2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label2->Location = System::Drawing::Point(30, 115);
			this->label2->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(200, 32);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Select Course:";
			// 
			// comboBoxCourse
			// 
			this->comboBoxCourse->FormattingEnabled = true;
			this->comboBoxCourse->Location = System::Drawing::Point(36, 154);
			this->comboBoxCourse->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->comboBoxCourse->Name = L"comboBoxCourse";
			this->comboBoxCourse->Size = System::Drawing::Size(462, 33);
			this->comboBoxCourse->TabIndex = 2;
			this->comboBoxCourse->SelectedIndexChanged += gcnew System::EventHandler(this, &myCourses::comboBoxCourse_SelectedIndexChanged);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->dataGridView1);
			this->panel1->Location = System::Drawing::Point(40, 315);
			this->panel1->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1302, 563);
			this->panel1->TabIndex = 5;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(10, 13);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 82;
			this->dataGridView1->Size = System::Drawing::Size(1290, 544);
			this->dataGridView1->TabIndex = 0;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F));
			this->label3->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label3->Location = System::Drawing::Point(44, 277);
			this->label3->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(429, 32);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Enrolled Students of this Course:";
			// 
			// myCourses
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Maroon;
			this->ClientSize = System::Drawing::Size(1368, 1056);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->comboBoxCourse);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->Name = L"myCourses";
			this->Text = L"My Courses";
			this->Load += gcnew System::EventHandler(this, &myCourses::myCourses_Load);
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		// Replace all instances of SqlConnection, SqlCommand, and SqlDataAdapter with MySqlConnection, MySqlCommand, and MySqlDataAdapter

private: void LoadLecturerCourses() {
	String^ connStr = "datasource=localhost;port=3306;username=root;password="";database=universitydb";

	try
	{
		int lecturerDbId = 0;
		try
		{
			lecturerDbId = safe_cast<int>(currentUser->dbID);
		}
		catch (Exception^)
		{
			MessageBox::Show(
				"Unable to read current user's DB id. Check your User class property name.",
				"Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
			return;
		}

		String^ sql =
			"SELECT courseID, courseCode, courseTitle "
			"FROM course WHERE facultyID = @facultyID";

		System::Data::DataTable^ dt = gcnew System::Data::DataTable();


		{
			MySqlConnection^ conn = gcnew MySqlConnection(connStr);
			MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);
			cmd->Parameters->AddWithValue("@facultyID", lecturerDbId);

			MySqlDataAdapter^ da = gcnew MySqlDataAdapter(cmd);
			da->Fill(dt);
		}

		if (!dt->Columns->Contains("display"))
		{
			dt->Columns->Add("display", String::typeid);

			for each (System::Data::DataRow^ row in dt->Rows)
			{
				String^ code = row["courseCode"]->ToString();
				String^ title = row["courseTitle"]->ToString();
				row["display"] = code + " - " + title;
			}
		}

		// Temporarily detach event to prevent premature firing
		comboBoxCourse->SelectedIndexChanged -= gcnew System::EventHandler(this, &myCourses::comboBoxCourse_SelectedIndexChanged);

		comboBoxCourse->DisplayMember = "display";
		comboBoxCourse->ValueMember = "courseID";
		comboBoxCourse->DataSource = dt;

		comboBoxCourse->SelectedIndexChanged += gcnew System::EventHandler(this, &myCourses::comboBoxCourse_SelectedIndexChanged);

		dataGridView1->DataSource = nullptr;
	}
	catch (Exception^ ex)
	{
		MessageBox::Show(
			"Error loading courses:\n" + ex->Message,
			"Database Error",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error
		);
	}
}
	private: System::Void myCourses_Load(System::Object^ sender, System::EventArgs^ e) {
		LoadLecturerCourses();
	}
private: System::Void comboBoxCourse_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (comboBoxCourse->SelectedValue == nullptr) return;
	if (comboBoxCourse->DataSource == nullptr) return;

	int courseId = 0;
	try
	{
		courseId = Convert::ToInt32(comboBoxCourse->SelectedValue);
	}
	catch (Exception^)
	{
		return;
	}

	String^ connStr = "datasource=localhost;port=3306;username=root;password=;database=universitydb";

	String^ sql =
		"SELECT u.dbID AS StudentDbID, u.firstName, u.lastName, "
		"s.currentLevel, cr.semester"
		"FROM courseregistration cr "
		"INNER JOIN student s ON cr.studentID = s.studentID "
		"INNER JOIN user u ON s.studentID = u.dbID "
		"WHERE cr.courseID = @courseID AND cr.status='Approved';";

	try
	{
		DataTable^ dt = gcnew DataTable();

		// Use 'using' for safe disposal
		{
			MySqlConnection^ conn = gcnew MySqlConnection(connStr);
			MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);
			cmd->Parameters->AddWithValue("@courseID", courseId);

			MySqlDataAdapter^ da = gcnew MySqlDataAdapter(cmd);
			da->Fill(dt);
		}

		// Rename column safely
		if (dt->Columns->Contains("StudentDbID"))
			dt->Columns["StudentDbID"]->ColumnName = "Student ID";

		dataGridView1->AutoGenerateColumns = true;
		dataGridView1->DataSource = dt;
	}
	catch (Exception^ ex)
	{
		MessageBox::Show("Error loading enrolled students:\n" + ex->Message,
			"Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
};
}
