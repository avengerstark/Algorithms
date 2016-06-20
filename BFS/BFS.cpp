// BFS.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
using namespace std;

// ����� � ������ 

int n; // ���������� ������
int m; // ���������� 

vector<int> *alg; // ������ ��������� ������
vector<bool> used; //������ ��� �������� ���������� � ���������� � �� ���������� ��������
queue<int> q; // //������� ��� ���������� ������ ��� ������ � ������

int *pred; // ������ �������, ����������� ��� �������������� ����������� ���� �� ��������� ������� 

void BFS(int v)
{
	if (used[v]) return;
	q.push(v);
	used[v] = true;
	while (!q.empty())
	{
		v = q.front();
		q.pop();
		cout << v+1 <<" ";
		for (int i = 0; i < alg[v].size(); i++)
		{
			int w;
			w = alg[v][i];
			if (used[w]) continue;
			q.push(w);
			used[w] = true;
			pred[w] = v;
		}
	}
}

void ReadData() // ���� ������
{
	cout << "������� ��������� ������ : "; cin >> n;
	cout << "������� ���������� ����� : "; cin >> m;
	alg = new vector<int>[n];
	pred = new int[n];
	for (int i = 0; i < n; i++)
	{
		pred[i] = -1;
	}
	for (int i = 0; i < m; i++)
	{
		char ch='n';
		int v, w;
		cout << "������� ����� : \n"; cin >> v >> w;
		cout << "����� ������. ? (y / n) "; cin >> ch;
		if (ch == 'y')
		{
			--v; --w;
			alg[v].push_back(w);
		}
		else{
			--v; --w;
			alg[v].push_back(w);
			alg[w].push_back(v);
		}
		used.resize(n, false);
	}

}

//��������� �������������� ����������� ���� �� ������� �������
void PrintWay(int v)
{
	if (v == -1) return;
	PrintWay(pred[v]);
	cout << v + 1 << " ";
}


int _tmain(int argc, _TCHAR* argv[])
{	
	setlocale(LC_ALL,"Rus");
	ReadData();
	int s; // ������� � ������� ����� ������������ �����.
	cout << "������� ����, � �������� �������� ����� : "; cin >> s;
	cout << "\n��������� : ";
	--s;
	BFS(s);
	cout << endl;

	int l;
	cout << "������� ������� �� ������� ����� ������ ���� : "; cin >> l;
	--l;
	cout << "���� : ";
	PrintWay(l);
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		alg[i].clear();
	}
	delete[] alg;
	used.clear();
	cout << endl;
}



