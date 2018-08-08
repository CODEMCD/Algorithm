#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int stick[7] = { 64, 32, 16, 8, 4, 2, 1 };
	int wantLen, judB = 0, count = 0;
	scanf("%d", &wantLen);

	while (1) {
		for (int i = 0; i < 7; i++) {
			if (wantLen >= stick[i]) {
				count++;
				wantLen -= stick[i];
			}
			if (wantLen == 0) {
				judB = 1;
				break;
			}
		}
		if (judB == 1)
			break;
	}

	printf("%d\n", count);

	return 0;
}