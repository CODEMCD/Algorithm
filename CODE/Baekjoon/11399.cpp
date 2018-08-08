#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define N 1001
int num[N];
int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);
	sort(num, n + num);
	//for (int i = 0; i < n; i++)
	//	printf("%d ", num[i]);
	//printf("\n");
	int sum = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		sum += num[i];
		ans += sum;
	}
	printf("%d\n", ans);
	return 0;
}