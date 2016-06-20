// Dijkstra'sAlgorithm.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
using namespace std;

// Алгоритм Дейкстры

const int INF = INT_MAX / 2;

int n; // количество вершин
int m; // количество вершин
int start; // стартовая вершина, от которой ищется расстяние до других вершин
int *pred; // массив предков
int *dist; // массив для хранения расстояния от стартовой вершины

vector<int> *alg;
vector<bool> used;
vector<int> *weight;

void Dijkstra(int s)
{
	dist[s] = 0; //кратчайшее расстояние до стартовой вершины равно 0
	for (int iter = 0; iter < n; iter++)
	{
		int v;
		int distV = INF;

		//выбираем вершину, кратчайшее расстояние до которого еще не найдено
		for (int i = 0; i < n; i++)
		{
			if (used[i]) continue;
			if (distV < dist[i]) continue;
			v = i;
			distV = dist[i];
		}

		// расмотрим все дуги, исходящие из найденной вершины
		for (int i = 0; i < alg[v].size(); i++)
		{
			int u = alg[v][i];
			int weightU = weight[v][i];
			// релаксация вершины
			if (dist[v] + weightU < dist[u])
			{
				dist[u] = dist[v] + weightU;
				pred[u] = v;
			}
		}

		//помечаем вершину v просмотренной, до нее найдено кратчайшее расстояние
		used[v] = true;
	}

}

//процедура восстановления кратчайшего пути по массиву предком
void PrintWay(int v)
{
	if (v == -1)
		return;
	PrintWay(pred[v]);
	cout << v + 1 << " ";
}


// процедура считывания входных данных
void ReadData()
{
	cout << "Введите количество вершин : "; cin >> n;
	cout << "Введите количество ребер : "; cin >> m;
	cout << "Введите стартовую вершину : "; cin >> start;
	--start;
	//инициализируем списка смежности графа размерности n
	alg = new vector<int>[n];
	//инициализация списка, в котором хранятся веса ребер
	weight = new vector<int>[n];
	cout << "Вводите ребра и их вес : \n";
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
			cout << "        Расстояние : "<<dist[i];
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

