// InterpolationSearch.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
using namespace std;
// »нтерпол€ционный поиск

int InterpolationSearch(int A[], int N, int key)
{
	int left = 0, right = N - 1, mid;

	while (A[left] <= key && A[right] >= key)
	{
		mid = left + ((key - A[left]) * (right - left)) / (A[right] - A[left]); // индекс элемента, с которым будем проводить сравнение 
		if (key > A[mid]) left = mid + 1;
		else if (key < A[mid]) right = mid - 1;
		else return mid;
	}
	/*if (A[left] == key) return left;*/
	 return -1; // ≈сли элемент не найден
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL,"Rus");
	const int N = 17;
	int key;
	int A[N] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59 };
	cout << "»сходный массив: "<<endl;
	for (int i = 0; i < N; i++)
	{
		cout <<"["<<i<<"] = "<< A[i] <<endl;
	}
	cout <<endl<< "¬ведите значение: "; cin >> key;
	if (InterpolationSearch(A, N, key) == -1) cout << endl << "Ёлемент не найден=(("<<endl;
	else cout << "»ндекс элемента: " << (InterpolationSearch(A, N, key))<<endl;
	return 0;
}

