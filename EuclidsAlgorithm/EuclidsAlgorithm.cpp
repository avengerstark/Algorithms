// EuclidsAlgorithm.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
using namespace std;

// Алгоритм Евклида
int EuclidsAlgorithm(int A, int B)
{
	while (A!=0 && B!=0)
	{
		if (A > B) A %= B;
		else B %= A;
	}
	return A + B;
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Rus");
	int A, B;
	cout << "A = "; cin >> A;
	cout << endl << "B = "; cin >> B;
	cout << endl << "НОД (" << A << ", " << B << ") = " << EuclidsAlgorithm(A, B) << endl;
	return 0;
}

