#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int n;
	int n1, n2;
	int a1, a2 = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &n1, &n2);
		a2 = 0;
		if (n1 < n2)
			a1 = n1;
		else
			a1 = n2;

		for (int i = 1; i <= a1; i++)
			if (n1 % i == 0 && n2 %i  == 0) {
				if(a2 < i)
					a2 = i;
			}

		printf("%d\n", (n1 / a2)*(n2 / a2)*a2);
	}
	return 0;
}	