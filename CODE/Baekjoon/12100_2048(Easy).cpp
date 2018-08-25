#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
using namespace std;

int n, ans;
//해당 보드판 중에서 가장 큰값을 반환한다.
int calMax(vector<vector<int>> &board) {
	int maxN = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			maxN = max(maxN, board[i][j]);
	return maxN;
}

//다음 보드판을 만들어 반환한다.
vector<vector<int>> makeNextBoard(vector<vector<int>> &board, int dir) {
	vector<vector<int>> nb(n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		//상하좌우로 움직였을 때, 해당 열들을 계산한후 오른쪽과 아래쪽은 앞에서 꺼내고
		//왼쪽과 위쪽은 뒤에서 꺼내기 위해 덱을 사용
		deque<int> dq;
		int dqSize;
		//Right
		if (dir == 0) {
			//한번 합치면 해당 턴에서는 합칠 수 없기 때문에 이를 검사하기 위한 flag
			vector<bool> flag;
			for (int j = n - 1; j >= 0; --j) {
				//보드판이 0이 아닐때
				if (board[i][j] != 0) {
					if (!dq.empty()) {
						int back = dq.back();
						//해당 덱의 마지막값이 현재 들어오는 값과 같고 그 전단계에서
						//계산되지 않은 값이라면, 더한 후에 다시 덱에 넣어준다.
						if (back == board[i][j] && !flag[flag.size() - 1]) {
							dq.pop_back();
							dq.push_back(back + board[i][j]);
							flag[flag.size() - 1] = true;
						}
						else {
							dq.push_back(board[i][j]);
							flag.push_back(false);
						}
					}
					else {
						dq.push_back(board[i][j]);
						flag.push_back(false);
					}
				}
			}
			//보드판 한 줄을 만든다.
			dqSize = dq.size();
			for (int j = 0; j < n; ++j) {
				if (j < (n - dqSize))
					nb[i][j] = 0;
				else {
					nb[i][j] = dq.back();
					dq.pop_back();
				}
			}
		}
		//Left
		else if (dir == 2) {
			vector<bool> flag;
			for (int j = 0; j < n; ++j) {
				if (board[i][j] != 0) {
					if (!dq.empty()) {
						int back = dq.back();
						if (back == board[i][j] && !flag[flag.size() - 1]) {
							dq.pop_back();
							dq.push_back(back + board[i][j]);
							flag[flag.size() - 1] = true;
						}
						else {
							dq.push_back(board[i][j]);
							flag.push_back(false);
						}
					}
					else {
						dq.push_back(board[i][j]);
						flag.push_back(false);
					}
				}
			}
			dqSize = dq.size();
			for (int j = 0; j < n; ++j) {
				if (j < dqSize) {
					nb[i][j] = dq.front();
					dq.pop_front();
				}
				else
					nb[i][j] = 0;
			}
		}
		//Bottom
		else if (dir == 1) {
			vector<bool> flag;
			for (int j = n - 1; j >= 0; --j) {
				if (board[j][i] != 0) {
					if (!dq.empty()) {
						int back = dq.back();
						if (back == board[j][i] && !flag[flag.size() - 1]) {
							dq.pop_back();
							dq.push_back(back + board[j][i]);
							flag[flag.size() - 1] = true;
						}
						else {
							dq.push_back(board[j][i]);
							flag.push_back(false);
						}
					}
					else {
						dq.push_back(board[j][i]);
						flag.push_back(false);
					}
				}
			}
			dqSize = dq.size();
			for (int j = 0; j < n; ++j) {
				if (j < (n - dqSize))
					nb[j][i] = 0;
				else {
					nb[j][i] = dq.back();
					dq.pop_back();
				}
			}
		}
		//Up
		else if (dir == 3) {
			vector<bool> flag;
			for (int j = 0; j < n; ++j) {
				if (board[j][i] != 0) {
					if (!dq.empty()) {
						int back = dq.back();
						if (back == board[j][i] && !flag[flag.size() - 1]) {
							dq.pop_back();
							dq.push_back(back + board[j][i]);
							flag[flag.size() - 1] = true;
						}
						else {
							dq.push_back(board[j][i]);
							flag.push_back(false);
						}
					}
					else {
						dq.push_back(board[j][i]);
						flag.push_back(false);
					}
				}
			}
			dqSize = dq.size();
			for (int j = 0; j < n; ++j) {
				if (j < dqSize) {
					nb[j][i] = dq.front();
					dq.pop_front();
				}
				else
					nb[j][i] = 0;
			}
		}
	}
	return nb;
}

//모든 보드판을 만들어 최대값을 계산한다.
void dfs(vector<vector<int>> board, int cnt) {
	if (cnt == 6) return;
	ans = max(ans, calMax(board));

	//Right
	dfs(makeNextBoard(board, 0), cnt + 1);
	//Bottom
	dfs(makeNextBoard(board, 1), cnt + 1);
	//Left
	dfs(makeNextBoard(board, 2), cnt + 1);
	//Up
	dfs(makeNextBoard(board, 3), cnt + 1);
}

int main()
{
	scanf("%d", &n);
	vector<vector<int>> inp(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int num; scanf("%d", &num);
			inp[i].push_back(num);
		}
	}
	dfs(inp, 0);
	printf("%d\n", ans);

	return 0;
}
