#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
#define N 1100000
int hmove[N][2];
int cnt;

void hanoitower(int n, int from, int by, int to)
{
	if (n == 1) {
		//printf("%d %d\n", from, to);
		hmove[cnt][0] = from;
		hmove[cnt++][1] = to;
	}
	else {
		hanoitower(n - 1, from, to, by);
		//printf("%d %d\n", from, to);
		hmove[cnt][0] = from;
		hmove[cnt++][1] = to;
		hanoitower(n - 1, by, from, to);
	}
}

int main(void)
{
	int n;
	scanf("%d", &n);
	hanoitower(n, 1, 2, 3);
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++)
		printf("%d %d\n", hmove[i][0], hmove[i][1]);
	return 0;
}