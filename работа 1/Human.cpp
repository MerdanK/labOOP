#include "Human.h"
#include <iomanip>
#include "MyExeption.h"


void Human::setFirstname(string strFirstname) {
	this->Firstname = strFirstname;
}

void Human::setLastname(string  strLastname) {
	this->Lastname = strLastname;
}

void Human::setYear(const int year) {
	this->Year = year;
}

void Human::setPosition(string strposition)
{
	this->Position = strposition;
}
void Human::setSpeciality(string strspeciality)
{
	this->Speciality = strspeciality;
}
void Human::setListpapers(int listpaper)
{
	this->Listpapers;
}
 


string Human::getFirstname()const
{
	return this->Firstname;
}

string Human::getLastname()const
{
	return this->Lastname;
}

int Human::getYear() const
{
	return this->Year;
}

string Human::getposition()const
{
	return this->Position;
}
string Human::getspeciality()const
{
	return this->Speciality;
}
int Human::getListpapers()const
{
	return this->Listpapers;
}

istream& operator>>(istream& in, Human& objp)
{
	cout << "1.¬ведите фамилию: ";
	objp.setFirstname(funk());
	cout << "2. ¬ведите  им€: ";
    objp.setLastname(funk());
	cout << "3. ¬ведите год рождени€: "; 
    objp.setYear(distane(1,100));
	cout << "4. ¬ведите должность: "; 
    objp.setPosition(funk());
	cout << "5. ¬ведите специальность: "; 
    objp.setSpeciality(funk());
	cout << "6. ¬ведите научный труд: " ; 
	in >> objp.Listpapers;
	return in;
}

ostream& operator<<(ostream& out, Human& objp)
{
	out << setw(15) << std::right << objp.Firstname << setw(18) << std::right << objp.Lastname << setw(14) << std::right << objp.Year << setw(13) << std:: right << objp.Position << setw(25) << std:: right << objp.Speciality << setw(20) << std :: right << objp.Listpapers;
	return out;
}


fstream& operator>>(fstream& in, Human& obj)
{
	in >> obj.Firstname >> obj.Lastname >> obj.Year >> obj.Position >> obj.Speciality >> obj.Listpapers;
	return in;
}

fstream& operator<<(fstream& out, Human& obj)
{	
	out << obj.Firstname << " " << obj.Lastname << " " << obj.Year << " " << obj.Position << " " << obj.Speciality << " " << obj.Listpapers << endl;
	return out;
}

 
ifstream& operator>>(ifstream& in, Human& obj)
{
	
	char buffer[40];
	in.read(reinterpret_cast<char*>(&buffer), sizeof(buffer));
	string s1 = string(buffer);
	obj.Firstname = s1;

	in.read(reinterpret_cast<char*>(&buffer), sizeof(buffer));
	string s2 = string(buffer);
	obj.Lastname = s2;

	in.read(reinterpret_cast<char*>(&obj.Year), sizeof(obj.Year));

	
	in.read(reinterpret_cast<char*>(&buffer), sizeof(buffer));
	string s3 = string(buffer);
	obj.Position = s3;

	in.read(reinterpret_cast<char*>(&buffer), sizeof(buffer));
	string s4 = string(buffer);
	obj.Speciality = s4;

	in.read(reinterpret_cast<char*>(&obj.Listpapers), sizeof(obj.Listpapers));

	return in;
}


ofstream& operator<<(ofstream& out, Human& obj)
{
	char buf[ssize];
	strcpy_s(buf, obj.Firstname.length() + 1, obj.Firstname.c_str());
	out.write(reinterpret_cast<char*>(&buf), sizeof(buf));

	strcpy_s(buf, obj.Lastname.length() + 1, obj.Lastname.c_str());
	out.write(reinterpret_cast<char*>(&buf), sizeof(buf));

	out.write(reinterpret_cast<char*>(&obj.Year), sizeof(obj.Year));
	return out;

	strcpy_s(buf, obj.Position.length() + 1, obj.Position.c_str());
	out.write(reinterpret_cast<char*>(&buf), sizeof(buf));

	strcpy_s(buf, obj.Speciality.length() + 1, obj.Speciality.c_str());
	out.write(reinterpret_cast<char*>(&buf), sizeof(buf));

	out.write(reinterpret_cast<char*>(&obj.Listpapers), sizeof(obj.Listpapers));
	return out;

	

}




//ofstream& operator << (ofstream& out, Human& obj)
//{
//	/*char 
//	out.write(obj.Firstname.c_str(), 255);
//	out.write(obj.Lastname.c_str(), 255);*/
//	out.write(reinterpret_cast<char*>(&obj.Year), sizeof(obj.Year));
//	/*out << obj.Firstname<< " " << obj.Lastname << " " << obj.Year << " " << obj.position << " " << obj.speciality << " " << obj.Listpapers << endl;*/
//
//	return out;
//
//}


