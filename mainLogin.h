#pragma once
#include "adminDashboard.h"

namespace Group7FinalProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for mainLogin
	/// </summary>
	public ref class mainLogin : public System::Windows::Forms::Form
	{
		String^ connString = "datasource = localhost; port=3306;"
			"username=root; password=""; database=universityDB";
	public:
		mainLogin(void)
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
		~mainLogin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtEmail;
	private: System::Windows::Forms::TextBox^ txtPassword;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ btnLogin;


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
			this->txtEmail = (gcnew System::Windows::Forms::TextBox());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Maroon;
			this->label1->Location = System::Drawing::Point(314, 124);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(294, 59);
			this->label1->TabIndex = 0;
			this->label1->Text = L"System Login";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Maroon;
			this->label2->Location = System::Drawing::Point(44, 291);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(189, 37);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Email Address:";
			// 
			// txtEmail
			// 
			this->txtEmail->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtEmail->Location = System::Drawing::Point(264, 298);
			this->txtEmail->Name = L"txtEmail";
			this->txtEmail->Size = System::Drawing::Size(502, 38);
			this->txtEmail->TabIndex = 2;
			// 
			// txtPassword
			// 
			this->txtPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtPassword->Location = System::Drawing::Point(264, 424);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->PasswordChar = '*';
			this->txtPassword->Size = System::Drawing::Size(502, 38);
			this->txtPassword->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Maroon;
			this->label3->Location = System::Drawing::Point(44, 417);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(134, 37);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Password:";
			this->label3->Click += gcnew System::EventHandler(this, &mainLogin::label3_Click);
			// 
			// btnLogin
			// 
			this->btnLogin->BackColor = System::Drawing::Color::Maroon;
			this->btnLogin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnLogin->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnLogin->ForeColor = System::Drawing::Color::White;
			this->btnLogin->Location = System::Drawing::Point(403, 584);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(190, 66);
			this->btnLogin->TabIndex = 5;
			this->btnLogin->Text = L"Login";
			this->btnLogin->UseVisualStyleBackColor = false;
			this->btnLogin->Click += gcnew System::EventHandler(this, &mainLogin::button1_Click);
			// 
			// mainLogin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(986, 939);
			this->Controls->Add(this->btnLogin);
			this->Controls->Add(this->txtPassword);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->txtEmail);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"mainLogin";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"mainLogin";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ email = txtEmail->Text;
			String^ pass = txtPassword->Text;

			if (String::IsNullOrWhiteSpace(email) || String::IsNullOrWhiteSpace(pass)) {
				MessageBox::Show("Please enter both email and password.");
				return;
			}

			MySqlConnection^ conn = gcnew MySqlConnection(connString);
			try {
				conn->Open();
				String^ query = "SELECT dbID, name FROM User WHERE email=@e AND password=@p";
				MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
				cmd->Parameters->AddWithValue("@e", email);
				cmd->Parameters->AddWithValue("@p", pass);

				MySqlDataReader^ reader = cmd->ExecuteReader();

				if (reader->Read()) {
					int userID = Convert::ToInt32(reader["dbID"]);
					String^ userName = reader["fname"]->ToString();
					reader->Close(); 

					if (CheckRole(userID, "adminstaff", conn)) {
						MessageBox::Show("Welcome" + userName);
						this->Hide();
						adminDashboard^ dash = gcnew adminDashboard();
						dash->ShowDialog();
						this->Close();

					}
					else if (CheckRole(userID,"student",conn)) {
						MessageBox::Show("Welcome" + userName);
					}
					else if (CheckRole(userID, "faculty", conn)) {
						MessageBox::Show("Welcome" + userName);
					}
				}
				else {
					MessageBox::Show("Invalid Email or Password.");
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show("Database Error: " + ex->Message);
			}
			finally {
				conn->Close();
			}
		}

		bool CheckRole(int id, String^ tableName, MySqlConnection^ conn) {
			String^ idColumn = "";
			if (tableName == "AdminStaff") { 
				idColumn = "staffID"; 
			}
			else if (tableName == "Student") { 
				idColumn = "studentID"; 
			}
			else if (tableName == "Faculty") { 
				idColumn = "facultyID"; 
			}

			String^ query = "SELECT COUNT(*) FROM " + tableName + " WHERE " + idColumn + " = @id";
			MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
			cmd->Parameters->AddWithValue("@id", id);

			int count = Convert::ToInt32(cmd->ExecuteScalar());
			return count > 0;
		}
	
};
}
