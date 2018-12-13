#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
//최소값을 구하기 위해 나타날 수 있는 가장 큰 값 설정
const int INF = 1111111111;
//최대값을 구하기 위해 나타날 수 있는 가장 작은 값 설정
//음수가 나올 수 있다는 것에 유의한다.(최소가 0이 아님)
const int RINF = -1111111111;
//num: 수 입력
//oper: 연산자 각각 저장
//0: +, 1: -, 2: *, 3: /
int num[12], oper[11];

int main()
{
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &num[i]);
	int cnt = 0;
	for (int i = 0; i < 4; ++i) {
		int on;
		scanf("%d", &on);
		for (int j = 0; j < on; ++j)
			oper[cnt++] = i;
	}

	int _min, _max;
	_min = INF;
	_max = RINF;
	//연산자의 모든 중복 순열을 구하여 계산한다. (최대 연산수: 10!)
	do {
		int cal = num[0];
		for (int i = 1; i < n; ++i) {
			switch (oper[i - 1]) {
			case 0: cal += num[i]; break;
			case 1: cal -= num[i]; break;
			case 2: cal *= num[i]; break;
			case 3: cal /= num[i]; break;
			default: break;
			}
		}
		_min = _min < cal ? _min : cal;
		_max = _max > cal ? _max : cal;
	} while (next_permutation(oper, oper + cnt));
	printf("%d\n%d\n", _max, _min);

	return 0;
}
