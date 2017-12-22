#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char days[7][10] = { "SUN", "MON","TUE","WED","THU","FRI","SAT" };
	int lastDayOfMon[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	int x, y, sumDays = 0;
	scanf("%d %d", &x, &y);
	for (int i = 0; i < x - 1; i++)
		sumDays += lastDayOfMon[i];
	sumDays += y;

	printf("%s\n", days[(sumDays % 7)]);

	return 0;
}