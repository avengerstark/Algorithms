// SieveOfEratosthenes.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
using namespace std;
const int ARRAY_SIZE = 10000;

//–ешето Ёратосфена
void SieveOfEratosthenes(int N)
{
	int A[ARRAY_SIZE] = {};
	int countPrime = 0; 
	for (int i = 2; i < N; i++)
	{
		if (A[i] == 0)
		{
			for (int j = i; j < N; j += i)
			{
				A[j] = 2; // 2 будем обозначать не простые числа
			}

			A[i] = 1; // еденицей будем обозначать простое число
		}
	}

	// ¬ыводим массив простых чисел
	for (int i = 0; i < N; i++)
	{
		if (A[i] == 1)
		{
			cout << setw(3) << i << "  ";
			countPrime++;
			if (countPrime % 5 == 0) cout << endl;
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL,"Rus");
	int n;
	cout<<"–ешето Ёратосфена"<<endl;
	cout << "¬ведите размер массива :"; cin >> n;
	SieveOfEratosthenes(n);
	cout<<endl;
	return 0;
}

