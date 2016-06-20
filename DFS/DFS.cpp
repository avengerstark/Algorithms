// DFS.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
using namespace std;

// ќбход в глубину

int n; // количество вершин
int m; // количество ребер

vector<int> *alg; // список смежности графов
vector<bool> used; // массив дл€ хранени€ информации о пройденных и непройденных вершинах

void DFS(int v)
{
	if (used[v])
	{
		return;
	}
	used[v] = true; //помечаем вершину как пройденную
	cout << v + 1 << " ";
	for (int i = 0; i < alg[v].size(); ++i)
	{
		int w = alg[v][i]; // w присваиваем смежные графы v
		DFS(w); // рекурсивно проходим в глубину
	}
}

//процедура считывани€ входных данных с консоли
void ReadData()
{
	cout << "¬ведите количество вершин : "; cin >> n;
	cout << "¬ведите количество ребер : "; cin >> m;
	alg = new vector<int>[n];
	cout << "¬водите ребра :\n";
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
	cout << "¬ведите вершину с которого начнетс€ поиск : "; cin >> s;
	--s;
	DFS(s);
	// ќсвобождаем пам€ть
	for (int i = 0; i < n; i++)
	{
		alg[i].clear();
	}
	delete[] alg;
	used.clear();
	cout << endl;
	return 0;
}

