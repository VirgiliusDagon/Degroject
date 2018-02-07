#include "stdafx.h"
#include <iostream>

using namespace std;

class Virt {
public:
	void static write() {
		write_message();
	}
protected: //„тобы получить доступ из класс наследника Virt::write_message(); нужен protected:
	void static write_message() {
		cout << "lol" << endl;
	}
};

class Rewrite : public Virt { //public < protected < private
public:
	void static write() {
		Virt::write_message();
	}
private:
	void static write_message() {
		cout << "kek" << endl;
	}
};

class Lone {
public:
	void write() {
		write_message();
	}
private:
	void write_message() {
		cout << "cheburek" << endl;
	}
};

int main()
{
	Rewrite::write();

	Lone obj;
	obj.write();

	system("pause");
    return 0;
}

