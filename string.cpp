#define _CRT_SECURE_NO_WARNINGS
#include "String.h"
#include <iostream>
#include <fstream>

using namespace std;

MyString::MyString(char *arg)
{
	int length = strlen(arg);
	str = new char[length + 1];
	strcpy(str, arg);
	str[strlen(str)] = 0;

}

MyString::~MyString()
{
	if (str != NULL)
		delete[] str;
}


bool MyString::operator>(const MyString &b)
{
	if (strcmp(str, b.str) > 0)
		return 1;
	else
		return 0;
}

bool MyString::operator<(const MyString &b)
{
	if (strcmp(str, b.str) < 0)
		return 1;
	else
		return 0;
}

bool MyString::operator==(const MyString & b)
{
	if (strcmp(str, b.str) == 0)
		return true;
	else
		return false;
}

ostream & operator<<(ostream &os, MyString &s)
{
	s.Print(os);
	return os;
}

ofstream & operator<<(ofstream & os, MyString & s)
{
	s.Print(os);
	return os;
}


MyString MyString::operator=(MyString &b)
{
	int length = b.Length() + 1;
	if (str != NULL)
		delete[] str;
	str = new char[length + 1];
	strcpy(str, b.str);
	return MyString(str);

}

int MyString::Length()
{
	return strlen(str);
}

void MyString::ChangeString(char * newStr)
{
	if (str != NULL)
		delete[] str;
	str = new char[strlen(newStr) + 1];
	strcpy(str, newStr);
	str[strlen(str)] = 0;
}

MyString::MyString()
{
	str = NULL;
}

void MyString::Print(ostream &os)
{
	if (str != NULL)
		os << str << endl;
}

void MyString::Print(ofstream &ofs)
{
	if (str != NULL)
		ofs << str << endl;

}

char* MyString::create_string(char* ar)
{
	int i;
	int lenth = rand() % 13 + 2;
	char* str = (char*)calloc(lenth, sizeof(char));

	for (i = 0; i < lenth - 1; i++)
		str[i] = ar[rand() % 26];

	str[i] = '\0';
	this->str = str;
	return str;
}

char* MyString::get_string()
{
	int size = 4;
	char ch;
	char* str = (char*)calloc(size + 1, sizeof(char));
	int index = 0;

	getchar();
	cout << "Введите строку:" << endl;
	while (ch = getchar())
	{
		if (ch == '\n')
			break;

		str[index] = ch;
		index++;

		if (index > size)
		{
			char* ptr;
			if ((ptr = (char*)realloc(str, (size * 2) + 1)) != NULL)
			{

				size *= 2;
				str = ptr;
			}
			else
			{
				cout << "Невозможно выделить память. Завершение работы программы.";
				system("pause");
				return NULL;
			}
		}
	}
	str[index] = '\0';
	this->str = str;
	return str;
}
