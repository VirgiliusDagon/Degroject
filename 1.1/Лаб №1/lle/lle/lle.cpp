#include <iostream>
#include "math.h"
using namespace std;
 
 int main() {
     
	setlocale(LC_ALL, "rus");

	double G, g, M, R, h;

	G=6.672*(pow(10.0,-11.0));
	M=5.96*(pow(10.0,24.0));
	R=6.37*(pow(10.0,6.0));

	cout<< "������� �������� ������ � (�) h = ";
	cin>> h;

	g=(G*M)/(pow(R+h,2));

	cout<< "�� ������ " << h << "(�)" <<endl;
	cout<< "��������� ���������� ������� g = " << g << "(�/�^2)" <<endl;

	system("pause");

    return 0;
}