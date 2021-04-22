#pragma once
#include <iostream>
#include <iomanip>

using namespace std;
template<typename T>
struct Node {
	T data;
	Node<T>* next = NULL;
};

template<typename T>
class Queue {
private:
	int Size;
	Node<T>* head;
	Node<T>* last;
public:
	Queue() : head(NULL), Size(0) {}
	~Queue();
	void Delete(int index);
	void show();
	T& operator[](int index);
	void enqueue(T data);
	T dequeue();
	bool is_Empty();
	int getSize();
	void Clear();
	T& Peek();

	void Search();

	void show(int index);

};

template<typename T>
inline Queue<T>::~Queue()
{
	Clear();
}


template<typename T>
inline void Queue<T>::show()
{
	Node<T>* temp = head;
	for (int i = 0; i < Size; i++) {
		cout << "|" << setw(3) << i + 1 << "|" << temp->data << endl;
		temp = temp->next;
	}
}

template<typename T>
inline T& Queue<T>::operator[](int index)
{
	Node<T>* curr = head;
	if (index >= Size || index < 0)
		return curr->data;

	for (int i = 0; i < index; i++) {
		curr = curr->next;
	}
	return curr->data;
}

template<typename T>
inline void Queue<T>::enqueue(T data)
{
	if (Size == 0) {
		head = new Node<T>;
		head->data = data;
		Size++;
		last = head;
		return;
	}
	else {
		Node<T>* p = new Node<T>;
		p->data = data;
		last->next = p;
		last = last->next;
		Size++;
	}
}

template<typename T>
inline T Queue<T>::dequeue()
{
	Node<T>* p;
	T data;
	if (Size != 0)
	{
		data = head->data;
		p = head;
		head = head->next;
		delete p;
		Size--;
		return data;
	}
	else return T();
}

template<typename T>
inline bool Queue<T>::is_Empty()
{
	return Size == 0;
}

template<typename T>
inline int Queue<T>::getSize()
{
	return Size;
}

template<typename T>
inline void Queue<T>::Clear()
{
	while (head) {
		if (!(head)) return;
		Node<T>* temp = head;
		head = head->next;
		delete temp;
		Size--;
	}
}

template<typename T>
T& Queue<T>::Peek() {
	if (head != NULL)
		return head->data;
	else {
		T* temp = nullptr;
		return *temp;

	}
}

template<typename T>
void Queue<T>::Search()
{
	if (!this->is_Empty()) {
		Node<T>* temp = head;
		Queue<T> result;
		T elem;
		cout << " поиск по  ";  elem.InputScan();
		for (int i = 0; i < getSize(); i++)
		{
			if (temp->data == elem) {
				result.enqueue(temp->data);
			}
			temp->next;
		}

		if (!result.is_Empty()) {
			elem.Title();
			result.show();
		}
		else {
			cout << " нету такого элемента " << endl;
		}
	}
	else {
		cout << " Пуст " << endl;
	}
}

template<typename T>
inline void Queue<T>::show(int index)
{
	Node<T>* temp = head;
	int i = 0;
	for (i = 0; i < index; i++) {
		temp = temp->next;
	}
	cout << "|" << setw(3) << i + 1 << "|" << temp->data << endl;
}

template<typename T>
inline void Queue<T>::Delete(int index)
{
	Node<T>* temp = head, * help = head;
	for (int i = 0; i < index; i++) {
		help = temp;
		temp = temp->next;
	}
	if (temp == head)
	{
		head = temp->next;
	}
	else
	{
		help->next = temp->next;
	}
	delete temp;
	Size--;
}



