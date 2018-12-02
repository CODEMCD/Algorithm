#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
#define N 21
int num[N];
bool check[N];
long long fac[N];

long long facto(int n)
{
	if (n == 0)
		return 1;
	else
		return n * facto(n - 1);
}

int main(void)
{
	int n, p;
	scanf("%d", &n);
	for (int i = 0; i < N; i++)
		fac[i] = facto(i);
	scanf("%d", &p);
	if (p == 1) {
		long long cnt, ans = 0;
		scanf("%lld", &cnt);
		for (int i = 0; i < n; i++) {
			for (int j = 1; j <= n; j++) {
				if (check[j] == true)
					continue;
				if (fac[n - i - 1] < cnt) {
					cnt -= fac[n - i - 1];
				}
				else {
					num[i] = j;
					check[j] = true;
					break;
				}
			}
		}
		for (int i = 0; i < n; i++)
			printf("%d ", num[i]);
		printf("\n");
	}
	else if (p == 2) {
		for (int i = 0; i < n; i++)
			scanf("%d", &num[i]);
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < num[i]; j++) {
				if (check[j] == false)
					ans += fac[n - i - 1];
			}
			check[num[i]] = true;
		}
		printf("%lld\n", ans + 1);
	}
	
	return 0;
}