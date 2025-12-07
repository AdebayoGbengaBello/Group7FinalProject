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
	/// Summary for PaymentView
	/// </summary>
	public ref class PaymentView : public System::Windows::Forms::Form
	{
	public:

		Database^ db = gcnew Database();

		int currentStudentID = 2;

		PaymentView(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			LoadFeeData();
			LoadTransactionHistory();
			//StyleCustomGrid(/*dataGridView1*/);

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PaymentView()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ txtAmountPaid;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ txtDueDate;

	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::TextBox^ txtAmount;

	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Button^ btnPay;

	private: System::Windows::Forms::ComboBox^ cmbPayMethod;

	private: System::Windows::Forms::Label^ label15;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(PaymentView::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->txtDueDate = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->txtAmountPaid = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->btnPay = (gcnew System::Windows::Forms::Button());
			this->cmbPayMethod = (gcnew System::Windows::Forms::ComboBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->txtAmount = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->txtDueDate);
			this->panel1->Controls->Add(this->label9);
			this->panel1->Controls->Add(this->label8);
			this->panel1->Controls->Add(this->txtAmountPaid);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Location = System::Drawing::Point(42, 131);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(821, 242);
			this->panel1->TabIndex = 3;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &PaymentView::panel1_Paint);
			// 
			// txtDueDate
			// 
			this->txtDueDate->AutoSize = true;
			this->txtDueDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.14286F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtDueDate->Location = System::Drawing::Point(148, 188);
			this->txtDueDate->Name = L"txtDueDate";
			this->txtDueDate->Size = System::Drawing::Size(258, 31);
			this->txtDueDate->TabIndex = 13;
			this->txtDueDate->Text = L"December  15, 2025";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.14286F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(29, 188);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(122, 31);
			this->label9->TabIndex = 11;
			this->label9->Text = L"Due by : ";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.14286F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(324, 139);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(72, 31);
			this->label8->TabIndex = 12;
			this->label8->Text = L"USD";
			// 
			// txtAmountPaid
			// 
			this->txtAmountPaid->AutoSize = true;
			this->txtAmountPaid->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtAmountPaid->ForeColor = System::Drawing::Color::Brown;
			this->txtAmountPaid->Location = System::Drawing::Point(25, 119);
			this->txtAmountPaid->Name = L"txtAmountPaid";
			this->txtAmountPaid->Size = System::Drawing::Size(243, 56);
			this->txtAmountPaid->TabIndex = 11;
			this->txtAmountPaid->Text = L"$ 2,500.00";
			this->txtAmountPaid->Click += gcnew System::EventHandler(this, &PaymentView::label7_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.14286F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(26, 77);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(407, 31);
			this->label6->TabIndex = 10;
			this->label6->Text = L"Summary Of the current Balance";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.14286F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(16, 28);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(301, 39);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Outstanding Fees";
			this->label5->Click += gcnew System::EventHandler(this, &PaymentView::label5_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(25, 28);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 48);
			this->label2->TabIndex = 8;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->btnPay);
			this->panel2->Controls->Add(this->cmbPayMethod);
			this->panel2->Controls->Add(this->label15);
			this->panel2->Controls->Add(this->label14);
			this->panel2->Controls->Add(this->txtAmount);
			this->panel2->Controls->Add(this->label13);
			this->panel2->Controls->Add(this->label12);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Location = System::Drawing::Point(906, 131);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(455, 485);
			this->panel2->TabIndex = 4;
			// 
			// btnPay
			// 
			this->btnPay->BackColor = System::Drawing::Color::Brown;
			this->btnPay->ForeColor = System::Drawing::Color::White;
			this->btnPay->Location = System::Drawing::Point(33, 369);
			this->btnPay->Name = L"btnPay";
			this->btnPay->Size = System::Drawing::Size(385, 75);
			this->btnPay->TabIndex = 17;
			this->btnPay->Text = L"🔒 Proceed to payment";
			this->btnPay->UseVisualStyleBackColor = false;
			this->btnPay->Click += gcnew System::EventHandler(this, &PaymentView::button1_Click);
			// 
			// cmbPayMethod
			// 
			this->cmbPayMethod->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->cmbPayMethod->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.14286F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->cmbPayMethod->FormattingEnabled = true;
			this->cmbPayMethod->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"  Mobile Money", L"  Bank Transfere" });
			this->cmbPayMethod->Location = System::Drawing::Point(41, 288);
			this->cmbPayMethod->Name = L"cmbPayMethod";
			this->cmbPayMethod->Size = System::Drawing::Size(358, 38);
			this->cmbPayMethod->TabIndex = 16;
			this->cmbPayMethod->Text = L"  Credit/Debit Card";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.142858F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->Location = System::Drawing::Point(36, 247);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(174, 25);
			this->label15->TabIndex = 15;
			this->label15->Text = L"Payment Method";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.142858F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->Location = System::Drawing::Point(29, 188);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(24, 25);
			this->label14->TabIndex = 14;
			this->label14->Text = L"$";
			// 
			// txtAmount
			// 
			this->txtAmount->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.14286F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtAmount->Location = System::Drawing::Point(59, 181);
			this->txtAmount->Name = L"txtAmount";
			this->txtAmount->Size = System::Drawing::Size(360, 37);
			this->txtAmount->TabIndex = 13;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.142858F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(36, 138);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(153, 25);
			this->label13->TabIndex = 12;
			this->label13->Text = L"Amount (USD)";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(37, 83);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(331, 25);
			this->label12->TabIndex = 11;
			this->label12->Text = L"Enter the amount you wish to pay";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(36, 42);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(239, 32);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Make a Payment";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(43, 537);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 72;
			this->dataGridView1->RowTemplate->Height = 31;
			this->dataGridView1->Size = System::Drawing::Size(820, 614);
			this->dataGridView1->TabIndex = 5;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel3->Controls->Add(this->label11);
			this->panel3->Controls->Add(this->label4);
			this->panel3->Location = System::Drawing::Point(44, 419);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(819, 112);
			this->panel3->TabIndex = 6;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.857143F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(15, 62);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(277, 29);
			this->label11->TabIndex = 11;
			this->label11->Text = L"Your recent transactions.";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(14, 20);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(236, 32);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Payment History";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(47, 46);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(279, 48);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Fee Payment";
			// 
			// PaymentView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(1392, 1230);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"PaymentView";
			this->Text = L"Payment";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &PaymentView::PaymentView_FormClosed);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ inputAmount = txtAmount->Text->Trim();
	String^ method = cmbPayMethod->Text;

	// Validation
	if (String::IsNullOrEmpty(inputAmount)) {
		MessageBox::Show("Please enter an amount.");
		return;
	}

	try {
		double amountToPay = Convert::ToDouble(inputAmount);

		if (amountToPay <= 0) {
			MessageBox::Show("Amount must be greater than 0.");
			return;
		}

		db->Open();

		// STEP A: Insert into PaymentHistory
		String^ insertHist = "INSERT INTO PaymentTransaction (studentID, transactionDate, description, amount, status) "
			"VALUES (" + currentStudentID + ", CURDATE(), 'Payment via " + method + "', " + amountToPay + ", 'Completed')";

		db->sqlCmd->CommandText = insertHist;
		db->sqlCmd->ExecuteNonQuery();

		// STEP B: Update Fee Table (Increase Amount Paid, which reduces Balance)
		String^ updateFee = "UPDATE Fee SET amountPaid = amountPaid + " + amountToPay + " WHERE studentID = " + currentStudentID;

		db->sqlCmd->CommandText = updateFee;
		db->sqlCmd->ExecuteNonQuery();

		db->Close();

		// Success & Refresh
		MessageBox::Show("Payment Successful! $" + amountToPay.ToString("N2") + " paid.");
		txtAmount->Text = ""; 
		LoadFeeData();       
		LoadTransactionHistory();
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error processing payment: " + ex->Message);
		if (db->sqlConn->State == ConnectionState::Open) db->Close();
	}
}

	// 1. Load Fee data
