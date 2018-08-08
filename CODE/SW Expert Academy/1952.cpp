#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 13
int month[N];
int dp[N];
int price[4];

int main(void)
{
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		for (int i = 0; i < 4; i++)
			scanf("%d", &price[i]);
		for (int i = 1; i < N; i++) {
			dp[i] = 0;
			scanf("%d", &month[i]);
		}
		int d, m, tm = price[2], y = price[3];
		for (int i = 1; i < N; i++) {
			if (month[i] > 0) {
				d = month[i] * price[0];
				m = price[1];
				//1일, 1달 비교
				if (dp[i - 1] + d > dp[i - 1] + m)
					dp[i] = dp[i - 1] + m;
				else
					dp[i] = dp[i - 1] + d;
				//3달 - 1달전 시작
				if (dp[i] > dp[i - 1] + tm)
					dp[i] = dp[i - 1] + tm;
				//3달 - 2달전 시작
				if (i >= 2 && dp[i] > dp[i - 2] + tm)
					dp[i] = dp[i - 2] + tm;
				//3달 - 3달전 시작
				if (i >= 3 && dp[i] > dp[i - 3] + tm)
					dp[i] = dp[i - 3] + tm;
				//1년
				if (dp[i] > y)
					dp[i] = y;
			}
			else
				dp[i] = dp[i - 1];
		}
		/*for (int i = 1; i < N; i++)
			printf("%d ", dp[i]);
		printf("\n");*/
		printf("#%d %d\n", tc, dp[12]);
	}

	return 0;
}