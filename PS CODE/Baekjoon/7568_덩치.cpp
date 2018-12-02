#define _CRT_SECURE_NO_WARNINGS

//¿ÏÀüÅ½»ö
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define N 51
vector<pair<int, int>> person;
int prank[N];

int main() 
{
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int weight, tall;
		scanf("%d %d", &weight, &tall);
		person.push_back({ weight, tall });
	}
	for (int i = 0; i < n; i++) {
		int calRank = 0;
		for (int j = 0; j < n; j++) {
			if (i != j) {
				if (person[i].first < person[j].first &&
					person[i].second < person[j].second)
					calRank++;
			}
		}
		prank[i] = calRank + 1;
	}
	for (int i = 0; i < n; i++)
		printf("%d ", prank[i]);
	printf("\n");

	return 0;
}
