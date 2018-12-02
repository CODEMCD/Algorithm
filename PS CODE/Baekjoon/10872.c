#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <math.h>

int Factorial(int n)
{
	if (n == 0)
		return 1;
	else
		return n * Factorial(n - 1);
}

int main(void)
{	
	int n, res;
	scanf("%d", &n);

	res = Factorial(n);
	printf("%d\n", res);
	return 0;
}