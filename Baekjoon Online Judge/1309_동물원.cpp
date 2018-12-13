#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
#define N 100001
#define M 9901
int dp[N];

int main() 
{
	dp[1] = 3; dp[2] = 7;
	int n; scanf("%d", &n);
	for (int i = 3; i <= n; i++) {
		//Á¡È­½Ä
		dp[i] = (dp[i - 1] * 3) - (dp[i - 1] - dp[i - 2]);
		dp[i] %= M;
	}
	printf("%d\n", dp[n]);

	return 0;
}
