// BinarySearch.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
using namespace std;

// Двоичный (бинарный) поиск.
int BinarySearch(int *A, int n, int key)
{
	int left = 0, right = n;	
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (key < A[mid]) right = mid - 1;
		else if (key > A[mid]) left = mid + 1;
		else return mid;
	}
	return -1; // элемент не найден.
}


int _tmain(int argc, _TCHAR* argv[])
{

	const int N = 10;
	int *A = new int[N];
	int key;
	setlocale(LC_ALL, "Rus");
	cout << "Исходный массив :" << endl;
	for (int i = 0; i < N; i++)
	{
		A[i] = i * 7; cout << A[i] << " ";
	}

	cout << endl << "Введите значение элемента, чтобы найти его индекс :"; cin >> key;
	if (BinarySearch(A, N, key) == -1) cout << "Элемент не найден."<<endl;
	else cout << "Номер элемента равен: " << BinarySearch(A, N, key) << endl;
	delete[] A;
	return 0;
}

