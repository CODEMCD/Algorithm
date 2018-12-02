#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#define N 20001
vector<pair<int, string>> v;

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		bool check = false;
		string s;
		cin >> s;
		for (int i = 0; i < v.size(); i++) {
			if (v[i].second == s) {
				check = true;
				break;
			}
		}
		if (check == true)
			continue;
		pair<int, string>p;
		p.first = s.size();
		p.second = s;
		v.push_back(p);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i].second << endl;

	return 0;
}
