#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
struct Meeting {
	int begin, end;
};

bool cmp(const Meeting &u, const Meeting &v)
{
	if (u.end == v.end)
		return u.begin < v.begin;
	else
		return u.end < v.end;
}

int main(void)
{
	int n;
	scanf("%d", &n);
	vector<Meeting> v(n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &v[i].begin, &v[i].end);

	sort(v.begin(), v.end(), cmp);
	/*for (int i = 0; i < v.size(); i++)
		printf("%d %d\n", v[i].begin, v[i].end);*/
	int now = 0, ans = 0;
	for (int i = 0; i < v.size(); i++) {
		if (now <= v[i].begin) {
			now = v[i].end;
			ans += 1;
		}
	}
	printf("%d\n", ans);

	return 0;
}