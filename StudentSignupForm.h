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
	/// Summary for StudentSignupForm
	/// </summary>
	public ref class StudentSignupForm : public System::Windows::Forms::Form
	{
	public:
		Database^ db = gcnew Database();
		StudentSignupForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &StudentSignupForm::OnRoleChanged);

			ToggleStudentFields(false);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~StudentSignupForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::LinkLabel^ linkSwitch;
	private: System::Windows::Forms::TextBox^ textBoxName;
	private: System::Windows::Forms::Label^ labelName;
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ txtSID;
	private: System::Windows::Forms::Label^ label6;
	protected:












	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(StudentSignupForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->txtSID = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->linkSwitch = (gcnew System::Windows::Forms::LinkLabel());
			this->textBoxName = (gcnew System::Windows::Forms::TextBox());
			this->labelName = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			resources->ApplyResources(this->label1, L"label1");
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Name = L"label1";
			this->label1->Text = L"Create Your Account";
			// 
			// panel1
			// 
			resources->ApplyResources(this->panel1, L"panel1");
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->textBox4);
			this->panel1->Controls->Add(this->label7);
			this->panel1->Controls->Add(this->txtSID);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->comboBox1);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->textBox3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->linkSwitch);
			this->panel1->Controls->Add(this->textBoxName);
			this->panel1->Controls->Add(this->labelName);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->textBox2);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Name = L"panel1";
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &StudentSignupForm::panel1_Paint);
			// 
			// textBox4
			// 
			resources->ApplyResources(this->textBox4, L"textBox4");
			this->textBox4->Name = L"textBox4";
			// 
			// label7
			// 
			resources->ApplyResources(this->label7, L"label7");
			this->label7->Name = L"label7";
			// 
			// txtSID
			// 
			resources->ApplyResources(this->txtSID, L"txtSID");
			this->txtSID->Name = L"txtSID";
			// 
			// label6
			// 
			resources->ApplyResources(this->label6, L"label6");
			this->label6->Name = L"label6";
			// 
			// comboBox1
			// 
			resources->ApplyResources(this->comboBox1, L"comboBox1");
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				resources->GetString(L"comboBox1.Items"), resources->GetString(L"comboBox1.Items1"),
					resources->GetString(L"comboBox1.Items2")
			});
			this->comboBox1->Name = L"comboBox1";
			// 
			// label5
			// 
			resources->ApplyResources(this->label5, L"label5");
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Name = L"label5";
			// 
			// textBox3
			// 
			resources->ApplyResources(this->textBox3, L"textBox3");
			this->textBox3->Name = L"textBox3";
			// 
			// label2
			// 
			resources->ApplyResources(this->label2, L"label2");
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Name = L"label2";
			// 
			// linkSwitch
			// 
			resources->ApplyResources(this->linkSwitch, L"linkSwitch");
			this->linkSwitch->BackColor = System::Drawing::Color::Transparent;
			this->linkSwitch->LinkColor = System::Drawing::Color::Brown;
			this->linkSwitch->Name = L"linkSwitch";
			this->linkSwitch->TabStop = true;
			// 
			// textBoxName
			// 
			resources->ApplyResources(this->textBoxName, L"textBoxName");
			this->textBoxName->Name = L"textBoxName";
			// 
			// labelName
			// 
			resources->ApplyResources(this->labelName, L"labelName");
			this->labelName->BackColor = System::Drawing::Color::Transparent;
			this->labelName->Name = L"labelName";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Brown;
			this->button1->ForeColor = System::Drawing::Color::White;
			resources->ApplyResources(this->button1, L"button1");
			this->button1->Name = L"button1";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// textBox2
			// 
			resources->ApplyResources(this->textBox2, L"textBox2");
			this->textBox2->Name = L"textBox2";
			// 
			// textBox1
			// 
			resources->ApplyResources(this->textBox1, L"textBox1");
			this->textBox1->Name = L"textBox1";
			// 
			// label4
			// 
			resources->ApplyResources(this->label4, L"label4");
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Name = L"label4";
			// 
			// label3
			// 
			resources->ApplyResources(this->label3, L"label3");
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Name = L"label3";
			// 
			// StudentSignupForm
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Snow;
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label1);
			this->Name = L"StudentSignupForm";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: void ToggleStudentFields(bool isVisible) {
		// Student ID Field and Label
		this->txtSID->Visible = isVisible;
		this->label6->Visible = isVisible;

		// Program Field and Label
		this->textBox4->Visible = isVisible;
		this->label7->Visible = isVisible;
	}

	private: System::Void OnRoleChanged(System::Object^ sender, System::EventArgs^ e) {
		if (this->comboBox1->SelectedItem == nullptr) return;

		String^ selectedRole = this->comboBox1->SelectedItem->ToString();

		// If you want fields to SHOW only when Student is picked:
		if (selectedRole == "Student") {
			ToggleStudentFields(true);
		}
		else {
			ToggleStudentFields(false);
		}
	}


	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}

	};
}

