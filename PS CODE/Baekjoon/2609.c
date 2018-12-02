#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int a, b, max = 1, min = 1, smaller,  i = 1;
	scanf("%d %d", &a, &b);

	smaller = a;
	if (smaller > b)
		smaller = b;

	while (1) {
		i++;
		if (i > smaller)
			break;
		if (a % i == 0 && b % i == 0) {
			max *= i;
			min *= i;
			a /= i;
			b /= i;
			i = 1;
		}
	}

	printf("%d\n", max);
	printf("%d\n", a*b*min);

	return 0;
}