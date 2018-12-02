#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int Fibo(int n)
{
	int f0 = 0, f1 = 1, fb;
	f0 += f1;
	fb = f1;
	for (int i = 0; i < n-2; i++) {
		f0 += fb;
		fb = f1;
		f1 = f0;
	}
	return f0;
}

int main(void)
{
	int n;
	scanf("%d", &n);

	printf("%d\n", Fibo(n));
	return 0;
}