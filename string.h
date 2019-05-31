#pragma once
#include <stdlib.h>
#include <cstring>
#include <iostream>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

//Делаем свою строчку,дабы перегрузить операторы сравнения ( хз зачем, в условии написали, а где пользоваться непонятно)

class MyString
{
private:
	char *str;
public:

	MyString();
	MyString(char *arg);
	~MyString();
	bool operator>(const MyString &b);// Те самые операторы
	bool operator<(const MyString &b);
	bool operator==(const MyString &b);
	friend ostream& operator<<(ostream &os, MyString &s);
	friend ofstream& operator<<(ofstream &os, MyString &s);
	MyString operator=(MyString &b);
	int Length();//Длина строчки
	void ChangeString(char *newStr);//функция замены строчки 
	void Print(ostream &os);//Ну тут по названию
	void Print(ofstream &os);//Ну тут по названию
	char* GetStr()
	{
		return str;
	}
	char* create_string(char* ar);
	char* get_string();
};
