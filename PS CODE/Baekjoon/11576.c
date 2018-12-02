#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 1000001
int input[N];
char output[N];

int main(void)
{
	int a, b, m, decimal = 0, cnt = 0;
	scanf("%d %d", &a, &b);
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
		scanf("%d", &input[i]);
	for (int i = m - 1; i >= 0; i--) {
		decimal += input[i] * (int)pow(a, cnt);
		cnt++;
	}

	cnt = 0;
	while (1) {
		if (decimal < b) {
			output[cnt] = decimal;
			cnt++;
			break;
		}
		output[cnt] = decimal % b;
		decimal /= b;
		cnt++;
	}
	for (int i = cnt - 1; i >= 0; i--)
		printf("%d ", output[i]);

	return 0;
}