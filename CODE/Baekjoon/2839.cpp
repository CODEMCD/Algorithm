#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
#define N 200001

int main(void)
{
	int n;
	scanf("%d", &n);
	int cnt = 0;
	int tmp = n % 5;
	if (tmp == 0) {
		cnt += n / 5;
	}
	else if (tmp == 3) {
		cnt += n / 5;
		cnt++;
	}
	else {
		while (1) {
			if (n >= 3) {
				n -= 3;
				cnt++;
			}
			if (n % 5 == 0) {
				cnt += n / 5;
				n = 0;
			}
			if (n == 0)
				break;
			else if (n < 3) {
				printf("-1\n");
				return 0;
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}