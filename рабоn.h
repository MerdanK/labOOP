#pragma once
#include<iostream>
#include<fstream>
#include"Queue.h"
using namespace std;

void showfilm();

void showhuman();

//template<class T>
//inline void writeToFile(Queue<T>*& queue, const char* filename);
//template<class T>
//inline void readFromFile(Queue<T>*& queue, const char* filename);

template<class T>
inline void writeToFile(Queue<T>*& queue, const char* filename)
{
	fstream file;
	file.open(filename, ios::out);
	if (!file.is_open()) {
		cout << "Ошибка открытие файла - " << filename << endl;
		return;
	}
	while (!queue->is_Empty())
	{
		T obj = queue->dequeue();
		file << obj << endl;
	}
	file.close();
}

template<class T>
inline void readFromFile(Queue<T>*& queue, const char* filename)
{
	fstream file;
	file.open(filename, ios::in);

	if (!file.is_open())
	{
		cout << "Ошибка открытие файла - " << filename << endl;
		return;
	}
	while (true) {
		T obj;
		file >> obj;
		if (file.eof())
			break;
		queue->enqueue(obj);
	}
	file.close();
}
