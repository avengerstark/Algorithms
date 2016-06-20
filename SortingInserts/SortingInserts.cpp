// SortingInserts.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
using namespace std;

// Сортировка вставками
void SortingInsert(int *A, int n)
{
	int temp, j;
	for(int i = 1; i<n; i++)
	{
		temp = A[i]; 
		for(j = i-1; j>=0 && A[j] > temp; j--) A[j+1]=A[j]; // если слева стоящие элементы больше temp, то меняем их местами
		A[j+1] = temp; // добовляем temp в массив,
		//так как его перезаписали в цикле(в цикле при продвижении эелемнта, элемент дублируется)
	}
	cout<<"Результирующий массив: ";
	for(int i=0;i<n; i++)
	{
		cout<<A[i]<<" ";
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL,"Rus");
	int n;
	cout<<"Введите размер массива > "; cin>>n;
	int *mass = new int [n];
	for(int i = 0; i<n; i++)
	{
		cout<<"["<<i+1<<"]"<<" = "; cin>>mass[i];
	}

	SortingInsert(mass,n);
	delete[] mass;
	return 0;
}

