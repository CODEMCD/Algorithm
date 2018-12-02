#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define M 1000000007
#define N 101
int dp[N];
int cache[N];

//TOP-DOWN
int tiling(int width)
{
	if (width <= 1) return 1;
	int &ret = cache[width];
	if (ret != -1) return ret;
	return ret = ((tiling(width - 1) + tiling(width - 2)) % M);
}

int main(void)
{
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		memset(dp, 0, sizeof(dp));
		memset(cache, -1, sizeof(cache));
		int n;
		scanf("%d", &n);
		//BOTTOM-UP
		dp[0] = 1; dp[1] = 2;
		for (int i = 2; i < n; i++) {
			dp[i] = (dp[i - 1] % M) + (dp[i - 2] % M);
			dp[i] %= M;
		}
		//printf("%d\n", dp[n - 1]);
		printf("%d\n", tiling(n));

	}
	return 0;
}