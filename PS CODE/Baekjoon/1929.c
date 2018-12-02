#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define N 1000001
int num[N];

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 2; i < m + 1; i++) {
		if (num[i] == 0) {
			for (int j = i + i; j < m + 1; j += i)
				num[j] = 1;
		}
	}

	for (int i = n; i < m + 1; i++)
		if (num[i] == 0 && i > 1)
			printf("%d\n", i);


	return 0;
}