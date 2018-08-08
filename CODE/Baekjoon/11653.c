#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 10000001
int num[N];
int prime[N];

int main(void)
{	
	num[0] = num[1] = 1;
	for (int i = 2; i < N; i++) {
		if (num[i] == 0) {
			for (int j = i + i; j < N; j += i)
				num[j] = 1;
		}
	}
	int cnt = 0;
	for (int i = 2; i < N; i++)
		if (num[i] == 0) {
			prime[cnt] = i;
			cnt++;
		}

	int n;
	scanf("%d", &n);

	while (1) {
		if (n == 1)
			break;
		for(int i=0; i<cnt; i++)
			if (n % prime[i] == 0) {
				printf("%d\n", prime[i]);
				n /= prime[i];
				break;
			}
	}

	return 0;
}