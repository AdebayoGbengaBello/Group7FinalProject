#pragma once
#include "Database.h"
#include "StudentProfile.h"
#include "TranscriptView.h"
#include "StudentCourses.h"
#include "PaymentView.h"
#include "CourseRegistration.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO; // Added for handling Images

namespace Group7FinalProject {

	public ref class StudentMain : public System::Windows::Forms::Form
	{
	public:
		// Create the database instance
		Database^ db = gcnew Database();
		int currentStudentID;
	private: System::Windows::Forms::ToolStripMenuItem^ courseRegistrationToolStripMenuItem;
	public:
		

		StudentMain(int userID)
		{
			currentStudentID = userID;
			InitializeComponent();
			
			// Call our custom function to load data from DB
			LoadDashboardData();
			
			
		}



	protected:
		~StudentMain()
		{
			if (components)
			{
				delete components;
			}
		}

	// =========================================================================
	// DO NOT EDIT BELOW THIS LINE (DESIGNER CODE)
	// =========================================================================
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem3;
	private: System::Windows::Forms::ToolStripMenuItem^ profileToolStripMenuItem;

	private: System::Windows::Forms::Label^ txtSemester2;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Label^ txtUserName;
	private: System::Windows::Forms::Label^ txtSemester;
	private: System::Windows::Forms::PictureBox^ profilePictureBox;
	private: System::Windows::Forms::Label^ txtCurrentSem;
	private: System::Windows::Forms::Label^ txtStudentName;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Label^ txtFee;
	private: System::Windows::Forms::Label^ txtCredit;
	private: System::Windows::Forms::Label^ txtCGPA;

	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(StudentMain::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->profileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->courseRegistrationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->txtSemester2 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->txtUserName = (gcnew System::Windows::Forms::Label());
			this->txtSemester = (gcnew System::Windows::Forms::Label());
			this->profilePictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->txtCurrentSem = (gcnew System::Windows::Forms::Label());
			this->txtStudentName = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->txtFee = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->txtCredit = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->txtCGPA = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->menuStrip1->SuspendLayout();
			this->panel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->profilePictureBox))->BeginInit();
			this->panel3->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->menuStrip1->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(28, 28);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->profileToolStripMenuItem,
					this->courseRegistrationToolStripMenuItem, this->toolStripMenuItem1, this->toolStripMenuItem2, this->toolStripMenuItem3
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1126, 38);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// profileToolStripMenuItem
			// 
			this->profileToolStripMenuItem->Name = L"profileToolStripMenuItem";
			this->profileToolStripMenuItem->Size = System::Drawing::Size(119, 34);
			this->profileToolStripMenuItem->Text = L"👤Profile";
			this->profileToolStripMenuItem->Click += gcnew System::EventHandler(this, &StudentMain::profileToolStripMenuItem_Click);
			// 
			// courseRegistrationToolStripMenuItem
			// 
			this->courseRegistrationToolStripMenuItem->Name = L"courseRegistrationToolStripMenuItem";
			this->courseRegistrationToolStripMenuItem->Size = System::Drawing::Size(246, 34);
			this->courseRegistrationToolStripMenuItem->Text = L"📖 Course Registration";
			this->courseRegistrationToolStripMenuItem->Click += gcnew System::EventHandler(this, &StudentMain::courseRegistrationToolStripMenuItem_Click);
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(168, 34);
			this->toolStripMenuItem1->Text = L"📕My Courses";
			this->toolStripMenuItem1->Click += gcnew System::EventHandler(this, &StudentMain::toolStripMenuItem1_Click);
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(149, 34);
			this->toolStripMenuItem2->Text = L"🧾Transcript";
			this->toolStripMenuItem2->Click += gcnew System::EventHandler(this, &StudentMain::toolStripMenuItem2_Click);
			// 
			// toolStripMenuItem3
			// 
			this->toolStripMenuItem3->Name = L"toolStripMenuItem3";
			this->toolStripMenuItem3->Size = System::Drawing::Size(178, 34);
			this->toolStripMenuItem3->Text = L"💳Fee Payment";
			this->toolStripMenuItem3->Click += gcnew System::EventHandler(this, &StudentMain::toolStripMenuItem3_Click);
			// 
			// txtSemester2
			// 
			this->txtSemester2->AutoSize = true;
			this->txtSemester2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.14286F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtSemester2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->txtSemester2->Location = System::Drawing::Point(426, 575);
			this->txtSemester2->Name = L"txtSemester2";
			this->txtSemester2->Size = System::Drawing::Size(230, 55);
			this->txtSemester2->TabIndex = 15;
			this->txtSemester2->Text = L"Fall 2024";
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel4->Controls->Add(this->txtUserName);
			this->panel4->Controls->Add(this->txtSemester);
			this->panel4->Controls->Add(this->profilePictureBox);
			this->panel4->Controls->Add(this->txtCurrentSem);
			this->panel4->Controls->Add(this->txtStudentName);
			this->panel4->Location = System::Drawing::Point(48, 116);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(1014, 218);
			this->panel4->TabIndex = 14;
			// 
			// txtUserName
			// 
			this->txtUserName->AutoSize = true;
			this->txtUserName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.14286F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtUserName->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->txtUserName->Location = System::Drawing::Point(434, 38);
			this->txtUserName->Name = L"txtUserName";
			this->txtUserName->Size = System::Drawing::Size(176, 39);
			this->txtUserName->TabIndex = 5;
			this->txtUserName->Text = L"Alex John";
			// 
			// txtSemester
			// 
			this->txtSemester->AutoSize = true;
			this->txtSemester->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.14286F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtSemester->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->txtSemester->Location = System::Drawing::Point(568, 91);
			this->txtSemester->Name = L"txtSemester";
			this->txtSemester->Size = System::Drawing::Size(167, 39);
			this->txtSemester->TabIndex = 4;
			this->txtSemester->Text = L"Fall 2024";
			// 
			// profilePictureBox
			// 
			this->profilePictureBox->Enabled = false;
			this->profilePictureBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"profilePictureBox.Image")));
			this->profilePictureBox->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"profilePictureBox.InitialImage")));
			this->profilePictureBox->Location = System::Drawing::Point(21, 18);
			this->profilePictureBox->Name = L"profilePictureBox";
			this->profilePictureBox->Size = System::Drawing::Size(189, 178);
			this->profilePictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->profilePictureBox->TabIndex = 3;
			this->profilePictureBox->TabStop = false;
			// 
			// txtCurrentSem
			// 
			this->txtCurrentSem->AutoSize = true;
			this->txtCurrentSem->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.14286F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtCurrentSem->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->txtCurrentSem->Location = System::Drawing::Point(252, 91);
			this->txtCurrentSem->Name = L"txtCurrentSem";
			this->txtCurrentSem->Size = System::Drawing::Size(310, 39);
			this->txtCurrentSem->TabIndex = 2;
			this->txtCurrentSem->Text = L"Current Semester:";
			// 
			// txtStudentName
			// 
			this->txtStudentName->AutoSize = true;
			this->txtStudentName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.14286F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtStudentName->Location = System::Drawing::Point(252, 38);
			this->txtStudentName->Name = L"txtStudentName";
			this->txtStudentName->Size = System::Drawing::Size(176, 39);
			this->txtStudentName->TabIndex = 1;
			this->txtStudentName->Text = L"Welcome,";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.14286F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(38, 575);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(368, 55);
			this->label1->TabIndex = 13;
			this->label1->Text = L"Current Course";
			// 
			// panel3
			// 
			this->panel3->AutoSize = true;
			this->panel3->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel3->Controls->Add(this->txtFee);
			this->panel3->Controls->Add(this->label4);
			this->panel3->Location = System::Drawing::Point(767, 392);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(295, 136);
			this->panel3->TabIndex = 12;
			// 
			// txtFee
			// 
			this->txtFee->AutoSize = true;
			this->txtFee->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->txtFee->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtFee->Location = System::Drawing::Point(18, 69);
			this->txtFee->Name = L"txtFee";
			this->txtFee->Size = System::Drawing::Size(104, 48);
			this->txtFee->TabIndex = 5;
			this->txtFee->Text = L" 800";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(21, 17);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(167, 25);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Outstanding Fees";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel2->Controls->Add(this->txtCredit);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Location = System::Drawing::Point(411, 392);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(295, 136);
			this->panel2->TabIndex = 11;
			// 
			// txtCredit
			// 
			this->txtCredit->AutoSize = true;
			this->txtCredit->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->txtCredit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtCredit->Location = System::Drawing::Point(17, 69);
			this->txtCredit->Name = L"txtCredit";
			this->txtCredit->Size = System::Drawing::Size(68, 48);
			this->txtCredit->TabIndex = 4;
			this->txtCredit->Text = L"35";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(20, 17);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(142, 25);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Credits Earned";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->panel1->Controls->Add(this->txtCGPA);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Location = System::Drawing::Point(53, 392);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(295, 136);
			this->panel1->TabIndex = 10;
			// 
			// txtCGPA
			// 
			this->txtCGPA->AutoSize = true;
			this->txtCGPA->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->txtCGPA->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtCGPA->Location = System::Drawing::Point(18, 69);
			this->txtCGPA->Name = L"txtCGPA";
			this->txtCGPA->Size = System::Drawing::Size(81, 48);
			this->txtCGPA->TabIndex = 5;
			this->txtCGPA->Text = L"3.8";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(21, 17);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(69, 25);
			this->label3->TabIndex = 1;
			this->label3->Text = L"CGPA";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(37, 674);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 72;
			this->dataGridView1->RowTemplate->Height = 31;
			this->dataGridView1->Size = System::Drawing::Size(1035, 565);
			this->dataGridView1->TabIndex = 9;
			// 
			// StudentMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BackColor = System::Drawing::SystemColors::ControlLight;
			this->ClientSize = System::Drawing::Size(1126, 1303);
			this->Controls->Add(this->txtSemester2);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->menuStrip1);
			this->Name = L"StudentMain";
			this->Text = L"StudentMain";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->profilePictureBox))->EndInit();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void toolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
		Group7FinalProject::StudentCourses studentCourses(currentStudentID);
		studentCourses.ShowDialog();
		this->LoadDashboardData();
	}

	private: System::Void toolStripMenuItem2_Click(System::Object^ sender, System::EventArgs^ e) {
		Group7FinalProject::TranscriptView transcriptView(currentStudentID);
		transcriptView.ShowDialog();
		this->LoadDashboardData();
	}

	private: System::Void toolStripMenuItem3_Click(System::Object^ sender, System::EventArgs^ e) {
		Group7FinalProject::PaymentView paymentView(currentStudentID);
		paymentView.ShowDialog();
		this->LoadDashboardData();
	}

	private: System::Void profileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		Group7FinalProject::StudentProfile studentProfile(currentStudentID);
		studentProfile.ShowDialog();
		this->LoadDashboardData();
	}

     // this code is used to load the  dashboard data

	private: void LoadDashboardData() {
		try {
			db->Open();

			String^ query = "SELECT u.firstName, u.lastName, u.profileImage, s.creditsEarned, t.cgpa, f.balance "
				"FROM User u "
				"JOIN Student s ON u.dbID = s.studentID "
				"LEFT JOIN Transcript t ON s.studentID = t.studentID "
				"LEFT JOIN Fee f ON s.studentID = f.studentID "
				"WHERE u.dbID = " + currentStudentID;

			db->sqlCmd->CommandText = query;
			db->sqlDR = db->sqlCmd->ExecuteReader();

			if (db->sqlDR->Read()) {

				txtUserName->Text = db->sqlDR["firstName"]->ToString() + " " + db->sqlDR["lastName"]->ToString();

				txtCredit->Text = db->sqlDR["creditsEarned"]->ToString();

				if (db->sqlDR["cgpa"] != DBNull::Value) {
					double cgpa = Convert::ToDouble(db->sqlDR["cgpa"]);
					txtCGPA->Text = cgpa.ToString("F2");
				}
				else {
					txtCGPA->Text = "0.00";
				}

				if (db->sqlDR["balance"] != DBNull::Value) {
					double balance = Convert::ToDouble(db->sqlDR["balance"]);
					txtFee->Text = "$ "+balance.ToString("N2");
				}
				else {
					txtFee->Text = "0.00";
				}
			}
			db->Close(); // Close reader before starting next query

			// LOAD COURSES GRID
			db->Open();
			String^ courseQuery = "SELECT c.courseCode AS 'Code', c.courseTitle AS 'Title', "
				"facUser.lastName AS 'Instructor', c.credit AS 'Credits', cr.status AS 'Status' "
				"FROM CourseRegistration cr "
				"JOIN Course c ON cr.courseID = c.courseID "
				"LEFT JOIN Faculty fac ON c.facultyID = fac.facultyID "
				"LEFT JOIN User facUser ON fac.facultyID = facUser.dbID "
				"WHERE cr.studentID = " + currentStudentID;

			db->sqlDA = gcnew MySqlDataAdapter(courseQuery, db->sqlConn);

			DataTable^ dt = gcnew DataTable();
			db->sqlDA->Fill(dt);

			dataGridView1->DataSource = dt;
			db->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error loading dashboard: " + ex->Message);
			if (db->sqlConn->State == ConnectionState::Open) db->Close();
		}
	}

private: System::Void courseRegistrationToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	Group7FinalProject::CourseRegistration^ regForm = gcnew CourseRegistration(currentStudentID);
	regForm->ShowDialog();
	this->LoadDashboardData();
}
};
}