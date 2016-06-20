// SieveOfSundaram.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
using namespace std;
//–ешето —ундарама
int const ARRAY_SIZE = 10000;
void SieveOfSundaram(int N)
{
	int A[ARRAY_SIZE] = {}; // инициализируем массивы нул€ми
	int k=0, q=0;
	for (int i = 1; 3 * i + 1 < N; i++)
	{
		for (int j = 1; (k = i + k + 2 * i * j) < N && i <= j; j++)
		{
			A[k] = 1; // вычеркиваем все составные числа
		}
	}

	// вывод простых чисел
	for (int i = 1; (i*2+1) < N; i++)
	{
		if (A[i] == 0)
		{
			cout << setw(5) << i * 2 + 1 << " "; // оставшиес€ числа умножаем на 2 и прибовд€ем 1
			q++;
			if (q % 5 == 0) cout << endl;
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	setlocale(LC_ALL,"Rus");
	cout << "************–ешето —ундарама*********************"<<endl;
	cout << "N = "; cin >> n;
	cout << "¬ывод всех простых чисел"<<endl;
	SieveOfSundaram(n);
	cout << endl;
	return 0;
}

