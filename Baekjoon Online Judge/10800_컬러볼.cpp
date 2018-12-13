#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define N 200001
typedef struct _colorvector
{
	int colNum;
	int size;
	int idx;
}colorvector;
typedef colorvector CV;
vector<CV> v;
int color[N];
int sizebox[2001];
int ans[N];

bool compare(CV a, CV b) { return a.size < b.size; }

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int c, s;
		scanf("%d %d", &c, &s);
		CV cv;
		cv.colNum = c;
		cv.size = s;
		cv.idx = i;
		v.push_back(cv);
	}
	sort(v.begin(), v.end(), compare);
	/*for (int i = 0; i < v.size(); i++)
		printf("%d %d %d\n", v[i].idx, v[i].colNum, v[i].size);*/
	for (int i = 0, j = 0; i < (int)v.size(); i++) {
		for (; v[j].size < v[i].size; j++) {
			color[0] += v[j].size;
			color[v[j].colNum] += v[j].size;
		}
		ans[v[i].idx] = color[0] - color[v[i].colNum];
	}
	for (int i = 0; i < n; i++)
		printf("%d\n", ans[i]);
	
	return 0;
}

