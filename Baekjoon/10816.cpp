#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>
using namespace std;

int main(void)
{
	int n, m;
	scanf("%d", &n);
	map<int, int> map;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		map[x]++;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		printf("%d ", map[x]);
	}

	return 0;
}