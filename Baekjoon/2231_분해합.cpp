#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
using namespace std;

int main() 
{
	int n; scanf("%d", &n);
	//ans: ������ ������ ����, 0���� �ʱ�ȭ
	//tn: �ش� ������ �ڸ����� ���� ����
	//dSum: �ش� ������ �������� ������ ����
	int ans = 0, tn, dSum;
	for (int i = 1; i <= n; i++) {
		tn = i;
		dSum = i;
		while (tn != 0) {
			dSum += tn % 10;
			tn /= 10;
		}
		if (dSum == n) {
			ans = i;
			break;
		}
	}
	printf("%d\n", ans);

	return 0;
}
