# LIS(Longest Increasing Sequence)

## 문제 개요

## 테스트 케이스
1. 기본 테스트 케이스
- 입력
```
3
4
1 2 3 4
8
5 4 3 2 1 6 7 8 
8
5 6 7 8 1 2 3 4
```
- 출력
```
4
4
4
```

2. 부분 수열의 한 시작점에서 여러가지 케이스가 나타나는 경구
- 입력
```
1
7
9 1 3 7 5 6 20
```
- 출력
```
5
```

## 코드 분석
- Bottom-up
  - DP[N]: 현재 인덱스에서 가장 긴 증가 부분 수열의 길이를 저장한다.
  - Input[N]: 입력 값으르 저장한다.
  - 현재 인덱스가 i일 때, j: (1 ~ i-1)중 만약 ```input[i] < input[j]```이라면 DP[i] = DP[j] + 1로 갱신한다.
  - 갱신된 값 중 가장 큰 값을 해당 인덱스의 최적해로 판단한다.
  - 시간 복잡도: ```1 + 2 + 3 + ... + n```이므로, O(n^2)이다.

- Top-down

## 결과 코드
- Bottom-up
```
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 501
int dp[N];
int input[N];

int main(void)
{
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		memset(dp, 0, sizeof(dp));
		memset(input, 0, sizeof(input));

		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &input[i]);

		//dp배열을 모두 1로 초기화(숫자가 한개 이면 길이가 1이기 때문)
		for (int i = 0; i < n; i++)
			dp[i] = 1;
		//i: 현재 인덱스, j: 이전 인덱스
		//dp배열에서 이전의 인덱스들의 값들은 최적해이다.
		//입력 배열에서 현재 인덱스의 값이 이전의 인덱스의 값보다 크다면
		//해당 dp배열의 값에서 1을 더하여 갱신하며, 갱신 값중의 최대값을 최적해라고 판단한다.
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (input[j] < input[i]) {
					if (dp[i] < (dp[j] + 1))
						dp[i] = dp[j] + 1;
				}
			}
		}
		int max = 0;
		for (int i = 0; i < n; i++)
			if (max < dp[i])
				max = dp[i];

		printf("%d\n", max);
	}

	return 0;
}
```
