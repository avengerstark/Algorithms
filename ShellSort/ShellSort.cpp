// ShellSort.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
using namespace std;

//Сортировка Шелла
void ShellSort(int *A, int size)
{
	int temp;
	int step = size/2; // задаем шаг
	while (step>0)
	{
		for(int i = 0; i < (size - step); i++)
		{
			for(int j = i; j >= 0 && A[j+step] < A[j]; j--)
			{
				temp = A[j+step];
				A[j+step] = A[j];
				A[j] = temp;
			}
			
		}
		step = step/2; // уменьшаем шаг
	}

	cout<<"Результирующий массив :"<<endl;
	for(int i = 0; i<size; i++)
	{
		cout<<A[i]<<" ";
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL,"Rus");
	clock_t t;
	int size;
	cout<<"Введите размер массива : "; cin>>size;
	int *A = new int[size];
	for(int i = 0; i < size; i++)
	{
		cout<<"["<<i+1<<"] = "; cin>>A[i];
	}
	t = clock();
	ShellSort(A, size);
	t = clock() - t;
	cout<<endl<<"**************"<<endl;
	printf("time -> %f", (float)t/CLOCKS_PER_SEC);
	cout<<endl;
	return 0;
}

