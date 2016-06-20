// ListOfAdjacency.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
using namespace std;
// ������ ���������

const int Vmax = 10000; // ������������ ���. ������
const int Emax = 20000; // ������������ ���. �����

int terminal[Emax]; // ������ �������, � ������� ������ �����
int next_el[Emax]; // �������� ��������� �� �������� ������� terminal
int head[Vmax]; // �������� ��������� �� ������ ����������, �. �.
// �� ����� ������� ���������� � ������ terminal, � ������� ���������� ������� ������������ ���� ������ ������� ����� i-�� �������

int k=0;
void Add(int v, int u) // ��������� ����� �� ������� V � U
{
	k += 1;
	terminal[k] = u; // ������������ �������� ��� ���������� ����� ������� (u)
	next_el[k] = head[v];
	head[v] = k; //  ����������� ����������� �� ��������� ��������,
	// �� � ������� ���������� ��������� (������ � �������) ������� ������ � ��������� i-�� ��������.
}

int _tmain(int argc, _TCHAR* argv[])
{
	int m, n; // ���������� ������ � �����
	int v, u; // ���������� ��� ���������� �����
	char ch;
	int j;
	setlocale(LC_ALL,"Rus");
	cout << "������� ���������� ������ : "; cin >> m; 
	cout << endl << "������� ��������� ����� : "; cin >> n;
	cout << endl << "������� ������� ������� :" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> v >> u;
		cout << "����� ������.? (y/n) "; cin >> ch;
		if ('y' == ch) Add(v,u);
		else
		{
			Add(v,u);
			Add(u,v);
		}
		cout << "_____________"<<endl;
	}

	// ����� ������ ���������
	for (int i = 1; i <= m; i++)
	{
		j = head[i];
		cout << i << " -> ";
		while (j > 0)
		{
			if (!next_el[j]) cout << terminal[j];
			else cout <<terminal[j]<<", ";
			j = next_el[j];
		}
		cout << endl;
	}
	cout << endl;
}

 