private: void LoadFeeData() {
	try {
		db->Open();
		String^ query = "SELECT balance, dueDate FROM Fee WHERE studentID = " + currentStudentID;

		db->sqlCmd->CommandText = query;
		db->sqlDR = db->sqlCmd->ExecuteReader();

		if (db->sqlDR->Read()) {
			if (db->sqlDR["balance"] != DBNull::Value) {
				double bal = Convert::ToDouble(db->sqlDR["balance"]);
				txtAmountPaid->Text = "$ " + bal.ToString("N2"); // e.g. $ 2,500.00
			}
			else {
				txtAmountPaid->Text = "$ 0.00";
			}

			if (db->sqlDR["dueDate"] != DBNull::Value) {
				DateTime dt = Convert::ToDateTime(db->sqlDR["dueDate"]);
				txtDueDate->Text = dt.ToString("MMMM dd, yyyy");
			}
		}
		db->Close();
	}
	catch (Exception^ ex) {
		MessageBox::Show(ex->Message);
		if (db->sqlConn->State == ConnectionState::Open) db->Close();
	}
}

// 2. Load Transaction History into the table
private: void LoadTransactionHistory() {
	try {
		db->Open();
		String^ query = "SELECT transactionDate AS 'Date', description AS 'Description', "
			"amount AS 'Amount', status AS 'Status' "
			"FROM PaymentTransaction WHERE studentID = " + currentStudentID + " ORDER BY transactionDate DESC";

		db->sqlDA = gcnew MySql::Data::MySqlClient::MySqlDataAdapter(query, db->sqlConn);
		DataTable^ dt = gcnew DataTable();
		db->sqlDA->Fill(dt);

		dataGridView1->DataSource = dt;
		db->Close();
	}
	catch (Exception^ ex) {
		MessageBox::Show(ex->Message);
		if (db->sqlConn->State == ConnectionState::Open) db->Close();
	}
}


private: System::Void PaymentView_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	/*Group7FinalProject::StudentMain^ parentForm = (Group7FinalProject::StudentMain^)this->Owner;
	parentForm->LoadDashboardData();*/
	this->Close();
}
};
}
