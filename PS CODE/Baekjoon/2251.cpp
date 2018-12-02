#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
#define N 201
bool check[N][N];
bool ans[N];

struct water
{
	int a, b, c;
};
typedef struct water water;

int main(void)
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	water w;
	w.a = 0; w.b = 0; w.c = c;
	check[w.a][w.b] = true;
	if (w.a == 0)
		ans[w.c] = true;
	queue<water> q;
	q.push(w);
	while (!q.empty()) {
		water wnow = q.front();
		water next;
		q.pop();
		int aa = wnow.a; int bb = wnow.b; int cc = wnow.c;
		if (cc != 0 && aa < a) {
			int d = a - aa;
			if (d < cc) {
				aa += d;
				cc = cc - d;
			}
			else {
				aa += cc;
				cc = 0;
			}
			next.a = aa; next.b = bb; next.c = cc;
			if (check[aa][bb] == false) {
				check[aa][bb] = true;
				q.push(next);
				if (aa == 0)
					ans[cc] = true;
			}
		}
		aa = wnow.a; bb = wnow.b; cc = wnow.c;
		if (cc != 0 && bb < b) {
			int d = b - bb;
			if (d < cc) {
				bb += d;
				cc = cc - d;
			}
			else {
				bb += cc;
				cc = 0;
			}
			next.a = aa; next.b = bb; next.c = cc;
			if (check[aa][bb] == false) {
				check[aa][bb] = true;
				q.push(next);
				if (aa == 0)
					ans[cc] = true;
			}
		}
		aa = wnow.a; bb = wnow.b; cc = wnow.c;
		if (bb != 0 && aa < a) {
			int d = a - aa;
			if (d < bb) {
				aa += d;
				bb = bb - d;
			}
			else {
				aa += bb;
				bb = 0;
			}
			next.a = aa; next.b = bb; next.c = cc;
			if (check[aa][bb] == false) {
				check[aa][bb] = true;
				q.push(next);
				if (aa == 0)
					ans[cc] = true;
			}
		}
		aa = wnow.a; bb = wnow.b; cc = wnow.c;
		if (bb != 0 && cc < c) {
			int d = c - cc;
			if (d < bb) {
				cc += d;
				bb = bb - d;
			}
			else {
				cc += bb;
				bb = 0;
			}
			next.a = aa; next.b = bb; next.c = cc;
			if (check[aa][bb] == false) {
				check[aa][bb] = true;
				q.push(next);
				if (aa == 0)
					ans[cc] = true;
			}
		}
		aa = wnow.a; bb = wnow.b; cc = wnow.c;
		if (aa != 0 && bb < b) {
			int d = b - bb;
			if (d < aa) {
				bb += d;
				aa = aa - d;
			}
			else {
				bb += aa;
				aa = 0;
			}
			next.a = aa; next.b = bb; next.c = cc;
			if (check[aa][bb] == false) {
				check[aa][bb] = true;
				q.push(next);
				if (aa == 0)
					ans[cc] = true;
			}
		}
		aa = wnow.a; bb = wnow.b; cc = wnow.c;
		if (aa != 0 && cc < c) {
			int d = c - cc;
			if (d < aa) {
				cc += d;
				aa = aa - d;
			}
			else {
				cc += aa;
				aa = 0;
			}
			next.a = aa; next.b = bb; next.c = cc;
			if (check[aa][bb] == false) {
				check[aa][bb] = true;
				q.push(next);
				if (aa == 0)
					ans[cc] = true;
			}
		}
	}
	for (int i = 0; i < N; i++)
		if (ans[i] == true)
			printf("%d ", i);
	printf("\n");

	return 0;
}