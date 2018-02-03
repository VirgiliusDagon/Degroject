#include "stdafx.h"
#include <iostream>

using namespace std;

class Time
{
private:

	int sek;
	int min;
	int chas;

public:

	Time () {};
	~Time () {};

	void message1()
	{
		cout << "\n����\n";
	}

	void message2()
	{
		cout << "\n����\n";
	}

	void message3()
	{
		cout << "\n�����\n";
	}

	void message4() 
	{
		cout << "\n����\n";
	}


	void setDate(int date_sek, int date_min, int date_chas)
	{
		sek = date_sek;
		min = date_min;
		chas = date_chas;
	}

	void fixDate()
	{
		if (sek > 59)
		{
			min++;
			sek-=60;
		}

		if (min > 59)
		{
			chas++;
			min-=60;
		}

		if (chas > 23)
		{
			chas-=24;
		}
	}

	void getDate()
	{
		cout << "�����: " << chas << ":" << min << ":" << sek << endl;
	}

	friend bool operator <(Time objTime, int num);
	friend bool operator >(Time objTime, int num);
	friend int operator +(Time &objTime, int num);
};

bool operator >(Time objTime, int num)
{
	if (objTime.chas > num)
		return true;
	else 
		return false;
}

bool operator <(Time objTime, int num)
{
	if (objTime.chas < num)
		return true;
	else 
		return false;
}

int operator +(Time &objTime, int num)
{
	return objTime.chas += num;
}


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");

	int sek, min, chas, poyas;

	Time objTime;	

	cout << "������� ������� ��� ������ � �������!\n";
	cout << "���: "; cin >> chas;
	cout << "������: "; cin >> min;
	cout << "�������: "; cin >> sek;

	objTime.setDate(sek, min, chas);
	objTime.fixDate ();

	if (objTime < 6)
	{
		objTime.message1();
	}
	if (objTime < 12 && objTime > 5)
	{
		objTime.message4();
	}

	if (objTime < 18 && objTime > 11)
	{
		objTime.message2();
	}

	if (objTime < 24 && objTime > 17)
	{	
		objTime.message3();
	}

	objTime.getDate();

	cout << "������� �������� �� ������ ����� (0 ���� ���) "; cin >> poyas;

	objTime + poyas;
	objTime.fixDate ();

	cout << "����� � ��������� ������� ������" << endl;
	objTime.getDate();

	system("pause");

	return 0;
} 