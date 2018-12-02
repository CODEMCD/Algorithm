#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define N 2001
int num[N];
bool dp[N][N];

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);
	for (int i = 0; i<n; i++)
		dp[i][i] = true;

	for (int i = 0; i<n - 1; i++) 
		if (num[i] == num[i + 1]) {
			dp[i][i + 1] = true;
		}
	
	for (int k = 3; k <= n; k++) {
		for (int i = 0; i <= n - k; i++) {
			int j = i + k - 1;
			if (num[i] == num[j] && dp[i + 1][j - 1]) {
				dp[i][j] = true;
			}
		}
	}

	int m;
	scanf("%d", &m);
	while (m--) {
		int s, e;
		scanf("%d %d", &s, &e);
		printf("%d\n", dp[s - 1][e - 1]);
	}
	
	return 0;
}
