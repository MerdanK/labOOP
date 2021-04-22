#include<iostream>
#include<fstream>

using namespace std;

class File
{
protected:
	string path;
	ifstream in;
	ofstream out;
	fstream stream;
public:
	File() { }
	File(string pt)
	{
		this->path = pt;
	}

	string getfilename() 
	{
		return this->path;
	}
	~File() {}

};

//------------------------------------------------------------------------------------------------------//

class Filetxt : public File
{
public:
	Filetxt() : File() { }
	Filetxt(string str) : File(str){}
	
	
	
	void Open_EE_file()
	{
		stream.open(path, ios::app | ios::out | ios::in);
		if (!stream.is_open())
		{
			cout << "ќщибка открытие файла";
			return;
		}
	}

	//void open_out_file()
	//{
	//	stream.open(path, ios::out | ios::app);
	//	if (!stream.is_open())
	//	{
	//		cout << "ќщибка открытие файла";
	//		return;
	//	}
	//}

	void Readtxt(Human& object)
	{
		this->stream >> object;
	}

	void Writetxt(Human& object)
	{
		this->stream << object;
	}

	bool R_endfile()
	{
		return stream.eof();
	}

	void Close_In_file()
	{
		this->stream.close();
	}

	void close_out_file()
	{
		this->stream.close();
	}

};

//----------------------------------------------------------------------------------------------------------------//


class Filebinari : File
{
public:
	Filebinari() :File() { }
	Filebinari(string st) : File(st) {}

	~Filebinari() {}


	void open_out_file()
	{
		out.open(path, ios::out | ios::app | ios::binary);
		if (!out.is_open())
		{
			cout << "ќщибка открытие файла";
			return;
		}
	}

	void open_read_file()
	{
		in.open(path, ios::in | ios::app | ios::binary);
		if (!in.is_open())
		{
			cout << "ќщибка открытие файла";
			return;
		}
	}

	void Readbinari(Human& obj)
	{
		this->in >> obj;
	}

	void Writebinari(Human& obj)
	{
		this->out << obj;
	}

	bool R_endfill()
	{
		return in.eof();
	}

	void Close_In_fill()
	{
		this->in.close();
	}

	void close_out_file()
	{
		this->out.close();
	}
};
/*stream.open(path, ios::app | ios::out|
						  ios :: in| ios:: binary);
		if (!stream.is_open()) {
			cout << " ќщибка открытие файла:";
			return;
		}*/




