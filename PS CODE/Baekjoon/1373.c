#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 1000001
char input[N];

int main(void)
{
	scanf("%s", input);
	int i = 0;
	while (1) {
		if (input[i] == '\0')
			break;
		i++;
	}
	if (i % 3 == 0) {
		for (int j = 0; j < i; j += 3)
			printf("%d", (input[j] - 48) * 4 + (input[j + 1] - 48) * 2 + (input[j + 2] - 48));
	}
	else if (i % 3 == 1) {
		printf("%d", input[0] - 48);
		for (int j = 1; j < i; j += 3) 
			printf("%d", (input[j] - 48) * 4 + (input[j + 1] - 48) * 2 + (input[j + 2] - 48));
	}
	else if (i % 3 == 2) {
		printf("%d", (input[0] - 48) * 2 + (input[1] - 48));
		for (int j = 2; j < i; j += 3)
			printf("%d", (input[j] - 48) * 4 + (input[j + 1] - 48) * 2 + (input[j + 2] - 48));
	}
	
	return 0;
}