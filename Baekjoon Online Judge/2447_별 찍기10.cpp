#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
#define N 2200
char star[N][N];

void solve(int x, int y, int n)
{
	if (n == 1) {
		star[x][y] = '*';
		return;
	}
	else {
		int m = n / 3;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (i != 1 || j != 1)
					solve(x + (m*i), y + (m*j), m);
	}
}


int main(void)
{
	int n;
	scanf("%d", &n);
	memset(star, ' ', sizeof(star));
	solve(0, 0, n);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%c", star[i][j]);
		printf("\n");
	}
	return 0;
}