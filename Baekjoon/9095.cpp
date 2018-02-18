#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 12
int dp[N];

int main(void)
{
	dp[1] = 1; dp[2] = 2; dp[3] = 4;
	for (int i = 4; i < N; i++)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", dp[n]);
	}

	return 0;
}