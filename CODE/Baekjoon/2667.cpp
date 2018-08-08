#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define N 26
int map[N][N];
int check[N][N];
int cntsort[N];
int n, ccnt;

void numbering(int i, int j, int cnt)
{
	if (check[i][j] == -1 && map[i][j] == 1) {
		check[i][j] = cnt;
		ccnt++;
	}
	if (check[i - 1][j] == -1 && (i - 1) >= 0 && map[i - 1][j] == 1)
		numbering(i - 1, j, cnt);
	if (check[i][j + 1] == -1 && (j + 1) < n && map[i][j + 1] == 1)
		numbering(i, j + 1, cnt);
	if (check[i + 1][j] == -1 && (i + 1) < n && map[i + 1][j] == 1)
		numbering(i + 1, j, cnt);
	if (check[i][j - 1] == -1 && (j - 1) >= 0 && map[i][j - 1] == 1)
		numbering(i, j - 1, cnt);
}

int main(void)
{
	for (int i = 0; i < N; i++)
		memset(check[i], -1, sizeof(int) * N);
	int cnt = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%1d", &map[i][j]);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0 && check[i][j] == -1)
				check[i][j] = 0;
			else if (check[i][j] == -1 && map[i][j] == 1) {
				numbering(i, j, cnt);
				cntsort[cnt] = ccnt;
				cnt++;
				ccnt = 0;
			}
		}
	}
	sort(cntsort, cntsort + cnt);
	printf("%d\n", cnt - 1);
	for (int i = 1; i < cnt; i++)
		printf("%d\n", cntsort[i]);
	
	//printf("\n");
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++)
	//		printf("%d ", check[i][j]);
	//	printf("\n");
	//}

	return 0;
}