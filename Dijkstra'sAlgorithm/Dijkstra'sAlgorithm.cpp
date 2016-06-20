// Dijkstra'sAlgorithm.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
using namespace std;

// �������� ��������

const int INF = INT_MAX / 2;

int n; // ���������� ������
int m; // ���������� ������
int start; // ��������� �������, �� ������� ������ ��������� �� ������ ������
int *pred; // ������ �������
int *dist; // ������ ��� �������� ���������� �� ��������� �������

vector<int> *alg;
vector<bool> used;
vector<int> *weight;

void Dijkstra(int s)
{
	dist[s] = 0; //���������� ���������� �� ��������� ������� ����� 0
	for (int iter = 0; iter < n; iter++)
	{
		int v;
		int distV = INF;

		//�������� �������, ���������� ���������� �� �������� ��� �� �������
		for (int i = 0; i < n; i++)
		{
			if (used[i]) continue;
			if (distV < dist[i]) continue;
			v = i;
			distV = dist[i];
		}

		// ��������� ��� ����, ��������� �� ��������� �������
		for (int i = 0; i < alg[v].size(); i++)
		{
			int u = alg[v][i];
			int weightU = weight[v][i];
			// ���������� �������
			if (dist[v] + weightU < dist[u])
			{
				dist[u] = dist[v] + weightU;
				pred[u] = v;
			}
		}

		//�������� ������� v �������������, �� ��� ������� ���������� ����������
		used[v] = true;
	}

}

//��������� �������������� ����������� ���� �� ������� �������
void PrintWay(int v)
{
	if (v == -1)
		return;
	PrintWay(pred[v]);
	cout << v + 1 << " ";
}


// ��������� ���������� ������� ������
void ReadData()
{
	cout << "������� ���������� ������ : "; cin >> n;
	cout << "������� ���������� ����� : "; cin >> m;
	cout << "������� ��������� ������� : "; cin >> start;
	--start;
	//�������������� ������ ��������� ����� ����������� n
	alg = new vector<int>[n];
	//������������� ������, � ������� �������� ���� �����
	weight = new vector<int>[n];
	cout << "������� ����� � �� ��� : \n";
	for (int i = 0; i < m; i++)
	{
		int v, u, w;
		cin >> v >> u >> w;
		--v; --u;
		alg[v].push_back(u);
		weight[v].push_back(w);
		cout << "_______________________________________\n";
	}
	used.resize(n, false);
	
	pred = new int[n];
	dist = new int[n];
	for (int i = 0; i < n; i++)
	{
		dist[i] = INF;
		pred[i] = -1;
	}
}

void PrintData()
{
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << " : ";
		if (dist[i] != INF)
		{
			PrintWay(i);
		}
		if (dist[i] != INF)
		{
			cout << "        ���������� : "<<dist[i];
		}
		cout << endl;
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL,"Rus");
	ReadData();
	Dijkstra(start);
	PrintData();

	return 0;
}

