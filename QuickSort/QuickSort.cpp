// QuickSort.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
using namespace std;

// Быстрая сортировка
void QuickSort(int *A, int first, int last)
{
	int count;
	int begin = first;
	int end = last;
	int mid = A[(begin+end)/2]; // Находим опорный элемент
	// слева ставим элементы кооторые меньше 
	// опорного, а справа которые больше. 
	do
	{
		while (A[begin]<mid) begin++; 
		while (A[end]>mid) end--;
		if(begin<=end)
		{
			count = A[begin];
			A[begin] = A[end];
			A[end] = count;
			begin++;
			end--;
		}
	}while(begin<end);
	// рекурсивно сортируем подмассивы 
	if(first<end) QuickSort(A, first, end);
	if(last>begin) QuickSort(A, begin, last);

}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL,"Rus");
	int *A = new int[1000];
	int n;
	cout<<"Введите размер массива: "; cin>>n;
	for(int i = 0; i < n; i++)
	{
		cout<<"["<<i<<"]"<<" = "; cin>>A[i];
	}
	cout<<endl<<"Введнный вами массив: ";
	
	for(int i = 0; i < n; i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
	QuickSort(A, 0, n-1);
	cout<<"Результирующий массив: ";
	for(int i = 0; i<n; i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
	delete[] A;
	return 0;
}

