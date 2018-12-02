#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define N 10001
int pluss[N];
int minuss[N];

bool cmp(int a, int b) { return a > b; }

int main(void)
{
	int n, num, max, ans, pcnt, mcnt;
	pcnt = 0; mcnt = 0; ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		if (num > 0) {
			pluss[pcnt] = num;
			pcnt++;
		}
		else {
			minuss[mcnt] = num;
			mcnt++;
		}

	}
	sort(pluss, pluss + pcnt, cmp);
	sort(minuss, minuss + mcnt);
	
	for (int i = 0; i < pcnt; i += 2) {
		max = pluss[i] * pluss[i + 1];
		if (max < (pluss[i] + pluss[i + 1]))
			ans += (pluss[i] + pluss[i + 1]);
		else
			ans += (pluss[i] * pluss[i + 1]);
	}
	for (int i = 0; i < mcnt; i += 2) {
		if (i + 1 < mcnt) {
			ans += (minuss[i] * minuss[i + 1]);
		}
		else
			ans += minuss[i];
	}
	printf("%d\n", ans);
	return 0;
}