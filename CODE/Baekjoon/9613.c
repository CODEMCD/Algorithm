#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define N 101
int num[N];

int GCD(int a, int b)
{
	if (b == 0)
		return a;
	else
		return GCD(b, a%b);
}
int main(void)
{
	int t, n, gcd, a, b;
	long long sum;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		for (int j = 0; j < n; j++)
			scanf("%d", &num[j]);
		sum = 0;
		for (int  k= 0; k < n - 1; k++) {
			for (int l = k + 1; l < n; l++) {
				a = num[k];
				b = num[l];
				gcd = GCD(a, b);
				sum += gcd;
			}
		}
		printf("%lld\n", sum);
	}

	return 0;
}