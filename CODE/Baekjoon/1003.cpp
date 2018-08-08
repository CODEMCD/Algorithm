#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 41
int dp0[N];  //0개수
int dp1[N];  //1개수

int main(void)
{
	dp0[0] = 1; dp0[1] = 0;
	dp1[0] = 0; dp1[1] = 1;
	for (int i = 2; i < N; i++) {
		dp0[i] = dp0[i - 1] + dp0[i - 2];
		dp1[i] = dp1[i - 1] + dp1[i - 2];
	}

	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		scanf("%d", &n);
		printf("%d %d\n", dp0[n], dp1[n]);
	}

	return 0;
}