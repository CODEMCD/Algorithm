#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define N 10000
char tmp[N];
char ntmp[100];
int num[51];
char pm[51];

int main(void)
{
	cin >> tmp;
	int ncnt, nncnt, ccnt, n;
	for(int i=0;i<N;i++)
		if (tmp[i] == '\0') {
			n = i;
			break;
		}
	ncnt = 0; nncnt = 0; ccnt = 1;
	for (int i = 0; i <= n; i++) {
		if (tmp[i] == '+' || tmp[i] == '-' || tmp[i] == '\0') {
			if (nncnt > 0) {
				num[ncnt] = atoi(ntmp);
				ncnt++;
				nncnt = 0;
				memset(ntmp, '\0', sizeof(ntmp));
			}
			pm[ccnt] = tmp[i];
			ccnt++;

		}
		else {
			ntmp[nncnt] = tmp[i];
			nncnt++;
		}
	}

	//for (int i = 0; i < ncnt; i++) 
		//printf("%d %c\n", num[i], pm[i]);

	int plus = 0;
	int minus = 0;
	for (int i = 0; i < ncnt; i++) {
		if (pm[i] == '-') {
			for (int j = i; j < ncnt; j++) {
				minus += num[j];
				i = j;
			}
		}
		else
			plus += num[i];
	}
	//printf("%d %d\n", plus, minus);
	printf("%d\n", plus - minus);
	return 0;
}