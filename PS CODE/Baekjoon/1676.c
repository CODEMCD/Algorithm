#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{	
	int n, two = 0, five = 0, num;
	scanf("%d", &n);

	for (int i = n; i > 1; i--) {
		num = i;
		while (1) {
			if (num == 1)
				break;
			if (num % 2 == 0) {
				two++;
				num /= 2;
			}
			else if (num % 5 == 0) {
				five++;
				num /= 5;
			}
			else
				break;
		}
	}
	if (two > five)
		printf("%d\n", five);
	else
		printf("%d\n", two);
	return 0;
}