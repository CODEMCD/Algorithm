#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
#define N 65
int n;
int map[N][N];

bool same(int x, int y, int n)
{
	for (int i = x; i < x + n; i++)
		for (int j = y; j < y + n; j++)
			if (map[x][y] != map[i][j])
				return false;
	return true;
}

void solve(int x, int y, int n)
{
	if (same(x, y, n))
		printf("%d", map[x][y]);
	else {
		printf("(");
		int m = n / 2;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				solve(x + m*i, y + m*j, m);
		printf(")");
	}
}

int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%1d", &map[i][j]);
	solve(0, 0, n);
	printf("\n");
	return 0;
}