// BubbleSort.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
using namespace std;

//���������� ���������
void BubbleSort(int A[], int n)
{
	int count;
	for(int i = 0; i < n; i++)
	{
	
		for(int j = 0; j < n-1; j++)
		{
			count = A[j+1];
			if(A[j]>A[j+1])
			{
				A[j+1]=A[j];
				A[j]=count;				
			}
		}
	}
	cout<<"�������������� ������: "<<endl;
	for(int i=0; i < n; i++)
	{
		cout<<A[i]<<" "<<endl;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL,"Rus");
	int n, A[1000];
	cout<<"������� ������ �������: "; cin>>n;
	for(int i = 0; i < n; i++)
	{
		cout<<i+1<<" >"; cin>>A[i];
	}
	BubbleSort(A,n);
	cout<<endl;
	return 0;
}

