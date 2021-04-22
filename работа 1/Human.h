#pragma once
#include <string>
#include <iostream>
#include<fstream>

using namespace std;


constexpr auto ssize = 40;


class Human
{
private:
	string Firstname;
	string Lastname;
	int Year;
	string Position;
	string Speciality;
	int  Listpapers;
public:
	Human(string Fname = "", string Lname = "", int Year = 0, string Positin = "", string specialit = "", int listpaper = 0)
	{
		this->Firstname = Fname;
		this->Lastname = Lname;
		this->Year = Year;
		this->Position = Positin;
		this->Speciality = specialit;
		this->Listpapers = listpaper;
	}

	Human(const Human& obj) 
	{
		this->Firstname = obj.Firstname;
		this->Lastname = obj.Lastname;
		this->Year = obj.Year;
		this->Position = obj.Position;
		this->Speciality = obj.Speciality;
		this->Listpapers = obj.Listpapers;
	}

	void setFirstname(string);
	void setLastname(string);
	void setYear(const int);
	void setPosition(string);
	void setSpeciality(string);
	void setListpapers(int Listpaper);

	string getFirstname()const;
	string getLastname()const;
	int getYear()const;
	string getposition()const;
	string getspeciality()const;
	int getListpapers()const;

	friend istream& operator >> (istream& in, Human&);
	friend ostream& operator << (ostream& out, Human&);

	friend ifstream& operator >>(ifstream& in, Human& obj);
	friend ofstream& operator << (ofstream& out, Human& obj);

	friend fstream& operator>>(fstream& in, Human& obj);
	friend fstream& operator<<(fstream& out, Human& obj);
};