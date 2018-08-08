#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define N 51
int um[N][N];  //지하 지도
queue<pair<int, int>> q;
bool check[N][N];  //좌표 중복 체크
int tt[N][N];  //시간 체크
//위,오른쪽,아래,왼쪽 순서로 파이프 좌표 저장(순서 중요, 파이프 연결 가능성 계산 때문)
int pipex[8][4] = { {0,0,0,0}, {-1,0,1,0}, {-1,0,1,0}, {0,0,0,0}, 
                 {-1,0,0,0}, {0,0,1,0}, {0,0,1,0}, {-1,0,0,0} };
int pipey[8][4] = { { 0,0,0,0 },{ 0,1,0,-1 },{ 0,0,0,0 },{ 0,1,0,-1 },
				 { 0,1,0,0 },{ 0,1,0,0 },{ 0,0,0,-1 },{ 0,0,0,-1 } };

int main(void)
{
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		int n, m, cx, cy, l;
		scanf("%d %d %d %d %d", &n, &m, &cx, &cy, &l);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%d", &um[i][j]);
		//시작 위치 설정
		pair<int, int> p;
		p = make_pair(cx, cy);
		check[cx][cy] = true;
		tt[cx][cy] = 1;
		q.push(p);
		bool escape = false;
		while (!q.empty()) {  //BFS
			int nowx = q.front().first;
			int nowy = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nextx = nowx + pipex[um[nowx][nowy]][i];
				int nexty = nowy + pipey[um[nowx][nowy]][i];
				if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < m) {
					if (um[nextx][nexty] != 0 && !check[nextx][nexty] ) {
						//파이프 연결 가능 확인 ( 방향 == ( 방향 + 2 ) % 4 )
						bool checkxy = false;
						if (pipex[um[nowx][nowy]][i] != 0 && pipex[um[nextx][nexty]][(i + 2) % 4] != 0)
							if (pipex[um[nowx][nowy]][i] == (-1 * pipex[um[nextx][nexty]][(i + 2) % 4]))
								checkxy = true;
						if (pipey[um[nowx][nowy]][i] != 0 && pipey[um[nextx][nexty]][(i + 2) % 4] != 0)
							if (pipey[um[nowx][nowy]][i] == (-1 * pipey[um[nextx][nexty]][(i + 2) % 4]))
								checkxy = true;
						if (checkxy) {
							//시간 증가
							tt[nextx][nexty] = tt[nowx][nowy] + 1;
							if (tt[nextx][nexty] > l) {  //시간 초과하면 반복문 빠져나감
								escape = true;
								break;
							}
							check[nextx][nexty] = true;
							p = make_pair(nextx, nexty);
							q.push(p);
						}
					}
				}
			}
			if (escape)
				break;
		}
		/*printf("\n");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				printf("%d ", tt[i][j]);
			printf("\n");
		}*/
		int ans = 0;
		//갯수 계산
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				if (check[i][j])
					ans++;
		}
		printf("#%d %d\n", tc, ans);
		//초기화
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < m; j++) {
				um[i][j] = 0;
				check[i][j] = false;
				tt[i][j] = 0;
			}
		while (!q.empty())
			q.pop();
	}

	return 0;
}