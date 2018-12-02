#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


int main(void)
{
	char n[101];
	int check[26];
	memset(check, -1, sizeof(check));
	scanf("%s", n);

	for (int i = 0; i < 101; i++) {
		if (n[i] == NULL)
			break;
		for (int j = 97; j < 123; j++)
			if (n[i] == j && check[j - 97] == -1) 
				check[j - 97] = i;
	}

	for (int i = 0; i < 26; i++)
		printf("%d ", check[i]);
	return 0;
}