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
	/// Summary for TranscriptView
	/// </summary>
	public ref class TranscriptView : public System::Windows::Forms::Form
	{
	public:
		Database^ db = gcnew Database();
		TranscriptView(void)
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
		~TranscriptView()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:





	private: System::Windows::Forms::PrintPreviewControl^ printPreviewControl1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnPrintTranscript;


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
			this->printPreviewControl1 = (gcnew System::Windows::Forms::PrintPreviewControl());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnPrintTranscript = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// printPreviewControl1
			// 
			this->printPreviewControl1->Location = System::Drawing::Point(65, 179);
			this->printPreviewControl1->Name = L"printPreviewControl1";
			this->printPreviewControl1->Size = System::Drawing::Size(1005, 974);
			this->printPreviewControl1->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(46, 64);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(421, 48);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Academic Transcript";
			// 
			// btnPrintTranscript
			// 
			this->btnPrintTranscript->BackColor = System::Drawing::Color::Brown;
			this->btnPrintTranscript->ForeColor = System::Drawing::Color::White;
			this->btnPrintTranscript->Location = System::Drawing::Point(844, 68);
			this->btnPrintTranscript->Name = L"btnPrintTranscript";
			this->btnPrintTranscript->Size = System::Drawing::Size(216, 56);
			this->btnPrintTranscript->TabIndex = 4;
			this->btnPrintTranscript->Text = L"🖨️  Print Transcript";
			this->btnPrintTranscript->UseVisualStyleBackColor = false;
			// 
			// TranscriptView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1162, 1187);
			this->Controls->Add(this->btnPrintTranscript);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->printPreviewControl1);
			this->Name = L"TranscriptView";
			this->Text = L"TranscriptView";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
