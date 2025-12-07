
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
	using namespace System::Data;
	using namespace System::Data::SqlClient;


	public ref class StudentLoginForm : public System::Windows::Forms::Form
	{
	public:
		Database^ db = gcnew Database();
		bool isLoginMode = true; // Login vs Signup toggle

		StudentLoginForm()
		{
			InitializeComponent();

			this->button1->Click += gcnew System::EventHandler(this, &StudentLoginForm::btnAction_Click);
			this->linkSwitch->Click += gcnew System::EventHandler(this, &StudentLoginForm::linkSwitch_Click);
			this->textBox2->PasswordChar = '*';

			InitializeView();
		}

	protected:
		~StudentLoginForm()
		{
			if (components) delete components;
		}

	private:

		// Your original fields
		System::Windows::Forms::Panel^ panel1;
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::Label^ label2;
		System::Windows::Forms::LinkLabel^ linkLabelForgotPassword;
		System::Windows::Forms::TextBox^ textBox2;
		System::Windows::Forms::TextBox^ textBox1;
		System::Windows::Forms::Label^ label4;
		System::Windows::Forms::Label^ label3;
		System::Windows::Forms::Button^ button1;

		// Signup fields (already existed)
		System::Windows::Forms::TextBox^ textBoxName;
		System::Windows::Forms::Label^ labelName;
		System::Windows::Forms::TextBox^ txtSID;
		System::Windows::Forms::Label^ labelSID;
		System::Windows::Forms::LinkLabel^ linkSwitch;

		// ————————————————
		// NEW ROLE FIELD (added)
		// ————————————————
		System::Windows::Forms::Label^ labelRole;
		System::Windows::Forms::ComboBox^ comboRole;
		// ————————————————

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->linkSwitch = (gcnew System::Windows::Forms::LinkLabel());
			this->txtSID = (gcnew System::Windows::Forms::TextBox());
			this->labelSID = (gcnew System::Windows::Forms::Label());
			this->textBoxName = (gcnew System::Windows::Forms::TextBox());
			this->labelName = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->linkLabelForgotPassword = (gcnew System::Windows::Forms::LinkLabel());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());

			// ——————————————
			// NEW ROLE CONTROLS
			// ——————————————
			this->labelRole = (gcnew System::Windows::Forms::Label());
			this->comboRole = (gcnew System::Windows::Forms::ComboBox());
			// ——————————————

			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());

			this->panel1->SuspendLayout();
			this->SuspendLayout();

			// 
			// panel1
			// 
			this->panel1->AutoSize = true;
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->labelRole);
			this->panel1->Controls->Add(this->comboRole);
			this->panel1->Controls->Add(this->linkSwitch);
			this->panel1->Controls->Add(this->txtSID);
			this->panel1->Controls->Add(this->labelSID);
			this->panel1->Controls->Add(this->textBoxName);
			this->panel1->Controls->Add(this->labelName);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->linkLabelForgotPassword);
			this->panel1->Controls->Add(this->textBox2);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Location = System::Drawing::Point(183, 282);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(942, 820);
			this->panel1->TabIndex = 0;

			// ————————————————
			// labelRole
			// ————————————————
			this->labelRole->AutoSize = true;
			this->labelRole->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold));
			this->labelRole->Location = System::Drawing::Point(147, 520);
			this->labelRole->Name = L"labelRole";
			this->labelRole->Size = System::Drawing::Size(78, 32);
			this->labelRole->TabIndex = 11;
			this->labelRole->Text = L"Role";

			// ————————————————
			// comboRole
			// ————————————————
			this->comboRole->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18));
			this->comboRole->FormattingEnabled = true;
			this->comboRole->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Student", L"Tutor", L"Admin" });
			this->comboRole->Location = System::Drawing::Point(152, 560);
			this->comboRole->Name = L"comboRole";
			this->comboRole->Size = System::Drawing::Size(641, 55);
			this->comboRole->TabIndex = 12;

			// — all your existing controls continue here unchanged —
			// (not repeating everything to avoid clutter, already provided above)

			// finalize form
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

		// ——————————————————————————
		// VIEW STATE (Login vs Signup)
		// ——————————————————————————
	private: void InitializeView() {
		if (isLoginMode) {
			label1->Text = "Welcome Back";
			label2->Text = "Sign in to your account to continue";
			button1->Text = "Login";
			linkSwitch->Text = "Don't have an account? Sign up";

			labelName->Visible = false;
			textBoxName->Visible = false;
			labelSID->Visible = false;
			txtSID->Visible = false;

			labelRole->Visible = false;
			comboRole->Visible = false;

			linkLabelForgotPassword->Visible = true;
		}
		else {
			label1->Text = "Create Account";
			label2->Text = "Fill details to create your student account";
			button1->Text = "Sign Up";
			linkSwitch->Text = "Already have an account? Login";

			labelName->Visible = true;
			textBoxName->Visible = true;
			labelSID->Visible = true;
			txtSID->Visible = true;

			labelRole->Visible = true;
			comboRole->Visible = true;

			linkLabelForgotPassword->Visible = false;
		}
	}

		   // Switch Login/Signup
	private: System::Void linkSwitch_Click(System::Object^ sender, System::EventArgs^ e) {
		isLoginMode = !isLoginMode;
		InitializeView();
	}

		   // Combine both actions
	private: System::Void btnAction_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ email = textBox1->Text->Trim();
		String^ password = textBox2->Text->Trim();

		if (String::IsNullOrEmpty(email) || String::IsNullOrEmpty(password)) {
			MessageBox::Show("Please enter both email and password.");
			return;
		}

		if (isLoginMode) {
			PerformLogin(email, password);
		}
		else {
			String^ name = textBoxName->Text->Trim();
			String^ sidText = txtSID->Text->Trim();
			String^ role = comboRole->Text;

			if (String::IsNullOrEmpty(name)) {
				MessageBox::Show("Please enter your full name.");
				return;
			}
			if (String::IsNullOrEmpty(sidText)) {
				MessageBox::Show("Please enter your Student ID.");
				return;
			}
			if (String::IsNullOrEmpty(role)) {
				MessageBox::Show("Please select a role.");
				return;
			}

			int sid = 0;
			if (!Int32::TryParse(sidText, sid)) {
				MessageBox::Show("Student ID must be a number.");
				return;
			}

			PerformSignup(name, email, password, sid, role);
		}
	}

		   // LOGIN
	/*private: void PerformLogin(String^ email, String^ pass) {
		try {
			db->Open();
			String^ query = "SELECT dbID, type FROM [User] WHERE email=@e AND password=@p";
			db->sqlCmd->CommandText = query;
			db->sqlCmd->Parameters->Clear();
			db->sqlCmd->Parameters->AddWithValue("@e", email);
			db->sqlCmd->Parameters->AddWithValue("@p", pass);

			Object^ reader = db->sqlCmd->ExecuteReader();

			if (reader) {
				int userID = Convert::ToInt32(reader["dbID"]);
				String^ role = reader["type"]->ToString();
				reader->Close();
				db->Close();

				if (role == "Student") {
					this->Hide();
					Group7FinalProject::StudentMain^ dashboard =
						gcnew Group7FinalProject::StudentMain(userID);
					dashboard->ShowDialog();
					this->Show();
					return;
				}

				MessageBox::Show("This account exists but is not a Student role.");
			}
			else {
				MessageBox::Show("Invalid Email or Password.");
				reader->Close();
			}

			db->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Login Error: " + ex->Message);
			if (db->sqlConn->State == ConnectionState::Open) db->Close();
		}
	}
*/

	void PerformLogin(String^ email, String^ pass) {
			   try {
				   db->Open();
				   // Example login check
				   String^ query = "SELECT dbID FROM User WHERE email = @email AND password = @pass";
				   db->sqlCmd->CommandText = query;
				   db->sqlCmd->Parameters->Clear();
				   db->sqlCmd->Parameters->AddWithValue("@email", email);
				   db->sqlCmd->Parameters->AddWithValue("@pass", pass);

				   Object^ result = db->sqlCmd->ExecuteScalar();

				   if (result != nullptr) {
					   int userID = Convert::ToInt32(result);
					   MessageBox::Show("Login Successful! ID: " + userID);
					   // Redirect to dashboard here
				   }
				   else {
					   MessageBox::Show("Invalid Credentials.");
				   }
				   db->Close();
			   }
			   catch (Exception^ ex) {
				   MessageBox::Show("Error: " + ex->Message);
				   db->Close();
			   }
	}

		   // SIGNUP
	private: void PerformSignup(String^ name, String^ email, String^ pass, int sid, String^ role) {
		try {
			db->Open();

			// 1) Email check
			String^ checkEmail = "SELECT COUNT(*) FROM [User] WHERE email=@e";
			db->sqlCmd->CommandText = checkEmail;
			db->sqlCmd->Parameters->Clear();
			db->sqlCmd->Parameters->AddWithValue("@e", email);

			int count = Convert::ToInt32(db->sqlCmd->ExecuteScalar());
			if (count > 0) {
				MessageBox::Show("Email already registered.");
				db->Close();
				return;
			}

			// 2) Insert User
			String^ insertUser =
				"INSERT INTO [User] (name, email, password, type) "
				"VALUES (@n, @e, @p, @t); SELECT SCOPE_IDENTITY();";

			db->sqlCmd->CommandText = insertUser;
			db->sqlCmd->Parameters->Clear();
			db->sqlCmd->Parameters->AddWithValue("@n", name);
			db->sqlCmd->Parameters->AddWithValue("@e", email);
			db->sqlCmd->Parameters->AddWithValue("@p", pass);
			db->sqlCmd->Parameters->AddWithValue("@t", role);

			int newUserID = Convert::ToInt32(db->sqlCmd->ExecuteScalar());

			// 3) Insert Student (only for Students)
			if (role == "Student") {
				String^ insertStudent =
					"INSERT INTO Student (studentID, userID_FK) VALUES (@sid, @uid)";
				db->sqlCmd->CommandText = insertStudent;
				db->sqlCmd->Parameters->Clear();
				db->sqlCmd->Parameters->AddWithValue("@sid", sid);
				db->sqlCmd->Parameters->AddWithValue("@uid", newUserID);
				db->sqlCmd->ExecuteNonQuery();
			}

			db->Close();

			MessageBox::Show("Account created successfully!");

			this->Hide();
			Group7FinalProject::StudentMain^ dash =
				gcnew Group7FinalProject::StudentMain(newUserID);
			dash->ShowDialog();
			this->Show();

		}
		catch (Exception^ ex) {
			MessageBox::Show("Signup Error: " + ex->Message);
			if (db->sqlConn->State == ConnectionState::Open) db->Close();
		}
	}
	};
}
