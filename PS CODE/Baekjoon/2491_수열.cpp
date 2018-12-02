#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define max(a,b) ((a) > (b) ? (a) : (b))
#define N 100001
int num[N];
//dpInc[x]: 인덱스가 x일때 증가하는 수열의 최대 길이
//dpDec[x]: 인덱스가 x일때 감소하는 수열의 최대 길이
int dpInc[N], dpDec[N];

int main()
{
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);

	//증가하는 수열 길이 계산
	dpInc[0] = 1;
	for (int i = 1; i < n; i++) {
		if (num[i] >= num[i - 1])
			dpInc[i] = dpInc[i - 1] + 1;
		else
			dpInc[i] = 1;
	}
	//감소하는 수열 길이 계산
	dpDec[0] = 1;
	for (int i = 1; i < n; i++) {
		if (num[i] <= num[i - 1])
			dpDec[i] = dpDec[i - 1] + 1;
		else
			dpDec[i] = 1;
	}

	//최소길이는 무조건 한개 이상이므로 1이 되어야 한다.
	int ans = 1;
	//최대값 계산
	for (int i = 1; i < n; i++) {
		ans = max(ans, dpInc[i]);
		ans = max(ans, dpDec[i]);
	}
	printf("%d\n", ans);

	return 0;
}
