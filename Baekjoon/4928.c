#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define N 250000
int num[N];

int main(void)
{
	//에라토스테네스의 체
	num[0] = num[1] = 1;  //0,1은 소수 판별에서 제외되는 숫자이기 때문
	for (int i = 2; i < N; i++) {
		if (num[i] == 0) {
			for (int j = i + i; j < N; j += i)
				num[j] = 1;
		}
	}

	int n, cnt = 0;
	while (1) {
		cnt = 0;
		scanf("%d", &n);
		if (n == 0)
			break;

		for (int i = n + 1; i < 2 * n + 1; i++)
			if (num[i] == 0)
				cnt++;
		printf("%d\n", cnt);
	}


	return 0;
}