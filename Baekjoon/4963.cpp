#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define N 51
int map[N][N];
int check[N][N];
int w, h;

void numbering(int i, int j, int cnt)
{
	if (check[i][j] == -1 && map[i][j] == 1)
		check[i][j] = cnt;
	if (check[i - 1][j] == -1 && (i - 1) >= 0 && map[i - 1][j] == 1)
		numbering(i - 1, j, cnt);
	if (check[i - 1][j + 1] == -1 && (j + 1) < w && (i - 1) >= 0 && map[i - 1][j + 1] == 1)
		numbering(i - 1, j + 1, cnt);
	if (check[i][j + 1] == -1 && (j + 1) < w && map[i][j + 1] == 1)
		numbering(i, j + 1, cnt);
	if (check[i + 1][j + 1] == -1 && (i + 1) < h && (j + 1) < w && map[i + 1][j + 1] == 1)
		numbering(i + 1, j + 1, cnt);
	if (check[i + 1][j] == -1 && (i + 1) < h && map[i + 1][j] == 1)
		numbering(i + 1, j, cnt);
	if (check[i + 1][j - 1] == -1 && (i + 1) < h && (j - 1) >= 0 && map[i + 1][j - 1] == 1)
		numbering(i + 1, j - 1, cnt);
	if (check[i][j - 1] == -1 && (j - 1) >= 0 && map[i][j - 1] == 1)
		numbering(i, j - 1, cnt);
	if (check[i - 1][j - 1] == -1 && (i - 1) >= 0 && (j - 1) >= 0 && map[i - 1][j - 1] == 1)
		numbering(i - 1, j - 1, cnt);
}

int main(void)
{
	int cnt;
	
	while (1) {
		for (int i = 0; i < N; i++)
			memset(check[i], -1, sizeof(int) * N);
		cnt = 1;

		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0)
			break;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				scanf("%d", &map[i][j]);
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 0 && check[i][j] == -1)
					check[i][j] = 0;
				else if (check[i][j] == -1 && map[i][j] == 1) {
					numbering(i, j, cnt);
					cnt++;
				}
			}
		}

		printf("%d\n", cnt - 1);
	}

	return 0;
}