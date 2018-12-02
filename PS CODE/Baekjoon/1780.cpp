#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
#define N 3000
int paper[N][N];
int cnt[3];

bool same(int x, int y, int n)
{
	for (int i = x; i < x + n; i++)
		for (int j = y; j < y + n; j++)
			if (paper[x][y] != paper[i][j])
				return false;
	return true;
}

void solve(int x, int y, int n)
{
	if (same(x, y, n)) {
		cnt[paper[x][y] + 1]++;
		return;
	}
	int m = n / 3;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			solve(x + i*m, y + j*m, m);  //important
}

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &paper[i][j]);
	solve(0, 0, n);
	for (int i = 0; i < 3; i++)
		printf("%d\n", cnt[i]);

	return 0;
}