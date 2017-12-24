#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int Factorial(int n)
{
	int res = 1;
	for (int i = 2; i <= n; i++)
		res *= i;
	return res;
}

int main(void)
{
	int n, k, Fn, Fk, Fnk, res;
	scanf("%d %d", &n, &k);

	Fn = Factorial(n);
	Fk = Factorial(k);
	Fnk = Factorial(n - k);

	res = Fn / (Fk * Fnk);

	printf("%d\n", res);

	return 0;
}