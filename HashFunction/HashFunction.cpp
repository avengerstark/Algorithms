// HashFunction.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
using namespace std;
// Метод умножения 

int HashMultiplication(int k)
{
	int N = 13; // константа
	double A = 0.618033; // число основано на свойствах золотого сечения
	return N * fmod(A*k,1);  
}


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Rus");
	char str[1000];
	cout << "Введите строку, затем нажмите Enter : \n";
	gets(str);

	// Вывод хеш кодов
	for (int i = 0;; i++)
	{
		if ((int)str[i] == '\0')
			break;
		cout <<HashMultiplication (str[i])<<" ";
	}
	cout << endl;
	return 0;
}

