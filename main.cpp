#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<fstream>
#include <time.h>
#include<ctime>
#include <Windows.h>
#include "list.h"

using namespace std; 

int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	int choose;
	int k;
	list<MyString>* my_list=new list<MyString>;
	MyString *myStr=new MyString;
	do
	{
		system("cls");
		cout << "Выберите действие:" << endl <<
			"1 - Добавление строки (c сохранением упорядоченности)." << endl <<
			"2 - Добавление строки в конец." << endl <<
			"3 - Добавление N случайных строк(с сохранением упорядоченности)." << endl <<
			"4 - Добавление N случайных строк в конец." << endl <<
			"5 - Загрузка из файла." << endl <<
			"6 - Вставка по логическому номеру." << endl <<
			"7 - Удаление по логическому номеру." << endl <<
			"8 - Поиск строки." << endl <<
			"9 - Сохранение в файл." << endl <<
			"10 - Сортировка." << endl <<
			"11 - Балансировка." << endl <<
			"12 - Вывод списка." << endl;

		cin >> choose;
		if (choose == 1)
		{
			if (my_list == NULL)
				my_list->add_list();
			system("cls");
			myStr->get_string();
			my_list->insert(*myStr);
			system("pause");

		}
		if (choose == 2)
		{
			if (my_list == NULL)
			{
				my_list->add_list();
			}
			system("cls");
			myStr->get_string();
			my_list->insert_end(*myStr);
			my_list->number();
		}
		if (choose == 3)
		{
			system("cls");
			if (my_list == NULL)
			{
				my_list->add_list();
			}
			int N;
			cout << "Введите количество добавляемых строк:" << endl;
			cin >> N;

			char* ar = (char*)calloc(27, sizeof(char*));
			for (int i = 0; i < 26; i++)
				ar[i] = 'a' + i;


			for (int i = 0; i < N; i++)
			{
				myStr->create_string(ar);
				my_list->insert(*myStr);
			}
			system("pause");
	
		}
		if (choose == 4)
		{
			system("cls");
			if (my_list == NULL)
			{
				my_list->add_list();
			}
			int N;
			cout << "Введите количество добавляемых строк:" << endl;
			cin >> N;

			char* ar = (char*)calloc(27, sizeof(char*));
			for (int i = 0; i < 26; i++)
				ar[i] = 'a' + i;

			for (int i = 0; i < N; i++)
			{
				myStr->create_string(ar);
				my_list->insert_end(*myStr);
			}
			my_list->number();
			system("pause");
		}
		if (choose == 5) 
		{
			bin_read(my_list);
			system("cls");
			cout << "Данные успешно загружены из текстового файла." << endl;
			system("pause");
		}
		if (choose == 6)
		{
			system("cls");
			my_list->show();
			cout << "Введите номер элемента." << endl;
			cin >> k;
			system("cls");
			myStr->get_string();
			my_list->insert_numb(*myStr, k);
			system("cls");
			cout << "Строка добавлена." << endl;
			system("pause");
		}
		if (choose == 7) {
			system("cls");
			my_list->show();
			cout << "Введите номер элемента." << endl;
			cin >> k;
			system("cls");
			my_list->delete_numb(k);
			system("cls");
			cout << "Строка удалена." << endl;
			system("pause");

		}
		if (choose == 8) {
			system("cls");
			myStr->get_string();
			my_list->find(*myStr);
			system("pause");

		}
		if (choose == 9)
		{
			system("cls");
			my_list->bin_write();
			cout << "Данные успешно записаны в текстовый файл." << endl;
			system("pause");
		}
		if (choose == 10)
		{
			system("cls");
			my_list->sort();
			cout << "Список успешно отсортирован:" << endl;
			my_list->show();
			system("pause");
		}
		if (choose == 11)
		{
			system("cls");
			my_list->balance();
			my_list->number();
			cout << "Список успешно сбалансирован:" << endl;
			my_list->show();
			system("pause");
		}
		if (choose == 12)
		{
			system("cls");
			my_list->show();
			system("pause");
		}
	} while (choose != 0);


	system("pause");
	return 0;

}