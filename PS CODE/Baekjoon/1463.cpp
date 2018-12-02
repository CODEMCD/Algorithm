#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 1000001
int dp[N];

int main(void)
{
	int n;
	scanf("%d", &n);
	dp[0] = 0; dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		int temp = dp[i - 1] + 1;
		if (i % 2 == 0 && dp[i / 2] + 1 < temp)
			temp = dp[i / 2] + 1;
		if (i % 3 == 0 && dp[i / 3] + 1 < temp)
			temp = dp[i / 3] + 1;
		dp[i] = temp;
	}
	/*for (int i = 1; i <= n; i++)
		printf("%d ", dp[i]);*/
	printf("%d\n", dp[n]);

	return 0;
}