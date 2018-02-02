#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
#define N 3300
char star[N][6500];

void solve(int x, int y, int n)
{
	if (n == 3) {
		star[x][y] = '*';
		star[x + 1][y - 1] = '*';
		star[x + 1][y + 1] = '*';
		star[x + 2][y - 2] = '*';
		star[x + 2][y - 1] = '*';
		star[x + 2][y] = '*';
		star[x + 2][y + 1] = '*';
		star[x + 2][y + 2] = '*';
		return;
	}
	solve(x, y, n / 2);
	solve(x + (n / 2), y - (n / 2), n / 2);
	solve(x + (n / 2), y + (n / 2), n / 2);
}


int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < N; i++)
		memset(star[i], ' ', sizeof(star[i]));
	solve(0, n - 1, n);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n; j++)
			printf("%c", star[i][j]);
		printf("\n");
	}
	return 0;
}