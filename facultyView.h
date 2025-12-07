#pragma once
#include "myCourses.h"
#include "gradeSub.h"
#include "users.h"


namespace Group7FinalProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for facultyView
	/// </summary>
	public ref class facultyView : public System::Windows::Forms::Form
	{
		User^ currentUser;
	public:
		facultyView(User^ user)
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
		~facultyView()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ ashesiMISToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ studentToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ enterToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ facultyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ enterToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ adminstrationToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ enterToolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^ systemSetupToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ enterToolStripMenuItem3;






	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem2;
	private: System::Windows::Forms::MenuStrip^ menuStrip2;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem3;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem4;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem5;
	private: System::Windows::Forms::ToolStripMenuItem^ myCoursesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ checkCoursesToolStripMenuItem;


	private: System::Windows::Forms::ToolStripMenuItem^ gradeSubmissionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ checkGradesToolStripMenuItem;








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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(facultyView::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->ashesiMISToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->studentToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->enterToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->facultyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->enterToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->adminstrationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->enterToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->systemSetupToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->enterToolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->menuStrip2 = (gcnew System::Windows::Forms::MenuStrip());
			this->toolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem4 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem5 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->myCoursesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->checkCoursesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->gradeSubmissionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->checkGradesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->menuStrip2->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->ashesiMISToolStripMenuItem,
					this->toolStripMenuItem1, this->studentToolStripMenuItem, this->facultyToolStripMenuItem, this->adminstrationToolStripMenuItem,
					this->systemSetupToolStripMenuItem, this->toolStripMenuItem2
			});
			this->menuStrip1->Location = System::Drawing::Point(126, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(600, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ashesiMISToolStripMenuItem
			// 
			this->ashesiMISToolStripMenuItem->Name = L"ashesiMISToolStripMenuItem";
			this->ashesiMISToolStripMenuItem->Size = System::Drawing::Size(73, 20);
			this->ashesiMISToolStripMenuItem->Text = L"AshesiMIS";
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->toolStripMenuItem1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(106, 20);
			this->toolStripMenuItem1->Text = L".............................";
			// 
			// studentToolStripMenuItem
			// 
			this->studentToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->enterToolStripMenuItem });
			this->studentToolStripMenuItem->Name = L"studentToolStripMenuItem";
			this->studentToolStripMenuItem->Size = System::Drawing::Size(60, 20);
			this->studentToolStripMenuItem->Text = L"Student";
			// 
			// enterToolStripMenuItem
			// 
			this->enterToolStripMenuItem->Name = L"enterToolStripMenuItem";
			this->enterToolStripMenuItem->Size = System::Drawing::Size(101, 22);
			this->enterToolStripMenuItem->Text = L"enter";
			// 
			// facultyToolStripMenuItem
			// 
			this->facultyToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->enterToolStripMenuItem1 });
			this->facultyToolStripMenuItem->Name = L"facultyToolStripMenuItem";
			this->facultyToolStripMenuItem->Size = System::Drawing::Size(57, 20);
			this->facultyToolStripMenuItem->Text = L"Faculty";
			// 
			// enterToolStripMenuItem1
			// 
			this->enterToolStripMenuItem1->Name = L"enterToolStripMenuItem1";
			this->enterToolStripMenuItem1->Size = System::Drawing::Size(101, 22);
			this->enterToolStripMenuItem1->Text = L"enter";
			// 
			// adminstrationToolStripMenuItem
			// 
			this->adminstrationToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->enterToolStripMenuItem2 });
			this->adminstrationToolStripMenuItem->Name = L"adminstrationToolStripMenuItem";
			this->adminstrationToolStripMenuItem->Size = System::Drawing::Size(95, 20);
			this->adminstrationToolStripMenuItem->Text = L"Adminstration";
			// 
			// enterToolStripMenuItem2
			// 
			this->enterToolStripMenuItem2->Name = L"enterToolStripMenuItem2";
			this->enterToolStripMenuItem2->Size = System::Drawing::Size(101, 22);
			this->enterToolStripMenuItem2->Text = L"enter";
			// 
			// systemSetupToolStripMenuItem
			// 
			this->systemSetupToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->enterToolStripMenuItem3 });
			this->systemSetupToolStripMenuItem->Name = L"systemSetupToolStripMenuItem";
			this->systemSetupToolStripMenuItem->Size = System::Drawing::Size(90, 20);
			this->systemSetupToolStripMenuItem->Text = L"System Setup";
			// 
			// enterToolStripMenuItem3
			// 
			this->enterToolStripMenuItem3->Name = L"enterToolStripMenuItem3";
			this->enterToolStripMenuItem3->Size = System::Drawing::Size(101, 22);
			this->enterToolStripMenuItem3->Text = L"enter";
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(64, 20);
			this->toolStripMenuItem2->Text = L"...............";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label1->Location = System::Drawing::Point(158, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(260, 39);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Welcome Back,";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label2->Location = System::Drawing::Point(164, 79);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(335, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Here\'s a summary of your academic activities for the current semester.";
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->dataGridView1);
			this->panel1->Location = System::Drawing::Point(142, 99);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(583, 423);
			this->panel1->TabIndex = 4;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToOrderColumns = true;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(3, 6);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(577, 417);
			this->dataGridView1->TabIndex = 0;
			// 
			// menuStrip2
			// 
			this->menuStrip2->Dock = System::Windows::Forms::DockStyle::Left;
			this->menuStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->toolStripMenuItem3,
					this->toolStripMenuItem4, this->toolStripMenuItem5, this->myCoursesToolStripMenuItem, this->gradeSubmissionToolStripMenuItem
			});
			this->menuStrip2->Location = System::Drawing::Point(0, 0);
			this->menuStrip2->Name = L"menuStrip2";
			this->menuStrip2->Size = System::Drawing::Size(126, 531);
			this->menuStrip2->TabIndex = 5;
			this->menuStrip2->Text = L"menuStrip2";
			// 
			// toolStripMenuItem3
			// 
			this->toolStripMenuItem3->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->toolStripMenuItem3->Name = L"toolStripMenuItem3";
			this->toolStripMenuItem3->Size = System::Drawing::Size(113, 19);
			this->toolStripMenuItem3->Text = L"...........";
			// 
			// toolStripMenuItem4
			// 
			this->toolStripMenuItem4->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->toolStripMenuItem4->Name = L"toolStripMenuItem4";
			this->toolStripMenuItem4->Size = System::Drawing::Size(113, 19);
			this->toolStripMenuItem4->Text = L".............";
			// 
			// toolStripMenuItem5
			// 
			this->toolStripMenuItem5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->toolStripMenuItem5->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->toolStripMenuItem5->Name = L"toolStripMenuItem5";
			this->toolStripMenuItem5->Size = System::Drawing::Size(113, 19);
			this->toolStripMenuItem5->Text = L"........................";
			this->toolStripMenuItem5->Click += gcnew System::EventHandler(this, &facultyView::toolStripMenuItem5_Click);
			// 
			// myCoursesToolStripMenuItem
			// 
			this->myCoursesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->checkCoursesToolStripMenuItem });
			this->myCoursesToolStripMenuItem->Name = L"myCoursesToolStripMenuItem";
			this->myCoursesToolStripMenuItem->Size = System::Drawing::Size(113, 19);
			this->myCoursesToolStripMenuItem->Text = L"My Courses";
			// 
			// checkCoursesToolStripMenuItem
			// 
			this->checkCoursesToolStripMenuItem->Name = L"checkCoursesToolStripMenuItem";
			this->checkCoursesToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->checkCoursesToolStripMenuItem->Text = L"Check Courses";
			this->checkCoursesToolStripMenuItem->Click += gcnew System::EventHandler(this, &facultyView::checkCoursesToolStripMenuItem_Click);
			// 
			// gradeSubmissionToolStripMenuItem
			// 
			this->gradeSubmissionToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->checkGradesToolStripMenuItem });
			this->gradeSubmissionToolStripMenuItem->Name = L"gradeSubmissionToolStripMenuItem";
			this->gradeSubmissionToolStripMenuItem->Size = System::Drawing::Size(113, 19);
			this->gradeSubmissionToolStripMenuItem->Text = L"Grade Submission";
			// 
			// checkGradesToolStripMenuItem
			// 
			this->checkGradesToolStripMenuItem->Name = L"checkGradesToolStripMenuItem";
			this->checkGradesToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->checkGradesToolStripMenuItem->Text = L"Check Grades";
			this->checkGradesToolStripMenuItem->Click += gcnew System::EventHandler(this, &facultyView::checkGradesToolStripMenuItem_Click);
			// 
			// facultyView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Maroon;
			this->ClientSize = System::Drawing::Size(726, 531);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->menuStrip2);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"facultyView";
			this->Text = L"AshesiMIS";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->menuStrip2->ResumeLayout(false);
			this->menuStrip2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void toolStripMenuItem5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void checkCoursesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	myCourses^ page = gcnew myCourses(currentUser);
	page->ShowDialog();
	this->Hide();

}



private: System::Void checkGradesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	gradeSub^ page = gcnew gradeSub(currentUser);
	page->ShowDialog();
	this->Hide();
}
};
}
