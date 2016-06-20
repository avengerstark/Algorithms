// SieveOfSundaram.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
using namespace std;
//������ ���������
int const ARRAY_SIZE = 10000;
void SieveOfSundaram(int N)
{
	int A[ARRAY_SIZE] = {}; // �������������� ������� ������
	int k=0, q=0;
	for (int i = 1; 3 * i + 1 < N; i++)
	{
		for (int j = 1; (k = i + k + 2 * i * j) < N && i <= j; j++)
		{
			A[k] = 1; // ����������� ��� ��������� �����
		}
	}

	// ����� ������� �����
	for (int i = 1; (i*2+1) < N; i++)
	{
		if (A[i] == 0)
		{
			cout << setw(5) << i * 2 + 1 << " "; // ���������� ����� �������� �� 2 � ���������� 1
			q++;
			if (q % 5 == 0) cout << endl;
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	setlocale(LC_ALL,"Rus");
	cout << "************������ ���������*********************"<<endl;
	cout << "N = "; cin >> n;
	cout << "����� ���� ������� �����"<<endl;
	SieveOfSundaram(n);
	cout << endl;
	return 0;
}

