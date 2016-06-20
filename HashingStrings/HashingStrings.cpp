// HashingStrings.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
using namespace std;
// �������� ����������� ������

const int P = 53; // ������� �������� ��� P ������� �����, �������� ������ ���������� �������� �� ������� ��������. 
const int N = 10000;  // ������������ ����� ������
vector<size_t> p_pow(N); // ������ ������ ������ ������� P
char str[N];

int HashingString(char str [])
{
	size_t hash=0;
	p_pow[0] = 1;
	for (int i = 1; i < p_pow.size(); i++) // ��������� ������ ��������� P
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
	/*cout << "������� ������, ����� ������� Enter : \n";
	gets(str);
	int hash = HashingString(str);
	cout <<"��� ������ : " <<hash<< " \n";*/
	





	string s, t; // ������� ������

	s = "i'm iron man";
	t = "man";

	// ������� ��� ������� p
	const int p = 31;
	vector<long long> p_pow(100);
	p_pow[0] = 1;
	for (size_t i = 1; i<p_pow.size(); ++i)
		p_pow[i] = p_pow[i - 1] * p;

	// ������� ���� �� ���� ��������� ������ T
	vector<long long> h(t.length());
	for (size_t i = 0; i<t.length(); ++i)
	{
		h[i] = (t[i] - 'a' + 1) * p_pow[i];
		if (i)  h[i] += h[i - 1];
	}

	// ������� ��� �� ������ S
	long long h_s = 0;
	for (size_t i = 0; i<s.length(); ++i)
		h_s += (s[i] - 'a' + 1) * p_pow[i];

	// ���������� ��� ��������� T ����� |S| � ���������� ��
	for (size_t i = 0; i + s.length() - 1 < t.length(); ++i)
	{
		long long cur_h = h[i + s.length() - 1];
		if (i)  cur_h -= h[i - 1];
		// �������� ���� � ����� ������� � ����������
		if (cur_h == h_s * p_pow[i])
			cout << i << ' ';
	}





	return 0;
}

