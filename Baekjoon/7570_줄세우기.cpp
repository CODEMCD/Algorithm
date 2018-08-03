#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
using namespace std;
#define max(a,b) ((a) > (b) ? (a) : (b))
#define N 1000001
int dp[N];

//LIS 알고리즘 응용
//어린이 숫자 수열에서 1씩 증가하는 수열의 최대 길이를 제외한
//나머지 어린이들을 각각 앞뒤로 옮겨 줘야 한다.
//1씩 증가하는 수열의 최대길이 점화식:
//dp[n]: 숫자 n일때 1씩 증가한 수열 최대 길이
//dp[n] = dp[n - 1] + 1
//max(dp[1 ~ n])
int main()
{
	int n; scanf("%d", &n);

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int cn; scanf("%d", &cn);
		dp[cn] = dp[cn - 1] + 1;
		cnt = max(cnt, dp[cn]);
	}
	printf("%d\n", n - cnt);

	return 0;
}
