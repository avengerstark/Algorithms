// HashFunction.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
using namespace std;
// ����� ��������� 

int HashMultiplication(int k)
{
	int N = 13; // ���������
	double A = 0.618033; // ����� �������� �� ��������� �������� �������
	return N * fmod(A*k,1);  
}


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Rus");
	char str[1000];
	cout << "������� ������, ����� ������� Enter : \n";
	gets(str);

	// ����� ��� �����
	for (int i = 0;; i++)
	{
		if ((int)str[i] == '\0')
			break;
		cout <<HashMultiplication (str[i])<<" ";
	}
	cout << endl;
	return 0;
}

