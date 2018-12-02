#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <queue>
using namespace std;
#define N 20
char str[N];
int n, m;

bool check(string pwd)
{
	int ja = 0;
	int mo = 0;
	for (char x : pwd) {
		if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
			mo += 1;
		else
			ja += 1;
	}
	return ja >= 2 && mo >= 1;
}

void go(string pwd, int i)
{
	if (pwd.length() == n) {
		if (check(pwd)) {
			cout << pwd << '\n';
		}
		return;
	}
	if (i == m) return;
	go(pwd + str[i], i + 1);
	go(pwd, i + 1);
}

int main(void)
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
		cin >> str[i];
	sort(str, str + m);
	go("", 0);

	return 0;
}