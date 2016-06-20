// ShellSort.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
using namespace std;

//���������� �����
void ShellSort(int *A, int size)
{
	int temp;
	int step = size/2; // ������ ���
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
		step = step/2; // ��������� ���
	}

	cout<<"�������������� ������ :"<<endl;
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
	cout<<"������� ������ ������� : "; cin>>size;
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

