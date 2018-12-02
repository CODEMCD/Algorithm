#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define N 10001

int main(void)
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	int team = 0;
	while (1) {
		if ((n - 2) >= 0 && (m - 1) >= 0) {
			team++;
			n -= 2;
			m -= 1;
		}
		else
			break;
	}
	k -= (n + m);
	if (k > 0) {
		int rem = k / 3;
		team -= rem;
		if ((k % 3) > 0)
			team -= 1;
	}
	printf("%d\n", team);
	return 0;
}