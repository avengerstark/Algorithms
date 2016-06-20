// GnomeSort.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
using namespace std;

// Гномья сортировка
void GnomeSort(int *A, int n)
{
	int i = 0;

	while(i<n)
	{
		if(i==0 || A[i-1]<=A[i]) i++;
		else
		{
			int count = A[i];
			A[i] = A[i-1];
			A[i-1] = count;
			i--;
		}
	}

	cout<<"Результирующий массив: ";
	for(int i = 0; i<n; i++)
	{
		cout<<A[i]<<" ";
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Rus");
	int n;
	int *A = new int [1000];
	cout<<"Введите размер массива: "; cin>>n;
	for(int i = 0; i<n; i++)
	{
		cout<<"["<<i<<"] = "; cin>>A[i];
	}
	cout<<endl<<"Исходный массив: ";

	for(int i = 0; i<n; i++)
		cout<<A[i]<<" ";

	GnomeSort(A,n);
	cout<<endl;
	return 0;
}

