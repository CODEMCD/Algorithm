#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define N 51
int a[N][N];
int b[N][N];

void flip(int i, int j)
{
	for (int k = i; k <= i + 2; k++)
		for (int l = j; l <= j + 2; l++) {
			a[k][l] = 1 - a[k][l];
		}
}

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%1d", &a[i][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%1d", &b[i][j]);

	int ans = 0;
	for (int i = 0; i < n - 2; i++)
		for (int j = 0; j < m - 2; j++) {
			if (a[i][j] != b[i][j]) {
				ans++;
				flip(i, j);
			}
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] != b[i][j]) {
				printf("-1\n");
				return 0;
			}
	printf("%d\n", ans);
	return 0;
}