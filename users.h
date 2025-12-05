#pragma once
using namespace System;
public ref class User {
	public:
		int dbID;
		String^ name;
		String^ email;
		String^ password;
};
public ref class AdminStaff : public User {
	public:
		int staffID;
		int deptID;
};
public ref class Faculty : public User {
	public:
		int facultyID;
		int deptID;
		String^ position;
};
public ref class Student : public User {
	public:
		int studentID;
		int currentLevel;
		String^ semester;
};
