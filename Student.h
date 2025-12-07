#pragma once
#include "Database.h"

using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;

namespace Group7FinalProject {

	public ref class Student {
	public:
		// --- PROPERTIES (Matches Database Schema) ---
		int ID;
		String^ FirstName;
		String^ LastName;
		String^ Email;
		String^ Password;
		String^ Gender;
		String^ Phone;
		String^ Address;
		String^ ProfileImage;
		DateTime DOB;

		// Student Specific
		int CurrentLevel;
		String^ Semester;
		int EnrollmentYear;
		int ExpectedGraduation;
		int CreditsEarned;

		// --- CONSTRUCTOR ---
		Student() {
			// Initialize defaults
			this->CreditsEarned = 0;
		}

		// --- STATIC LOGIN METHOD ---
		// Returns a Student object if successful, or nullptr if failed
		static Student^ Login(String^ email, String^ password) {
			Database^ db = gcnew Database();
			Student^ student = nullptr;

			try {
				db->Open();

				// 1. Join User and Student tables to verify identity AND role
				String^ query = "SELECT u.*, s.* FROM User u "
					"JOIN Student s ON u.dbID = s.studentID "
					"WHERE u.email = @email AND u.password = @pass";

				db->sqlCmd->CommandText = query;
				db->sqlCmd->Parameters->Clear();
				db->sqlCmd->Parameters->AddWithValue("@email", email);
				db->sqlCmd->Parameters->AddWithValue("@pass", password);

				MySqlDataReader^ reader = db->sqlCmd->ExecuteReader();

				if (reader->Read()) {
					// User found! Create and populate the Student object
					student = gcnew Student();

					student->ID = Convert::ToInt32(reader["dbID"]);
					student->FirstName = reader["firstName"]->ToString();
					student->LastName = reader["lastName"]->ToString();
					student->Email = reader["email"]->ToString();
					student->Gender = reader["gender"]->ToString();
					student->Phone = reader["phoneNumber"]->ToString();
					student->Address = reader["address"]->ToString();
					student->ProfileImage = reader["profileImage"]->ToString();

					if (reader["dateOfBirth"] != DBNull::Value)
						student->DOB = Convert::ToDateTime(reader["dateOfBirth"]);

					// Student Specifics
					student->CurrentLevel = Convert::ToInt32(reader["currentLevel"]);
					student->Semester = reader["semester"]->ToString();
					student->EnrollmentYear = Convert::ToInt32(reader["enrollmentYear"]);
					student->ExpectedGraduation = Convert::ToInt32(reader["expectedGraduation"]);
					student->CreditsEarned = Convert::ToInt32(reader["creditsEarned"]);
				}
				reader->Close();
			}
			catch (Exception^ ex) {
				System::Windows::Forms::MessageBox::Show("Login Error: " + ex->Message);
			}
			finally {
				db->Close();
			}

			return student;
		}
	};
}