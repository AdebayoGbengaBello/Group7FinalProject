#pragma once
<<<<<<< HEAD
#pragma once
=======
>>>>>>> Student_View

using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;

public ref class Database {
public:
	MySqlConnection^ sqlConn;
	MySqlCommand^ sqlCmd;
	MySqlDataAdapter^ sqlDA;
	MySqlDataReader^ sqlDR;
	DataTable^ sqlDT;
	String^ connectionString;

	// Constructor: This runs immediately when you write 'gcnew Database()'
	Database() {
		// 1. Set up the connection string exactly as shown in your image
		connectionString = "datasource=localhost; port=3306; username=root; password=; database=universityDB";

		// 2. Initialize the Connection
		sqlConn = gcnew MySqlConnection(connectionString);

		// 3. Initialize the Command and link it to the connection
		sqlCmd = gcnew MySqlCommand();
		sqlCmd->Connection = sqlConn;

		// 4. Initialize DataAdapter and DataTable
		sqlDA = gcnew MySqlDataAdapter();
		sqlDT = gcnew DataTable();
	}

	// Helper function to easily open the connection
	void Open() {
		if (sqlConn->State == ConnectionState::Closed) {
			sqlConn->Open();
		}
	}

	// Helper function to easily close the connection
	void Close() {
		if (sqlConn->State == ConnectionState::Open) {
			sqlConn->Close();
		}
	}
};