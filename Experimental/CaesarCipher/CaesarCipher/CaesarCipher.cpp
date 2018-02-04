// CaesarCipher.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void crypter(char *str) { //Шифратор
	
	for (int j = 0; j < 2; j++) {                  
		str[0] += (str[1] + str[strlen(str) - 1]); 
		/*Цикл для повторной шифровки и изменения хэша при изменении хотя бы 1 символа
		  Принцип шифровки в прибавлении значений символа слева и справа
		  Да вот только слева от крайне левого символа находится какая-то ерунда,	
		  а не часть сообщения, смекаешь?*/                			  
		for (int i = 1; str[i]; i++) {
			if (!str[i + 1]) {
				str[i] += (str[0] + str[i - 1]);
			}
			/*То же самое но для последнего символа,
			  а (!str[i+1]) патамушта ласт символ строки всегда '\0',
			  то есть 0, то есть false, a ! инвертирует. Got it?*/    
			else
				str[i] += (str[i + 1] + str[i - 1]); //А тут все по христиански складывается
		}
	}
}

void decrypter(char* str) {
	
	int str_l = strlen(str);//Тупо +эффективность
	for (int j = 0; j < 2; j++) {
		str[str_l - 1] -= (str[0] + str[str_l - 2]);//То же что и при шифровки только в обратную сторону и с вычитанием
		for (int i = str_l - 2; i >= 0; i--) {
			if (i == 0)
				str[i] -= (str[i + 1] + str[str_l - 1]);
			else
				str[i] -= (str[i + 1] + str[i - 1]);
		}
	}
}

int main()
{
	char str[] = "Random message";
	
	cout << str << endl;
	crypter(str);
	cout << str << endl;
	decrypter(str);
	cout << str << endl;

	system("pause");
    return 0;
}