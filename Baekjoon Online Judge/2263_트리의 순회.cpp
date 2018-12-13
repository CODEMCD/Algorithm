#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
#define N 100001
int in[N];
int post[N];
int position[N];

void solve(int in_start, int in_end, int post_start, int post_end)
{
	if (in_start > in_end || post_start > post_end)
		return;
	int root = post[post_end];
	printf("%d ", root);
	int p = position[root]; //inorder에서 root의 위치
	int left = p - in_start;  //왼쪽 서브트리 오른쪽 서브트리 구분
	solve(in_start, p - 1, post_start, post_start + left - 1); //left tree
	solve(p + 1, in_end, post_start + left, post_end - 1); //right tree
}

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &in[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &post[i]);
	for (int i = 0; i < n; i++)
		position[in[i]] = i;
	solve(0, n - 1, 0, n - 1);
	return 0;
}