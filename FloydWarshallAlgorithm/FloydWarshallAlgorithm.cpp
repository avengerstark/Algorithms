// FloydWarshallAlgorithm.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
using namespace std;
// Алгоритм Флойда-Уоршелла

int n, s; // число вершин, стартовая вершина
const int INF = INT_MAX / 2; // Типа бесконечность
int D[1000][1000]; // матрица кратчайших расстояний
int par[1000][1000]; // матрица предков

// Floyd-Warshall Algorithm
void FloydWarshallAlgorithm()
{
	for (int k = 0; k < n; k++) // Через каждый шаг добовляем вершину через которую можно проложить путь
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (D[i][k] < INF && D[k][j] < INF)
					if (D[i][k] + D[k][j] < D[i][j]) // Если путь меньше через вершину к, то записываем это значение 
					{
						D[i][j] = D[i][k] + D[k][j];
						par[i][j] = par[k][j]; // Обновляем матрицу предшествования, т.е заносим новый путь
					}
}


// Функция восстановления кратчайших путей
void Travel( int v)
{
	if (s == v)
	{
		cout << v + 1 << " ";
	}
	else
	{
		Travel(par[s][v]);
		cout << v + 1 << " ";
	}
}

// Считываем данные
void ReadData()
{
	cout << "Введите количество вершин : "; cin >> n;
	cout << "Заполните матрицу смежности : \n\n";
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cout << "D" << "[" << i+1 << "] " << "[" << j+1 << "] = "; cin >> D[i][j];

			// По условию если D[i][j] = 0, то это
			// означает, что дуги из i в j нет;
			// в этом случае расстояние между этими
			// вершинами бесконечно велико
			if (D[i][j] == 0)
				D[i][j] = INF;

			par[i][j] = i;
		}
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Rus");
	ReadData();
	FloydWarshallAlgorithm();

	// Вывод матрицы весов
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		for (int j = 0; j < n; j++)
		{
			if (D[i][j] == INF) cout << "NO ";
			else cout << D[i][j] << " ";
		}
	}



	cout << endl << "\nВывод кратчайших путей : \n\n";
	for (int i = 0; i < n; i++)
	{
		s = i;
		for (int j = 0; j < n; j++)
		{
			if (!(i == j))
			{
				cout << "Путь из " << i + 1 << " в " << j + 1 << " : ";
				if (D[i][j] == INF)
					cout << "Путь не существует. \n";
				else
				{
					Travel(j);
					cout << endl;
				}
			}
		}
	}

	cout << "\n";

	return 0;
}

