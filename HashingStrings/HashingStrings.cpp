// HashingStrings.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
using namespace std;
// Алгоритм хеширования строки

const int P = 53; // Разумно выбирать для P простое число, примерно равное количеству символов во входном алфавите. 
const int N = 10000;  // Максимальное длина строки
vector<size_t> p_pow(N); // массив хранит нужные степени P
char str[N];

int HashingString(char str [])
{
	size_t hash=0;
	p_pow[0] = 1;
	for (int i = 1; i < p_pow.size(); i++) // заполняем массив степенями P
	{
		p_pow[i] = p_pow[i - 1] * P;
	}

	for (int i = 0;; i++)
	{
		if (str[i] == '\0') break;
		hash += str[i] * p_pow[i];
	}
	return hash;
}

int _tmain(int argc, _TCHAR* argv[])
{
	
	setlocale(LC_ALL, "Rus");
	/*cout << "Введите строку, затем нажмите Enter : \n";
	gets(str);
	int hash = HashingString(str);
	cout <<"Хеш строки : " <<hash<< " \n";*/
	





	string s, t; // входные данные

	s = "i'm iron man";
	t = "man";

	// считаем все степени p
	const int p = 31;
	vector<long long> p_pow(100);
	p_pow[0] = 1;
	for (size_t i = 1; i<p_pow.size(); ++i)
		p_pow[i] = p_pow[i - 1] * p;

	// считаем хэши от всех префиксов строки T
	vector<long long> h(t.length());
	for (size_t i = 0; i<t.length(); ++i)
	{
		h[i] = (t[i] - 'a' + 1) * p_pow[i];
		if (i)  h[i] += h[i - 1];
	}

	// считаем хэш от строки S
	long long h_s = 0;
	for (size_t i = 0; i<s.length(); ++i)
		h_s += (s[i] - 'a' + 1) * p_pow[i];

	// перебираем все подстроки T длины |S| и сравниваем их
	for (size_t i = 0; i + s.length() - 1 < t.length(); ++i)
	{
		long long cur_h = h[i + s.length() - 1];
		if (i)  cur_h -= h[i - 1];
		// приводим хэши к одной степени и сравниваем
		if (cur_h == h_s * p_pow[i])
			cout << i << ' ';
	}





	return 0;
}

