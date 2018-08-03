# LCS(Longest Common Subsequence)

## 문제 링크
- LCS 길이 구하기
  - https://www.acmicpc.net/problem/9251
- LCS 길이 + LCS 문자열 구하기
  - https://www.acmicpc.net/problem/9252
  
## 추가 테스트 케이스
- 입력
```
AKAK
AAK
```
- 출력
```
4
AAK
```

## 코드 분석
- LCS 길이 구하기
  - 동적 계획법
  - str1[]: 입력 배열1, str2[]: 입력 배열2
  - dp[x][y]: str1[x], str2[y] 일때, LCS 길이
    - 점화식 계산을 위해 인덱스 0일 때, 모든 값을 0으로 채워준다.(즉 str1, str2길이가 n일 때, dp[n+1][n+1]이어야 한다.)
  - 점화식: for문 i: 1 ~ str1 문자열 길이, j: 1 ~ str2 문자열 길이
  ```
  str1[i - 1] == str2[j - 1] => dp[i][j] = dp[i - 1][j - 1] + 1
  str1[i - 1] != str2[j - 1] => MAX(dp[i - 1][j], dp[i][j - 1])
  ```
  - 예제 배열 최종 결과 그림
  
  ![lcs1](https://user-images.githubusercontent.com/34755287/43620018-9af15aa0-970b-11e8-8b97-b11e604c5157.JPG)
  
  - 시간 복잡도: str1, str2 중 최대 문자열 길이를 N이라 할때, ```O(N^2)```
  
- LCS 문자열 구하기
  - check[x][y]: str1[x] == str2[y]일때 LCS 길이, 아니면 0값이다.
    - 위의 LCS 길이를 구하는 점화식에서 두 문자열이 같을 때의 dp배열값을 같은 인덱스 위치 check배열에 삽입한다.
  - maxLen: LCS 길이 값
  - 슈도 코드
  ```
  for( i: str1 문자열길이 ~ 1)
    for( j: str2 문자열길이 ~ 1)
      if(check[i][j] == maxLen)
        정답 배열[maxLen - 1] = str1[i - 1] or str2[j - 1]
        maxLen--
        break
  ```
  - 예제 배열 그림
  
  ![lcs2](https://user-images.githubusercontent.com/34755287/43620019-9b1a2426-970b-11e8-9ab8-f66e4849331c.JPG)
  
  - 시간복잡도: ```O(N^2)```
  
## 결과 코드
- LCS 길이 + LCS 문자열 구하기
```
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define max(a,b) ((a) > (b) ? (a) : (b))
#define N 1002
//str1, str2: 입력 배열
char str1[N], str2[N];
//dp: LCS 길이를 계산할 배열, check: LCS 문자열을 계산할 배열
int dp[N][N], check[N][N];
//ans: LCS 문자열을 저장할 배열
char ans[N];

int main() 
{
	scanf("%s %s", str1, str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);

	//LCS 길이 계산
	for (int i = 1; i < len1 + 1; i++) {
		for (int j = 1; j < len2 + 1; j++) {
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				check[i][j] = dp[i][j];
			}
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	printf("%d\n", dp[len1][len2]);

	//LCS 문자열 계산
	int maxlen = dp[len1][len2];
	for (int i = len1; i >= 1; i--) {
		if (!maxlen) break;
		for (int j = len2; j >= 1; j--) {
			if (check[i][j] == maxlen) {
				ans[maxlen - 1] = str1[i - 1];
				maxlen--;
				break;
			}
		}
	}
	printf("%s\n", ans);

	return 0;
}
```
