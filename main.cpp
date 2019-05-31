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
		cout << "�������� ��������:" << endl <<
			"1 - ���������� ������ (c ����������� ���������������)." << endl <<
			"2 - ���������� ������ � �����." << endl <<
			"3 - ���������� N ��������� �����(� ����������� ���������������)." << endl <<
			"4 - ���������� N ��������� ����� � �����." << endl <<
			"5 - �������� �� �����." << endl <<
			"6 - ������� �� ����������� ������." << endl <<
			"7 - �������� �� ����������� ������." << endl <<
			"8 - ����� ������." << endl <<
			"9 - ���������� � ����." << endl <<
			"10 - ����������." << endl <<
			"11 - ������������." << endl <<
			"12 - ����� ������." << endl;

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
			cout << "������� ���������� ����������� �����:" << endl;
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
			cout << "������� ���������� ����������� �����:" << endl;
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
			cout << "������ ������� ��������� �� ���������� �����." << endl;
			system("pause");
		}
		if (choose == 6)
		{
			system("cls");
			my_list->show();
			cout << "������� ����� ��������." << endl;
			cin >> k;
			system("cls");
			myStr->get_string();
			my_list->insert_numb(*myStr, k);
			system("cls");
			cout << "������ ���������." << endl;
			system("pause");
		}
		if (choose == 7) {
			system("cls");
			my_list->show();
			cout << "������� ����� ��������." << endl;
			cin >> k;
			system("cls");
			my_list->delete_numb(k);
			system("cls");
			cout << "������ �������." << endl;
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
			cout << "������ ������� �������� � ��������� ����." << endl;
			system("pause");
		}
		if (choose == 10)
		{
			system("cls");
			my_list->sort();
			cout << "������ ������� ������������:" << endl;
			my_list->show();
			system("pause");
		}
		if (choose == 11)
		{
			system("cls");
			my_list->balance();
			my_list->number();
			cout << "������ ������� �������������:" << endl;
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