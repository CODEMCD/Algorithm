#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define N 250000
int num[N];

int main(void)
{
	//�����佺�׳׽��� ü
	num[0] = num[1] = 1;  //0,1�� �Ҽ� �Ǻ����� ���ܵǴ� �����̱� ����
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