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
	/// Summary for StudentProfile
	/// </summary>
	public ref class StudentProfile : public System::Windows::Forms::Form
	{
	public:
		Database^ db = gcnew Database();

		StudentProfile(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~StudentProfile()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Button^ btnEditPersonal;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ txtLastName;

	private: System::Windows::Forms::Label^ txtFirstName;
	private: System::Windows::Forms::Label^ txtDOB;


	private: System::Windows::Forms::Label^ txtGender;
	private: System::Windows::Forms::Label^ txtAddress;
	private: System::Windows::Forms::Label^ txtPhone;



	private: System::Windows::Forms::Label^ txtEmail;
	private: System::Windows::Forms::Button^ btnEditDetails;



	private: System::Windows::Forms::Label^ label11;



	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ txtYear;
	private: System::Windows::Forms::Label^ txtGraduationYear;
	private: System::Windows::Forms::Label^ txtProgram;
	private: System::Windows::Forms::Label^ txtSID;




	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::Button^ btnChangePwd;


	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ txtLastChanged;



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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->btnEditPersonal = (gcnew System::Windows::Forms::Button());
			this->txtFirstName = (gcnew System::Windows::Forms::Label());
			this->txtLastName = (gcnew System::Windows::Forms::Label());
			this->txtGender = (gcnew System::Windows::Forms::Label());
			this->txtDOB = (gcnew System::Windows::Forms::Label());
			this->txtAddress = (gcnew System::Windows::Forms::Label());
			this->txtPhone = (gcnew System::Windows::Forms::Label());
			this->txtEmail = (gcnew System::Windows::Forms::Label());
			this->btnEditDetails = (gcnew System::Windows::Forms::Button());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->txtYear = (gcnew System::Windows::Forms::Label());
			this->txtGraduationYear = (gcnew System::Windows::Forms::Label());
			this->txtProgram = (gcnew System::Windows::Forms::Label());
			this->txtSID = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->btnChangePwd = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->txtLastChanged = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.14286F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(36, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(116, 38);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Profile";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.14286F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(17, 26);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(284, 31);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Personal Infromation";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->panel1->Controls->Add(this->txtDOB);
			this->panel1->Controls->Add(this->txtGender);
			this->panel1->Controls->Add(this->txtLastName);
			this->panel1->Controls->Add(this->txtFirstName);
			this->panel1->Controls->Add(this->btnEditPersonal);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Location = System::Drawing::Point(71, 141);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(985, 272);
			this->panel1->TabIndex = 2;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ControlLight;
			this->panel2->Controls->Add(this->txtAddress);
			this->panel2->Controls->Add(this->txtPhone);
			this->panel2->Controls->Add(this->txtEmail);
			this->panel2->Controls->Add(this->btnEditDetails);
			this->panel2->Controls->Add(this->label11);
			this->panel2->Controls->Add(this->label13);
			this->panel2->Controls->Add(this->label14);
			this->panel2->Controls->Add(this->label15);
			this->panel2->Location = System::Drawing::Point(71, 445);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(985, 256);
			this->panel2->TabIndex = 3;
			this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &StudentProfile::panel2_Paint);
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::SystemColors::ControlLight;
			this->panel3->Controls->Add(this->txtLastChanged);
			this->panel3->Controls->Add(this->label9);
			this->panel3->Controls->Add(this->btnChangePwd);
			this->panel3->Controls->Add(this->label7);
			this->panel3->Controls->Add(this->label8);
			this->panel3->Location = System::Drawing::Point(71, 1052);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(985, 210);
			this->panel3->TabIndex = 4;
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::SystemColors::ControlLight;
			this->panel4->Controls->Add(this->txtYear);
			this->panel4->Controls->Add(this->txtGraduationYear);
			this->panel4->Controls->Add(this->txtProgram);
			this->panel4->Controls->Add(this->txtSID);
			this->panel4->Controls->Add(this->label12);
			this->panel4->Controls->Add(this->label16);
			this->panel4->Controls->Add(this->label17);
			this->panel4->Controls->Add(this->label18);
			this->panel4->Controls->Add(this->label19);
			this->panel4->Location = System::Drawing::Point(71, 736);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(985, 273);
			this->panel4->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->ForeColor = System::Drawing::SystemColors::GrayText;
			this->label3->Location = System::Drawing::Point(17, 172);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(118, 25);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Date of Birth";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->ForeColor = System::Drawing::SystemColors::GrayText;
			this->label4->Location = System::Drawing::Point(17, 75);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(106, 25);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Fisrt Name";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->ForeColor = System::Drawing::SystemColors::GrayText;
			this->label5->Location = System::Drawing::Point(576, 75);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(106, 25);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Last Name";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->ForeColor = System::Drawing::SystemColors::GrayText;
			this->label6->Location = System::Drawing::Point(576, 172);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(77, 25);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Gender";
			// 
			// btnEditPersonal
			// 
			this->btnEditPersonal->BackColor = System::Drawing::Color::Transparent;
			this->btnEditPersonal->ForeColor = System::Drawing::Color::Brown;
			this->btnEditPersonal->Location = System::Drawing::Point(881, 14);
			this->btnEditPersonal->Name = L"btnEditPersonal";
			this->btnEditPersonal->Size = System::Drawing::Size(88, 37);
			this->btnEditPersonal->TabIndex = 6;
			this->btnEditPersonal->Text = L"✏️ Edit";
			this->btnEditPersonal->UseVisualStyleBackColor = false;
			// 
			// txtFirstName
			// 
			this->txtFirstName->AutoSize = true;
			this->txtFirstName->Location = System::Drawing::Point(26, 119);
			this->txtFirstName->Name = L"txtFirstName";
			this->txtFirstName->Size = System::Drawing::Size(51, 25);
			this->txtFirstName->TabIndex = 7;
			this->txtFirstName->Text = L"Alex";
			// 
			// txtLastName
			// 
			this->txtLastName->AutoSize = true;
			this->txtLastName->Location = System::Drawing::Point(576, 119);
			this->txtLastName->Name = L"txtLastName";
			this->txtLastName->Size = System::Drawing::Size(88, 25);
			this->txtLastName->TabIndex = 8;
			this->txtLastName->Text = L"Johnson";
			// 
			// txtGender
			// 
			this->txtGender->AutoSize = true;
			this->txtGender->Location = System::Drawing::Point(576, 212);
			this->txtGender->Name = L"txtGender";
			this->txtGender->Size = System::Drawing::Size(55, 25);
			this->txtGender->TabIndex = 9;
			this->txtGender->Text = L"Male";
			// 
			// txtDOB
			// 
			this->txtDOB->AutoSize = true;
			this->txtDOB->Location = System::Drawing::Point(17, 212);
			this->txtDOB->Name = L"txtDOB";
			this->txtDOB->Size = System::Drawing::Size(159, 25);
			this->txtDOB->TabIndex = 10;
			this->txtDOB->Text = L"January 15,2003";
			this->txtDOB->Click += gcnew System::EventHandler(this, &StudentProfile::label10_Click);
			// 
			// txtAddress
			// 
			this->txtAddress->AutoSize = true;
			this->txtAddress->Location = System::Drawing::Point(16, 208);
			this->txtAddress->Name = L"txtAddress";
			this->txtAddress->Size = System::Drawing::Size(284, 25);
			this->txtAddress->TabIndex = 20;
			this->txtAddress->Text = L"1 University Avenue , Berekuso";
			// 
			// txtPhone
			// 
			this->txtPhone->AutoSize = true;
			this->txtPhone->Location = System::Drawing::Point(575, 115);
			this->txtPhone->Name = L"txtPhone";
			this->txtPhone->Size = System::Drawing::Size(176, 25);
			this->txtPhone->TabIndex = 18;
			this->txtPhone->Text = L"+1 (555) 123-4567";
			// 
			// txtEmail
			// 
			this->txtEmail->AutoSize = true;
			this->txtEmail->Location = System::Drawing::Point(17, 115);
			this->txtEmail->Name = L"txtEmail";
			this->txtEmail->Size = System::Drawing::Size(197, 25);
			this->txtEmail->TabIndex = 17;
			this->txtEmail->Text = L"alex.j@university.edu";
			// 
			// btnEditDetails
			// 
			this->btnEditDetails->BackColor = System::Drawing::Color::Transparent;
			this->btnEditDetails->ForeColor = System::Drawing::Color::Brown;
			this->btnEditDetails->Location = System::Drawing::Point(880, 10);
			this->btnEditDetails->Name = L"btnEditDetails";
			this->btnEditDetails->Size = System::Drawing::Size(88, 37);
			this->btnEditDetails->TabIndex = 16;
			this->btnEditDetails->Text = L"✏️ Edit";
			this->btnEditDetails->UseVisualStyleBackColor = false;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->ForeColor = System::Drawing::SystemColors::GrayText;
			this->label11->Location = System::Drawing::Point(575, 71);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(143, 25);
			this->label11->TabIndex = 14;
			this->label11->Text = L"Phone Number";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->ForeColor = System::Drawing::SystemColors::GrayText;
			this->label13->Location = System::Drawing::Point(16, 71);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(138, 25);
			this->label13->TabIndex = 13;
			this->label13->Text = L"Email Address";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->ForeColor = System::Drawing::SystemColors::GrayText;
			this->label14->Location = System::Drawing::Point(16, 168);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(163, 25);
			this->label14->TabIndex = 12;
			this->label14->Text = L"Physical Address";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.14286F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->Location = System::Drawing::Point(16, 22);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(215, 31);
			this->label15->TabIndex = 11;
			this->label15->Text = L"Contact Details";
			// 
			// txtYear
			// 
			this->txtYear->AutoSize = true;
			this->txtYear->Location = System::Drawing::Point(25, 215);
			this->txtYear->Name = L"txtYear";
			this->txtYear->Size = System::Drawing::Size(56, 25);
			this->txtYear->TabIndex = 19;
			this->txtYear->Text = L"2023";
			// 
			// txtGraduationYear
			// 
			this->txtGraduationYear->AutoSize = true;
			this->txtGraduationYear->Location = System::Drawing::Point(584, 215);
			this->txtGraduationYear->Name = L"txtGraduationYear";
			this->txtGraduationYear->Size = System::Drawing::Size(55, 25);
			this->txtGraduationYear->TabIndex = 18;
			this->txtGraduationYear->Text = L"Male";
			// 
			// txtProgram
			// 
			this->txtProgram->AutoSize = true;
			this->txtProgram->Location = System::Drawing::Point(593, 122);
			this->txtProgram->Name = L"txtProgram";
			this->txtProgram->Size = System::Drawing::Size(221, 25);
			this->txtProgram->TabIndex = 17;
			this->txtProgram->Text = L"BSc. Computer Science";
			// 
			// txtSID
			// 
			this->txtSID->AutoSize = true;
			this->txtSID->Location = System::Drawing::Point(30, 122);
			this->txtSID->Name = L"txtSID";
			this->txtSID->Size = System::Drawing::Size(51, 25);
			this->txtSID->TabIndex = 16;
			this->txtSID->Text = L"Alex";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->ForeColor = System::Drawing::SystemColors::GrayText;
			this->label12->Location = System::Drawing::Point(584, 175);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(195, 25);
			this->label12->TabIndex = 15;
			this->label12->Text = L"Expected Graduation";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->ForeColor = System::Drawing::SystemColors::GrayText;
			this->label16->Location = System::Drawing::Point(584, 87);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(86, 25);
			this->label16->TabIndex = 14;
			this->label16->Text = L"Program";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->ForeColor = System::Drawing::SystemColors::GrayText;
			this->label17->Location = System::Drawing::Point(25, 87);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(104, 25);
			this->label17->TabIndex = 13;
			this->label17->Text = L"Student ID";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->ForeColor = System::Drawing::SystemColors::GrayText;
			this->label18->Location = System::Drawing::Point(25, 175);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(150, 25);
			this->label18->TabIndex = 12;
			this->label18->Text = L"Enrollment Year";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.14286F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label19->Location = System::Drawing::Point(25, 29);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(259, 31);
			this->label19->TabIndex = 11;
			this->label19->Text = L"Academic Program";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->ForeColor = System::Drawing::SystemColors::Desktop;
			this->label7->Location = System::Drawing::Point(18, 93);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(98, 25);
			this->label7->TabIndex = 15;
			this->label7->Text = L"Password";
			this->label7->Click += gcnew System::EventHandler(this, &StudentProfile::label7_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.14286F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(17, 35);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(236, 31);
			this->label8->TabIndex = 14;
			this->label8->Text = L"Security Settings";
			// 
			// btnChangePwd
			// 
			this->btnChangePwd->BackColor = System::Drawing::Color::Transparent;
			this->btnChangePwd->ForeColor = System::Drawing::Color::Brown;
			this->btnChangePwd->Location = System::Drawing::Point(769, 104);
			this->btnChangePwd->Name = L"btnChangePwd";
			this->btnChangePwd->Size = System::Drawing::Size(200, 58);
			this->btnChangePwd->TabIndex = 17;
			this->btnChangePwd->Text = L"Change Password";
			this->btnChangePwd->UseVisualStyleBackColor = false;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->ForeColor = System::Drawing::SystemColors::GrayText;
			this->label9->Location = System::Drawing::Point(18, 137);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(141, 25);
			this->label9->TabIndex = 18;
			this->label9->Text = L"Last changed :";
			// 
			// txtLastChanged
			// 
			this->txtLastChanged->AutoSize = true;
			this->txtLastChanged->ForeColor = System::Drawing::SystemColors::GrayText;
			this->txtLastChanged->Location = System::Drawing::Point(163, 137);
			this->txtLastChanged->Name = L"txtLastChanged";
			this->txtLastChanged->Size = System::Drawing::Size(132, 25);
			this->txtLastChanged->TabIndex = 19;
			this->txtLastChanged->Text = L"March 1,2024";
			// 
			// StudentProfile
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1139, 1364);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label1);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"StudentProfile";
			this->Text = L"StudentProfile";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label10_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
