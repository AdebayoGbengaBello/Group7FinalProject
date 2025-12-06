#pragma once

namespace Group7FinalProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for myCourses
	/// </summary>
	public ref class myCourses : public System::Windows::Forms::Form
	{
	public:
		myCourses(void)
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
	private: System::Windows::Forms::Button^ button1;









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
			this->button1 = (gcnew System::Windows::Forms::Button());
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
			this->label1->Location = System::Drawing::Point(12, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(369, 31);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Course Content Management";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F));
			this->label2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label2->Location = System::Drawing::Point(15, 60);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(100, 17);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Select Course:";
			// 
			// comboBoxCourse
			// 
			this->comboBoxCourse->FormattingEnabled = true;
			this->comboBoxCourse->Location = System::Drawing::Point(18, 80);
			this->comboBoxCourse->Name = L"comboBoxCourse";
			this->comboBoxCourse->Size = System::Drawing::Size(233, 21);
			this->comboBoxCourse->TabIndex = 2;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F));
			this->button1->Location = System::Drawing::Point(498, 24);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(174, 30);
			this->button1->TabIndex = 3;
			this->button1->Text = L"+ Add New Material";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->dataGridView1);
			this->panel1->Location = System::Drawing::Point(20, 164);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(651, 293);
			this->panel1->TabIndex = 5;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(5, 7);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(645, 283);
			this->dataGridView1->TabIndex = 0;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F));
			this->label3->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label3->Location = System::Drawing::Point(22, 144);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(215, 17);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Enrolled Students of this Course:";
			// 
			// myCourses
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Maroon;
			this->ClientSize = System::Drawing::Size(684, 549);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBoxCourse);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"myCourses";
			this->Text = L"My Courses";
			this->Load += gcnew System::EventHandler(this, &myCourses::myCourses_Load);
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void myCourses_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
