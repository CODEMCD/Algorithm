#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
#define N 11
int d[N][N];
int v[N];

int distcal(int size)
{
	int dist = 0;
	bool check = true;
	for (int i = 0; i < size - 1; i++) {
		if (d[v[i]][v[i + 1]] != 0)
			dist += d[v[i]][v[i + 1]];
		else
			check = false;
	}
	if (check && d[v[size - 1]][v[0]] != 0) {
		dist += d[v[size - 1]][v[0]];
		//printf("%d\n", dist);
		return dist;
	}
	else
		return -1;
}

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		v[i] = i;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &d[i][j]);
	int min = distcal(n);
	while (next_permutation(v, v + n)) {
		int dist = distcal(n);
		if (dist != -1 && min > dist)
			min = dist;
	}
	printf("%d\n", min);

	return 0;
}