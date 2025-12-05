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
	/// Summary for adminCourses
	/// </summary>
	public ref class adminCourses : public System::Windows::Forms::Form
	{
		User^ currentUser;
	public:
		adminCourses(User^ user)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->currentUser = user;
			lblUser->Text = "Hello " + currentUser->name;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~adminCourses()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Label^ lblUser;
	private: System::Windows::Forms::Button^ btnDashboard;

	private: System::Windows::Forms::Button^ btnDepartment;
	private: System::Windows::Forms::Button^ btnFaculty;
	private: System::Windows::Forms::Button^ btnStudents;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ lblWelcome;
	private: System::Windows::Forms::Button^ btnProgrammes;


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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->btnProgrammes = (gcnew System::Windows::Forms::Button());
			this->lblUser = (gcnew System::Windows::Forms::Label());
			this->btnDashboard = (gcnew System::Windows::Forms::Button());
			this->btnDepartment = (gcnew System::Windows::Forms::Button());
			this->btnFaculty = (gcnew System::Windows::Forms::Button());
			this->btnStudents = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->lblWelcome = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Maroon;
			this->panel1->Controls->Add(this->btnProgrammes);
			this->panel1->Controls->Add(this->lblUser);
			this->panel1->Controls->Add(this->btnDashboard);
			this->panel1->Controls->Add(this->btnDepartment);
			this->panel1->Controls->Add(this->btnFaculty);
			this->panel1->Controls->Add(this->btnStudents);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(260, 1168);
			this->panel1->TabIndex = 1;
			// 
			// btnProgrammes
			// 
			this->btnProgrammes->FlatAppearance->BorderSize = 0;
			this->btnProgrammes->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnProgrammes->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnProgrammes->ForeColor = System::Drawing::Color::White;
			this->btnProgrammes->Location = System::Drawing::Point(26, 772);
			this->btnProgrammes->Name = L"btnProgrammes";
			this->btnProgrammes->Size = System::Drawing::Size(197, 50);
			this->btnProgrammes->TabIndex = 6;
			this->btnProgrammes->Text = L"Programmes";
			this->btnProgrammes->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnProgrammes->UseVisualStyleBackColor = true;
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
			// btnDashboard
			// 
			this->btnDashboard->FlatAppearance->BorderSize = 0;
			this->btnDashboard->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDashboard->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDashboard->ForeColor = System::Drawing::Color::White;
			this->btnDashboard->Location = System::Drawing::Point(26, 187);
			this->btnDashboard->Name = L"btnDashboard";
			this->btnDashboard->Size = System::Drawing::Size(182, 50);
			this->btnDashboard->TabIndex = 4;
			this->btnDashboard->Text = L"Dashboard";
			this->btnDashboard->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnDashboard->UseVisualStyleBackColor = true;
			this->btnDashboard->Click += gcnew System::EventHandler(this, &adminCourses::btnDashboard_Click);
			// 
			// btnDepartment
			// 
			this->btnDepartment->FlatAppearance->BorderSize = 0;
			this->btnDepartment->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDepartment->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDepartment->ForeColor = System::Drawing::Color::White;
			this->btnDepartment->Location = System::Drawing::Point(26, 608);
			this->btnDepartment->Name = L"btnDepartment";
			this->btnDepartment->Size = System::Drawing::Size(197, 50);
			this->btnDepartment->TabIndex = 3;
			this->btnDepartment->Text = L"Departments";
			this->btnDepartment->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnDepartment->UseVisualStyleBackColor = true;
			this->btnDepartment->Click += gcnew System::EventHandler(this, &adminCourses::btnDepartment_Click);
			// 
			// btnFaculty
			// 
			this->btnFaculty->FlatAppearance->BorderSize = 0;
			this->btnFaculty->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnFaculty->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnFaculty->ForeColor = System::Drawing::Color::White;
			this->btnFaculty->Location = System::Drawing::Point(26, 468);
			this->btnFaculty->Name = L"btnFaculty";
			this->btnFaculty->Size = System::Drawing::Size(182, 50);
			this->btnFaculty->TabIndex = 2;
			this->btnFaculty->Text = L"Faculty";
			this->btnFaculty->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnFaculty->UseVisualStyleBackColor = true;
			// 
			// btnStudents
			// 
			this->btnStudents->FlatAppearance->BorderSize = 0;
			this->btnStudents->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnStudents->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnStudents->ForeColor = System::Drawing::Color::White;
			this->btnStudents->Location = System::Drawing::Point(26, 332);
			this->btnStudents->Name = L"btnStudents";
			this->btnStudents->Size = System::Drawing::Size(182, 50);
			this->btnStudents->TabIndex = 0;
			this->btnStudents->Text = L"Students";
			this->btnStudents->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnStudents->UseVisualStyleBackColor = true;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->Controls->Add(this->lblWelcome);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(260, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1625, 80);
			this->panel2->TabIndex = 2;
			// 
			// lblWelcome
			// 
			this->lblWelcome->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblWelcome->AutoSize = true;
			this->lblWelcome->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblWelcome->ForeColor = System::Drawing::Color::Maroon;
			this->lblWelcome->Location = System::Drawing::Point(614, 18);
			this->lblWelcome->Name = L"lblWelcome";
			this->lblWelcome->Size = System::Drawing::Size(330, 45);
			this->lblWelcome->TabIndex = 0;
			this->lblWelcome->Text = L"Course Management";
			this->lblWelcome->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// adminCourses
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1885, 1168);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"adminCourses";
			this->Text = L"adminCourses";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		private: System::Void btnDashboard_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void btnDepartment_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
