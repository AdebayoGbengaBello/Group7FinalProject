#pragma once
#include "Database.h"

namespace Group7FinalProject {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Drawing::Printing;

    public ref class TranscriptView : public System::Windows::Forms::Form
    {
    public:
        Database^ db = gcnew Database();
        DataTable^ transcriptTable;
        PrintDocument^ printDoc;

        int studentID;  // set this when opening the form

        TranscriptView(int sid)
        {
            studentID = sid;

            InitializeComponent();

            printDoc = gcnew PrintDocument();
            printDoc->PrintPage += gcnew PrintPageEventHandler(this, &TranscriptView::OnPrintPage);

            printPreviewControl1->Document = printDoc;

            LoadTranscriptData();
        }

    protected:
        ~TranscriptView()
        {
            if (components)
                delete components;
        }

    private:
        System::Windows::Forms::PrintPreviewControl^ printPreviewControl1;
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::Button^ btnPrintTranscript;
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
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
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold));
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
            this->btnPrintTranscript->Click += gcnew System::EventHandler(this, &TranscriptView::btnPrintTranscript_Click);
            // 
            // TranscriptView
            // 
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

    private:

        // Fetch Transcript Data From DB
        void LoadTranscriptData()
        {
            transcriptTable = gcnew DataTable();

            try
            {
                db->Open();

                String^ query =
                    "SELECT c.courseCode, c.courseTitle, c.credit, g.letterGrade, c.semester, t.cgpa "
                    "FROM Grade g "
                    "JOIN Course c ON g.courseID = c.courseID "
                    "LEFT JOIN Transcript t ON g.studentID = t.studentID "
                    "WHERE g.studentID = @sid "
                    "ORDER BY c.semester, c.courseCode";

                db->sqlCmd->CommandText = query;
                db->sqlCmd->Parameters->Clear();
                db->sqlCmd->Parameters->AddWithValue("@sid", studentID);

                MySqlDataAdapter^ da = gcnew MySqlDataAdapter(db->sqlCmd);
                da->Fill(transcriptTable);

                db->Close();
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Failed to load transcript: " + ex->Message);
            }
        }

        // DRAW THE TRANSCRIPT DOCUMENT
        void OnPrintPage(Object^ sender, PrintPageEventArgs^ e)
        {
            int x = 50;
            int y = 50;
            int lineHeight = 40;

            System::Drawing::Font^ headerFont = gcnew System::Drawing::Font("Arial", 18, System::Drawing::FontStyle::Bold);
            System::Drawing::Font^ boldFont = gcnew System::Drawing::Font("Arial", 12, System::Drawing::FontStyle::Bold);
            System::Drawing::Font^ textFont = gcnew System::Drawing::Font("Arial", 12);

            e->Graphics->DrawString("ACADEMIC TRANSCRIPT", headerFont, Brushes::Black, x, y);
            y += 60;

            // Table header
            e->Graphics->DrawString("Code", boldFont, Brushes::Black, x, y);
            e->Graphics->DrawString("Course Name", boldFont, Brushes::Black, x + 120, y);
            e->Graphics->DrawString("Credits", boldFont, Brushes::Black, x + 420, y);
            e->Graphics->DrawString("Grade", boldFont, Brushes::Black, x + 500, y);
            e->Graphics->DrawString("Semester", boldFont, Brushes::Black, x + 580, y);
            y += 35;

            // Table rows
            for each (DataRow ^ row in transcriptTable->Rows)
            {
                e->Graphics->DrawString(row["courseCode"]->ToString(), textFont, Brushes::Black, x, y);
                e->Graphics->DrawString(row["courseName"]->ToString(), textFont, Brushes::Black, x + 120, y);
                e->Graphics->DrawString(row["creditHours"]->ToString(), textFont, Brushes::Black, x + 420, y);
                e->Graphics->DrawString(row["grade"]->ToString(), textFont, Brushes::Black, x + 500, y);
                e->Graphics->DrawString(row["semester"]->ToString(), textFont, Brushes::Black, x + 580, y);

                y += lineHeight;
            }

            // Display CGPA at the bottom if available
            if (transcriptTable->Rows->Count > 0)
            {
                DataRow^ firstRow = transcriptTable->Rows[0];
                if (!Convert::IsDBNull(firstRow["cgpa"]))
                {
                    y += 20;
                    e->Graphics->DrawString("CGPA: " + firstRow["cgpa"]->ToString(), boldFont, Brushes::Black, x, y);
                }
            }
        }

        // PRINT BUTTON
        System::Void btnPrintTranscript_Click(System::Object^ sender, System::EventArgs^ e)
        {
            PrintDialog^ dlg = gcnew PrintDialog();
            dlg->Document = printDoc;

            if (dlg->ShowDialog() == System::Windows::Forms::DialogResult::OK)
            {
                printDoc->Print();
            }
        }
    };
}
