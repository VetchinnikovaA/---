#pragma once
#include <stdlib.h>
#include <cstring>
#include <iostream>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

//������ ���� �������,���� ����������� ��������� ��������� ( �� �����, � ������� ��������, � ��� ������������ ���������)

class MyString
{
private:
	char *str;
public:

	MyString();
	MyString(char *arg);
	~MyString();
	bool operator>(const MyString &b);// �� ����� ���������
	bool operator<(const MyString &b);
	bool operator==(const MyString &b);
	friend ostream& operator<<(ostream &os, MyString &s);
	friend ofstream& operator<<(ofstream &os, MyString &s);
	MyString operator=(MyString &b);
	int Length();//����� �������
	void ChangeString(char *newStr);//������� ������ ������� 
	void Print(ostream &os);//�� ��� �� ��������
	void Print(ofstream &os);//�� ��� �� ��������
	char* GetStr()
	{
		return str;
	}
	char* create_string(char* ar);
	char* get_string();
};
