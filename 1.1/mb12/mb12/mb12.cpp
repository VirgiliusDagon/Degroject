// mb12.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>


using namespace std;

class Man{
protected:
	char name[15];
	double age;
	char pol[3];
	double ves;
public:
	Man (char _name[], double _age, char _pol[], double _ves) {
		strcpy (name, _name);
		age = _age;
		strcpy(pol, _pol);
		ves = _ves;
	}
	~Man() {}
	void vyvod () {
		cout << age << endl;
		cout << pol << endl;
		cout << ves << endl;
	}
};

class Student : public Man {
private:
	int god;
public:
	Student (int _god, char _name[], double _age, char _pol[], double _ves) :
	  Man (_name, _age, _pol, _ves) {
		  god = _god;
	  }
	  void vyvod () {
		  cout << name << endl;
		  cout << age << endl;
		  cout << pol << endl;
		  cout << ves << endl;
		  cout << god << endl;
	  }
	  void r () {
		cout << "_____________" << endl;
		cout << "Name "; 
		gets (name);
		cin.sync ();
		cout << "Age ";
		cin >> age; 
		cin.sync ();
		cout << "Pol ";
		gets (pol);
		cin.sync ();
		cout << "Ves ";
		cin >> ves;
		cin.sync ();
		cout << "God ";
		cin >> god;
		cin.sync ();
		cout << "_____________" << endl;
	  }
};

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale (LC_ALL, "rus");

	Student st(1998, "ivanov", 20, "M", 75);

	st.vyvod ();
	st.r ();
	st.vyvod ();

	system ("pause");
	return 0;
}

