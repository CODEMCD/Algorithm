#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
using namespace std;

int main() 
{
	int n; scanf("%d", &n);
	//ans: 정답을 저장할 변수, 0으로 초기화
	//tn: 해당 숫자의 자리수를 만들 변수
	//dSum: 해당 숫자의 분해합을 저장할 변수
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
