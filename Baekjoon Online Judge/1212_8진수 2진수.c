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
	if (input[0] == '1')
		printf("1");
	else if (input[0] == '2')
		printf("10");
	else if (input[0] == '3')
		printf("11");
	else if (input[0] == '4')
		printf("100");
	else if (input[0] == '5')
		printf("101");
	else if (input[0] == '6')
		printf("110");
	else if (input[0] == '7')
		printf("111");
	else
		printf("0");
	for (int j = 1; j < i; j++) {
		if (input[j] == '1')
			printf("001");
		else if (input[j] == '2')
			printf("010");
		else if (input[j] == '3')
			printf("011");
		else if (input[j] == '4')
			printf("100");
		else if (input[j] == '5')
			printf("101");
		else if (input[j] == '6')
			printf("110");
		else if (input[j] == '7')
			printf("111");
		else
			printf("000");
	}
	
	return 0;
}