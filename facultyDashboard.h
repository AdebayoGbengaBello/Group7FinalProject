#pragma once

namespace Group7FinalProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for facultyDashboard
	/// </summary>
	public ref class facultyDashboard : public System::Windows::Forms::Form
	{
	public:
		facultyDashboard(void)
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
		~facultyDashboard()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::Button^ btnTranscript;

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::Button^ btnSessons;
	private: System::Windows::Forms::Button^ btnAnnouncements;
	private: System::Windows::Forms::Button^ btnResources;




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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(facultyDashboard::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->btnTranscript = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->btnSessons = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->btnAnnouncements = (gcnew System::Windows::Forms::Button());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->btnResources = (gcnew System::Windows::Forms::Button());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->panel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->panel5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Century Schoolbook", 20, System::Drawing::FontStyle::Bold));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label1->Location = System::Drawing::Point(12, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(288, 32);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Faculty Dashboard";
			this->label1->Click += gcnew System::EventHandler(this, &facultyDashboard::label1_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->btnTranscript);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Location = System::Drawing::Point(19, 67);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(152, 124);
			this->panel1->TabIndex = 1;
			// 
			// btnTranscript
			// 
			this->btnTranscript->Font = (gcnew System::Drawing::Font(L"Century Schoolbook", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnTranscript->Location = System::Drawing::Point(-1, 73);
			this->btnTranscript->Name = L"btnTranscript";
			this->btnTranscript->Size = System::Drawing::Size(153, 51);
			this->btnTranscript->TabIndex = 1;
			this->btnTranscript->Text = L"View All Transcripts";
			this->btnTranscript->UseVisualStyleBackColor = true;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(3, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(147, 78);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->btnSessons);
			this->panel2->Controls->Add(this->pictureBox2);
			this->panel2->Location = System::Drawing::Point(192, 67);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(154, 124);
			this->panel2->TabIndex = 2;
			// 
			// btnSessons
			// 
			this->btnSessons->Font = (gcnew System::Drawing::Font(L"Century Schoolbook", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSessons->Location = System::Drawing::Point(0, 73);
			this->btnSessons->Name = L"btnSessons";
			this->btnSessons->Size = System::Drawing::Size(154, 51);
			this->btnSessons->TabIndex = 1;
			this->btnSessons->Text = L"Schedule Sessions";
			this->btnSessons->UseVisualStyleBackColor = true;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(2, 2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(151, 75);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 0;
			this->pictureBox2->TabStop = false;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->btnAnnouncements);
			this->panel3->Controls->Add(this->pictureBox3);
			this->panel3->Location = System::Drawing::Point(373, 67);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(159, 124);
			this->panel3->TabIndex = 3;
			// 
			// btnAnnouncements
			// 
			this->btnAnnouncements->Font = (gcnew System::Drawing::Font(L"Century Schoolbook", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAnnouncements->Location = System::Drawing::Point(0, 73);
			this->btnAnnouncements->Name = L"btnAnnouncements";
			this->btnAnnouncements->Size = System::Drawing::Size(159, 51);
			this->btnAnnouncements->TabIndex = 1;
			this->btnAnnouncements->Text = L"Send Announcements";
			this->btnAnnouncements->UseVisualStyleBackColor = true;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(2, 2);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(156, 75);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox3->TabIndex = 0;
			this->pictureBox3->TabStop = false;
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->btnResources);
			this->panel4->Controls->Add(this->pictureBox4);
			this->panel4->Location = System::Drawing::Point(550, 66);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(153, 125);
			this->panel4->TabIndex = 4;
			// 
			// btnResources
			// 
			this->btnResources->Font = (gcnew System::Drawing::Font(L"Century Schoolbook", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnResources->Location = System::Drawing::Point(0, 74);
			this->btnResources->Name = L"btnResources";
			this->btnResources->Size = System::Drawing::Size(152, 51);
			this->btnResources->TabIndex = 1;
			this->btnResources->Text = L"Access Resources";
			this->btnResources->UseVisualStyleBackColor = true;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(2, 0);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(148, 78);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox4->TabIndex = 0;
			this->pictureBox4->TabStop = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Century Schoolbook", 17.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label2->Location = System::Drawing::Point(12, 254);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(147, 28);
			this->label2->TabIndex = 5;
			this->label2->Text = L"My Advisees";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Century Schoolbook", 17.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label3->Location = System::Drawing::Point(442, 254);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(276, 28);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Upcoming Appointments";
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->dataGridView1);
			this->panel5->Location = System::Drawing::Point(9, 291);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(407, 305);
			this->panel5->TabIndex = 7;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(2, 2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 50;
			this->dataGridView1->Size = System::Drawing::Size(404, 302);
			this->dataGridView1->TabIndex = 0;
			// 
			// panel6
			// 
			this->panel6->Controls->Add(this->dataGridView2);
			this->panel6->Location = System::Drawing::Point(443, 291);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(259, 305);
			this->panel6->TabIndex = 8;
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Location = System::Drawing::Point(4, 4);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowHeadersWidth = 40;
			this->dataGridView2->Size = System::Drawing::Size(254, 299);
			this->dataGridView2->TabIndex = 0;
			// 
			// facultyDashboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Maroon;
			this->ClientSize = System::Drawing::Size(721, 617);
			this->Controls->Add(this->panel6);
			this->Controls->Add(this->panel5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"facultyDashboard";
			this->Text = L"Faculty Dashboard";
			this->Load += gcnew System::EventHandler(this, &facultyDashboard::facultyDashboard_Load);
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->panel3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->panel4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->panel5->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel6->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void facultyDashboard_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
