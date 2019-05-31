#pragma once
#include "string.h"
#include <stdlib.h>

using namespace std;

template<class T>class list
{
	int size = 8;
	T *arr[8];
	list<T> *next;
	int lognumb;
public:
	list()
	{
		for (int i = 0; i < size; i++)
			arr[i] = NULL;
		next = NULL;
	}
	list* add_list()
	{
		if (this == NULL)
		{
			list* new_list=new list;
			return new_list;
		}
		else
		{
			list* new_list = new list;


			new_list->next = this->next;
			this->next = new_list;
			return this;
		}
	}
	list* find_insert_place(T &str)
	{
		list* iterator;
		for (iterator = this; iterator->next != NULL; iterator = iterator->next)
		{
			if (str<*(iterator->next->arr[0]))
			{
				return iterator;
			}
		}
	}
	list* insert(T obj)
	{
		list* insert_list;
		insert_list = this;
		insert_list->find_insert_place(obj);
		for (int i = 0; i < size; i++)
		{
			if (insert_list->arr[i] != NULL)
			{
				if (*(insert_list->arr[i])>obj)
				{
					int j = size - 1;
					for (; insert_list->arr[j] == NULL; j--);
					for (; j >= i; j--)
					{
						insert_list->arr[j + 1] = insert_list->arr[j];
					}
					insert_list->arr[i] = new T;
					*(insert_list->arr[i]) = obj;
					break;
				}
			}
			else
			{
				insert_list->arr[i] = new T;
				*(insert_list->arr[i]) = obj;
				break;
			}
		}
		if (insert_list->arr[size - 1] != NULL)
		{
			insert_list->add_list();
			for (int i = size / 2, j = 0; i < size; i++)
			{
				insert_list->next->arr[j++] = insert_list->arr[i];
				insert_list->arr[i] = NULL;
			}
		}
		insert_list->number();
		return insert_list;
	}
	void show() {
		list* iterator = new list;
		iterator = this;
		if (iterator == NULL) {
			cout << "В списке нет данных" << endl;
			return;
		}
		while (iterator != NULL) 
		{
			cout << iterator->lognumb << endl;
			for (int i = 0; i < size && iterator->arr[i] != NULL; i++)
				cout << *(iterator->arr[i]);
			iterator = iterator->next;
			cout<< endl;
		}


	}
	list* insert_end(T obj)
	{
		list* iterator = this;
		for (;; iterator = iterator->next)
		{
			if (iterator->next == NULL)
			{
				for (int i = 0; i < size; i++)
				{
					if (iterator->arr[i] == NULL)
					{
						iterator->arr[i] = new T;
						*(iterator->arr[i]) = obj;

						break;
					}
				}
				if (iterator->arr[size - 1] != NULL)
				{
					iterator->add_list();
					for (int i = size / 2, j = 0; i < size; i++)
					{
						iterator->next->arr[j++] = iterator->arr[i];
						iterator->arr[i] = NULL;
					}
					this->number();
					iterator->number();
					return iterator;
				}
				this->number();
				iterator->number();
				return iterator;
			}
		}

	}
	friend void bin_read(list* &my_list)
	{
		ifstream fin("file.bin", ios::binary);
		char *str = new char[100];
		while (fin.getline(str, 100))
		{
			T *tmp = new T(str);
			my_list->insert_end(*tmp);
		}
		fin.close();

		return;
	}
	void bin_write()
	{
		list* iterator = this;
		ofstream fout("file.bin");
		if (iterator == NULL)
		{
			fout << "В списке нет данных" << endl;
			return ;
		}
		while (iterator != NULL)
		{
			for (int i = 0; i < size && iterator->arr[i] != NULL; i++)
				fout << *(iterator->arr[i]);
			iterator=iterator->next; 
		}
		return ;
	}
	list* number()
	{
		list* iterator;
		int cmp = 1;
		for (iterator = this; iterator != NULL; iterator = iterator->next, cmp++)
		{
			iterator->lognumb=cmp;
		}
		return iterator;
	}
	list* find(T obj)
	{
		if (this == NULL)
		{
			cout << "В списке нет элементов.";
			return NULL;
		}
		list* find_list = this->find_insert_place(obj);
		for (int position = 0; position < size&& find_list->arr[position] != NULL; position++)
		{
			if (*(find_list->arr[position])==obj)
			{
				cout << "Строка найдена на " << ++position << " позиции "<<find_list->lognumb<<"-го элемента списка." << endl;
				return find_list;
			}
		}
		cout << "Строка не найдена." << endl;
		return NULL;
	}
	list* insert_numb(T obj, int numb)
	{
		list* insert_numb;
		for (insert_numb = this; insert_numb != NULL; insert_numb = insert_numb->next)
		{
			if (insert_numb->lognumb == numb)
			{
				for (int i = 0; i < size; i++)
				{
					if (insert_numb->arr[i] == NULL)
					{
						insert_numb->arr[i] = new T;
						*(insert_numb->arr[i]) = obj;
						break;
					}
				}
				if (insert_numb->arr[size - 1] != NULL)
				{
					insert_numb->add_list();
					for (int i = size / 2, j = 0; i < size; i++)
					{
						insert_numb->next->arr[j++] = insert_numb->arr[i];
						insert_numb->arr[i] = NULL;
					}
					insert_numb->number();
					return insert_numb;
				}
				insert_numb->number();
				return insert_numb;
			}
		}
	}
	list* delete_numb(int numb)
	{
		list* iterator = this;
		if (iterator == NULL)
		{
			cout << "В списке нет элементов.";
			return NULL;
		}
		list* delete_list;
		for (delete_list = this; delete_list != NULL; delete_list = delete_list->next)
		{
			if (delete_list->lognumb == numb)
			{
				for (int i = 0; i < size; i++)
				{
					if (delete_list->arr[i] != NULL)
					{
						cout << i << endl << *(delete_list->arr[i]) << endl;
					}
				}
				cout << "Введите номер удаляемой строки." << endl;
				int j;
				cin >> j;
				delete_list->arr[j] = NULL;
				for (int i = j; i < size - 1; i++)
				{
					if (delete_list->arr[i] == NULL)
					{
						delete_list->arr[i] = delete_list->arr[i + 1];
						delete_list->arr[i + 1] = NULL;
					}
				}
				if (delete_list->arr[0] == NULL && delete_list->next != NULL)
				{

					for (int i = 0; i < size - 1; i++)
						iterator->arr[i] = delete_list->next->arr[i];
					iterator->next = delete_list->next->next;
					delete delete_list->next;
					for (int i = 0; i < size - 1; i++)
						delete_list->arr[i] = iterator->arr[i];
					delete_list->next = iterator->next;
				}

			}
		}
		for (delete_list = this; delete_list != NULL; delete_list = delete_list->next)
		{
			if (delete_list->next == NULL)
				delete delete_list->next;
			delete_list->number();
			return delete_list;
		}

		cout << "Элемент не найден." << endl;
		return NULL;
	}
	list* sort()
	{
		list* iterator;
		list* new_list=new list;

		for (iterator = this; iterator != NULL; iterator = iterator->next)
		{
			for (int i = 0; i < size-1; i++)
			{
				if(iterator->arr[i]!=NULL)
					new_list->insert(*(iterator->arr[i]));
			}
		}
		new_list->number();
		return new_list;
	}
	list* balance()
	{
		list* iterator = (list*)calloc(1, sizeof(list));
		if (this == NULL)
		{
			cout << "В списке нет элементов.";
			return NULL;
		}
		list* balance_list;
		for (balance_list = this; balance_list != NULL; balance_list = balance_list->next)
		{
			int j = 0;
			while(balance_list->arr[size - 2] == NULL)
			{
				for (int i = 0; i < size -1; i++)
				{
					if (balance_list->arr[i] == NULL)
					{
						++j;
					}
				}
				if (balance_list->next != NULL)
				{
					for (j = size-1 - j; j < size - 1; )
					{
						balance_list->arr[j] = balance_list->next->arr[0];
						j++;
						balance_list->next->arr[0] = NULL;
						for (int i = 0; i < size - 1; i++)
						{
							if (balance_list->next->arr[i] == NULL)
							{
								balance_list->next->arr[i] = balance_list->next->arr[i + 1];
								balance_list->next->arr[i + 1] = NULL;
							}
						}
					}
					if (balance_list->next->next != NULL&& balance_list->next->arr[0] == NULL)
					{
						balance_list->next = balance_list->next->next;

					}
					if (balance_list->next!=NULL && balance_list->next->arr[0]== NULL)
					{
						delete balance_list->next;
						balance_list->next = NULL;
						return balance_list;
					}
				}
			}
		}
		return balance_list;
	}

};