// SortingAlgorithms.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
using namespace std;

void SelectionSort(int A[], int n)
{
	int value, minValueIndex;
	for(int i=0; i < n-1; i++)
	{
		value = A[i]; minValueIndex = i;
		for(int j=i+1;j < n; j++)
		{
			if(A[j]<A[minValueIndex]) minValueIndex = j;
		}
		if(minValueIndex!=i)
		{
			A[i] = A[minValueIndex];
			A[minValueIndex] = value;
		}
	}
	cout<<"�������������� ������: "<<endl;
	for(int i = 0; i < n; i++)
	{
		cout<<A[i]<<" ";
	}
}



int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL,"Rus");
	int n, A[1000];
	cout<<"������� ������ ������ > "; cin>>n;
	for(int i=0; i<n; i++)
	{
		cout<<"������� "<<i<< " >"; cin>>A[i]; 
	}
	SelectionSort(A,n);
	cout<<endl;
	return 0;
}


