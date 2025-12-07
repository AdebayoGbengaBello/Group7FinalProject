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
			label2->Text = currentUser->name + ".";
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

	protected:
















	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;



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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->menuStrip2 = (gcnew System::Windows::Forms::MenuStrip());
			this->toolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem4 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem5 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->myCoursesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->checkCoursesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->gradeSubmissionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->checkGradesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip2->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label1->Location = System::Drawing::Point(316, 67);
			this->label1->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(520, 79);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Welcome Back,";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label2->Location = System::Drawing::Point(328, 152);
			this->label2->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 42);
			this->label2->TabIndex = 3;
			// 
			// menuStrip2
			// 
			this->menuStrip2->Dock = System::Windows::Forms::DockStyle::Left;
			this->menuStrip2->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->menuStrip2->ImageScalingSize = System::Drawing::Size(32, 32);
			this->menuStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->toolStripMenuItem3,
					this->toolStripMenuItem4, this->toolStripMenuItem5, this->myCoursesToolStripMenuItem, this->gradeSubmissionToolStripMenuItem
			});
			this->menuStrip2->Location = System::Drawing::Point(0, 0);
			this->menuStrip2->Name = L"menuStrip2";
			this->menuStrip2->Size = System::Drawing::Size(246, 1021);
			this->menuStrip2->TabIndex = 5;
			this->menuStrip2->Text = L"menuStrip2";
			// 
			// toolStripMenuItem3
			// 
			this->toolStripMenuItem3->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->toolStripMenuItem3->Name = L"toolStripMenuItem3";
			this->toolStripMenuItem3->Size = System::Drawing::Size(233, 36);
			this->toolStripMenuItem3->Text = L"...........";
			// 
			// toolStripMenuItem4
			// 
			this->toolStripMenuItem4->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->toolStripMenuItem4->Name = L"toolStripMenuItem4";
			this->toolStripMenuItem4->Size = System::Drawing::Size(233, 36);
			this->toolStripMenuItem4->Text = L".............";
			// 
			// toolStripMenuItem5
			// 
			this->toolStripMenuItem5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->toolStripMenuItem5->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->toolStripMenuItem5->Name = L"toolStripMenuItem5";
			this->toolStripMenuItem5->Size = System::Drawing::Size(233, 36);
			this->toolStripMenuItem5->Text = L"........................";
			this->toolStripMenuItem5->Click += gcnew System::EventHandler(this, &facultyView::toolStripMenuItem5_Click);
			// 
			// myCoursesToolStripMenuItem
			// 
			this->myCoursesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->checkCoursesToolStripMenuItem });
			this->myCoursesToolStripMenuItem->Name = L"myCoursesToolStripMenuItem";
			this->myCoursesToolStripMenuItem->Size = System::Drawing::Size(233, 36);
			this->myCoursesToolStripMenuItem->Text = L"My Courses";
			// 
			// checkCoursesToolStripMenuItem
			// 
			this->checkCoursesToolStripMenuItem->Name = L"checkCoursesToolStripMenuItem";
			this->checkCoursesToolStripMenuItem->Size = System::Drawing::Size(359, 44);
			this->checkCoursesToolStripMenuItem->Text = L"Check Courses";
			this->checkCoursesToolStripMenuItem->Click += gcnew System::EventHandler(this, &facultyView::checkCoursesToolStripMenuItem_Click);
			// 
			// gradeSubmissionToolStripMenuItem
			// 
			this->gradeSubmissionToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->checkGradesToolStripMenuItem });
			this->gradeSubmissionToolStripMenuItem->Name = L"gradeSubmissionToolStripMenuItem";
			this->gradeSubmissionToolStripMenuItem->Size = System::Drawing::Size(233, 36);
			this->gradeSubmissionToolStripMenuItem->Text = L"Grade Submission";
			// 
			// checkGradesToolStripMenuItem
			// 
			this->checkGradesToolStripMenuItem->Name = L"checkGradesToolStripMenuItem";
			this->checkGradesToolStripMenuItem->Size = System::Drawing::Size(292, 44);
			this->checkGradesToolStripMenuItem->Text = L"Check Grades";
			this->checkGradesToolStripMenuItem->Click += gcnew System::EventHandler(this, &facultyView::checkGradesToolStripMenuItem_Click);
			// 
			// facultyView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Maroon;
			this->ClientSize = System::Drawing::Size(1452, 1021);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip2);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"facultyView";
			this->Text = L"AshesiMIS";
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

}



private: System::Void checkGradesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	gradeSub^ page = gcnew gradeSub(currentUser);
	page->ShowDialog();
}
};
}
