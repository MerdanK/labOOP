#pragma once
#include<iostream>
using namespace std;

class Exeption
{
protected:
	int errorNumber;

public:
	Exeption(int errnum = 0)
	{
		this->errorNumber = errnum;
	}
	~Exeption() {}
};

class exeption_mes : public Exeption
{
private:

	string message; 

public:
	exeption_mes(int errnum, string mes)
	{

		this->errorNumber = errnum;
		this->message = mes;
	}
	void wwod() {
		cout << "Код ошибки " << this->errorNumber << this->message << endl;
		cout << "Повторите ввод!!" << endl;
	}
	~exeption_mes() {}
};

inline char* funk()
{
	int const  size = 100;
	char* ptr = new char[size];
	int ch = 0;

	do
	{
		try
		{
			ch = 0;
			cin >> ptr;
			for (int i = 0; ptr[i]; i++)
			{
				if ((ptr[i] < 'A' || ptr[i]> 'Z') && (ptr[i] < 'a' || ptr[i]>'z'))
					throw exeption_mes(105, "| Напишите на английском!!! ");
			}

		}
		catch (exeption_mes ob)
		{
			ch = 1;
			ob.wwod();

		}
	} while (ch);
	return ptr;
}


inline int distane(int bas, int son)
{
	int nm = 0;
	int ch = 0;
	do
	{

		try
		{

			ch = 0;
			cin >> nm;
			ch = cin.rdstate();
			//ch = cin.good();
			//ch = cin.rdstate();
			//ch = cin.fail();

			if (nm < bas || nm > son)
				throw exeption_mes(665, "| Возрасть должно быть от 1  до 100 !!!");


			if ((ch & ios::failbit) || cin.get() != '\n')
				throw exeption_mes(150, "| Напишите цифры !!! ");





		}

		catch (exeption_mes ob)
		{
			ch = 1;
			ob.wwod();
			cin.clear();
			rewind(stdin);

		}


	} while (ch);
	return nm;



}



