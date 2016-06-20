// ListOfAdjacency.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
using namespace std;
// Список смежности

const int Vmax = 10000; // максимальное кол. вершин
const int Emax = 20000; // максимальное кол. ребер

int terminal[Emax]; // хранит вершины, в которые входят ребра
int next_el[Emax]; // содержит указатели на элементы массива terminal
int head[Vmax]; // содержит указатели на начала подсписков, т. е.
// на такие вершины записанные в массив terminal, с которых начинается процесс перечисления всех вершин смежных одной i-ой вершине

int k=0;
void Add(int v, int u) // добовляем ребро из вершины V в U
{
	k += 1;
	terminal[k] = u; // записывается конечная для некоторого ребра вершина (u)
	next_el[k] = head[v];
	head[v] = k; //  заполняется указателями на стартовые элементы,
	// те с которых начинается подсписок (строка в таблице) смежных вершин с некоторой i-ой вершиной.
}

int _tmain(int argc, _TCHAR* argv[])
{
	int m, n; // Количество вершин и ребер
	int v, u; // Переменные для добовления ребра
	char ch;
	int j;
	setlocale(LC_ALL,"Rus");
	cout << "Введите количество вершин : "; cin >> m; 
	cout << endl << "Введите количетво ребер : "; cin >> n;
	cout << endl << "Вводите смежные вершины :" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> v >> u;
		cout << "Ребро ориент.? (y/n) "; cin >> ch;
		if ('y' == ch) Add(v,u);
		else
		{
			Add(v,u);
			Add(u,v);
		}
		cout << "_____________"<<endl;
	}

	// Вывод списка смежности
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

 