#pragma once

namespace Group7FinalProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SudentDashboard
	/// </summary>
	public ref class SudentDashboard : public System::Windows::Forms::Form
	{
	public:
		SudentDashboard(void)
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
		~SudentDashboard()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:

	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem3;
	private: System::Windows::Forms::ToolStripMenuItem^ profileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ systemSetUpToolStripMenuItem;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Label^ txtStudentName;
	private: System::Windows::Forms::Label^ txtCurrentSem;
	private: System::Windows::Forms::PictureBox^ profilePictureBox;
	private: System::Windows::Forms::TextBox^ txtSearch;
	private: System::Windows::Forms::ComboBox^ comboBox1;





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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(SudentDashboard::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->profileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->systemSetUpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->txtStudentName = (gcnew System::Windows::Forms::Label());
			this->txtCurrentSem = (gcnew System::Windows::Forms::Label());
			this->profilePictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->txtSearch = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->profilePictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->menuStrip1->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(28, 28);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->toolStripMenuItem1,
					this->toolStripMenuItem2, this->toolStripMenuItem3, this->profileToolStripMenuItem, this->systemSetUpToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1153, 38);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(168, 34);
			this->toolStripMenuItem1->Text = L"📕My Courses";
			this->toolStripMenuItem1->Click += gcnew System::EventHandler(this, &SudentDashboard::toolStripMenuItem1_Click);
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(149, 34);
			this->toolStripMenuItem2->Text = L"🧾Transcript";
			// 
			// toolStripMenuItem3
			// 
			this->toolStripMenuItem3->Name = L"toolStripMenuItem3";
			this->toolStripMenuItem3->Size = System::Drawing::Size(178, 34);
			this->toolStripMenuItem3->Text = L"💳Fee Payment";
			// 
			// profileToolStripMenuItem
			// 
			this->profileToolStripMenuItem->Name = L"profileToolStripMenuItem";
			this->profileToolStripMenuItem->Size = System::Drawing::Size(119, 34);
			this->profileToolStripMenuItem->Text = L"👤Profile";
			// 
			// systemSetUpToolStripMenuItem
			// 
			this->systemSetUpToolStripMenuItem->Name = L"systemSetUpToolStripMenuItem";
			this->systemSetUpToolStripMenuItem->Size = System::Drawing::Size(134, 34);
			this->systemSetUpToolStripMenuItem->Text = L"⚙️Settings";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(61, 714);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 72;
			this->dataGridView1->RowTemplate->Height = 31;
			this->dataGridView1->Size = System::Drawing::Size(1035, 565);
			this->dataGridView1->TabIndex = 1;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->textBox3);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Location = System::Drawing::Point(56, 334);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(295, 136);
			this->panel1->TabIndex = 3;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->textBox1);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Location = System::Drawing::Point(414, 334);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(295, 136);
			this->panel2->TabIndex = 4;
			// 
			// panel3
			// 
			this->panel3->AutoSize = true;
			this->panel3->BackColor = System::Drawing::Color::White;
			this->panel3->Controls->Add(this->textBox2);
			this->panel3->Controls->Add(this->label4);
			this->panel3->Location = System::Drawing::Point(770, 334);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(295, 136);
			this->panel3->TabIndex = 5;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.14286F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(51, 517);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(291, 55);
			this->label1->TabIndex = 6;
			this->label1->Text = L"My Courses";
			this->label1->Click += gcnew System::EventHandler(this, &SudentDashboard::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(25, 17);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(142, 25);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Credits Earned";
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
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(21, 17);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(167, 25);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Outstanding Fees";
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::White;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.14286F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(26, 52);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(120, 61);
			this->textBox2->TabIndex = 2;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &SudentDashboard::textBox2_TextChanged);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::White;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.14286F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(30, 52);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(103, 61);
			this->textBox1->TabIndex = 3;
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::Color::White;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.14286F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(26, 52);
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(111, 61);
			this->textBox3->TabIndex = 3;
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->profilePictureBox);
			this->panel4->Controls->Add(this->txtCurrentSem);
			this->panel4->Controls->Add(this->txtStudentName);
			this->panel4->Location = System::Drawing::Point(61, 58);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(1014, 218);
			this->panel4->TabIndex = 7;
			// 
			// txtStudentName
			// 
			this->txtStudentName->AutoSize = true;
			this->txtStudentName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.14286F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtStudentName->Location = System::Drawing::Point(252, 38);
			this->txtStudentName->Name = L"txtStudentName";
			this->txtStudentName->Size = System::Drawing::Size(389, 38);
			this->txtStudentName->TabIndex = 1;
			this->txtStudentName->Text = L"Welcome, Alex Johnson";
			// 
			// txtCurrentSem
			// 
			this->txtCurrentSem->AutoSize = true;
			this->txtCurrentSem->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.14286F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtCurrentSem->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->txtCurrentSem->Location = System::Drawing::Point(252, 91);
			this->txtCurrentSem->Name = L"txtCurrentSem";
			this->txtCurrentSem->Size = System::Drawing::Size(453, 38);
			this->txtCurrentSem->TabIndex = 2;
			this->txtCurrentSem->Text = L"Current Semester: Fall 2025";
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
			// txtSearch
			// 
			this->txtSearch->Location = System::Drawing::Point(56, 621);
			this->txtSearch->Name = L"txtSearch";
			this->txtSearch->Size = System::Drawing::Size(402, 29);
			this->txtSearch->TabIndex = 8;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(907, 630);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(189, 32);
			this->comboBox1->TabIndex = 9;
			// 
			// SudentDashboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1153, 1327);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->txtSearch);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"SudentDashboard";
			this->Text = L"SudentDashboard";
			this->Load += gcnew System::EventHandler(this, &SudentDashboard::SudentDashboard_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->profilePictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void toolStripTextBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void toolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void SudentDashboard_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void backgroundWorker1_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
