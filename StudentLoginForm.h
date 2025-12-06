#pragma once
#include "Database.h"
#include "Student.h"
#include "StudentMain.h"

namespace Group7FinalProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class StudentLoginForm : public System::Windows::Forms::Form
	{
	public:
		Database^ db = gcnew Database();

		StudentLoginForm()
		{
			InitializeComponent();
			this->button1->Click += gcnew System::EventHandler(this, &StudentLoginForm::btnLogin_Click);
			this->textBox2->PasswordChar = '*';
		}

	protected:
		~StudentLoginForm()
		{
			if (components) delete components;
		}

	private: System::Void btnLogin_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ email = textBox1->Text->Trim();
		String^ password = textBox2->Text->Trim();

		if (String::IsNullOrEmpty(email) || String::IsNullOrEmpty(password)) {
			MessageBox::Show("Please enter both email and password.");
			return;
		}

		try {
			db->Open();
			String^ query = "SELECT dbID FROM User WHERE email = @email AND password = @pass";
			db->sqlCmd->CommandText = query;
			db->sqlCmd->Parameters->Clear();
			db->sqlCmd->Parameters->AddWithValue("@email", email);
			db->sqlCmd->Parameters->AddWithValue("@pass", password);

			Object^ result = db->sqlCmd->ExecuteScalar();

			if (result != nullptr) {
				int userID = Convert::ToInt32(result);

				if (CheckIfStudent(userID)) {
					this->Hide();
					Group7FinalProject::StudentMain^ dashboard = gcnew Group7FinalProject::StudentMain(userID);
					dashboard->ShowDialog();
					this->Show();
					textBox2->Clear();
				}
				else {
					MessageBox::Show("Account found, but it is not a Student account.");
				}
			}
			else {
				MessageBox::Show("Invalid Email or Password.");
			}
			db->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Connection Error: " + ex->Message);
			if (db->sqlConn->State == ConnectionState::Open) db->Close();
		}
	}

	private: bool CheckIfStudent(int id) {
		String^ query = "SELECT COUNT(*) FROM Student WHERE studentID = " + id;
		db->sqlCmd->CommandText = query;
		int count = Convert::ToInt32(db->sqlCmd->ExecuteScalar());
		return count > 0;
	}

	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::LinkLabel^ linkLabel1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button1;
	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->AutoSize = true;
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->linkLabel1);
			this->panel1->Controls->Add(this->textBox2);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Location = System::Drawing::Point(183, 282);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(942, 765);
			this->panel1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(444, 118);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(412, 64);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Welcome Back";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.14286F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ActiveBorder;
			this->label2->Location = System::Drawing::Point(427, 209);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(464, 31);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Sign in to your account to continue";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(147, 103);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(91, 32);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Email";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(147, 278);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(146, 32);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Password";
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(152, 177);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(641, 55);
			this->textBox1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(152, 346);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(641, 55);
			this->textBox2->TabIndex = 3;
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->LinkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->linkLabel1->Location = System::Drawing::Point(627, 285);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(168, 25);
			this->linkLabel1->TabIndex = 4;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"Forgot password\?";
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button1->AutoSize = true;
			this->button1->BackColor = System::Drawing::Color::Brown;
			this->button1->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 9.857143F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(152, 482);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(641, 120);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Login";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// StudentLoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Snow;
			this->ClientSize = System::Drawing::Size(1372, 1213);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel1);
			this->Name = L"StudentLoginForm";
			this->Text = L"StudentLoginForm";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}