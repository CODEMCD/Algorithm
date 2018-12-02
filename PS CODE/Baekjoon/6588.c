#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 1000001
int num[N];
int prime[N];

int main(void)
{	
	int cnt = 0;
	num[0] = num[1] = 1;
	for (int i = 2; i < N; i++) {
		if (num[i] == 0) {
			for (int j = i + i; j < N; j += i)
				num[j] = 1;
		}
	}
	for (int i = 2; i < N; i++) {
		if (num[i] == 0) {
			prime[cnt] = i;
			cnt++;
		}
	}
	int n;
	while (1) {
		scanf("%d", &n);
		if (n == 0)
			break;
		for (int i = 1; i < cnt; i++) {
			if (num[n - prime[i]] == 0) {
				printf("%d = %d + %d\n", n, prime[i], n - prime[i]);
				break;
			}
		}
	}

	return 0;
}