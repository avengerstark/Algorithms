// BFS.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
using namespace std;

// Поиск в ширину 

int n; // количество вершин
int m; // количество 

vector<int> *alg; // список смежности графов
vector<bool> used; //массив для хранения информации о пройденных и не пройденных вершинах
queue<int> q; // //очередь для добавления вершин при обходе в ширину

int *pred; // массив предков, необходимых для восстановления кратчайшего пути из стартовой вершины 

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

void ReadData() // Ввод данных
{
	cout << "Введите количесво вершин : "; cin >> n;
	cout << "Введите количество ребер : "; cin >> m;
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
		cout << "Введите ребро : \n"; cin >> v >> w;
		cout << "Ребро ориент. ? (y / n) "; cin >> ch;
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

//процедура восстановления кратчайшего пути по массиву предком
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
	int s; // Вершина с которго будет производится поиск.
	cout << "Введите граф, с которого начнется обход : "; cin >> s;
	cout << "\nРезультат : ";
	--s;
	BFS(s);
	cout << endl;

	int l;
	cout << "Введите вершину до которой нужно узнать путь : "; cin >> l;
	--l;
	cout << "Путь : ";
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



