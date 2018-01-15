#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <math.h>
#define MIN(a,b) ((a)<(b)?(a):(b))

int main(void)
{	
	long long n, m, two = 0, five = 0;
	scanf("%lld %lld", &m, &n);

	for (long long i = 2; i <= m; i *= 2)
		two += m / i;
	for (long long i = 2; i <= m - n; i *= 2)
		two -= (m - n) / i;
	for (long long i = 2; i <= n; i *= 2)
		two -= n / i;
	for (long long i = 5; i <= m; i *= 5)
		five += m / i;
	for (long long i = 5; i <= m - n; i *= 5)
		five -= (m - n) / i;
	for (long long i = 5; i <= n; i *= 5)
		five -= n / i;

	printf("%lld\n", MIN(two, five));

	return 0;
}