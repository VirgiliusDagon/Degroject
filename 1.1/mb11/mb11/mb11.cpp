// mb11.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class employee {
private:
	int id;
	char fio[40];
	char date[15];
	int stazh;
	double payment;
public:
	employee ();
	employee (int _id, char _fio, char _date, int _stazh, double _payment);
	~employee ();

	void setid (int);
	void setfio (char *);
	void setdata (char *);
	void setstazh (int);
	void setpayment (double);

	int getid ();
	char* getfio ();
	char* getdata ();
	int getstazh ();
	double getpayment ();
}
int _tmain(int argc, _TCHAR* argv[]) {

	setlocale (LC_ALL, "rus");


	system ("pause");
	return 0;
}

