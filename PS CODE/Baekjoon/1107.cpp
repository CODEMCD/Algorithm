#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
#define N 10
bool broken[N];
int num[N];

int possible(int c)
{
	if (c == 0)
		if (broken[0])
			return 0;
		else
			return 1;
	int len = 0;
	while (c != 0) {
		int ch = c % 10;
		//printf("c = %d  ch = %d\n", c, ccnt);
		if (broken[ch] == true)
			return 0;
		c /= 10;
		len++;
	}
	return len;
}

int main(void)
{
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int ip;
		scanf("%d", &ip);
		broken[ip] = true;
	}
	int cnt = 0;
	int nn = n;
	while (1) {
		cnt++;
		nn /= 10;
		if (nn == 0)
			break;
	}
	int x;
	int min = abs(100 - n);
	//int max = (int)pow(10, cnt);
	for (int i = 0; i <= 1000000; i++) {
		int c = i;
		int len = possible(c);
		if (len > 0) {
			x = abs(c - n);
			if (min > x + len) {
				min = x + len;
			}
		}
	}
	printf("%d\n", min);

	return 0;
}