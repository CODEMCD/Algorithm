#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 1001
char str1[N];
char str2[N];
int dp[N][N];

int main(void)
{
	scanf("%s", str1);
	scanf("%s", str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for (int i = 1; i <= len2; i++) {
		for (int j = 1; j <= len1; j++) {
			if (dp[i][j - 1] < dp[i - 1][j]) {
				dp[i][j] = dp[i - 1][j];
				if (str1[j - 1] == str2[i - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = dp[i][j - 1];
				if (str1[j - 1] == str2[i - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
			}
		}
	}
	/*for (int i = 0; i <= len1; i++) {
		for (int j = 0; j <= len2; j++)
			printf("%d ", dp[i][j]);
		printf("\n");
	}*/
	printf("%d\n", dp[len2][len1]);

	return 0;
}