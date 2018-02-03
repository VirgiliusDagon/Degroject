// Lab11.cpp: ���������� ����� ����� ��� ����������� ����������.
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


	HomeLibrary *mas = new HomeLibrary[10]; //  ������
	HomeLibrary buf;

	do 
	{
		cout << "�������� ����� - 1\n������� ����� - 2\n����� ����� - 3\n���������� - 4\n����� ���� ���� - 5\n����� - 6" << endl;
		cout << "�������� �������: ";
		cin >> ask;
		cout << endl;

		switch(ask) 
		{
		case 1 : //���� ����
			cout << "������� ����� ";
			cin >> num;
			cout << "��� ";
			cin >> name;
			cout << "���� ";
			cin >> date;
			cout << "���� ";
			cin >> price;
			cout << endl;
			mas[n] = HomeLibrary (num, name, date, price);
			n++;
			break;

		case 2: //�������� ����
			cout << "������� ����� ����� ������� ������ ������� ";
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

		case 3:        //����� ����
			cout << "������� ����� ����� ������� ������ ����� ";
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

		case 4:      //���������� ����
			cout << "��������������" << endl << endl;
			for (int i = 0; i < n - 1; i++)
				for (int j = 0; j < n - 1; j++)
					if (mas[i].getNum()>mas[i + 1].getNum()) 
						{
							buf = mas[i];
							mas[i] = mas[i + 1];
							mas[i + 1] = buf;
						}
			break;

		case 5:      //����� ���� ����
			for (int i = 0; i < n; i++)
				mas[i].getBook();
			cout << endl;
			break;
		default:
			cout << "������ �������� �������" << endl << endl;
			
		}
	} while (ask != 6);

	delete [] mas;
	return 0;
}

