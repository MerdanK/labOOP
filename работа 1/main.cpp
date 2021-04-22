#pragma once
#include"func.h"
#include"Human.h"
#include"Queue.h"
#include"File.h"
#include <iostream>


void MenuWork()
{
	int perem;
	setlocale(LC_ALL, "rus");
	Queue<Human>* human = new Queue<Human>;
	do
	{
		system("cls");
		cout << "1.Меню" << endl;
		cout << "0.Выход из системы" << endl;

		cin >> perem;

		switch (perem)
		{
		case 1:
		{
			int sum;
			do
			{
				system("cls");
				cout << " 1.Добавить Персональ" << endl;
				cout << " 2.Просмотр Персонал" << endl;
				cout << " 3.Удалить Персонал" << endl;
				cout << " 4.Запись в файл txt" << endl;
				cout << " 5. читать с файла txt" << endl;
				cout << " 6. Запись в файл бинарном виде" << endl;
				cout << " 7. Читать с файла в бинарном виде" << endl;
				cout << " 0.Выход\n" << endl;

				cin >> sum;

				cout << "\n\n";
				switch (sum)
				{
				case 1:
				{
					Human ab;
					cin >> ab;
					human->enqueue(ab);
					break;


				}
				
				case 2:
				{
					if (human->getSize() != 0)
					{
						showhuman();
						human->show();
					}
					else
						cout << "Очередь пусть!!!" << endl;
					break;
					
				}
				
				case 3:
				{
					if (human->getSize() != 0)
					{
						showhuman();
						human->show();
						cout << " - Выберите Персонала: ";
						int a;

						cin >> a;
						a--;
						human->Delete(a);
						cout << "Персональ удалень!!!" << endl;
					}
					break;
				}

				
				case 4:
				{
					Human temp;
					Filetxt path("Human.txt");
					path.Open_EE_file();
					while (!human->is_Empty())
					{
						temp = human->dequeue();
						path.Writetxt(temp);
					}
					cout << "Успешно записан в файль" << endl;
					break;
				}
				case 5: 
				{
					Human temp;
					Filetxt path("Human.txt");
					path.Open_EE_file();
					while (1) 
					{
						path.Readtxt(temp);
						if (path.R_endfile()) 
							break;
						human->enqueue(temp);
					}
					break;
				}

				case 6:
				{
					Human ptr;
					Filebinari pat("HumanBB.txt ");
					pat.open_out_file();
					while (!human->is_Empty())
					{
						ptr = human->dequeue();
						pat.Writebinari(ptr);

					}
					break;
				}

				
				case 7:
				{
					Human temp;
					Filebinari pat  ("HumanBB.txt");
					pat.open_read_file();
					while (1)
					{
						pat.Readbinari(temp);
						if (pat.R_endfill())
							break;
						human->enqueue(temp);
					}
					break;

				}
				
				default:
					break;
				}

				cout << endl;
				system("pause");

			} while (sum != 0);

			break;
		}
		default:
			break;

		}

	} while (perem != 0);
	delete human;
}

int main()
{
	MenuWork();
	return 0;
}