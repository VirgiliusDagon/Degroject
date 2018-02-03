// Lab11.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class HomeLibrary 
{
private:
	int num;
	char name[20];
	char date[10];
	double price;
public:
	HomeLibrary () {};
	HomeLibrary (int _num, char _name[], char _date[], double _price) 
	{
		num = _num;
		strcpy(name, _name);
		strcpy(date, _date);
		price = _price;
	}
	~HomeLibrary () {};
	void getBook() 
	{
		cout << num << "/" << name << "/" << date << "/" << price << endl;
		return;
	}

	int getNum() 
	{
		return num;
	}

	void delBook(HomeLibrary *mas, int i, int &n)
	{
		for (int j = i; j < n - 1; j++)
			mas[j] = mas[j + 1];
		n--;
		return;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");

	int ask, num, n = 0;
	double price;
	char name[20], date[10];


	HomeLibrary *mas = new HomeLibrary[10]; //  Массив
	HomeLibrary buf;

	do 
	{
		cout << "Добавить книгу - 1\nУдалить книгу - 2\nПоиск книги - 3\nСортировка - 4\nВывод всех книг - 5\nВыход - 6" << endl;
		cout << "Выберите вариант: ";
		cin >> ask;
		cout << endl;

		switch(ask) 
		{
		case 1 : //Ввод книг
			cout << "Введите номер ";
			cin >> num;
			cout << "Имя ";
			cin >> name;
			cout << "Дату ";
			cin >> date;
			cout << "Цену ";
			cin >> price;
			cout << endl;
			mas[n] = HomeLibrary (num, name, date, price);
			n++;
			break;

		case 2: //Удаление книг
			cout << "Введите номер книги которую хотите удалить ";
			cin >> num;
			cout << endl;
			for (int i = 0; i < n; i++)
			{
				if(mas[i].getNum() == num)
				{
					mas[i].delBook (mas, i, n);
					break;
				}
			}
			break;

		case 3:        //Поиск книг
			cout << "Введите номер книги которую хотите найти ";
			cin >> num;
			cout << endl;
			for (int i = 0; i < n; i++)
				if (mas[i].getNum() == num)
				{
					mas[i].getBook();
					break;
				}
				cout << endl;
			break;

		case 4:      //Сортировка книг
			cout << "Отсортированно" << endl << endl;
			for (int i = 0; i < n - 1; i++)
				for (int j = 0; j < n - 1; j++)
					if (mas[i].getNum()>mas[i + 1].getNum()) 
						{
							buf = mas[i];
							mas[i] = mas[i + 1];
							mas[i + 1] = buf;
						}
			break;

		case 5:      //Вывод всех книг
			for (int i = 0; i < n; i++)
				mas[i].getBook();
			cout << endl;
			break;
		default:
			cout << "Выбран неверный вариант" << endl << endl;
			
		}
	} while (ask != 6);

	delete [] mas;
	return 0;
}

