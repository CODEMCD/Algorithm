#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

//톱니바퀴 정보 저장
int wheel[4][8];
//회전 정보 저장
int rotIn[2][101];
//각 톱니바퀴 회전 여부와 방향 저장
pair<bool, int> rotCheck[4];
//톱니바퀴 방문 여부 저장
bool visited[4];

//톱니바퀴를 시계방향으로 회전한 결과
void rotCircle(int idx) {
	int tmp = wheel[idx][7];
	for (int i = 6; i >= 0; --i)
		wheel[idx][i + 1] = wheel[idx][i];
	wheel[idx][0] = tmp;
}

//톱니바퀴를 반시계방향으로 회전한 결과
void rotReCircle(int idx) {
	int tmp = wheel[idx][0];
	for (int i = 1; i < 8; ++i)
		wheel[idx][i - 1] = wheel[idx][i];
	wheel[idx][7] = tmp;
}

int main()
{
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 8; ++j)
			scanf("%1d", &wheel[i][j]);
	int k; scanf("%d", &k);
	for (int i = 0; i < k; ++i)
		scanf("%d %d", &rotIn[0][i], &rotIn[1][i]);

	queue<int> q;
	for (int i = 0; i < k; ++i) {
		//초기화
		rotIn[0][i] -= 1;
		for (int j = 0; j < 4; ++j) {
			visited[j] = false;
			rotCheck[j].first = false;
		}

		//처음 회전하는 톱니바퀴의 회전 정보 저장
		rotCheck[rotIn[0][i]].first = true;
		rotCheck[rotIn[0][i]].second = rotIn[1][i];

		//주위 톱니바퀴 상태 체크(BFS)
		q.push(rotIn[0][i]);
		visited[rotIn[0][i]] = true;
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			//앞 톱니바퀴
			int pre = cur - 1;
			//뒤 톱니바퀴
			int next = cur + 1;
			//앞 톱니바퀴 회전 여부 검사
			if (pre >= 0 && !visited[pre]) {
				if (wheel[cur][6] != wheel[pre][2]) {
					rotCheck[pre].first = true;
					rotCheck[pre].second = -rotCheck[cur].second;
					visited[pre] = true;
					q.push(pre);
				}
			}
			//뒤 톱니바퀴 회전 여부 검사
			if (next < 4 && !visited[next]) {
				if (wheel[cur][2] != wheel[next][6]) {
					rotCheck[next].first = true;
					rotCheck[next].second = -rotCheck[cur].second;
					visited[next] = true;
					q.push(next);
				}
			}
		}
		
		//회전하기
		for (int j = 0; j < 4; ++j) {
			if (rotCheck[j].first) {
				if (rotCheck[j].second == 1)
					rotCircle(j);
				else if (rotCheck[j].second == -1)
					rotReCircle(j);
			}
		}
	}

	//점수 출력
	printf("%d\n", wheel[0][0] * 1 + wheel[1][0] * 2 + wheel[2][0] * 4
		+ wheel[3][0] * 8);

	return 0;
}
