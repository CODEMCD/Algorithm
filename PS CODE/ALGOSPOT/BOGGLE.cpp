#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char map[5][5];
char word[11];
int dp[5][5][10];
int mx[8] = { 0,1,1,1,0,-1,-1,-1 };
int my[8] = { -1,-1,0,1,1,1,0,-1 };

int solve(int y, int x, int idx)
{
	int &ret = dp[y][x][idx];
	//초기화 오류 처리
	if (ret != -1) return ret;
	for (int i = 0; i < 8; i++) {
		int nexty = y + my[i];
		int nextx = x + mx[i];

		if (nexty >= 0 && nexty < 5 && nextx >= 0 && nextx < 5) {
			//단어와 일치되는 알파벳을 찾았을 때,
			if (map[nexty][nextx] == word[idx]) {
				//단어의 다음 문자가 NULL이면, 모두 찾았기 때문에 TRUE를 반환
				if (word[idx + 1] == '\0') return ret = 1;
				//아직 단어를 찾을 것이 남아있다면 다시 재귀함수 호출
				ret = solve(nexty, nextx, idx + 1);  
				//문자열을 찾았다면 남은 재귀함수에서 모두 1(TRUE)값을 반환하여 마지막 결과에 1을 반환하도록 한다.
				if (ret) return ret;
			}
		}
	}
	//문자를 모두 매칭할 수 없으므로 FALSE를 반환
	return false;
}

int find()
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			int &ret = dp[i][j][0];
			if (ret != -1) return ret;  //초기화가 안됬다면 바로 리턴(오류 처리)
			if (map[i][j] == word[0]) {  //첫 단어를 map에서 찾았다면
				ret = solve(i, j, 1);
				if (ret) return ret;
			}
		}
	}
	return false;
}

int main(void)
{
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		for (int i = 0; i < 5; i++)
			scanf("%s", map[i]);
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			memset(dp, -1, sizeof(dp));
			scanf("%s", word);
			printf("%s %s\n", word, find() ? "YES" : "NO");
		}
	}
	return 0;
}