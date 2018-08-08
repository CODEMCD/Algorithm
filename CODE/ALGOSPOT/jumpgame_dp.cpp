#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define N 101
int board[N][N];
int cache[N][N];
int n;

int jump(int y, int x)
{
	//기저 사례 처리
	if (y >= n || x >= n) return 0;
	if (y == n - 1 && x == n - 1) return 1;
	//Memoization
	int &ret = cache[y][x];
	if (ret != -1) return ret;
	int jumpSize = board[y][x];
	return ret = (jump(y + jumpSize, x) || jump(y, x + jumpSize));
}

int main(void)
{
	int c;
	scanf("%d", &c);
	while (c--) {
		for(int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				board[i][j] = 0;
				cache[i][j] = -1;
			}
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &board[i][j]);
		if (jump(0, 0))
			printf("YES\n");
		else
			printf("NO\n");
		
	}
	
	return 0;
}