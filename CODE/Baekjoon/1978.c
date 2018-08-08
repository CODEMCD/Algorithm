#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define N 200

int main() 
{
	int num[N];
	int n, count = 0, prime;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);
	for (int i = 0; i < n; i++) {
		prime = 0;
		if (num[i] > 2) {
			for (int j = 2; j < num[i]; j++) {
				if (num[i] % j == 0)
					prime++;
			}
			if (prime == 0)
				count++;
		}
		else if (num[i] == 2)
			count++;
	}
	printf("%d\n", count);

	return 0;
}

