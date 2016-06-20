// QuickSort.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
using namespace std;

// ������� ����������
void QuickSort(int *A, int first, int last)
{
	int count;
	int begin = first;
	int end = last;
	int mid = A[(begin+end)/2]; // ������� ������� �������
	// ����� ������ �������� �������� ������ 
	// ��������, � ������ ������� ������. 
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
	// ���������� ��������� ���������� 
	if(first<end) QuickSort(A, first, end);
	if(last>begin) QuickSort(A, begin, last);

}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL,"Rus");
	int *A = new int[1000];
	int n;
	cout<<"������� ������ �������: "; cin>>n;
	for(int i = 0; i < n; i++)
	{
		cout<<"["<<i<<"]"<<" = "; cin>>A[i];
	}
	cout<<endl<<"�������� ���� ������: ";
	
	for(int i = 0; i < n; i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
	QuickSort(A, 0, n-1);
	cout<<"�������������� ������: ";
	for(int i = 0; i<n; i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
	delete[] A;
	return 0;
}

