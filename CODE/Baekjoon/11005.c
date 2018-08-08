#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#define N 100001
int pronum[N];

int main(void)
{
	int num, prop, i = 0;
	scanf("%d %d", &num, &prop);
	while (1) {
		if (num < prop) {
			pronum[i] = num;
			break;
		}
		pronum[i] = num % prop;
		num /= prop;
		i++;
	}

	for (int j = i; j >= 0; j--) {
		if (pronum[j] < 10)
			printf("%d", pronum[j]);
		else
			printf("%c", pronum[j] + 55);
	}
	return 0;
}