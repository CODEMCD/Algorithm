#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;
#define N 1001
string a, s[N];

int main(void)
{
	cin >> a;
	for (int i = 0; i < a.size(); i++)
		s[i] = a.substr(i);
	sort(s, s + a.size());
	for (int i = 0; i < a.size(); i++)
		cout << s[i] << endl;
	
	return 0;
}