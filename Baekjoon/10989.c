#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 10001
int res[N];

int main(void)
{
	int n, num;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		res[num] += 1;
	}
	for (int i = 1; i <= 10000; i++) {
		for (int j = 0; j < res[i]; j++)
			printf("%d\n", i);
	}

	return 0;
}