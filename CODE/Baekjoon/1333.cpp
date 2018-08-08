#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 5000001
char listen[N];

int main(void)
{
	int n, l, d;
	scanf("%d %d %d", &n, &l, &d);
	int cnt = 1;
	int len = n * l + (5 * (n - 1)); //앨범 총 길이
	for (int i = 0; i < len; i++) {
		if (i == (l * cnt + 5 * (cnt - 1))) {  //휴식 시작 시간
			int j = i;
			listen[j] = 'B';
			listen[j + 1] = 'B';
			listen[j + 2] = 'B';
			listen[j + 3] = 'B';
			listen[j + 4] = 'B';
			i += 4;
			cnt++;
		}
		else
			listen[i] = 'L';
	}
	//전화벨 울리는 시간: 0초, D*1초, D*2초, D*3초, ...
	cnt = 1;
	int ans = 0;
	for (int i = 0; i < len; i++) {
		if (i == d * cnt) {
			//전화벨 울리는 시간이 휴식 시간일 때
			if (listen[i] == 'B') {
				ans = i;
				break;
			}
			else
				cnt++;
		}
	}
	if (!ans)
		printf("%d\n", d * cnt);
	else
		printf("%d\n", ans);

	return 0;
}