#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
using namespace std;
#define N 16
int board[N];

int nqueen(int nq, int n)
{
	int sum = 0, j;
	if (nq == n)
		return 1;
	for (int i = 0; i < n; i++) {
		for (j = 0; j < nq; j++) {
			if (board[j] == i || abs(nq - j) == abs(i - board[j])) //except to horizontal and diagonal line
				break;
		}
		if (j != nq)
			continue;
		board[nq] = i;
		sum += nqueen(nq + 1, n);
	}
	return sum;
}

int main(void)
{
	int n;
	scanf("%d", &n);
	printf("%d\n", nqueen(0, n));
	return 0;
}