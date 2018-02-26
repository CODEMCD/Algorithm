#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 5001
int dp[N];
int mod = 1000000;

int main(void)
{
	char str[N];
	scanf("%s", str);
	int len = strlen(str);
	if (len == 1 && str[0] == '0') {
		printf("0\n");
		return 0;
	}

	dp[0] = 1; dp[1] = 1;
	for (int i = 2; i <= len; i++) {
		int now = i - 1;
		if (str[now] > '0')
			dp[i] = dp[i - 1] % mod;
		int x = (str[now - 1] - '0') * 10 + str[now] - '0';
		if (x >= 10 && x <= 26)
			dp[i] = (dp[i] + dp[i - 2]) % mod;
	}
	printf("%d\n", dp[len]);
	
	return 0;
}