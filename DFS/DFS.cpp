// DFS.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
using namespace std;

// ����� � �������

int n; // ���������� ������
int m; // ���������� �����

vector<int> *alg; // ������ ��������� ������
vector<bool> used; // ������ ��� �������� ���������� � ���������� � ������������ ��������

void DFS(int v)
{
	if (used[v])
	{
		return;
	}
	used[v] = true; //�������� ������� ��� ����������
	cout << v + 1 << " ";
	for (int i = 0; i < alg[v].size(); ++i)
	{
		int w = alg[v][i]; // w ����������� ������� ����� v
		DFS(w); // ���������� �������� � �������
	}
}

//��������� ���������� ������� ������ � �������
void ReadData()
{
	cout << "������� ���������� ������ : "; cin >> n;
	cout << "������� ���������� ����� : "; cin >> m;
	alg = new vector<int>[n];
	cout << "������� ����� :\n";
	for (int i = 0; i < m; ++i)
	{
		int v, w;
		cin >> v >> w;
		v--;
		w--;
		alg[v].push_back(w);
		alg[w].push_back(v);
		cout << "_______________\n";
	}
	used.assign(n, false);
}




int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Rus");
	int s;
	ReadData();
	cout << "������� ������� � �������� �������� ����� : "; cin >> s;
	--s;
	DFS(s);
	// ����������� ������
	for (int i = 0; i < n; i++)
	{
		alg[i].clear();
	}
	delete[] alg;
	used.clear();
	cout << endl;
	return 0;
}

