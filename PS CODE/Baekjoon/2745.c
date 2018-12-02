#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 100001
char pronum[N];

int main(void)
{
	int num = 0, prop, i = 0, cal, cnt = 0;
	scanf("%s %d", pronum, &prop);

	while (1) {
		if (pronum[i] == '\0')
			break;
		i++;
	}
	for (int j = i - 1; j >= 0; j--) {
		if (pronum[j] >= 65 && pronum[j] <= 90) {
			cal = pronum[j] - 55;
			num += cal * (int)pow(prop, cnt);
			cnt++;
		}
		else {
			cal = pronum[j] - 48;
			num += cal * (int)pow(prop, cnt);
			cnt++;
		}
	}
	printf("%d\n", num);

	return 0;
}