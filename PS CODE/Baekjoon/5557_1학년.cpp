#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 101
//num: 입력값을 저장할 배열
int num[N];
//cache[x][y]: num배열의 인덱스가 x일때, 계산결과값이 y인 경우의 수
//-1: 초기값
//0: 계산결과값에 해당하는 경우의 수가 없음
//1: 계산결과값이 될 수 있음
long long cache[N][21];
int n;

//num배열의 인덱스가 idx일때, 계산결과값이 cal이 되는 경우의 수 반환
long long solve(int idx, int cal)
{
	//기저사례1: 계산결과값이 20보다 크거나 0미만이면 바로 다음으로 넘어간다.
	if (cal > 20 || cal < 0)
		return 0;
	//메모이제이션
	long long &ret = cache[idx][cal];
	//기저사례2: 입력의 마지막 바로 앞까지 인덱스가 왔을 때
	if (idx == n - 2) {
		//계산결과값이 입력 마지막 인덱스와 같다면 경우의 수를 메모이제이션 배열에 갱신한다.
		if (cal == num[n - 1])
			ret = 1;
		else 
			ret = 0;
		return ret;
	}
	//메모이제이션
	if (ret != -1) return ret;

	//cnt: 총 경우의 수 계산
	long long cnt = 0;
	cnt += solve(idx + 1, cal + num[idx + 1]);
	cnt += solve(idx + 1, cal - num[idx + 1]);
	return ret = cnt;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);

	memset(cache, -1, sizeof(cache));
	printf("%lld\n", solve(0, num[0]));

	return 0;
}
