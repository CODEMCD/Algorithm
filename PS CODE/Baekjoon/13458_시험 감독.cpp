#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int room[1000001];

int main(void)
{
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &room[i]);
	int a, b;
	scanf("%d %d", &a, &b);

	//한 강의실마다 감독관이 100만명이 필요하고 강의실 개수가 최대 100만개면
	//int타입의 범위를 훨씬 넘어선다.
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += 1;
		room[i] -= a;
		if (room[i] > 0) {
			int sub = room[i] % b;
			int needSub = room[i] / b;
			if (sub == 0)
				ans += needSub;
			else if (sub > 0)
				ans += (needSub + 1);
		}
	}
	printf("%lld\n", ans);

	return 0;
}
