#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 10001
int deq[N];

int main(void)
{
	int n;
	scanf("%d", &n);

	int size = 0;
	while (n--) {
		char cmd[20];
		scanf("%s", cmd);
		if (!strcmp(cmd, "push_front")) {
			int x;
			scanf("%d", &x);
			if (size > 0) {
				for (int i = size; i >= 0; i--)
					deq[i + 1] = deq[i];
			}
			deq[0] = x;
			size++;
		}
		if (!strcmp(cmd, "push_back")) {
			int x;
			scanf("%d", &x);
			deq[size++] = x;
		}
		if (!strcmp(cmd, "pop_front")) {
			if (size == 0)
				printf("-1\n");
			else if (size > 0) {
				printf("%d\n", deq[0]);
				for (int i = 1; i <= size; i++)
					deq[i - 1] = deq[i];
				size--;
			}
		}
		if (!strcmp(cmd, "pop_back")) {
			if (size == 0)
				printf("-1\n");
			else if (size > 0) {
				printf("%d\n", deq[size - 1]);
				size--;
			}
		}
		if (!strcmp(cmd, "size"))
			printf("%d\n", size);
		if (!strcmp(cmd, "empty")) {
			if (size == 0)
				printf("1\n");
			else
				printf("0\n");
		}
		if (!strcmp(cmd, "front")) {
			if (size == 0)
				printf("-1\n");
			else if (size > 0) 
				printf("%d\n", deq[0]);
		}
		if (!strcmp(cmd, "back")) {
			if (size == 0)
				printf("-1\n");
			else if (size > 0)
				printf("%d\n", deq[size - 1]);
		}
	}
	return 0;
}